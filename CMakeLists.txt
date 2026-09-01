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
main.cpp
src/src/server.cpp)

target_include_directories(VoiceChat PRIVATE 
src/include
src/singleton)

target_link_libraries(VoiceChat Boost::headers)