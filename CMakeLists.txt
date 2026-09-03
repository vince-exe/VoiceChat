cmake_minimum_required(VERSION 3.28.3)
project(VoiceChat)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED)

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/config.json"
    "${CMAKE_CURRENT_BINARY_DIR}/config.json"
    COPYONLY
) #sposta il file di configurazione vicino all'eseguibile

add_executable(VoiceChat 
server/src/src/main_server.cpp
server/src/src/server.cpp
server/src/singleton/configuration.cpp)

target_include_directories(VoiceChat PRIVATE 
server/src/include
server/src/singleton/include)

target_link_libraries(VoiceChat Boost::headers)