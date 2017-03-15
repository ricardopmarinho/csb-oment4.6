//
// Generated file, do not edit! Created by nedtool 4.6 from inet/routing/lar/LARControlPackets.msg.
//

#ifndef _INET_LARCONTROLPACKETS_M_H_
#define _INET_LARCONTROLPACKETS_M_H_

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
#include "inet/common/geometry/common/Coord.h"
// }}


namespace inet {

/**
 * Enum generated from <tt>inet/routing/lar/LARControlPackets.msg:44</tt> by nedtool.
 * <pre>
 * enum LARControlPacketType
 * {
 * 
 *     //	RREQ = 1;
 *     //	RREP = 2;
 *     //	RERR = 3;
 *     //	RREPACK = 4;
 *     MoveInfo = 5;
 * }
 * </pre>
 */
enum LARControlPacketType {
    MoveInfo = 5
};

/**
 * Class generated from <tt>inet/routing/lar/LARControlPackets.msg:56</tt> by nedtool.
 * <pre>
 * //
 * // Base packet for LAR Control Packets
 * //
 * packet LARControlPacket extends AODVControlPacket
 * {
 * }
 * </pre>
 */
class INET_API LARControlPacket : public ::inet::AODVControlPacket
{
  protected:

  private:
    void copy(const LARControlPacket& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const LARControlPacket&);

  public:
    LARControlPacket(const char *name=NULL, int kind=0);
    LARControlPacket(const LARControlPacket& other);
    virtual ~LARControlPacket();
    LARControlPacket& operator=(const LARControlPacket& other);
    virtual LARControlPacket *dup() const {return new LARControlPacket(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
};

inline void doPacking(cCommBuffer *b, LARControlPacket& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, LARControlPacket& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/routing/lar/LARControlPackets.msg:63</tt> by nedtool.
 * <pre>
 * //
 * // Represents an LAR Route Request
 * //
 * class LARRREQ extends LARControlPacket
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
 *     Coord senderCoord;
 *     Coord ReceiverPossibleCoord;
 *     unsigned int type;
 * }
 * </pre>
 */
class INET_API LARRREQ : public ::inet::LARControlPacket
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
    Coord senderCoord_var;
    Coord ReceiverPossibleCoord_var;
    unsigned int type_var;

  private:
    void copy(const LARRREQ& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const LARRREQ&);

  public:
    LARRREQ(const char *name=NULL);
    LARRREQ(const LARRREQ& other);
    virtual ~LARRREQ();
    LARRREQ& operator=(const LARRREQ& other);
    virtual LARRREQ *dup() const {return new LARRREQ(*this);}
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
    virtual const L3Address& getDestAddr() const {return const_cast<LARRREQ*>(this)->getDestAddr();}
    virtual void setDestAddr(const L3Address& destAddr);
    virtual unsigned int getDestSeqNum() const;
    virtual void setDestSeqNum(unsigned int destSeqNum);
    virtual L3Address& getOriginatorAddr();
    virtual const L3Address& getOriginatorAddr() const {return const_cast<LARRREQ*>(this)->getOriginatorAddr();}
    virtual void setOriginatorAddr(const L3Address& originatorAddr);
    virtual unsigned int getOriginatorSeqNum() const;
    virtual void setOriginatorSeqNum(unsigned int originatorSeqNum);
    virtual Coord& getSenderCoord();
    virtual const Coord& getSenderCoord() const {return const_cast<LARRREQ*>(this)->getSenderCoord();}
    virtual void setSenderCoord(const Coord& senderCoord);
    virtual Coord& getReceiverPossibleCoord();
    virtual const Coord& getReceiverPossibleCoord() const {return const_cast<LARRREQ*>(this)->getReceiverPossibleCoord();}
    virtual void setReceiverPossibleCoord(const Coord& ReceiverPossibleCoord);
    virtual unsigned int getType() const;
    virtual void setType(unsigned int type);
};

inline void doPacking(cCommBuffer *b, LARRREQ& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, LARRREQ& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/routing/lar/LARControlPackets.msg:85</tt> by nedtool.
 * <pre>
 * //
 * // Represents an LAR Route Reply
 * //
 * class LARRREP extends LARControlPacket
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
class INET_API LARRREP : public ::inet::LARControlPacket
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
    void copy(const LARRREP& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const LARRREP&);

  public:
    LARRREP(const char *name=NULL);
    LARRREP(const LARRREP& other);
    virtual ~LARRREP();
    LARRREP& operator=(const LARRREP& other);
    virtual LARRREP *dup() const {return new LARRREP(*this);}
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
    virtual const L3Address& getDestAddr() const {return const_cast<LARRREP*>(this)->getDestAddr();}
    virtual void setDestAddr(const L3Address& destAddr);
    virtual unsigned int getDestSeqNum() const;
    virtual void setDestSeqNum(unsigned int destSeqNum);
    virtual L3Address& getOriginatorAddr();
    virtual const L3Address& getOriginatorAddr() const {return const_cast<LARRREP*>(this)->getOriginatorAddr();}
    virtual void setOriginatorAddr(const L3Address& originatorAddr);
    virtual unsigned int getOriginatorSeqNum() const;
    virtual void setOriginatorSeqNum(unsigned int originatorSeqNum);
    virtual simtime_t getLifeTime() const;
    virtual void setLifeTime(simtime_t lifeTime);
};

inline void doPacking(cCommBuffer *b, LARRREP& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, LARRREP& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/routing/lar/LARControlPackets.msg:102</tt> by nedtool.
 * <pre>
 * //
 * // Represents an LAR Route Error
 * //
 * class LARRERR extends LARControlPacket
 * {
 *     unsigned int packetType = RERR;
 *     UnreachableNode unreachableNodes[];
 *     bool noDeleteFlag;
 *     unsigned int destCount;
 * }
 * </pre>
 */
class INET_API LARRERR : public ::inet::LARControlPacket
{
  protected:
    unsigned int packetType_var;
    UnreachableNode *unreachableNodes_var; // array ptr
    unsigned int unreachableNodes_arraysize;
    bool noDeleteFlag_var;
    unsigned int destCount_var;

  private:
    void copy(const LARRERR& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const LARRERR&);

  public:
    LARRERR(const char *name=NULL);
    LARRERR(const LARRERR& other);
    virtual ~LARRERR();
    LARRERR& operator=(const LARRERR& other);
    virtual LARRERR *dup() const {return new LARRERR(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual unsigned int getPacketType() const;
    virtual void setPacketType(unsigned int packetType);
    virtual void setUnreachableNodesArraySize(unsigned int size);
    virtual unsigned int getUnreachableNodesArraySize() const;
    virtual UnreachableNode& getUnreachableNodes(unsigned int k);
    virtual const UnreachableNode& getUnreachableNodes(unsigned int k) const {return const_cast<LARRERR*>(this)->getUnreachableNodes(k);}
    virtual void setUnreachableNodes(unsigned int k, const UnreachableNode& unreachableNodes);
    virtual bool getNoDeleteFlag() const;
    virtual void setNoDeleteFlag(bool noDeleteFlag);
    virtual unsigned int getDestCount() const;
    virtual void setDestCount(unsigned int destCount);
};

inline void doPacking(cCommBuffer *b, LARRERR& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, LARRERR& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/routing/lar/LARControlPackets.msg:113</tt> by nedtool.
 * <pre>
 * //
 * // Represents an LAR Route Reply ACK
 * //
 * class LARRREPACK extends LARControlPacket
 * {
 *     unsigned int packetType = RREPACK;
 * }
 * </pre>
 */
class INET_API LARRREPACK : public ::inet::LARControlPacket
{
  protected:
    unsigned int packetType_var;

  private:
    void copy(const LARRREPACK& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const LARRREPACK&);

  public:
    LARRREPACK(const char *name=NULL);
    LARRREPACK(const LARRREPACK& other);
    virtual ~LARRREPACK();
    LARRREPACK& operator=(const LARRREPACK& other);
    virtual LARRREPACK *dup() const {return new LARRREPACK(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual unsigned int getPacketType() const;
    virtual void setPacketType(unsigned int packetType);
};

inline void doPacking(cCommBuffer *b, LARRREPACK& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, LARRREPACK& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/routing/lar/LARControlPackets.msg:118</tt> by nedtool.
 * <pre>
 * class MOVEINFO extends LARControlPacket
 * {
 *     unsigned int packetType = MoveInfo;
 *     unsigned int hostIndex;
 *     double x;
 *     double y;
 *     long speed;
 * }
 * </pre>
 */
class INET_API MOVEINFO : public ::inet::LARControlPacket
{
  protected:
    unsigned int packetType_var;
    unsigned int hostIndex_var;
    double x_var;
    double y_var;
    long speed_var;

  private:
    void copy(const MOVEINFO& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const MOVEINFO&);

  public:
    MOVEINFO(const char *name=NULL);
    MOVEINFO(const MOVEINFO& other);
    virtual ~MOVEINFO();
    MOVEINFO& operator=(const MOVEINFO& other);
    virtual MOVEINFO *dup() const {return new MOVEINFO(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual unsigned int getPacketType() const;
    virtual void setPacketType(unsigned int packetType);
    virtual unsigned int getHostIndex() const;
    virtual void setHostIndex(unsigned int hostIndex);
    virtual double getX() const;
    virtual void setX(double x);
    virtual double getY() const;
    virtual void setY(double y);
    virtual long getSpeed() const;
    virtual void setSpeed(long speed);
};

inline void doPacking(cCommBuffer *b, MOVEINFO& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, MOVEINFO& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef _INET_LARCONTROLPACKETS_M_H_

