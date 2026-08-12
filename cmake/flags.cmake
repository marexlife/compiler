cmake_minimum_required(VERSION 3.20)

if(MSVC)
set(MAREX_FLAGS /W4)
else()
set(MAREX_FLAGS -Wall -Wextra -Wpedantic -Wconversion -Werror)
endif()

