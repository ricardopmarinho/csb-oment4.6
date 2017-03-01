//
// Generated file, do not edit! Created by nedtool 4.6 from inet/routing/csb/CSBControlPackets.msg.
//

#ifndef _INET_CSBCONTROLPACKETS_M_H_
#define _INET_CSBCONTROLPACKETS_M_H_

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0406
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif

// dll export symbol
#ifndef INET_API
#  if defined(INET_EXPORT)
#    define INET_API  OPP_DLLEXPORT
#  elif defined(INET_IMPORT)
#    define INET_API  OPP_DLLIMPORT
#  else
#    define INET_API
#  endif
#endif

// cplusplus {{
#include "inet/networklayer/common/L3Address.h"
#include "inet/routing/aodv/AODVControlPackets_m.h"
// }}


namespace inet {

/**
 * Enum generated from <tt>inet/routing/csb/CSBControlPackets.msg:42</tt> by nedtool.
 * <pre>
 * enum CSBControlPacketType
 * {
 * 
 *     //	RREQ = 1;
 *     //	RREP = 2;
 *     //	RERR = 3;
 *     //	RREPACK = 4;
 *     ContactInfo = 5;
 * }
 * </pre>
 */
enum CSBControlPacketType {
    ContactInfo = 5
};

/**
 * Class generated from <tt>inet/routing/csb/CSBControlPackets.msg:54</tt> by nedtool.
 * <pre>
 * //
 * // Base packet for CSB Control Packets
 * //
 * packet CSBControlPacket extends AODVControlPacket
 * {
 * }
 * </pre>
 */
class INET_API CSBControlPacket : public ::inet::AODVControlPacket
{
  protected:

  private:
    void copy(const CSBControlPacket& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const CSBControlPacket&);

  public:
    CSBControlPacket(const char *name=NULL, int kind=0);
    CSBControlPacket(const CSBControlPacket& other);
    virtual ~CSBControlPacket();
    CSBControlPacket& operator=(const CSBControlPacket& other);
    virtual CSBControlPacket *dup() const {return new CSBControlPacket(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
};

inline void doPacking(cCommBuffer *b, CSBControlPacket& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, CSBControlPacket& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/routing/csb/CSBControlPackets.msg:61</tt> by nedtool.
 * <pre>
 * //
 * // Represents an CSB Route Request
 * //
 * class CSBRREQ extends CSBControlPacket
 * {
 *     unsigned int packetType = RREQ;
 *     bool joinFlag;
 *     bool repairFlag;
 *     bool gratuitousRREPFlag;
 *     bool destOnlyFlag;
 *     bool unknownSeqNumFlag;
 *     unsigned int hopCount;
 *     unsigned int rreqId;
 *     L3Address destAddr;
 *     unsigned int destSeqNum;
 *     L3Address originatorAddr;
 *     unsigned int originatorSeqNum;
 * }
 * </pre>
 */
class INET_API CSBRREQ : public ::inet::CSBControlPacket
{
  protected:
    unsigned int packetType_var;
    bool joinFlag_var;
    bool repairFlag_var;
    bool gratuitousRREPFlag_var;
    bool destOnlyFlag_var;
    bool unknownSeqNumFlag_var;
    unsigned int hopCount_var;
    unsigned int rreqId_var;
    L3Address destAddr_var;
    unsigned int destSeqNum_var;
    L3Address originatorAddr_var;
    unsigned int originatorSeqNum_var;

  private:
    void copy(const CSBRREQ& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const CSBRREQ&);

  public:
    CSBRREQ(const char *name=NULL);
    CSBRREQ(const CSBRREQ& other);
    virtual ~CSBRREQ();
    CSBRREQ& operator=(const CSBRREQ& other);
    virtual CSBRREQ *dup() const {return new CSBRREQ(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual unsigned int getPacketType() const;
    virtual void setPacketType(unsigned int packetType);
    virtual bool getJoinFlag() const;
    virtual void setJoinFlag(bool joinFlag);
    virtual bool getRepairFlag() const;
    virtual void setRepairFlag(bool repairFlag);
    virtual bool getGratuitousRREPFlag() const;
    virtual void setGratuitousRREPFlag(bool gratuitousRREPFlag);
    virtual bool getDestOnlyFlag() const;
    virtual void setDestOnlyFlag(bool destOnlyFlag);
    virtual bool getUnknownSeqNumFlag() const;
    virtual void setUnknownSeqNumFlag(bool unknownSeqNumFlag);
    virtual unsigned int getHopCount() const;
    virtual void setHopCount(unsigned int hopCount);
    virtual unsigned int getRreqId() const;
    virtual void setRreqId(unsigned int rreqId);
    virtual L3Address& getDestAddr();
    virtual const L3Address& getDestAddr() const {return const_cast<CSBRREQ*>(this)->getDestAddr();}
    virtual void setDestAddr(const L3Address& destAddr);
    virtual unsigned int getDestSeqNum() const;
    virtual void setDestSeqNum(unsigned int destSeqNum);
    virtual L3Address& getOriginatorAddr();
    virtual const L3Address& getOriginatorAddr() const {return const_cast<CSBRREQ*>(this)->getOriginatorAddr();}
    virtual void setOriginatorAddr(const L3Address& originatorAddr);
    virtual unsigned int getOriginatorSeqNum() const;
    virtual void setOriginatorSeqNum(unsigned int originatorSeqNum);
};

inline void doPacking(cCommBuffer *b, CSBRREQ& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, CSBRREQ& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/routing/csb/CSBControlPackets.msg:80</tt> by nedtool.
 * <pre>
 * //
 * // Represents an CSB Route Reply
 * //
 * class CSBRREP extends CSBControlPacket
 * {
 *     unsigned int packetType = RREP;
 *     bool repairFlag;
 *     bool ackRequiredFlag;
 *     unsigned int prefixSize;
 *     unsigned int hopCount;
 *     L3Address destAddr;
 *     unsigned int destSeqNum;
 *     L3Address originatorAddr;
 *     unsigned int originatorSeqNum;
 *     simtime_t lifeTime;
 * }
 * </pre>
 */
class INET_API CSBRREP : public ::inet::CSBControlPacket
{
  protected:
    unsigned int packetType_var;
    bool repairFlag_var;
    bool ackRequiredFlag_var;
    unsigned int prefixSize_var;
    unsigned int hopCount_var;
    L3Address destAddr_var;
    unsigned int destSeqNum_var;
    L3Address originatorAddr_var;
    unsigned int originatorSeqNum_var;
    simtime_t lifeTime_var;

  private:
    void copy(const CSBRREP& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const CSBRREP&);

  public:
    CSBRREP(const char *name=NULL);
    CSBRREP(const CSBRREP& other);
    virtual ~CSBRREP();
    CSBRREP& operator=(const CSBRREP& other);
    virtual CSBRREP *dup() const {return new CSBRREP(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual unsigned int getPacketType() const;
    virtual void setPacketType(unsigned int packetType);
    virtual bool getRepairFlag() const;
    virtual void setRepairFlag(bool repairFlag);
    virtual bool getAckRequiredFlag() const;
    virtual void setAckRequiredFlag(bool ackRequiredFlag);
    virtual unsigned int getPrefixSize() const;
    virtual void setPrefixSize(unsigned int prefixSize);
    virtual unsigned int getHopCount() const;
    virtual void setHopCount(unsigned int hopCount);
    virtual L3Address& getDestAddr();
    virtual const L3Address& getDestAddr() const {return const_cast<CSBRREP*>(this)->getDestAddr();}
    virtual void setDestAddr(const L3Address& destAddr);
    virtual unsigned int getDestSeqNum() const;
    virtual void setDestSeqNum(unsigned int destSeqNum);
    virtual L3Address& getOriginatorAddr();
    virtual const L3Address& getOriginatorAddr() const {return const_cast<CSBRREP*>(this)->getOriginatorAddr();}
    virtual void setOriginatorAddr(const L3Address& originatorAddr);
    virtual unsigned int getOriginatorSeqNum() const;
    virtual void setOriginatorSeqNum(unsigned int originatorSeqNum);
    virtual simtime_t getLifeTime() const;
    virtual void setLifeTime(simtime_t lifeTime);
};

inline void doPacking(cCommBuffer *b, CSBRREP& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, CSBRREP& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/routing/csb/CSBControlPackets.msg:97</tt> by nedtool.
 * <pre>
 * //
 * // Represents an CSB Route Error
 * //
 * class CSBRERR extends CSBControlPacket
 * {
 *     unsigned int packetType = RERR;
 *     UnreachableNode unreachableNodes[];
 *     bool noDeleteFlag;
 *     unsigned int destCount;
 * }
 * </pre>
 */
class INET_API CSBRERR : public ::inet::CSBControlPacket
{
  protected:
    unsigned int packetType_var;
    UnreachableNode *unreachableNodes_var; // array ptr
    unsigned int unreachableNodes_arraysize;
    bool noDeleteFlag_var;
    unsigned int destCount_var;

  private:
    void copy(const CSBRERR& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const CSBRERR&);

  public:
    CSBRERR(const char *name=NULL);
    CSBRERR(const CSBRERR& other);
    virtual ~CSBRERR();
    CSBRERR& operator=(const CSBRERR& other);
    virtual CSBRERR *dup() const {return new CSBRERR(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual unsigned int getPacketType() const;
    virtual void setPacketType(unsigned int packetType);
    virtual void setUnreachableNodesArraySize(unsigned int size);
    virtual unsigned int getUnreachableNodesArraySize() const;
    virtual UnreachableNode& getUnreachableNodes(unsigned int k);
    virtual const UnreachableNode& getUnreachableNodes(unsigned int k) const {return const_cast<CSBRERR*>(this)->getUnreachableNodes(k);}
    virtual void setUnreachableNodes(unsigned int k, const UnreachableNode& unreachableNodes);
    virtual bool getNoDeleteFlag() const;
    virtual void setNoDeleteFlag(bool noDeleteFlag);
    virtual unsigned int getDestCount() const;
    virtual void setDestCount(unsigned int destCount);
};

inline void doPacking(cCommBuffer *b, CSBRERR& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, CSBRERR& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/routing/csb/CSBControlPackets.msg:108</tt> by nedtool.
 * <pre>
 * //
 * // Represents an CSB Route Reply ACK
 * //
 * class CSBRREPACK extends CSBControlPacket
 * {
 *     unsigned int packetType = RREPACK;
 * }
 * </pre>
 */
class INET_API CSBRREPACK : public ::inet::CSBControlPacket
{
  protected:
    unsigned int packetType_var;

  private:
    void copy(const CSBRREPACK& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const CSBRREPACK&);

  public:
    CSBRREPACK(const char *name=NULL);
    CSBRREPACK(const CSBRREPACK& other);
    virtual ~CSBRREPACK();
    CSBRREPACK& operator=(const CSBRREPACK& other);
    virtual CSBRREPACK *dup() const {return new CSBRREPACK(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual unsigned int getPacketType() const;
    virtual void setPacketType(unsigned int packetType);
};

inline void doPacking(cCommBuffer *b, CSBRREPACK& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, CSBRREPACK& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/routing/csb/CSBControlPackets.msg:112</tt> by nedtool.
 * <pre>
 * class CONTACTINFO extends CSBControlPacket
 * {
 *     unsigned int packetType = ContactInfo;
 *     unsigned int hostIndex;
 *     L3Address sourceAddr;
 * }
 * </pre>
 */
class INET_API CONTACTINFO : public ::inet::CSBControlPacket
{
  protected:
    unsigned int packetType_var;
    unsigned int hostIndex_var;
    L3Address sourceAddr_var;

  private:
    void copy(const CONTACTINFO& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const CONTACTINFO&);

  public:
    CONTACTINFO(const char *name=NULL);
    CONTACTINFO(const CONTACTINFO& other);
    virtual ~CONTACTINFO();
    CONTACTINFO& operator=(const CONTACTINFO& other);
    virtual CONTACTINFO *dup() const {return new CONTACTINFO(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual unsigned int getPacketType() const;
    virtual void setPacketType(unsigned int packetType);
    virtual unsigned int getHostIndex() const;
    virtual void setHostIndex(unsigned int hostIndex);
    virtual L3Address& getSourceAddr();
    virtual const L3Address& getSourceAddr() const {return const_cast<CONTACTINFO*>(this)->getSourceAddr();}
    virtual void setSourceAddr(const L3Address& sourceAddr);
};

inline void doPacking(cCommBuffer *b, CONTACTINFO& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, CONTACTINFO& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef _INET_CSBCONTROLPACKETS_M_H_
