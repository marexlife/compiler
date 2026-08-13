cmake_minimum_required(VERSION 3.20)

if(MSVC)
set(MAREX_FLAGS /W4)
else()
set(MAREX_FLAGS 
    -fno-exceptions 
    -fno-rtti
    -Wall
    -Wextra
    -Wconversion
    -Werror
)
endif()

