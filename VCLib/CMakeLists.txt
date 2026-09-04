cmake_minimum_required(VERSION 3.28.3)
project(VoiceChat)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BOOST_ROOT "/home/vince/myLibs/boost_1_92_0")
set(BOOST_INCLUDEDIR "/home/vince/myLibs/boost_1_92_0/include")

find_package(Boost REQUIRED)

add_library(${PROJECT_NAME} STATIC 
src/test.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} Boost::headers)