// Not_afraid
// 2024/11/29

#ifndef SIPSERVER_SIPSDPMESSAGE_H
#define SIPSERVER_SIPSDPMESSAGE_H

#include "SipMessage.h"

class SipSdpMessage : public SipMessage {
public:
    SipSdpMessage(std::string message, sockaddr_in src);

    void setMedia(std::string value);
    void setRtpPort(int port);

    std::string getVersion() const;
    std::string getOriginator() const;
    std::string getSessionName() const;
    std::string getConnectionInformation() const;
    std::string getTime() const;
    std::string getMedia() const;
    int getRtpPort() const;

private:
    void parse() override;
    int extractRtpPort(std::string data) const;

    std::string _version;
    std::string _originator;
    std::string _sessionName;
    std::string _connectionInformation;
    std::string _time;
    std::string _media;
    int _rtpPort;
};


#endif //SIPSERVER_SIPSDPMESSAGE_H
