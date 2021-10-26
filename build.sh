#!/bin/sh

git clean -xdf

cmake -S ./src -B build -DPATCH_VERSION=1
cmake --build build

cmake -S ./src/lib -B build_lib -DCMAKE_INSTALL_PREFIX=install
cmake --build build_lib --target install

cmake -S ./tests -B build_tests
cmake --build build_tests
ctest --test-dir build_tests

cmake --build ./build --target package