cmake_minimum_required(VERSION 3.10)

project(Solid)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/build/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/build/Release)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_subdirectory(Solid)
add_subdirectory(Sandbox)

add_subdirectory(vendor/spdlog vendor/spdlog_build)
