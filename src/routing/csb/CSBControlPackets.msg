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
// MERCHANTABILITY or FITNESS FOR A PARTICUCSB PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

cplusplus {{
#include "inet/networklayer/common/L3Address.h"
#include "inet/routing/aodv/AODVControlPackets_m.h"
}}

namespace inet;

class noncobject L3Address;
struct UnreachableNode;

packet AODVControlPacket;


//
// Helper struct to represent (L3Address, sequence number) pairs in a RERR message
//
//struct UnreachableNode
//{
//    L3Address addr;
//    unsigned int seqNum;
//};

enum CSBControlPacketType
{
//	RREQ = 1;
//	RREP = 2;
//	RERR = 3;
//	RREPACK = 4;
	ContactInfo = 5;
};

//
// Base packet for CSB Control Packets
//
packet CSBControlPacket extends AODVControlPacket
{
}

//
// Represents an CSB Route Request
//
class CSBRREQ extends CSBControlPacket
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
}

//
// Represents an CSB Route Reply
//
class CSBRREP extends CSBControlPacket
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
// Represents an CSB Route Error
//
class CSBRERR extends CSBControlPacket
{
    unsigned int packetType = RERR;
    UnreachableNode unreachableNodes[];
    bool noDeleteFlag;
    unsigned int destCount;
}

//
// Represents an CSB Route Reply ACK
//
class CSBRREPACK extends CSBControlPacket
{
    unsigned int packetType = RREPACK;
}

class CONTACTINFO extends CSBControlPacket{
    unsigned int packetType = ContactInfo;
    unsigned int hostIndex;
    L3Address sourceAddr;
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
