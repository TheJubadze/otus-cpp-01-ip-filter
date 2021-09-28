#!/bin/sh
git clean -xdf
cmake -S ./src -B build
cmake --build build
cd build && ctest
