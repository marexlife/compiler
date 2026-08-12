cmake_minimum_required(VERSION 3.20)

if(MSVC)
message(FATAL "MSVC is not allowed")
else()
set(MAREX_FLAGS -fno-exceptions)
endif()
