//
// Copyright (C) 2014 OpenSim Ltd.
// Author: Benjamin Seregi
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

#ifndef __INET_LARROUTING_H
#define __INET_LARROUTING_H

#include "inet/common/INETDefs.h"
#include "inet/networklayer/contract/IInterfaceTable.h"
#include "inet/networklayer/contract/IL3AddressType.h"
#include "inet/networklayer/contract/IRoutingTable.h"
#include "inet/networklayer/contract/INetfilter.h"
#include "inet/common/lifecycle/ILifecycle.h"
#include "inet/common/lifecycle/NodeStatus.h"
#include "inet/transportlayer/contract/udp/UDPSocket.h"
#include "inet/routing/lar/LARRouteData.h"
#include "inet/transportlayer/udp/UDPPacket.h"
#include "inet/routing/lar/LARControlPackets_m.h"

#include "inet/mobility/single/BonnMotionMobility.h"
#include "inet/networklayer/larinfo/LARNodeInfo.h"
#include "inet/common/geometry/common/Coord.h"
#include <omnetpp.h>
#include <vector>

namespace inet {

/*
 * This class implements LAR routing protocol and Netfilter hooks
 * in the IP-layer required by this protocol.
 */

class INET_API LARRouting : public cSimpleModule, public ILifecycle, public INetfilter::IHook, public cListener
{
private:

  protected:

    BonnMotionMobility* baseMobility = nullptr;

    /*
     * It implements a unique identifier for an arbitrary RREQ message
     * in the network. See: rreqsArrivalTime.
     */
    class RREQIdentifier
    {
      public:
        L3Address originatorAddr;
        unsigned int rreqID;
        RREQIdentifier(const L3Address& originatorAddr, unsigned int rreqID) : originatorAddr(originatorAddr), rreqID(rreqID) {};
        bool operator==(const RREQIdentifier& other) const
        {
            return this->originatorAddr == other.originatorAddr && this->rreqID == other.rreqID;
        }
    };

    class RREQIdentifierCompare
    {
      public:
        bool operator()(const RREQIdentifier& lhs, const RREQIdentifier& rhs) const
        {
            return lhs.rreqID < rhs.rreqID;
        }
    };

    //added
    std::vector<LARNodeInfo*> nodesInfo;
    unsigned int numHosts;

    // context
    IL3AddressType *addressType = nullptr;    // to support both IPv4 and v6 addresses.

    // environment
    cModule *host = nullptr;
    IRoutingTable *routingTable = nullptr;
    IInterfaceTable *interfaceTable = nullptr;
    INetfilter *networkProtocol = nullptr;

    // LAR parameters: the following parameters are configurable, see the NED file for more info.
    unsigned int rerrRatelimit = 0;
    unsigned int larUDPPort = 0;
    bool askGratuitousRREP = false;
    bool useHelloMessages = false;
    simtime_t maxJitter;
    simtime_t activeRouteTimeout;
    simtime_t helloInterval;
    unsigned int netDiameter = 0;
    unsigned int rreqRetries = 0;
    unsigned int rreqRatelimit = 0;
    unsigned int timeoutBuffer = 0;
    unsigned int ttlStart = 0;
    unsigned int ttlIncrement = 0;
    unsigned int ttlThreshold = 0;
    unsigned int localAddTTL = 0;
    unsigned int allowedHelloLoss = 0;
    simtime_t nodeTraversalTime;
    cPar *jitterPar = nullptr;
    cPar *periodicJitter = nullptr;

    // the following parameters are calculated from the parameters defined above
    // see the NED file for more info
    simtime_t deletePeriod;
    simtime_t myRouteTimeout;
    simtime_t blacklistTimeout;
    simtime_t netTraversalTime;
    simtime_t nextHopWait;
    simtime_t pathDiscoveryTime;

    // state
    unsigned int rreqId = 0;    // when sending a new RREQ packet, rreqID incremented by one from the last id used by this node
    unsigned int sequenceNum = 0;    // it helps to prevent loops in the routes (RFC 3561 6.1 p11.)
    std::map<L3Address, WaitForRREP *> waitForRREPTimers;    // timeout for Route Replies
    std::map<RREQIdentifier, simtime_t, RREQIdentifierCompare> rreqsArrivalTime;    // maps RREQ id to its arriving time
    L3Address failedNextHop;    // next hop to the destination who failed to send us RREP-ACK
    std::map<L3Address, simtime_t> blacklist;    // we don't accept RREQs from blacklisted nodes
    unsigned int rerrCount = 0;    // num of originated RERR in the last second
    unsigned int rreqCount = 0;    // num of originated RREQ in the last second
    simtime_t lastBroadcastTime;    // the last time when any control packet was broadcasted
    std::map<L3Address, unsigned int> addressToRreqRetries;    // number of re-discovery attempts per address

    // self messages
    cMessage *helloMsgTimer = nullptr;    // timer to send hello messages (only if the feature is enabled)
    cMessage *expungeTimer = nullptr;    // timer to clean the routing table out
    cMessage *counterTimer = nullptr;    // timer to set rrerCount = rreqCount = 0 in each second
    cMessage *rrepAckTimer = nullptr;    // timer to wait for RREP-ACKs (RREP-ACK timeout)
    cMessage *blacklistTimer = nullptr;    // timer to clean the blacklist out

    //statistics
    simsignal_t rreqSentSignal;
    simsignal_t rrepSentSignal;
    simsignal_t rreqRecSignal;
    simsignal_t rreq1RecSignal;
    simsignal_t rrepRecSignal;
    simsignal_t rrep1RecSignal;
    simsignal_t rrep2RecSignal;
    long rreqSent = 0;
    long rrepSent = 0;
    long rreqRec = 0;
    long rreq1Rec = 0;
    long rrepRec = 0;
    long rrep1Rec = 0;
    long rrep2Rec = 0;

    // lifecycle
    simtime_t rebootTime;    // the last time when the node rebooted
    bool isOperational = false;

    // internal
    std::multimap<L3Address, INetworkDatagram *> targetAddressToDelayedPackets;    // queue for the datagrams we have no route for

  protected:
    void handleMessage(cMessage *msg) override;
    void initialize(int stage) override;
    virtual int numInitStages() const override { return NUM_INIT_STAGES; }

    /* Route Discovery */
    void startRouteDiscovery(const L3Address& target, unsigned int timeToLive = 0);
    void completeRouteDiscovery(const L3Address& target);
    bool hasOngoingRouteDiscovery(const L3Address& destAddr);
    void cancelRouteDiscovery(const L3Address& destAddr);

    /* Routing Table management */
    void updateRoutingTable(IRoute *route, const L3Address& nextHop, unsigned int hopCount, bool hasValidDestNum, unsigned int destSeqNum, bool isActive, simtime_t lifeTime);
    IRoute *createRoute(const L3Address& destAddr, const L3Address& nextHop, unsigned int hopCount, bool hasValidDestNum, unsigned int destSeqNum, bool isActive, simtime_t lifeTime);
    bool updateValidRouteLifeTime(const L3Address& destAddr, simtime_t lifetime);
    void scheduleExpungeRoutes();
    void expungeRoutes();

    /* Control packet creators */
    LARRREPACK *createRREPACK();
    LARRREP *createHelloMessage();
    LARRREQ *createRREQ(const L3Address& destAddr, Coord senderCord, Coord receiverCord,unsigned int type);
    LARRREP *createRREP(LARRREQ *rreq, IRoute *destRoute, IRoute *originatorRoute, const L3Address& sourceAddr);
    MOVEINFO *createMOVEINFO(unsigned int hostIndex, double x, double y, long speed);
    LARRREP *createGratuitousRREP(LARRREQ *rreq, IRoute *originatorRoute);
    LARRERR *createRERR(const std::vector<UnreachableNode>& unreachableNodes);

    /*Create possible position of receiver*/
    Coord createReceiverCoord(double x,double y,long speed,simtime_t time,unsigned int type);

    /* Control Packet handlers */
    void handleRREP(LARRREP *rrep, const L3Address& sourceAddr);
    void handleRREQ(LARRREQ *rreq, const L3Address& sourceAddr, unsigned int timeToLive);
    void handleRERR(LARRERR *rerr, const L3Address& sourceAddr);
    void handleHelloMessage(LARRREP *helloMessage);
    void handleRREPACK(LARRREPACK *rrepACK, const L3Address& neighborAddr);
    void handleMOVEINFO(MOVEINFO* moveMsg);
    void createNodeInfoVet();

    bool hostCanForward(LARRREQ *rreq);

    /* Control Packet sender methods */
    void sendRREQ(LARRREQ *rreq, const L3Address& destAddr, unsigned int timeToLive);
    void sendRREPACK(LARRREPACK *rrepACK, const L3Address& destAddr);
    void sendRREP(LARRREP *rrep, const L3Address& destAddr, unsigned int timeToLive);
    void sendGRREP(LARRREP *grrep, const L3Address& destAddr, unsigned int timeToLive);

    /* Control Packet forwarders */
    void forwardRREP(LARRREP *rrep, const L3Address& destAddr, unsigned int timeToLive);
    void forwardRREQ(LARRREQ *rreq, unsigned int timeToLive);

    /* Self message handlers */
    void handleRREPACKTimer();
    void handleBlackListTimer();
    void sendHelloMessagesIfNeeded();
    void handleWaitForRREP(WaitForRREP *rrepTimer);

    /* General functions to handle route errors */
    void sendRERRWhenNoRouteToForward(const L3Address& unreachableAddr);
    void handleLinkBreakSendRERR(const L3Address& unreachableAddr);
    virtual void receiveSignal(cComponent *source, simsignal_t signalID, cObject *obj) override;

    /* Netfilter hooks */
    Result ensureRouteForDatagram(INetworkDatagram *datagram);
    virtual Result datagramPreRoutingHook(INetworkDatagram *datagram, const InterfaceEntry *inputInterfaceEntry, const InterfaceEntry *& outputInterfaceEntry, L3Address& nextHopAddress) override { Enter_Method("datagramPreRoutingHook"); return ensureRouteForDatagram(datagram); }
    virtual Result datagramForwardHook(INetworkDatagram *datagram, const InterfaceEntry *inputInterfaceEntry, const InterfaceEntry *& outputInterfaceEntry, L3Address& nextHopAddress) override;
    virtual Result datagramPostRoutingHook(INetworkDatagram *datagram, const InterfaceEntry *inputInterfaceEntry, const InterfaceEntry *& outputInterfaceEntry, L3Address& nextHopAddress) override { return ACCEPT; }
    virtual Result datagramLocalInHook(INetworkDatagram *datagram, const InterfaceEntry *inputInterfaceEntry) override { return ACCEPT; }
    virtual Result datagramLocalOutHook(INetworkDatagram *datagram, const InterfaceEntry *& outputInterfaceEntry, L3Address& nextHopAddress) override { Enter_Method("datagramLocalOutHook"); return ensureRouteForDatagram(datagram); }
    void delayDatagram(INetworkDatagram *datagram);

    /* Helper functions */
    L3Address getSelfIPAddress() const;
    void sendLARPacket(LARControlPacket *packet, const L3Address& destAddr, unsigned int timeToLive, double delay);
    void clearState();

    /* Lifecycle */
    virtual bool handleOperationStage(LifecycleOperation *operation, int stage, IDoneCallback *doneCallback) override;

  public:
    LARRouting();
    virtual ~LARRouting();
};

} // namespace inet

#endif    // ifndef LARROUTING_H_

