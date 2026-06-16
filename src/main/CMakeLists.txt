cmake_minimum_required(VERSION 3.20)
project(compiler)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CXX_CLANG_TIDY ON)

add_executable(${PROJECT_NAME}
    main.cc
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    app
    lex
    parse
    cl
    fetch
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND $<TARGET_FILE:${PROJECT_NAME}>
)