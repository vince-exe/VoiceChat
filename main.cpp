#include "configuration.hpp"

using VoiceChat::Config::App;

int main()
{
    App::get().loadConfiguration();
    
    std::cout << "Server port: " << App::get().getPort() << std::endl;
}