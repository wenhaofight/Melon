cmake_minimum_required(VERSION 3.0)

project(Melon)

include_directories(include t/include)

file(GLOB SOURCES "src/*.c" "t/src/*.c")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -O3 -fPIC -DMLN_ROOT=\\\"/opt/project/c/Melon\\\" -DMLN_NULL=\\\"/dev/null\\\" -DMLN_LANG_LIB=\\\"/opt/project/c/Melon/lib/melang\\\" -DMLN_LANG_DYLIB=\\\"/opt/project/c/Melon/lib/melang_dynamic\\\"")

add_executable(Melon ${SOURCES} main.c)