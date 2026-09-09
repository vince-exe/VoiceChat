#include "netpacket.hpp"

VoiceChat::NetPacket::NetPacket(Header header) {
    m_header = header;
}

VoiceChat::NetPacket::NetPacket(Header header, std::vector<uint8_t> body)
{
    m_header = header;
    m_body.assign(body.begin(), body.end());
}

const std::vector<uint8_t> VoiceChat::NetPacket::serialize() const
{
    std::vector<uint8_t> serializeVec;

    serializeVec.push_back(static_cast<uint8_t>(m_header));

    return serializeVec;
}