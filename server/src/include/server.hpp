#pragma once

#include <iostream>
#include <cstdint>
#include <boost/asio.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/co_spawn.hpp>
#include <boost/asio/detached.hpp>
#include <boost/asio/io_context.hpp>

#include "configuration.hpp"

using boost::asio::ip::tcp;
using boost::asio::awaitable;

namespace App {
    class Server {
        private:
            boost::asio::ip::port_type m_port;
            std::uint_least16_t m_maxConnections;
            std::uint_least16_t m_activeConnections;

            awaitable<void> _handleVCOption(tcp::socket socket);

        public:
            Server();

            awaitable<void> listen();
    };
}