// Not_afraid
// 2024/11/29

#ifndef SIPSERVER_SIPSERVER_H
#define SIPSERVER_SIPSERVER_H

#include "UdpServer.hpp"
#include "RequestsHandler.h"
#include "Session.h"
#include "SipMessageFactory.h"

class SipServer {
public:
    SipServer(std::string ip, int port=5060);

private:
    void onNewMessage(std::string data, sockaddr_in src);
    void onHandled(const sockaddr_in& dest, std::shared_ptr<SipMessage> message);

    UdpServer _socket;
    RequestsHandler _handler;
    SipMessageFactory _messagesFactory;
};


#endif //SIPSERVER_SIPSERVER_H
