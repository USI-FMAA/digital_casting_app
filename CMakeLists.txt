cmake_minimum_required(VERSION 3.29.0)

project(dcs_app VERSION 1.0 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_TOOLCHAIN_FILE ./VCPKG/vcpkg/scripts/buildsystems/vcpkg.cmake)
set(CMAKE_CXX_STANDARD 17)

# check the operating system, and set the vcpkg target triplet accordingly
if (WIN32)
    message("Configuring for windows")
    set(VCPKG_TARGET_TRIPLET "x64-windows" CACHE STRING "")
endif()
if (UNIX AND NOT APPLE)
    message("Configuring for linux")
    set(VCPKG_TARGET_TRIPLET "x64-linux" CACHE STRING "")
endif()
if (APPLE)
    message("Configuring for apple")
    set(VCPKG_TARGET_TRIPLET "x64-osx" CACHE STRING "" )
endif()

# Define the path to the installed directory
# set(INSTALLED_SHARED_DIR ./VCPKG/installed/${VCPKG_TARGET_TRIPLET}/share)
#
# # Check if dependencies are already installed
# if(NOT EXISTS ${INSTALLED_SHARED_DIR})
#     message("Dependencies not installed. Installing...")
#     # Define the path to the vcpkg executable
#     set(VCPKG_EXECUTABLE "${CMAKE_SOURCE_DIR}/VCPKG/vcpkg")
#
#     # Run vcpkg install command
#     execute_process(
#         COMMAND ${VCPKG_EXECUTABLE} install
#         WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/VCPKG
#         RESULT_VARIABLE VCPKG_INSTALL_RESULT
#     )
#     # Check the result of the installation
#     if(VCPKG_INSTALL_RESULT)
#         message(FATAL_ERROR "Failed to install dependencies with Vcpkg.")
#     endif()
# endif()

set(REQUIRE_PACKAGE
    glfw3
    glad
    imgui
    implot
)

add_executable(${PROJECT_NAME} src/main.cpp)
# foreach(PACKAGE ${REQUIRE_PACKAGE})
#     set(${PACKAGE}_DIR ${INSTALLED_SHARED_DIR}/${PACKAGE})
# endforeach()

foreach(PACKAGE ${REQUIRE_PACKAGE})
    find_package(${PACKAGE} CONFIG QUIET)
endforeach()

find_path(OPENGL_REGISTRY_INCLUDE_DIRS "GL/glcorearb.h")
find_package(OpenGL REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${OPENGL_REGISTRY_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} PRIVATE
    glfw
    glad::glad
    imgui::imgui
    implot::implot
    OpenGL::GL
)

