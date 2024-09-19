#!/usr/bin/env bash

VCPKG_TARGET_TRIPLET="x64-osx"
VCPKG_DIR="$PWD/VCPKG"
INSTALLED_SHARED_DIR="$PWD/vcpkg_installed"  # Replace with actual path

# Check if dependencies are already installed
if [ ! -d "$INSTALLED_SHARED_DIR" ]; then
    echo "Dependencies not installed. Installing..."

    # Define the path to the vcpkg executable
    pushd "$VCPKG_DIR" || exit

    # Run vcpkg install command
    # ./vcpkg install --triplet="$VCPKG_TARGET_TRIPLET"
    ./vcpkg install

    # Check the result of the installation
    if [ $? -ne 0 ]; then
        echo "Failed to install dependencies with Vcpkg."
        exit 1
    fi

    popd || exit
fi

exit 0
