#!/usr/bin/env bash

if [ -d "build" ]; then
    rm -rf build
    rm -rf ./cache
fi

mkdir -p build

cmake  -B build -S . -DCMAKE_TOOLCHAIN_FILE=./VCPKG/scripts/buildsystems/vcpkg.cmake

cd build

make  -j16
