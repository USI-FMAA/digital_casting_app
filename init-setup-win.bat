@echo off

REM Check if the build dir exists
if not exist build (
    mkdir  build
) else (
    rmdir /s /q build
    mkdir  build
)
REM echo "Build directory created"
REM echo "Delete old bin and build files"

REM Visual Studio 2019, MSYS Makefiles, MinGW Makefiles, ninja
cmake  -B build -S . -DCMAKE_TOOLCHAIN_FILE=./VCPKG/scripts/buildsystems/vcpkg.cmake

cd build
REM
cmake --build . -j16
