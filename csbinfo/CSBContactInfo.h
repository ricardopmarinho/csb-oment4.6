/*
 * CSB NodeInfo.h
 *
 *  Created on: 22/07/2015
 *      Author: ricardopagoto
 */

#ifndef CSBCONTACTINFO_H_
#define CSBCONTACTINFO_H_

#include  <omnetpp.h>

namespace inet {

class CSBContactInfo {
private:
    simtime_t contactDuration;
    simtime_t lastContactTime;
    unsigned int contactNumber;
public:
    CSBContactInfo(const simtime_t& time,const simtime_t& lastContact);
    virtual ~CSBContactInfo();
    const simtime_t& getContactDuration();
    double getContactNumber();CSBContactInfo();
    void setContactDuration(const simtime_t& time);
    void incrementContactNumber();

    const simtime_t& getLastContactTime() const {
        return lastContactTime;
    }

    void setLastContactTime(const simtime_t& lastContactTime) {
        this->lastContactTime = lastContactTime;
    }
};

} /* namespace inet */

#endif /* CSB NODEINFO_H_ */
