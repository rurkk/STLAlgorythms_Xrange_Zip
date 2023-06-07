cmake_minimum_required(VERSION 3.23)
project(labwork_11_rurkk)

set(CMAKE_CXX_STANDARD 23)

add_executable(labwork_11_rurkk
        main.cpp
        xrange.h
        zip.h
        algorithms.h
        CCirtucalBuffer.h
        CCirtucalBufferExt.h
        Iterator.h)

enable_testing()
add_subdirectory(gtests)
