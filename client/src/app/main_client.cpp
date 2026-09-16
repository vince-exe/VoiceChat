#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/asio/co_spawn.hpp>
#include <boost/asio/detached.hpp>
#include <boost/asio/io_context.hpp>

#include "client.hpp"

int main() {
    std::string ip; boost::asio::ip::port_type port;
    boost::asio::io_context io_context;

    std::cout << "Inserisci l'ip: ";
    std::cin >> ip;

    std::cout << "Inserisci la porta: ";
    std::cin >> port;

    VoiceChat::Client client(io_context, ip, port);

    try {
        client.asyncConnect();

        io_context.run();
    }
    catch(boost::system::system_error& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}