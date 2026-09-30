#pragma once

#include <iostream>
#include <vector>
#include <cstdint>

namespace VoiceChat {
    class NetPacket {            
        public:
            enum class Header : uint8_t {
                JoinVc,
                CreateVC,
                Comunication
            };

        NetPacket(Header header);
        
        NetPacket(Header header, std::vector<uint8_t> body);
        
        NetPacket(Header header, std::string string);

        const std::vector<uint8_t> serialize() const;
        
        static const NetPacket deserialize(const std::vector<uint8_t> data);
        
        private:
            Header m_header;
            std::vector<uint8_t> m_body;
    };
}