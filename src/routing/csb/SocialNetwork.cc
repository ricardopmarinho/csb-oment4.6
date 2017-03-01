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

#include "SocialNetwork.h"
#include <string.h>

namespace inet {

double SocialNetwork::networkWeight(const L3Address& nextHop){
    std::string str = nextHop.str();
    std::string addrStr = str.substr(10,1);
    int hostIndex = stoi(addrStr);

    double weight;

    weight = checkFriend(hostIndex-1);
    switch(this->sNetworkID){
    case 0:
        weight *= 0.25;
        break;
    case 1:
        weight *=0.75;
    }

    return weight;
}

void SocialNetwork::initializeFriends(){

    for(int i = 0 ; i < friendsNumber;i++)
        friends.push_back(0);
}

void SocialNetwork::createFriends(){
    int i,index;

    for(i = 0; i < friendsNumber; i++){
        index = intuniform(0,friendsNumber-1);

        /*in case that a same friend number appear more than one time*/
        while(friends[index] == 1)
            index = intuniform(0,friendsNumber-1);
        friends[index] = 1;

        char friendName[20];
        sprintf(friendName,"host[%d]",index);
        fNames.push_back(friendName);
    }
}

char* SocialNetwork::getSNName(){
    return this->name;
}

double SocialNetwork::checkFriend(int hostIndex){
    int i;
    char hostName[20];
    sprintf(hostName,"host[%d]",hostIndex);
    for(i=0;i<friendsNumber;i++){
        if(!strcmp(hostName,fNames[i])){
            return 1;
        }
    }
    return 0;
}

int SocialNetwork::getSocialNetworkID(){
    return sNetworkID;
}

SocialNetwork::SocialNetwork(int socialNetworkId, unsigned int friendsNumber) {
    this->sNetworkID = socialNetworkId;
    this->friendsNumber = friendsNumber;
    switch(socialNetworkId){
    case 0:
        sprintf(name,"Facebook");
        break;
    case 1:
        sprintf(name,"WhatAapp");
        break;
    case 2:
        sprintf(name,"Twitter");
        break;
    case 3:
        sprintf(name,"Linkedin");
        break;
    default:
        sprintf(name,"Unspecified");
        break;
    }
    initializeFriends();
    createFriends();
}

SocialNetwork::~SocialNetwork() {
    int i;
    for(i=0;i<friendsNumber;i++){
        delete(fNames[i]);
    }

}

} /* namespace inet */
