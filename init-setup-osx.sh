#!/usr/bin/env bash

if [ -d "build" ]; then
    rm -rf build
    rm -rf ./cache
fi

mkdir build

echo "Build directory created"
echo "Delete old bin and build files"

cmake  -B build -S . -DCMAKE_TOOLCHAIN_FILE=./VCPKG/scripts/buildsystems/vcpkg.cmake

cd build

# Build the project using make
make

echo "Build complete"
