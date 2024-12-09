cmake_minimum_required(VERSION 3.0)

project(Melon)

include_directories(include)

file(GLOB SOURCES "src/*.c")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -O3 -fPIC -DMLN_ROOT=\\\"/opt/project/c/Melon\\\" -DMLN_NULL=\\\"/dev/null\\\" -DMLN_LANG_LIB=\\\"/opt/project/c/Melon/lib/melang\\\" -DMLN_LANG_DYLIB=\\\"/opt/project/c/Melon/lib/melang_dynamic\\\"")

add_library(melon SHARED ${SOURCES})

add_library(melon_static STATIC ${SOURCES})

install(DIRECTORY conf include DESTINATION /opt/project/c/Melon)
install(FILES ${CMAKE_BINARY_DIR}/conf/melon.conf DESTINATION /opt/project/c/Melon/conf)
install(TARGETS melon melon_static
    ARCHIVE DESTINATION /opt/project/c/Melon/lib
    LIBRARY DESTINATION /opt/project/c/Melon/lib
)

