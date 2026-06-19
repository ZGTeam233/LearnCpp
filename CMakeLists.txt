cmake_minimum_required(VERSION 4.2)
project(LearnCpp LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(LearnCpp src/main.cpp
        src/Person.h
        src/Person.cpp
        src/core.h
        src/core.cpp
        src/Sales_item.h
        src/Sales_data.h
        src/Sales_data.cpp
        src/DebugErr.h
        src/DebugErr.cpp
        src/grade.cpp
        src/grade.h)
