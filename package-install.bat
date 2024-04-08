@echo off

set "VCPKG_TARGET_TRIPLET=x64-windows"
set "VCPKG_DIR=%CD%\VCPKG"

REM  NOTE: https://vcpkg.io/en/packages

rem Check if dependencies are already installed

if not exist "%INSTALLED_SHARED_DIR%" (
    echo Dependencies not installed. Installing...
    rem Define the path to the vcpkg executable

    pushd "%VCPKG_DIR%"
    rem Run vcpkg install command
    REM vcpkg remove %PACKAGE%
    vcpkg install --triplet %VCPKG_TARGET_TRIPLET%

    rem Check the result of the installation
    if %errorlevel% neq 0 (
        echo Failed to install dependencies with Vcpkg.
        exit /b 1
    )
)
exit /b 0
