cmake_minimum_required(VERSION 3.0.0)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.0-preview3
)

FetchContent_MakeAvailable(Catch2)

add_executable(tests tests.cpp ../src/bts.cpp)
include_directories(../inc)
target_link_libraries(tests PRIVATE cxxopts plog Catch2::Catch2WithMain)
