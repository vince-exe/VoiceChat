#include <iostream>
#include <boost/asio.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/co_spawn.hpp>
#include <boost/asio/detached.hpp>
#include <boost/asio/io_context.hpp>

#include "configuration.hpp"
#include "server.hpp"

int main()
{
    try {
        App::ConfigManager::get().loadConfiguration();
        
        App::Server server;

        boost::asio::io_context io_context(1);
        co_spawn(io_context, server.listen(), boost::asio::detached);
    }
    catch(const boost::system::system_error& err) {
        std::cerr << err.code() << ": " << err.what() << std::endl;
        return -1;
    } 
    catch(std::exception& e) {
        std::cout<< "Exception: " << e.what() << std::endl;
    }

    return 0;
}