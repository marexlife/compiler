cmake_minimum_required(VERSION 3.20)
project(lex)

include(${CMAKE_SOURCE_DIR}/cmake/flags.cmake)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CXX_CLANG_TIDY ON)

add_library(${PROJECT_NAME}
    Lexer.cpp
    TokenFactory.cpp
    LexerPrinter.cpp
)

target_compile_options(${PROJECT_NAME} PUBLIC
    ${MAREX_FLAGS}
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    core

    absl::base
    absl::statusor
    absl::inlined_vector
    absl::flat_hash_map
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
