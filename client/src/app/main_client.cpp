#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/asio/co_spawn.hpp>
#include <boost/asio/detached.hpp>
#include <boost/asio/io_context.hpp>

#include "client.hpp"

int main() {
    std::string ip; boost::asio::ip::port_type port;

    std::cout << "Inserisci l'ip: ";
    std::cin >> ip;

    std::cout << "Inserisci la porta: ";
    std::cin >> port;

    std::cout << "Ip: " << ip << " Porta: " << port;

    boost::asio::io_context io_context;

    VoiceChat::Client client(io_context, ip, port);
    co_spawn(io_context, client.asyncConnect(), boost::asio::detached);
    
    io_context.run();

    return 0;
}