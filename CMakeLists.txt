cmake_minimum_required(VERSION 4.2)
project(LearnCpp LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(LearnCpp main.cpp
        modules/Person.h
        modules/Person.cpp
        modules/Person_main.cpp
        core.h
        primer/Sales_item.h
        primer/Sales_data.h
        primer/Sales_data.cpp
        primer/Sales_main.cpp
        logutil/LogUtil.h
        logutil/LogUtil.cpp
        modules/Student.h
        primer/Screen.h
        primer/Screen.cpp
        primer/Screen_main.cpp
        modules/guess.cpp
        modules/grade.cpp
        modules/Student_main.cpp)
add_executable(LearnC cmain.c
        ccore.h
        cmodules/calc.c
        cmodules/donut.c
        cmodules/guess.c)
