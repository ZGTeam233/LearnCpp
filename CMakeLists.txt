cmake_minimum_required(VERSION 4.2)
project(LearnCpp LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(circle src/calc/circle.c)
add_executable(prime src/calc/prime.c)
add_executable(trifx src/calc/trifx.c)
add_executable(ClassTest src/ClassTest/ClassMain.cpp
        src/ClassTest/Person.h)
add_executable(donut src/donut/donut.c)
add_executable(cguess src/guess/guess.c)
add_executable(guess src/guess/guess.cpp)
add_executable(StuSys src/StuSys/StuSys.cpp
        src/StuSys/Student.h)
add_executable(grade src/StuSys/grade.cpp)
add_executable(CppApi src/CppApi.cpp)
add_executable(Sales src/Sales/Sales_main.cpp
        src/Sales/Sales_item.h
        src/Sales/Sales_data.h
        src/Sales/Sales_data.cpp)
