#pragma once

#include <boost/asio.hpp>
#include <boost/asio/ip/tcp.hpp>



using boost::asio::ip::tcp;

namespace VoiceChat {
    class Client {
        private:
            boost::asio::io_context m_ioContext;
            tcp::socket m_socket {m_ioContext};

        public:
            Client();
    }
}