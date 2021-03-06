cmake_minimum_required(VERSION 3.17)

project(ip-filter-tests)

set(CMAKE_CXX_STANDARD 17)

find_package(ip-filter CONFIG REQUIRED
        PATHS ${CMAKE_CURRENT_SOURCE_DIR}/../install/lib/cmake)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        hello_test
        hello_test.cc
)
target_link_libraries(
        hello_test
        gtest_main
        ip-filter::ip-filter
)

include(GoogleTest)
gtest_discover_tests(hello_test)