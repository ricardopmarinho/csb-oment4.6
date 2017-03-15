//
// Generated file, do not edit! Created by nedtool 4.6 from inet/routing/lar/LARControlPackets.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "LARControlPackets_m.h"

USING_NAMESPACE


// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}



namespace inet {

// Template rule for outputting std::vector<T> types
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("inet::LARControlPacketType");
    if (!e) enums.getInstance()->add(e = new cEnum("inet::LARControlPacketType"));
    e->insert(MoveInfo, "MoveInfo");
);

Register_Class(LARControlPacket);

LARControlPacket::LARControlPacket(const char *name, int kind) : ::inet::AODVControlPacket(name,kind)
{
}

LARControlPacket::LARControlPacket(const LARControlPacket& other) : ::inet::AODVControlPacket(other)
{
    copy(other);
}

LARControlPacket::~LARControlPacket()
{
}

LARControlPacket& LARControlPacket::operator=(const LARControlPacket& other)
{
    if (this==&other) return *this;
    ::inet::AODVControlPacket::operator=(other);
    copy(other);
    return *this;
}

void LARControlPacket::copy(const LARControlPacket& other)
{
}

void LARControlPacket::parsimPack(cCommBuffer *b)
{
    ::inet::AODVControlPacket::parsimPack(b);
}

void LARControlPacket::parsimUnpack(cCommBuffer *b)
{
    ::inet::AODVControlPacket::parsimUnpack(b);
}

class LARControlPacketDescriptor : public cClassDescriptor
{
  public:
    LARControlPacketDescriptor();
    virtual ~LARControlPacketDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(LARControlPacketDescriptor);

LARControlPacketDescriptor::LARControlPacketDescriptor() : cClassDescriptor("inet::LARControlPacket", "inet::AODVControlPacket")
{
}

LARControlPacketDescriptor::~LARControlPacketDescriptor()
{
}

bool LARControlPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<LARControlPacket *>(obj)!=NULL;
}

const char *LARControlPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int LARControlPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int LARControlPacketDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *LARControlPacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int LARControlPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *LARControlPacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *LARControlPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int LARControlPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    LARControlPacket *pp = (LARControlPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string LARControlPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    LARControlPacket *pp = (LARControlPacket *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool LARControlPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    LARControlPacket *pp = (LARControlPacket *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *LARControlPacketDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *LARControlPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    LARControlPacket *pp = (LARControlPacket *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(LARRREQ);

LARRREQ::LARRREQ(const char *name) : ::inet::LARControlPacket(name)
{
    this->packetType_var = RREQ;
    this->joinFlag_var = 0;
    this->repairFlag_var = 0;
    this->gratuitousRREPFlag_var = 0;
    this->destOnlyFlag_var = 0;
    this->unknownSeqNumFlag_var = 0;
    this->hopCount_var = 0;
    this->rreqId_var = 0;
    this->destSeqNum_var = 0;
    this->originatorSeqNum_var = 0;
    this->type_var = 0;
}

LARRREQ::LARRREQ(const LARRREQ& other) : ::inet::LARControlPacket(other)
{
    copy(other);
}

LARRREQ::~LARRREQ()
{
}

LARRREQ& LARRREQ::operator=(const LARRREQ& other)
{
    if (this==&other) return *this;
    ::inet::LARControlPacket::operator=(other);
    copy(other);
    return *this;
}

void LARRREQ::copy(const LARRREQ& other)
{
    this->packetType_var = other.packetType_var;
    this->joinFlag_var = other.joinFlag_var;
    this->repairFlag_var = other.repairFlag_var;
    this->gratuitousRREPFlag_var = other.gratuitousRREPFlag_var;
    this->destOnlyFlag_var = other.destOnlyFlag_var;
    this->unknownSeqNumFlag_var = other.unknownSeqNumFlag_var;
    this->hopCount_var = other.hopCount_var;
    this->rreqId_var = other.rreqId_var;
    this->destAddr_var = other.destAddr_var;
    this->destSeqNum_var = other.destSeqNum_var;
    this->originatorAddr_var = other.originatorAddr_var;
    this->originatorSeqNum_var = other.originatorSeqNum_var;
    this->senderCoord_var = other.senderCoord_var;
    this->ReceiverPossibleCoord_var = other.ReceiverPossibleCoord_var;
    this->type_var = other.type_var;
}

void LARRREQ::parsimPack(cCommBuffer *b)
{
    ::inet::LARControlPacket::parsimPack(b);
    doPacking(b,this->packetType_var);
    doPacking(b,this->joinFlag_var);
    doPacking(b,this->repairFlag_var);
    doPacking(b,this->gratuitousRREPFlag_var);
    doPacking(b,this->destOnlyFlag_var);
    doPacking(b,this->unknownSeqNumFlag_var);
    doPacking(b,this->hopCount_var);
    doPacking(b,this->rreqId_var);
    doPacking(b,this->destAddr_var);
    doPacking(b,this->destSeqNum_var);
    doPacking(b,this->originatorAddr_var);
    doPacking(b,this->originatorSeqNum_var);
    doPacking(b,this->senderCoord_var);
    doPacking(b,this->ReceiverPossibleCoord_var);
    doPacking(b,this->type_var);
}

void LARRREQ::parsimUnpack(cCommBuffer *b)
{
    ::inet::LARControlPacket::parsimUnpack(b);
    doUnpacking(b,this->packetType_var);
    doUnpacking(b,this->joinFlag_var);
    doUnpacking(b,this->repairFlag_var);
    doUnpacking(b,this->gratuitousRREPFlag_var);
    doUnpacking(b,this->destOnlyFlag_var);
    doUnpacking(b,this->unknownSeqNumFlag_var);
    doUnpacking(b,this->hopCount_var);
    doUnpacking(b,this->rreqId_var);
    doUnpacking(b,this->destAddr_var);
    doUnpacking(b,this->destSeqNum_var);
    doUnpacking(b,this->originatorAddr_var);
    doUnpacking(b,this->originatorSeqNum_var);
    doUnpacking(b,this->senderCoord_var);
    doUnpacking(b,this->ReceiverPossibleCoord_var);
    doUnpacking(b,this->type_var);
}

unsigned int LARRREQ::getPacketType() const
{
    return packetType_var;
}

void LARRREQ::setPacketType(unsigned int packetType)
{
    this->packetType_var = packetType;
}

bool LARRREQ::getJoinFlag() const
{
    return joinFlag_var;
}

void LARRREQ::setJoinFlag(bool joinFlag)
{
    this->joinFlag_var = joinFlag;
}

bool LARRREQ::getRepairFlag() const
{
    return repairFlag_var;
}

void LARRREQ::setRepairFlag(bool repairFlag)
{
    this->repairFlag_var = repairFlag;
}

bool LARRREQ::getGratuitousRREPFlag() const
{
    return gratuitousRREPFlag_var;
}

void LARRREQ::setGratuitousRREPFlag(bool gratuitousRREPFlag)
{
    this->gratuitousRREPFlag_var = gratuitousRREPFlag;
}

bool LARRREQ::getDestOnlyFlag() const
{
    return destOnlyFlag_var;
}

void LARRREQ::setDestOnlyFlag(bool destOnlyFlag)
{
    this->destOnlyFlag_var = destOnlyFlag;
}

bool LARRREQ::getUnknownSeqNumFlag() const
{
    return unknownSeqNumFlag_var;
}

void LARRREQ::setUnknownSeqNumFlag(bool unknownSeqNumFlag)
{
    this->unknownSeqNumFlag_var = unknownSeqNumFlag;
}

unsigned int LARRREQ::getHopCount() const
{
    return hopCount_var;
}

void LARRREQ::setHopCount(unsigned int hopCount)
{
    this->hopCount_var = hopCount;
}

unsigned int LARRREQ::getRreqId() const
{
    return rreqId_var;
}

void LARRREQ::setRreqId(unsigned int rreqId)
{
    this->rreqId_var = rreqId;
}

L3Address& LARRREQ::getDestAddr()
{
    return destAddr_var;
}

void LARRREQ::setDestAddr(const L3Address& destAddr)
{
    this->destAddr_var = destAddr;
}

unsigned int LARRREQ::getDestSeqNum() const
{
    return destSeqNum_var;
}

void LARRREQ::setDestSeqNum(unsigned int destSeqNum)
{
    this->destSeqNum_var = destSeqNum;
}

L3Address& LARRREQ::getOriginatorAddr()
{
    return originatorAddr_var;
}

void LARRREQ::setOriginatorAddr(const L3Address& originatorAddr)
{
    this->originatorAddr_var = originatorAddr;
}

unsigned int LARRREQ::getOriginatorSeqNum() const
{
    return originatorSeqNum_var;
}

void LARRREQ::setOriginatorSeqNum(unsigned int originatorSeqNum)
{
    this->originatorSeqNum_var = originatorSeqNum;
}

Coord& LARRREQ::getSenderCoord()
{
    return senderCoord_var;
}

void LARRREQ::setSenderCoord(const Coord& senderCoord)
{
    this->senderCoord_var = senderCoord;
}

Coord& LARRREQ::getReceiverPossibleCoord()
{
    return ReceiverPossibleCoord_var;
}

void LARRREQ::setReceiverPossibleCoord(const Coord& ReceiverPossibleCoord)
{
    this->ReceiverPossibleCoord_var = ReceiverPossibleCoord;
}

unsigned int LARRREQ::getType() const
{
    return type_var;
}

void LARRREQ::setType(unsigned int type)
{
    this->type_var = type;
}

class LARRREQDescriptor : public cClassDescriptor
{
  public:
    LARRREQDescriptor();
    virtual ~LARRREQDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(LARRREQDescriptor);

LARRREQDescriptor::LARRREQDescriptor() : cClassDescriptor("inet::LARRREQ", "inet::LARControlPacket")
{
}

LARRREQDescriptor::~LARRREQDescriptor()
{
}

bool LARRREQDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<LARRREQ *>(obj)!=NULL;
}

const char *LARRREQDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int LARRREQDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 15+basedesc->getFieldCount(object) : 15;
}

unsigned int LARRREQDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<15) ? fieldTypeFlags[field] : 0;
}

const char *LARRREQDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "packetType",
        "joinFlag",
        "repairFlag",
        "gratuitousRREPFlag",
        "destOnlyFlag",
        "unknownSeqNumFlag",
        "hopCount",
        "rreqId",
        "destAddr",
        "destSeqNum",
        "originatorAddr",
        "originatorSeqNum",
        "senderCoord",
        "ReceiverPossibleCoord",
        "type",
    };
    return (field>=0 && field<15) ? fieldNames[field] : NULL;
}

int LARRREQDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetType")==0) return base+0;
    if (fieldName[0]=='j' && strcmp(fieldName, "joinFlag")==0) return base+1;
    if (fieldName[0]=='r' && strcmp(fieldName, "repairFlag")==0) return base+2;
    if (fieldName[0]=='g' && strcmp(fieldName, "gratuitousRREPFlag")==0) return base+3;
    if (fieldName[0]=='d' && strcmp(fieldName, "destOnlyFlag")==0) return base+4;
    if (fieldName[0]=='u' && strcmp(fieldName, "unknownSeqNumFlag")==0) return base+5;
    if (fieldName[0]=='h' && strcmp(fieldName, "hopCount")==0) return base+6;
    if (fieldName[0]=='r' && strcmp(fieldName, "rreqId")==0) return base+7;
    if (fieldName[0]=='d' && strcmp(fieldName, "destAddr")==0) return base+8;
    if (fieldName[0]=='d' && strcmp(fieldName, "destSeqNum")==0) return base+9;
    if (fieldName[0]=='o' && strcmp(fieldName, "originatorAddr")==0) return base+10;
    if (fieldName[0]=='o' && strcmp(fieldName, "originatorSeqNum")==0) return base+11;
    if (fieldName[0]=='s' && strcmp(fieldName, "senderCoord")==0) return base+12;
    if (fieldName[0]=='R' && strcmp(fieldName, "ReceiverPossibleCoord")==0) return base+13;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+14;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *LARRREQDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
        "bool",
        "bool",
        "bool",
        "bool",
        "bool",
        "unsigned int",
        "unsigned int",
        "L3Address",
        "unsigned int",
        "L3Address",
        "unsigned int",
        "Coord",
        "Coord",
        "unsigned int",
    };
    return (field>=0 && field<15) ? fieldTypeStrings[field] : NULL;
}

const char *LARRREQDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int LARRREQDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    LARRREQ *pp = (LARRREQ *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string LARRREQDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    LARRREQ *pp = (LARRREQ *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPacketType());
        case 1: return bool2string(pp->getJoinFlag());
        case 2: return bool2string(pp->getRepairFlag());
        case 3: return bool2string(pp->getGratuitousRREPFlag());
        case 4: return bool2string(pp->getDestOnlyFlag());
        case 5: return bool2string(pp->getUnknownSeqNumFlag());
        case 6: return ulong2string(pp->getHopCount());
        case 7: return ulong2string(pp->getRreqId());
        case 8: {std::stringstream out; out << pp->getDestAddr(); return out.str();}
        case 9: return ulong2string(pp->getDestSeqNum());
        case 10: {std::stringstream out; out << pp->getOriginatorAddr(); return out.str();}
        case 11: return ulong2string(pp->getOriginatorSeqNum());
        case 12: {std::stringstream out; out << pp->getSenderCoord(); return out.str();}
        case 13: {std::stringstream out; out << pp->getReceiverPossibleCoord(); return out.str();}
        case 14: return ulong2string(pp->getType());
        default: return "";
    }
}

bool LARRREQDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    LARRREQ *pp = (LARRREQ *)object; (void)pp;
    switch (field) {
        case 0: pp->setPacketType(string2ulong(value)); return true;
        case 1: pp->setJoinFlag(string2bool(value)); return true;
        case 2: pp->setRepairFlag(string2bool(value)); return true;
        case 3: pp->setGratuitousRREPFlag(string2bool(value)); return true;
        case 4: pp->setDestOnlyFlag(string2bool(value)); return true;
        case 5: pp->setUnknownSeqNumFlag(string2bool(value)); return true;
        case 6: pp->setHopCount(string2ulong(value)); return true;
        case 7: pp->setRreqId(string2ulong(value)); return true;
        case 9: pp->setDestSeqNum(string2ulong(value)); return true;
        case 11: pp->setOriginatorSeqNum(string2ulong(value)); return true;
        case 14: pp->setType(string2ulong(value)); return true;
        default: return false;
    }
}

const char *LARRREQDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 8: return opp_typename(typeid(L3Address));
        case 10: return opp_typename(typeid(L3Address));
        case 12: return opp_typename(typeid(Coord));
        case 13: return opp_typename(typeid(Coord));
        default: return NULL;
    };
}

void *LARRREQDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    LARRREQ *pp = (LARRREQ *)object; (void)pp;
    switch (field) {
        case 8: return (void *)(&pp->getDestAddr()); break;
        case 10: return (void *)(&pp->getOriginatorAddr()); break;
        case 12: return (void *)(&pp->getSenderCoord()); break;
        case 13: return (void *)(&pp->getReceiverPossibleCoord()); break;
        default: return NULL;
    }
}

Register_Class(LARRREP);

LARRREP::LARRREP(const char *name) : ::inet::LARControlPacket(name)
{
    this->packetType_var = RREP;
    this->repairFlag_var = 0;
    this->ackRequiredFlag_var = 0;
    this->prefixSize_var = 0;
    this->hopCount_var = 0;
    this->destSeqNum_var = 0;
    this->originatorSeqNum_var = 0;
    this->lifeTime_var = 0;
}

LARRREP::LARRREP(const LARRREP& other) : ::inet::LARControlPacket(other)
{
    copy(other);
}

LARRREP::~LARRREP()
{
}

LARRREP& LARRREP::operator=(const LARRREP& other)
{
    if (this==&other) return *this;
    ::inet::LARControlPacket::operator=(other);
    copy(other);
    return *this;
}

void LARRREP::copy(const LARRREP& other)
{
    this->packetType_var = other.packetType_var;
    this->repairFlag_var = other.repairFlag_var;
    this->ackRequiredFlag_var = other.ackRequiredFlag_var;
    this->prefixSize_var = other.prefixSize_var;
    this->hopCount_var = other.hopCount_var;
    this->destAddr_var = other.destAddr_var;
    this->destSeqNum_var = other.destSeqNum_var;
    this->originatorAddr_var = other.originatorAddr_var;
    this->originatorSeqNum_var = other.originatorSeqNum_var;
    this->lifeTime_var = other.lifeTime_var;
}

void LARRREP::parsimPack(cCommBuffer *b)
{
    ::inet::LARControlPacket::parsimPack(b);
    doPacking(b,this->packetType_var);
    doPacking(b,this->repairFlag_var);
    doPacking(b,this->ackRequiredFlag_var);
    doPacking(b,this->prefixSize_var);
    doPacking(b,this->hopCount_var);
    doPacking(b,this->destAddr_var);
    doPacking(b,this->destSeqNum_var);
    doPacking(b,this->originatorAddr_var);
    doPacking(b,this->originatorSeqNum_var);
    doPacking(b,this->lifeTime_var);
}

void LARRREP::parsimUnpack(cCommBuffer *b)
{
    ::inet::LARControlPacket::parsimUnpack(b);
    doUnpacking(b,this->packetType_var);
    doUnpacking(b,this->repairFlag_var);
    doUnpacking(b,this->ackRequiredFlag_var);
    doUnpacking(b,this->prefixSize_var);
    doUnpacking(b,this->hopCount_var);
    doUnpacking(b,this->destAddr_var);
    doUnpacking(b,this->destSeqNum_var);
    doUnpacking(b,this->originatorAddr_var);
    doUnpacking(b,this->originatorSeqNum_var);
    doUnpacking(b,this->lifeTime_var);
}

unsigned int LARRREP::getPacketType() const
{
    return packetType_var;
}

void LARRREP::setPacketType(unsigned int packetType)
{
    this->packetType_var = packetType;
}

bool LARRREP::getRepairFlag() const
{
    return repairFlag_var;
}

void LARRREP::setRepairFlag(bool repairFlag)
{
    this->repairFlag_var = repairFlag;
}

bool LARRREP::getAckRequiredFlag() const
{
    return ackRequiredFlag_var;
}

void LARRREP::setAckRequiredFlag(bool ackRequiredFlag)
{
    this->ackRequiredFlag_var = ackRequiredFlag;
}

unsigned int LARRREP::getPrefixSize() const
{
    return prefixSize_var;
}

void LARRREP::setPrefixSize(unsigned int prefixSize)
{
    this->prefixSize_var = prefixSize;
}

unsigned int LARRREP::getHopCount() const
{
    return hopCount_var;
}

void LARRREP::setHopCount(unsigned int hopCount)
{
    this->hopCount_var = hopCount;
}

L3Address& LARRREP::getDestAddr()
{
    return destAddr_var;
}

void LARRREP::setDestAddr(const L3Address& destAddr)
{
    this->destAddr_var = destAddr;
}

unsigned int LARRREP::getDestSeqNum() const
{
    return destSeqNum_var;
}

void LARRREP::setDestSeqNum(unsigned int destSeqNum)
{
    this->destSeqNum_var = destSeqNum;
}

L3Address& LARRREP::getOriginatorAddr()
{
    return originatorAddr_var;
}

void LARRREP::setOriginatorAddr(const L3Address& originatorAddr)
{
    this->originatorAddr_var = originatorAddr;
}

unsigned int LARRREP::getOriginatorSeqNum() const
{
    return originatorSeqNum_var;
}

void LARRREP::setOriginatorSeqNum(unsigned int originatorSeqNum)
{
    this->originatorSeqNum_var = originatorSeqNum;
}

simtime_t LARRREP::getLifeTime() const
{
    return lifeTime_var;
}

void LARRREP::setLifeTime(simtime_t lifeTime)
{
    this->lifeTime_var = lifeTime;
}

class LARRREPDescriptor : public cClassDescriptor
{
  public:
    LARRREPDescriptor();
    virtual ~LARRREPDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(LARRREPDescriptor);

LARRREPDescriptor::LARRREPDescriptor() : cClassDescriptor("inet::LARRREP", "inet::LARControlPacket")
{
}

LARRREPDescriptor::~LARRREPDescriptor()
{
}

bool LARRREPDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<LARRREP *>(obj)!=NULL;
}

const char *LARRREPDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int LARRREPDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 10+basedesc->getFieldCount(object) : 10;
}

unsigned int LARRREPDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<10) ? fieldTypeFlags[field] : 0;
}

const char *LARRREPDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "packetType",
        "repairFlag",
        "ackRequiredFlag",
        "prefixSize",
        "hopCount",
        "destAddr",
        "destSeqNum",
        "originatorAddr",
        "originatorSeqNum",
        "lifeTime",
    };
    return (field>=0 && field<10) ? fieldNames[field] : NULL;
}

int LARRREPDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetType")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "repairFlag")==0) return base+1;
    if (fieldName[0]=='a' && strcmp(fieldName, "ackRequiredFlag")==0) return base+2;
    if (fieldName[0]=='p' && strcmp(fieldName, "prefixSize")==0) return base+3;
    if (fieldName[0]=='h' && strcmp(fieldName, "hopCount")==0) return base+4;
    if (fieldName[0]=='d' && strcmp(fieldName, "destAddr")==0) return base+5;
    if (fieldName[0]=='d' && strcmp(fieldName, "destSeqNum")==0) return base+6;
    if (fieldName[0]=='o' && strcmp(fieldName, "originatorAddr")==0) return base+7;
    if (fieldName[0]=='o' && strcmp(fieldName, "originatorSeqNum")==0) return base+8;
    if (fieldName[0]=='l' && strcmp(fieldName, "lifeTime")==0) return base+9;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *LARRREPDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
        "bool",
        "bool",
        "unsigned int",
        "unsigned int",
        "L3Address",
        "unsigned int",
        "L3Address",
        "unsigned int",
        "simtime_t",
    };
    return (field>=0 && field<10) ? fieldTypeStrings[field] : NULL;
}

const char *LARRREPDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int LARRREPDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    LARRREP *pp = (LARRREP *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string LARRREPDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    LARRREP *pp = (LARRREP *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPacketType());
        case 1: return bool2string(pp->getRepairFlag());
        case 2: return bool2string(pp->getAckRequiredFlag());
        case 3: return ulong2string(pp->getPrefixSize());
        case 4: return ulong2string(pp->getHopCount());
        case 5: {std::stringstream out; out << pp->getDestAddr(); return out.str();}
        case 6: return ulong2string(pp->getDestSeqNum());
        case 7: {std::stringstream out; out << pp->getOriginatorAddr(); return out.str();}
        case 8: return ulong2string(pp->getOriginatorSeqNum());
        case 9: return double2string(pp->getLifeTime());
        default: return "";
    }
}

bool LARRREPDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    LARRREP *pp = (LARRREP *)object; (void)pp;
    switch (field) {
        case 0: pp->setPacketType(string2ulong(value)); return true;
        case 1: pp->setRepairFlag(string2bool(value)); return true;
        case 2: pp->setAckRequiredFlag(string2bool(value)); return true;
        case 3: pp->setPrefixSize(string2ulong(value)); return true;
        case 4: pp->setHopCount(string2ulong(value)); return true;
        case 6: pp->setDestSeqNum(string2ulong(value)); return true;
        case 8: pp->setOriginatorSeqNum(string2ulong(value)); return true;
        case 9: pp->setLifeTime(string2double(value)); return true;
        default: return false;
    }
}

const char *LARRREPDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 5: return opp_typename(typeid(L3Address));
        case 7: return opp_typename(typeid(L3Address));
        default: return NULL;
    };
}

void *LARRREPDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    LARRREP *pp = (LARRREP *)object; (void)pp;
    switch (field) {
        case 5: return (void *)(&pp->getDestAddr()); break;
        case 7: return (void *)(&pp->getOriginatorAddr()); break;
        default: return NULL;
    }
}

Register_Class(LARRERR);

LARRERR::LARRERR(const char *name) : ::inet::LARControlPacket(name)
{
    this->packetType_var = RERR;
    unreachableNodes_arraysize = 0;
    this->unreachableNodes_var = 0;
    this->noDeleteFlag_var = 0;
    this->destCount_var = 0;
}

LARRERR::LARRERR(const LARRERR& other) : ::inet::LARControlPacket(other)
{
    unreachableNodes_arraysize = 0;
    this->unreachableNodes_var = 0;
    copy(other);
}

LARRERR::~LARRERR()
{
    delete [] unreachableNodes_var;
}

LARRERR& LARRERR::operator=(const LARRERR& other)
{
    if (this==&other) return *this;
    ::inet::LARControlPacket::operator=(other);
    copy(other);
    return *this;
}

void LARRERR::copy(const LARRERR& other)
{
    this->packetType_var = other.packetType_var;
    delete [] this->unreachableNodes_var;
    this->unreachableNodes_var = (other.unreachableNodes_arraysize==0) ? NULL : new UnreachableNode[other.unreachableNodes_arraysize];
    unreachableNodes_arraysize = other.unreachableNodes_arraysize;
    for (unsigned int i=0; i<unreachableNodes_arraysize; i++)
        this->unreachableNodes_var[i] = other.unreachableNodes_var[i];
    this->noDeleteFlag_var = other.noDeleteFlag_var;
    this->destCount_var = other.destCount_var;
}

void LARRERR::parsimPack(cCommBuffer *b)
{
    ::inet::LARControlPacket::parsimPack(b);
    doPacking(b,this->packetType_var);
    b->pack(unreachableNodes_arraysize);
    doPacking(b,this->unreachableNodes_var,unreachableNodes_arraysize);
    doPacking(b,this->noDeleteFlag_var);
    doPacking(b,this->destCount_var);
}

void LARRERR::parsimUnpack(cCommBuffer *b)
{
    ::inet::LARControlPacket::parsimUnpack(b);
    doUnpacking(b,this->packetType_var);
    delete [] this->unreachableNodes_var;
    b->unpack(unreachableNodes_arraysize);
    if (unreachableNodes_arraysize==0) {
        this->unreachableNodes_var = 0;
    } else {
        this->unreachableNodes_var = new UnreachableNode[unreachableNodes_arraysize];
        doUnpacking(b,this->unreachableNodes_var,unreachableNodes_arraysize);
    }
    doUnpacking(b,this->noDeleteFlag_var);
    doUnpacking(b,this->destCount_var);
}

unsigned int LARRERR::getPacketType() const
{
    return packetType_var;
}

void LARRERR::setPacketType(unsigned int packetType)
{
    this->packetType_var = packetType;
}

void LARRERR::setUnreachableNodesArraySize(unsigned int size)
{
    UnreachableNode *unreachableNodes_var2 = (size==0) ? NULL : new UnreachableNode[size];
    unsigned int sz = unreachableNodes_arraysize < size ? unreachableNodes_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        unreachableNodes_var2[i] = this->unreachableNodes_var[i];
    unreachableNodes_arraysize = size;
    delete [] this->unreachableNodes_var;
    this->unreachableNodes_var = unreachableNodes_var2;
}

unsigned int LARRERR::getUnreachableNodesArraySize() const
{
    return unreachableNodes_arraysize;
}

UnreachableNode& LARRERR::getUnreachableNodes(unsigned int k)
{
    if (k>=unreachableNodes_arraysize) throw cRuntimeError("Array of size %d indexed by %d", unreachableNodes_arraysize, k);
    return unreachableNodes_var[k];
}

void LARRERR::setUnreachableNodes(unsigned int k, const UnreachableNode& unreachableNodes)
{
    if (k>=unreachableNodes_arraysize) throw cRuntimeError("Array of size %d indexed by %d", unreachableNodes_arraysize, k);
    this->unreachableNodes_var[k] = unreachableNodes;
}

bool LARRERR::getNoDeleteFlag() const
{
    return noDeleteFlag_var;
}

void LARRERR::setNoDeleteFlag(bool noDeleteFlag)
{
    this->noDeleteFlag_var = noDeleteFlag;
}

unsigned int LARRERR::getDestCount() const
{
    return destCount_var;
}

void LARRERR::setDestCount(unsigned int destCount)
{
    this->destCount_var = destCount;
}

class LARRERRDescriptor : public cClassDescriptor
{
  public:
    LARRERRDescriptor();
    virtual ~LARRERRDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(LARRERRDescriptor);

LARRERRDescriptor::LARRERRDescriptor() : cClassDescriptor("inet::LARRERR", "inet::LARControlPacket")
{
}

LARRERRDescriptor::~LARRERRDescriptor()
{
}

bool LARRERRDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<LARRERR *>(obj)!=NULL;
}

const char *LARRERRDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int LARRERRDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int LARRERRDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *LARRERRDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "packetType",
        "unreachableNodes",
        "noDeleteFlag",
        "destCount",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int LARRERRDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetType")==0) return base+0;
    if (fieldName[0]=='u' && strcmp(fieldName, "unreachableNodes")==0) return base+1;
    if (fieldName[0]=='n' && strcmp(fieldName, "noDeleteFlag")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "destCount")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *LARRERRDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
        "UnreachableNode",
        "bool",
        "unsigned int",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *LARRERRDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int LARRERRDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    LARRERR *pp = (LARRERR *)object; (void)pp;
    switch (field) {
        case 1: return pp->getUnreachableNodesArraySize();
        default: return 0;
    }
}

std::string LARRERRDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    LARRERR *pp = (LARRERR *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPacketType());
        case 1: {std::stringstream out; out << pp->getUnreachableNodes(i); return out.str();}
        case 2: return bool2string(pp->getNoDeleteFlag());
        case 3: return ulong2string(pp->getDestCount());
        default: return "";
    }
}

bool LARRERRDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    LARRERR *pp = (LARRERR *)object; (void)pp;
    switch (field) {
        case 0: pp->setPacketType(string2ulong(value)); return true;
        case 2: pp->setNoDeleteFlag(string2bool(value)); return true;
        case 3: pp->setDestCount(string2ulong(value)); return true;
        default: return false;
    }
}

const char *LARRERRDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 1: return opp_typename(typeid(UnreachableNode));
        default: return NULL;
    };
}

void *LARRERRDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    LARRERR *pp = (LARRERR *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getUnreachableNodes(i)); break;
        default: return NULL;
    }
}

Register_Class(LARRREPACK);

LARRREPACK::LARRREPACK(const char *name) : ::inet::LARControlPacket(name)
{
    this->packetType_var = RREPACK;
}

LARRREPACK::LARRREPACK(const LARRREPACK& other) : ::inet::LARControlPacket(other)
{
    copy(other);
}

LARRREPACK::~LARRREPACK()
{
}

LARRREPACK& LARRREPACK::operator=(const LARRREPACK& other)
{
    if (this==&other) return *this;
    ::inet::LARControlPacket::operator=(other);
    copy(other);
    return *this;
}

void LARRREPACK::copy(const LARRREPACK& other)
{
    this->packetType_var = other.packetType_var;
}

void LARRREPACK::parsimPack(cCommBuffer *b)
{
    ::inet::LARControlPacket::parsimPack(b);
    doPacking(b,this->packetType_var);
}

void LARRREPACK::parsimUnpack(cCommBuffer *b)
{
    ::inet::LARControlPacket::parsimUnpack(b);
    doUnpacking(b,this->packetType_var);
}

unsigned int LARRREPACK::getPacketType() const
{
    return packetType_var;
}

void LARRREPACK::setPacketType(unsigned int packetType)
{
    this->packetType_var = packetType;
}

class LARRREPACKDescriptor : public cClassDescriptor
{
  public:
    LARRREPACKDescriptor();
    virtual ~LARRREPACKDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(LARRREPACKDescriptor);

LARRREPACKDescriptor::LARRREPACKDescriptor() : cClassDescriptor("inet::LARRREPACK", "inet::LARControlPacket")
{
}

LARRREPACKDescriptor::~LARRREPACKDescriptor()
{
}

bool LARRREPACKDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<LARRREPACK *>(obj)!=NULL;
}

const char *LARRREPACKDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int LARRREPACKDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int LARRREPACKDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *LARRREPACKDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "packetType",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int LARRREPACKDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetType")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *LARRREPACKDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *LARRREPACKDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int LARRREPACKDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    LARRREPACK *pp = (LARRREPACK *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string LARRREPACKDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    LARRREPACK *pp = (LARRREPACK *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPacketType());
        default: return "";
    }
}

bool LARRREPACKDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    LARRREPACK *pp = (LARRREPACK *)object; (void)pp;
    switch (field) {
        case 0: pp->setPacketType(string2ulong(value)); return true;
        default: return false;
    }
}

const char *LARRREPACKDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *LARRREPACKDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    LARRREPACK *pp = (LARRREPACK *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(MOVEINFO);

MOVEINFO::MOVEINFO(const char *name) : ::inet::LARControlPacket(name)
{
    this->packetType_var = MoveInfo;
    this->hostIndex_var = 0;
    this->x_var = 0;
    this->y_var = 0;
    this->speed_var = 0;
}

MOVEINFO::MOVEINFO(const MOVEINFO& other) : ::inet::LARControlPacket(other)
{
    copy(other);
}

MOVEINFO::~MOVEINFO()
{
}

MOVEINFO& MOVEINFO::operator=(const MOVEINFO& other)
{
    if (this==&other) return *this;
    ::inet::LARControlPacket::operator=(other);
    copy(other);
    return *this;
}

void MOVEINFO::copy(const MOVEINFO& other)
{
    this->packetType_var = other.packetType_var;
    this->hostIndex_var = other.hostIndex_var;
    this->x_var = other.x_var;
    this->y_var = other.y_var;
    this->speed_var = other.speed_var;
}

void MOVEINFO::parsimPack(cCommBuffer *b)
{
    ::inet::LARControlPacket::parsimPack(b);
    doPacking(b,this->packetType_var);
    doPacking(b,this->hostIndex_var);
    doPacking(b,this->x_var);
    doPacking(b,this->y_var);
    doPacking(b,this->speed_var);
}

void MOVEINFO::parsimUnpack(cCommBuffer *b)
{
    ::inet::LARControlPacket::parsimUnpack(b);
    doUnpacking(b,this->packetType_var);
    doUnpacking(b,this->hostIndex_var);
    doUnpacking(b,this->x_var);
    doUnpacking(b,this->y_var);
    doUnpacking(b,this->speed_var);
}

unsigned int MOVEINFO::getPacketType() const
{
    return packetType_var;
}

void MOVEINFO::setPacketType(unsigned int packetType)
{
    this->packetType_var = packetType;
}

unsigned int MOVEINFO::getHostIndex() const
{
    return hostIndex_var;
}

void MOVEINFO::setHostIndex(unsigned int hostIndex)
{
    this->hostIndex_var = hostIndex;
}

double MOVEINFO::getX() const
{
    return x_var;
}

void MOVEINFO::setX(double x)
{
    this->x_var = x;
}

double MOVEINFO::getY() const
{
    return y_var;
}

void MOVEINFO::setY(double y)
{
    this->y_var = y;
}

long MOVEINFO::getSpeed() const
{
    return speed_var;
}

void MOVEINFO::setSpeed(long speed)
{
    this->speed_var = speed;
}

class MOVEINFODescriptor : public cClassDescriptor
{
  public:
    MOVEINFODescriptor();
    virtual ~MOVEINFODescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(MOVEINFODescriptor);

MOVEINFODescriptor::MOVEINFODescriptor() : cClassDescriptor("inet::MOVEINFO", "inet::LARControlPacket")
{
}

MOVEINFODescriptor::~MOVEINFODescriptor()
{
}

bool MOVEINFODescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MOVEINFO *>(obj)!=NULL;
}

const char *MOVEINFODescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MOVEINFODescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int MOVEINFODescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *MOVEINFODescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "packetType",
        "hostIndex",
        "x",
        "y",
        "speed",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int MOVEINFODescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetType")==0) return base+0;
    if (fieldName[0]=='h' && strcmp(fieldName, "hostIndex")==0) return base+1;
    if (fieldName[0]=='x' && strcmp(fieldName, "x")==0) return base+2;
    if (fieldName[0]=='y' && strcmp(fieldName, "y")==0) return base+3;
    if (fieldName[0]=='s' && strcmp(fieldName, "speed")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *MOVEINFODescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
        "unsigned int",
        "double",
        "double",
        "long",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *MOVEINFODescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int MOVEINFODescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MOVEINFO *pp = (MOVEINFO *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string MOVEINFODescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    MOVEINFO *pp = (MOVEINFO *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPacketType());
        case 1: return ulong2string(pp->getHostIndex());
        case 2: return double2string(pp->getX());
        case 3: return double2string(pp->getY());
        case 4: return long2string(pp->getSpeed());
        default: return "";
    }
}

bool MOVEINFODescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MOVEINFO *pp = (MOVEINFO *)object; (void)pp;
    switch (field) {
        case 0: pp->setPacketType(string2ulong(value)); return true;
        case 1: pp->setHostIndex(string2ulong(value)); return true;
        case 2: pp->setX(string2double(value)); return true;
        case 3: pp->setY(string2double(value)); return true;
        case 4: pp->setSpeed(string2long(value)); return true;
        default: return false;
    }
}

const char *MOVEINFODescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *MOVEINFODescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MOVEINFO *pp = (MOVEINFO *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

} // namespace inet

