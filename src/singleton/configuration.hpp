#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <boost/json.hpp>

namespace App
{
    class ConfigManager {
    private:
        boost::json::object m_configObj;

        ConfigManager() {}

        std::string readConfiguration() {
            std::ifstream ifs;
            std::string str;

            ifs.open("config.json", std::ios::in);

            if (!ifs) // TODO: Utilizzare log e gestire errore
                std::cout << "[ERROR]: Can't read configuration file" << std::endl;

            std::string line;
            std::string fileContent;

            while (std::getline(ifs, line))
                fileContent.append(line);
            
            ifs.close();

            return fileContent;
        }

    public:
        ConfigManager(ConfigManager const &) = delete;
        ConfigManager &operator=(const ConfigManager &) = delete;

        static ConfigManager &get() {
            static ConfigManager istance;
            return istance;
        }

        // * This method has to be called once at the program start
        void loadConfiguration() {
            boost::system::error_code ec;
            boost::json::value jsonParsed = boost::json::parse(readConfiguration());

            m_configObj = jsonParsed.try_as_object().value();
        }

        const std::int64_t &getPort() {
            return m_configObj.at("Server").at("port").try_as_int64().value();
        }
    };
}