#pragma once

#include <iostream>
#include <boost/asio.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <string>
#include <boost/asio/co_spawn.hpp>
#include <boost/asio/detached.hpp>
#include <boost/asio/io_context.hpp>
#include <common.hpp>

using boost::asio::ip::tcp;
using boost::asio::awaitable;
using VoiceChat::NetPacket;

namespace VoiceChat {
    class Client {
        private:
            tcp::socket m_socket;

            std::string m_ip;
            boost::asio::ip::port_type m_port;
            
            awaitable<void> asyncConnect();

        public:
            Client(boost::asio::io_context& io_context, std::string ip, boost::asio::ip::port_type port);
            
            awaitable<void> run();
    };
}