cmake_minimum_required(VERSION 3.0.0)
project(cpp-unit VERSION 0.1.0)

add_executable(cpp-unit main.cpp src/bts.cpp)
include_directories(cxxopts/include)
include_directories(plog/include)
include_directories(inc)

if(PROJECT_NAME STREQUAL CMAKE_PROJECT_NAME)
    add_subdirectory(tests)
endif() #PROJECT_NAME STREQUAL CMAKE_PROJECT_NAME

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
