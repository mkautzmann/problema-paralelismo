cmake_minimum_required (VERSION 2.6)
project(ProblemaParalelismo)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")

add_custom_target(cleanall
rm -rf bin
rm -rf CMakeFiles
rm Makefile
rm cmake_install.cmake
rm CMakeCache.txt
)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

add_executable(ProblemaFilosofos main.cpp Filosofo.cpp Filosofo.h Garfo.cpp Garfo.h ProblemaFilosofos.cpp ProblemaFilosofos.h Messenger.cpp Messenger.h)

