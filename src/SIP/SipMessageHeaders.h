// Not_afraid
// 2024/11/29

#ifndef SIPSERVER_SIPMESSAGEHEADERS_H
#define SIPSERVER_SIPMESSAGEHEADERS_H

class SipMessageHeaders {
public:
    SipMessageHeaders() = delete;

    static constexpr auto VIA = "Via";
    static constexpr auto FROM = "From";
    static constexpr auto TO = "To";
    static constexpr auto CALL_ID = "Call-ID";
    static constexpr auto CSEQ = "CSeq";
    static constexpr auto CONTACT = "Contact";
    static constexpr auto CONTENT_LENGTH = "Content-Length";

    static constexpr auto HEADERS_DELIMETER = "\r\n";

};

#endif //SIPSERVER_SIPMESSAGEHEADERS_H
