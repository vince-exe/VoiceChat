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
        
        const std::vector<uint8_t> serialize() const;

        private:
            Header m_header;
            std::vector<uint8_t> m_body;
    };
}