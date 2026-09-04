cmake_minimum_required(VERSION 3.28.3)
project(VoiceChat-Server)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BOOST_ROOT "/home/vince/myLibs/boost_1_92_0")
set(BOOST_INCLUDEDIR "/home/vince/myLibs/boost_1_92_0/include")

find_package(Boost REQUIRED)

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/config.json"
    "${CMAKE_CURRENT_BINARY_DIR}/config.json"
    COPYONLY
) #sposta il file di configurazione vicino all'eseguibile

add_executable(VoiceChat-Server 
src/app/main_server.cpp
src/app/server.cpp
src/singleton/configuration.cpp
)

target_include_directories(VoiceChat-Server PRIVATE 
src/include
src/singleton/include)

target_link_libraries(VoiceChat-Server Boost::headers)