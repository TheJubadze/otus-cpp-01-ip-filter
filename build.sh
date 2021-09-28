#!/bin/sh
git clean -xdf
cmake -S . -B build
cmake --build build
ctest --test-dir build/tests
