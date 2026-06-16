cmake_minimum_required(VERSION 3.20)

include(FetchContent)

FetchContent_Declare(
    ABSEIL
    GIT_REPOSITORY https://github.com/abseil/abseil-cpp.git
    GIT_TAG lts_2026_01_07
)

FetchContent_Declare(
    GTEST
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0
)

FetchContent_MakeAvailable(
    ABSEIL
    GTEST
)