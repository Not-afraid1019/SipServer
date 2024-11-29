// Not_afraid
// 2024/11/29

#ifndef SIPSERVER_REQUESTSHANDLER_H
#define SIPSERVER_REQUESTSHANDLER_H

#include <functional>
#include <unordered_map>
#include <optional>
#include "SipMessage.h"
#include "SipClient.h"
#include "Session.h"

class RequestsHandler {
public:
    using OnHandledEvent = std::function<void(const sockaddr_in&, std::shared_ptr<SipMessage>)>;

    RequestsHandler(std::string serverIp, int serverPort, OnHandledEvent onHandledEvent);

    void handle(std::shared_ptr<SipMessage> request);

    std::optional<std::shared_ptr<Session>> getSession(const std::string& callID);

private:
    void initHandles();

    void OnRegister(std::shared_ptr<SipMessage> data);
    void OnCancel(std::shared_ptr<SipMessage> data);
    void OnReqTerminated(std::shared_ptr<SipMessage> data);
    void OnInvite(std::shared_ptr<SipMessage> data);
    void OnTrying(std::shared_ptr<SipMessage> data);
    void OnRinging(std::shared_ptr<SipMessage> data);
    void OnBusy(std::shared_ptr<SipMessage> data);
    void OnUnavailable(std::shared_ptr<SipMessage> data);
    void OnBye(std::shared_ptr<SipMessage> data);
    void OnOk(std::shared_ptr<SipMessage> data);
    void OnAck(std::shared_ptr<SipMessage> data);

    bool setCallState(const std::string& callID, Session::State state);
    void endCall(const std::string& callID, const std::string& srcNumber, const std::string& destNumber, const std::string& reason="");

    bool registerClient(std::shared_ptr<SipClient> client);
    void unregisterClient(std::shared_ptr<SipClient> client);

    std::optional<std::shared_ptr<SipClient>> findClient(const std::string& number);

    void endHandle(const std::string& destNumber, std::shared_ptr<SipMessage> message);

    std::unordered_map<std::string, std::function<void(std::shared_ptr<SipMessage> request)>> _handlers;
    std::unordered_map<std::string, std::shared_ptr<Session>> _sessions;
    std::unordered_map<std::string, std::shared_ptr<SipClient>> _clients;

    std::function<void(std::shared_ptr<SipClient>)> _onNewClient;
    std::function<void(std::shared_ptr<SipClient>)> _onUnregister;
    OnHandledEvent _onHandled;

    std::string _serverIp;
    int _serverPort;
};


#endif //SIPSERVER_REQUESTSHANDLER_H
