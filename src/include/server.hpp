#pragma once

#include <iostream>
#include <boost/asio.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/json/src.hpp>
#include <boost/asio/co_spawn.hpp>
#include <boost/asio/detached.hpp>
#include <boost/asio/io_context.hpp>

#include "configuration.hpp"

using boost::asio::ip::tcp;
using boost::asio::awaitable;

namespace App {
    class Server {
        private:
            std::uint64_t m_port;
            std::uint64_t m_activeConnections;
            std::uint64_t m_maxConnections;

        public:
            Server();

            awaitable<void> listen();

            awaitable<void> write(tcp::socket socket);
    };
}