cmake_minimum_required(VERSION 3.20)

include(${CMAKE_SOURCE_DIR}/CMake/MakeLib.cmake)

MakeLib_Make(
    cl
    cli.cc
    absl::base
)

