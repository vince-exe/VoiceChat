#include "configuration.hpp"
#include <boost/asio.hpp>

int main()
{
    try {
        App::ConfigManager::get().loadConfiguration();
    }
    catch(const boost::system::system_error& err) {
        std::cerr << err.code() << ": " << err.what() << std::endl;
        return -1;
    } 
    
    std::cout << "Server port: " << App::ConfigManager::get().getPort() << std::endl;
}