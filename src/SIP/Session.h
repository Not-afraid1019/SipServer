// Not_afraid
// 2024/11/29

#ifndef SIPSERVER_SESSION_H
#define SIPSERVER_SESSION_H

#include <memory>

#include "SipClient.h"

class Session {
public:
    enum class State {
        Invited,
        Busy,
        Unavailable,
        Cancel,
        Bye,
        Connected,
    };

    Session(std::string callID, std::shared_ptr<SipClient> src, uint32_t srcRtpPort);

    void setState(State state);
    void setDest(std::shared_ptr<SipClient> dest, uint32_t destRtpPort);

    std::string getCallID() const;
    std::shared_ptr<SipClient> getSrc() const;
    std::shared_ptr<SipClient> getDest() const;
    State getState() const;

private:
    std::string _callID;
    std::shared_ptr<SipClient> _src;
    std::shared_ptr<SipClient> _dest;
    State _state;

    uint32_t _srcRtpPort;
    uint32_t _destRtpPort;
};


#endif //SIPSERVER_SESSION_H
