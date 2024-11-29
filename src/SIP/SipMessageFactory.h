// Not_afraid
// 2024/11/29

#ifndef SIPSERVER_SIPMESSAGEFACTORY_H
#define SIPSERVER_SIPMESSAGEFACTORY_H

#include <optional>
#include <memory>
#include "SipSdpMessage.h"

class SipMessageFactory {
public:
    std::optional<std::shared_ptr<SipMessage>> createMessage(std::string message, sockaddr_in src);

private:
    static constexpr auto SDP_CONTENT_TYPE = "application/sdp";

    bool containSdp(const std::string &message) const;
};


#endif //SIPSERVER_SIPMESSAGEFACTORY_H
