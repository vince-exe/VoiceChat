#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

namespace VoiceChat {
    namespace Configuration {
        class App {
            private:
            
            public:
                static App& get() {
                    static App istance;
                    return istance;
                }
                
                void loadConfiguration() {
                    std::ifstream ifs;
                    std::string str;
                    
                    ifs.open("config.json", std::ios::in);

                    if(ifs)
                        std::cout<<"OK";
                    else
                        std::cout<<"NO";
                }
        };
    }
}