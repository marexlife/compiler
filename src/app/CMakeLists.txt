cmake_minimum_required(VERSION 3.20)
project(app)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CXX_CLANG_TIDY ON)

add_library(${PROJECT_NAME}
    app.cpp
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    lex
    parse
    cl
    fetch
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
