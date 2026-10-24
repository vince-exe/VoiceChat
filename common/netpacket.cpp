#include "netpacket.hpp"

VoiceChat::NetPacket::NetPacket(Header header) {
    m_header = header;
}

VoiceChat::NetPacket::NetPacket(Header header, std::vector<uint8_t> body)
{
    m_header = header;
    m_body.assign(body.begin(), body.end());
}

VoiceChat::NetPacket::NetPacket(Header header, std::string string) {
    m_header = header;
    m_body.assign(string.begin(), string.end());
}

const std::vector<uint8_t> VoiceChat::NetPacket::serialize() const
{
    std::vector<uint8_t> serializeVec;

    serializeVec.push_back(static_cast<uint8_t>(m_header));
    serializeVec.insert(serializeVec.begin(), );

    return serializeVec;
}

const VoiceChat::NetPacket VoiceChat::NetPacket::deserialize(const std::vector<uint8_t> serialized)
{
    NetPacket::Header header = static_cast<NetPacket::Header>(serialized.front());

    std::vector<uint8_t> body(&serialized[1], &serialized[serialized.size() - 1]);

    return NetPacket(header, body);
}
