/*
 * CSBContactInfo.cpp
 *
 *  Created on: 22/07/2015
 *      Author: ricardopagoto
 */

#include "inet/networklayer/csbinfo/CSBContactInfo.h"

namespace inet {

CSBContactInfo::CSBContactInfo(const simtime_t& time,const simtime_t& lastContact) {
    this->contactDuration = time;
    this->contactNumber = 1;
    this->lastContactTime = lastContact;
}

CSBContactInfo::~CSBContactInfo() {
    // TODO Auto-generated destructor stub
}

const simtime_t& CSBContactInfo::getContactDuration(){
    return this->contactDuration;
}
double CSBContactInfo::getContactNumber(){
    return this->contactNumber;
}

void CSBContactInfo::setContactDuration(const simtime_t& time){
    this->contactDuration = time;
}
void CSBContactInfo::incrementContactNumber(){
    this->contactNumber++;
}

} /* namespace inet */

