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

cplusplus {{
#include "inet/networklayer/common/L3Address.h"
#include "inet/routing/aodv/AODVControlPackets_m.h"
#include "inet/common/geometry/common/Coord.h"
}}

namespace inet;

class noncobject L3Address;
struct UnreachableNode;
class noncobject Coord;

packet AODVControlPacket;


//
// Helper struct to represent (L3Address, sequence number) pairs in a RERR message
//
//struct UnreachableNode
//{
//    L3Address addr;
//    unsigned int seqNum;
//};

enum LARControlPacketType
{
//	RREQ = 1;
//	RREP = 2;
//	RERR = 3;
//	RREPACK = 4;
	MoveInfo = 5;
};

//
// Base packet for LAR Control Packets
//
packet LARControlPacket extends AODVControlPacket
{
}

//
// Represents an LAR Route Request
//
class LARRREQ extends LARControlPacket
{
    unsigned int packetType = RREQ;
    bool joinFlag;
    bool repairFlag;
    bool gratuitousRREPFlag;
    bool destOnlyFlag;
    bool unknownSeqNumFlag;
    unsigned int hopCount;
    unsigned int rreqId;
    L3Address destAddr;
    unsigned int destSeqNum;
    L3Address originatorAddr;
    unsigned int originatorSeqNum;
    Coord senderCoord;
    Coord ReceiverPossibleCoord;
    unsigned int type;
}

//
// Represents an LAR Route Reply
//
class LARRREP extends LARControlPacket
{
    unsigned int packetType = RREP;
    bool repairFlag;
    bool ackRequiredFlag;
    unsigned int prefixSize;
    unsigned int hopCount;
    L3Address destAddr;
    unsigned int destSeqNum;
    L3Address originatorAddr;
    unsigned int originatorSeqNum;
    simtime_t lifeTime;
}

//
// Represents an LAR Route Error
//
class LARRERR extends LARControlPacket
{
    unsigned int packetType = RERR;
    UnreachableNode unreachableNodes[];
    bool noDeleteFlag;
    unsigned int destCount;
}

//
// Represents an LAR Route Reply ACK
//
class LARRREPACK extends LARControlPacket
{
    unsigned int packetType = RREPACK;
}

class MOVEINFO extends LARControlPacket
{
    unsigned int packetType = MoveInfo;
    unsigned int hostIndex;
    double x;
    double y;
    long speed;
}


//
// Represents a timer for a Route Reply packet
//
//message WaitForRREP
//{
//    L3Address destAddr;
//    unsigned int lastTTL;
//    bool fromInvalidEntry;
//}
