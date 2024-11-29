// Not_afraid
// 2024/11/29

#ifndef SIPSERVER_SIPCLIENT_H
#define SIPSERVER_SIPCLIENT_H

#ifdef __linux__
#include <netinet/in.h>
#elif defined _WIN32 || defined _WIN64
#include <WinSock2.h>
#endif

#include <iostream>

class SipClient {
public:
    SipClient(std::string number, sockaddr_in address);

    bool operator==(SipClient other);

    std::string getNumber() const;
    sockaddr_in getAddress() const;

private:
    std::string _number;
    sockaddr_in _address;
};


#endif //SIPSERVER_SIPCLIENT_H
