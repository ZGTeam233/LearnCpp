cmake_minimum_required(VERSION 4.2)
project(LearnCpp LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(LearnCpp main.cpp
        modules/Person.h
        modules/Person.cpp
        modules/use_Person.cpp
        core.h
        primer/Sales_data.h
        primer/Sales_data.cpp
        primer/use_Sales.cpp
        logutil/LogUtil.h
        logutil/LogUtil.cpp
        modules/Student.h
        primer/Screen.h
        primer/Screen.cpp
        primer/use_Screen.cpp
        modules/guess.cpp
        modules/grade.cpp
        modules/use_Student.cpp
        primer/Account.cpp
        primer/Account.h
        primer/use_Account.cpp)
add_executable(LearnC cmain.c
        ccore.h
        cmodules/calc.c
        cmodules/donut.c
        cmodules/guess.c)
