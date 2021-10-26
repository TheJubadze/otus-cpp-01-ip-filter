cmake_minimum_required(VERSION 3.17)

project(ip-filter-lib)

add_library(
        ip-filter
        STATIC
        IpAddress.cpp
        IpAddress.h IpReader.cpp IpReader.h IpParser.cpp IpParser.h)

set_target_properties(
        ip-filter
        PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        )

target_include_directories(
        ip-filter
        PRIVATE
        "${CMAKE_CURRENT_BINARY_DIR}")

install(TARGETS ip-filter EXPORT ip-filter-targets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        INCLUDES DESTINATION include
        )

install(FILES IpAddress.h DESTINATION include)

install(EXPORT ip-filter-targets
        FILE ip-filter-config.cmake
        NAMESPACE ip-filter::
        DESTINATION lib/cmake
        )
