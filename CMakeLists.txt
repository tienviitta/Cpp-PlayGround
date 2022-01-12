cmake_minimum_required(VERSION 3.0.0)
project(cpp-plgrd VERSION 0.1.0)

Include(FetchContent)

FetchContent_Declare(
  cxxopts
  GIT_REPOSITORY https://github.com/jarro2783/cxxopts.git
  GIT_TAG        v3.0.0
)
FetchContent_Declare(
  plog
  GIT_REPOSITORY https://github.com/SergiusTheBest/plog.git
  GIT_TAG        1.1.5
)

FetchContent_MakeAvailable(cxxopts plog)

add_executable(${PROJECT_NAME} main.cpp src/bts.cpp)
# include_directories(cxxopts/include)
# include_directories(plog/include)
# include_directories(inc)
target_include_directories(${PROJECT_NAME} PRIVATE inc)
target_link_libraries(${PROJECT_NAME} cxxopts plog)

if(PROJECT_NAME STREQUAL CMAKE_PROJECT_NAME)
    add_subdirectory(tests)
endif() #PROJECT_NAME STREQUAL CMAKE_PROJECT_NAME

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
