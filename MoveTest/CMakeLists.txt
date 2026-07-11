cmake_minimum_required(VERSION 4.3)
project(MoveTest)

set(CMAKE_CXX_STANDARD 20)

add_executable(MoveTest main.cpp
        MyBuffer.h
        use_MyBuffer.cpp
        test.h
        use_SimpleString.cpp
        SimpleString.h)
