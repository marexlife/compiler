cmake_minimum_required(VERSION 3.20)

include(FetchContent)

set(CMAKE_CXX_STABNDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

FetchContent_Declare(
      ABSEIL
      GIT_REPOSITORY https://github.com/abseil/abseil-cpp.git
      GIT_TAG lts_2026_01_07
)

FetchContent_Declare(
      SPDLOG
      GIT_REPOSITORY https://github.com/gabime/spdlog.git
      GIT_TAG v1.17.0
)

FetchContent_MakeAvailable(
      ABSEIL
      SPDLOG
)
