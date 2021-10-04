cmake_minimum_required(VERSION 3.17)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(ip-filter-cli VERSION ${PROJECT_VESRION})

configure_file(version.hxx.in version.hxx)

add_executable(ip-filter-cli main.cxx)
add_subdirectory(lib)

set_target_properties(
        ip-filter-cli
        PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
)

target_link_libraries(
        ip-filter-cli
        PRIVATE
        ip-filter
)

if (MSVC)
    target_compile_options(ip-filter-cli PRIVATE /W4)
else ()
    target_compile_options(ip-filter-cli PRIVATE -Wall)
endif ()

install(TARGETS ip-filter-cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Vitaly Senokosov")

include(CPack)
