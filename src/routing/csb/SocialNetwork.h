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

#ifndef SOCIALNETWORK_H_
#define SOCIALNETWORK_H_

#include "inet/networklayer/ipv4/IPv4Route.h"
#include <vector>

namespace inet {

class SocialNetwork {
protected:

    /*class parameters*/
    unsigned int friendsNumber;
    std::vector<char*> fNames;
    std::vector<int> friends;
    char name[20];
    int sNetworkID;
    enum socialNetworksID{
        FACEBOOK = 0,
        WHATSAPP = 1,
        TWITTER = 2,
        LINKEDIN = 3,
    };

public:
    /*class methods*/
    double networkWeight(const L3Address& nextHop);
    void initializeFriends();
    void createFriends();
    SocialNetwork(int socialNetworkId, unsigned int friendsNumber);
    virtual ~SocialNetwork();
    char* getSNName();
    double checkFriend(int hostIndex);
    int getSocialNetworkID();
};

} /* namespace inet */

#endif /* SOCIALNETWORK_H_ */
