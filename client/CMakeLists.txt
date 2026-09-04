cmake_minimum_required(VERSION 3.28.3)

project(VoiceChat-Client)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BOOST_ROOT "/home/vince/myLibs/boost_1_92_0")
set(BOOST_INCLUDEDIR "/home/vince/myLibs/boost_1_92_0/include")

find_package(Boost REQUIRED)

add_executable(VoiceChat-Client 
src/app/main_client.cpp
)

target_include_directories(VoiceChat-Client PRIVATE 
src/include
)

target_link_libraries(VoiceChat-Client Boost::headers)