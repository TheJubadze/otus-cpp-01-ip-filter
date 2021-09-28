#!/bin/sh
git clean -xdf
cmake -S ./src -B build
cmake --build build
ctest --test-dir build/tests
