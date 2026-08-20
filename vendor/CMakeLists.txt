cmake_minimum_required(VERSION 3.20)

include(FetchContent)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

FetchContent_Declare(
    FMT
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 12.2.0
)

FetchContent_Declare(
    ABSEIL
    GIT_REPOSITORY https://github.com/abseil/abseil-cpp.git
    GIT_TAG lts_2026_01_07
)

FetchContent_MakeAvailable(
    FMT
    ABSEIL
)
