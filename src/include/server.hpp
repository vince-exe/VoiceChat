#pragma once

#include <boost/asio.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/json/src.hpp>

using boost::asio::ip::tcp;

namespace VoiceChat {
    class Server {
        private:
            boost::asio::executor acceptorExecutor;
            tcp::acceptor tcpAcceptor;

        public:
            void startListening();
    };
}