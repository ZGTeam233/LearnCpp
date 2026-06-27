cmake_minimum_required(VERSION 4.2)
project(LearnCpp LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(LearnCpp src/main.cpp
        src/modules/Person.hpp
        src/modules/Person.cpp
        src/core.hpp
        src/core.cpp
        src/modules/Sales_item.hpp
        src/modules/Sales_data.hpp
        src/modules/Sales_data.cpp
        src/modules/DebugUtil.hpp
        src/modules/DebugUtil.cpp
        src/modules/grade.cpp
        src/modules/grade.hpp
        src/modules/Student.hpp)
add_executable(LearnC src/cmain.c
        src/ccore.h
        src/modules/calc.c
        src/modules/donut.c
        src/modules/guess.c)
