cmake_minimum_required(VERSION 4.2)
project(LearnCpp LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(LearnCpp src/main.cpp
        src/modules/Person.h
        src/modules/Person.cpp
        src/core.h
        src/core.cpp
        src/modules/Sales_item.h
        src/modules/Sales_data.h
        src/modules/Sales_data.cpp
        src/modules/DebugErr.h
        src/modules/DebugErr.cpp
        src/modules/grade.cpp
        src/modules/grade.h
        src/modules/Student.h)
add_executable(LearnC src/cmain.c
        src/modules/calc.h
        src/modules/calc.c)
