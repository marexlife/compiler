cmake_minimum_required(VERSION 3.20)
project(parse)

include(${CMAKE_SOURCE_DIR}/cmake/flags.cmake)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CXX_CLANG_TIDY ON)

add_library(${PROJECT_NAME}
    Parser.cpp
    ParserPack.cpp
    NodeFactory.cpp
    TranslationUnit.cpp

    nodes/AstNode.cpp
    nodes/ClassItem.cpp
    nodes/PrintNode.cpp
    nodes/ValueNode.cpp
    nodes/VarNode.cpp
    nodes/IdentNode.cpp
    nodes/FuncNode.cpp
    nodes/ClassNode.cpp
    nodes/FileItem.cpp
    nodes/exceptions/InvalidTokenException.cpp
    
    linter/CaseCheck.cpp
    linter/exceptions/WrongCaseException.cpp
)

target_compile_options(${PROJECT_NAME} PUBLIC
    ${MAREX_FLAGS}
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    lex

    absl::base
    absl::statusor
    absl::inlined_vector
    absl::flat_hash_map
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
