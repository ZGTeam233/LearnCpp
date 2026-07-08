cmake_minimum_required(VERSION 4.2)
project(LearnCpp LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(LearnCpp src/main.cpp
        src/modules/Person.h
        src/modules/Person.cpp
        src/modules/Person_main.cpp
        src/core.h
        src/primer/Sales_item.h
        src/primer/Sales_data.h
        src/primer/Sales_data.cpp
        src/primer/Sales_main.cpp
        src/logutil/LogUtil.h
        src/logutil/LogUtil.cpp
        src/modules/Student.h
        src/primer/Screen.h
        src/primer/Screen.cpp
        src/primer/Screen_main.cpp
        src/modules/guess.cpp
        src/modules/grade.cpp
        src/modules/Student_main.cpp)
add_executable(LearnC src/cmain.c
        src/ccore.h
        src/cmodules/calc.c
        src/cmodules/donut.c
        src/cmodules/guess.c)
