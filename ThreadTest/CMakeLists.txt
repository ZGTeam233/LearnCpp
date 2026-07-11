cmake_minimum_required(VERSION 4.3)
project(ThreadTest)

set(CMAKE_CXX_STANDARD 26)

add_executable(ThreadTest main.cpp
        ThreadGuard.h)
