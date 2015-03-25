cmake_minimum_required(VERSION 3.1)
project(build)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/main.cpp)

add_executable(build ${SOURCE_FILES} src/Filosofo.cpp src/Filosofo.h src/Garfo.cpp src/Garfo.h src/ProblemaFilosofos.cpp src/ProblemaFilosofos.h src/Messenger.cpp src/Messenger.h)