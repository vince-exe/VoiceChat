#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <boost/json.hpp>

using namespace boost::json;

namespace VoiceChat {
    namespace Config {
        class App {
            private:
                object m_configObj;
                object m_serverObj;

                std::string readConfiguration() {
                    std::ifstream ifs;
                    std::string str;
                    
                    ifs.open("config.json", std::ios::in);

                    if(!ifs) //TO-DO: Utilizzare log e gestire errore
                        std::cout << "[ERROR]: Can't read configuration file" << std::endl;

                    std::string line;
                    std::string fileContent;

                    while(std::getline(ifs, line)) {
                        fileContent.append(line);
                    }
                    ifs.close();

                    return fileContent;
                }

                App() {}
                App(App const&);
                void operator=(App const&);

            public:
                App(App const&) = delete;
                App(const App&) = delete;
                App& operator=(const App&) = delete;

                static App& get() {
                    static App istance;
                    return istance;
                }
                
                // * This method has to be called once at the program start
                void loadConfiguration() {                    
                    boost::system::error_code ec;
                    value jsonParsed = parse(readConfiguration(), ec);
                    if(ec) { // TODO: Utilizzare log e gestire errore
                        std::cout << "[ERROR]: Parsing failed: " << ec.message() << std::endl;
                    }
                    
                    auto parsedObject = jsonParsed.if_object();
                    if(!parsedObject) { // TODO: Utilizzare log e gestire errore
                        std::cout << "[ERROR]: Invalid JSON expected an object" << std::endl;
                    }
                    
                    m_configObj = *parsedObject;
                    m_serverObj = m_configObj.at("Server");
                }   

                int getPort() const { 
                    /*
                    const object& serverVal = m_configObj.at("Server");

                    value v = (const) m_configObj["port"];
                    if(!v.is_int64())
                        throw std::runtime_error("value is not an integer");
                    
                    return v.as_int64();
                    */

                    return 0;
                }
        };
    }
}