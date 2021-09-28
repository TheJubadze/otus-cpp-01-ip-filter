cmake_minimum_required(VERSION 3.17)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(ip-filer VERSION ${PROJECT_VESRION})

set(CMAKE_CXX_STANDARD 11)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(version.hxx.in version.hxx)

add_executable(ip-filer-cli main.cxx)
add_library(ip-filer lib.cxx)
add_executable(test_version test_version.cxx)

set_target_properties(ip-filer-cli ip-filer test_version PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        )

set_target_properties(test_version PROPERTIES
        COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
        INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
        )

target_include_directories(ip-filer PRIVATE "${CMAKE_BINARY_DIR}")

target_link_libraries(ip-filer-cli PRIVATE ip-filer)
target_link_libraries(test_version ${Boost_LIBRARIES} ip-filer)

if (MSVC)
    target_compile_options(ip-filer-cli PRIVATE /W4)
    target_compile_options(ip-filer PRIVATE /W4)
    target_compile_options(test_version PRIVATE /W4)
else ()
    target_compile_options(ip-filer-cli PRIVATE -Wall)
    target_compile_options(ip-filer PRIVATE -Wall)
    target_compile_options(test_version PRIVATE -Wall)
endif ()

install(TARGETS ip-filer-cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Vitaly Senokosov")

include(CPack)

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
)

include(GoogleTest)
gtest_discover_tests(hello_test)