cmake_minimum_required(VERSION 3.28.3)
project(VoiceChat)

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

########## SERVER ##########
add_executable(VoiceChat-Server 
server/src/app/main_server.cpp
server/src/app/server.cpp
server/src/singleton/configuration.cpp
common/netpacket.cpp
)

target_include_directories(VoiceChat-Server PRIVATE 
server/src/include
server/src/singleton/include
common/include)

target_link_libraries(VoiceChat-Server Boost::headers)
##########


########## CLIENT ##########
add_executable(VoiceChat-Client 
client/src/app/main_client.cpp
client/src/app/client.cpp
common/netpacket.cpp
)

target_include_directories(VoiceChat-Client PRIVATE 
client/src/include
common/include
)

target_link_libraries(VoiceChat-Client Boost::headers)

##########