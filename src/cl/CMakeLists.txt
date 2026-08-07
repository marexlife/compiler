cmake_minimum_required(VERSION 3.20)
project(cl)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME}
    cli.cc
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    absl::base
    absl::statusor
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
