cmake_minimum_required(VERSION 3.17)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(ip-filer VERSION ${PROJECT_VESRION})

configure_file(version.hxx.in version.hxx)

add_executable(ip-filer-cli main.cxx)
add_library(ip-filer lib.cxx)

set_target_properties(ip-filer-cli ip-filer PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        )

target_include_directories(ip-filer PRIVATE "${CMAKE_BINARY_DIR}")

target_link_libraries(ip-filer-cli PRIVATE ip-filer)

if (MSVC)
    target_compile_options(ip-filer-cli PRIVATE /W4)
    target_compile_options(ip-filer PRIVATE /W4)
else ()
    target_compile_options(ip-filer-cli PRIVATE -Wall)
    target_compile_options(ip-filer PRIVATE -Wall)
endif ()

install(TARGETS ip-filer-cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Vitaly Senokosov")

include(CPack)
