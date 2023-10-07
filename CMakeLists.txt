cmake_minimum_required(VERSION 3.25)
project(hash_table)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)

FetchContent_Declare(googlebenchmark
        GIT_REPOSITORY https://github.com/google/benchmark.git
        GIT_TAG main)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
include_directories($ENV{HOME}/googletest/googletest/include)
FetchContent_MakeAvailable(
        googletest
        googlebenchmark)


add_executable(hash_table main.cpp)
target_link_libraries(hash_table gtest_main benchmark::benchmark)