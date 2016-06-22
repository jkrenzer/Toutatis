cmake_minimum_required(VERSION 2.6)
project(toutatis)

add_executable(toutatis main.cpp)

install(TARGETS toutatis RUNTIME DESTINATION bin)
