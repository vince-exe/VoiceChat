#include <iostream>
#include <boost/asio.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/json/src.hpp>
#include <boost/asio/co_spawn.hpp>
#include <boost/asio/detached.hpp>
#include <boost/asio/io_context.hpp>

#include "configuration.hpp"
#include "server.hpp"

int main()
{
    try {
        App::ConfigManager::get().loadConfiguration();
    }
    catch(const boost::system::system_error& err) {
        std::cerr << err.code() << ": " << err.what() << std::endl;
        return -1;
    } 
    
    App::Server server;
    co_spawn(server.listen());
}