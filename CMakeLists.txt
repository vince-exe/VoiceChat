cmake_minimum_required(VERSION 3.28.3)
project(VoiceChat)

find_package(Boost REQUIRED)
add_executable(VoiceChat main.cpp)
target_link_libraries(VoiceChat Boost::headers)