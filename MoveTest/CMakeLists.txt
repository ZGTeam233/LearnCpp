cmake_minimum_required(VERSION 4.3)
project(MoveTest)

set(CMAKE_CXX_STANDARD 20)

add_executable(MoveTest main.cpp
        my_buffer/MyBuffer.h
        my_buffer/use_my_buffer.cpp
        test.h
        simple_string/use_simple_str.cpp
        simple_string/SimpleString.h
        resource_pool/Node.h
        resource_pool/ResourcePool.h
        resource_pool/test_res_pool.cpp)
