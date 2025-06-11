cmake_minimum_required(VERSION 3.27)
project(sokoban)

set(CMAKE_CXX_STANDARD 17)

find_package(raylib CONFIG REQUIRED)

# Optional: Add sanitizers for debug
if(APPLE)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -g")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")
    set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -fsanitize=address")
elseif(UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -fsanitize=address -fsanitize=undefined")
endif()

add_executable(sokoban
        sokoban.cpp
        globals.h
        levels.h
        player.h
        graphics.h
        images.h
        sounds.h
        levels_data.h
        move.h
        levels.cpp
        sounds.cpp
        player_globals.cpp
        levels_globalc.cpp
        images.cpp
        globals.cpp
        levels_data.cpp

)

target_link_libraries(sokoban PRIVATE raylib)

if(APPLE)
    find_library(COCOA_LIBRARY Cocoa)
    find_library(OPENGL_LIBRARY OpenGL)
    find_library(IOKIT_LIBRARY IOKit)
    find_library(CORE_FOUNDATION_LIBRARY CoreFoundation)
    find_library(CORE_VIDEO_LIBRARY CoreVideo)

    target_link_libraries(sokoban PRIVATE
            ${COCOA_LIBRARY}
            ${OPENGL_LIBRARY}
            ${IOKIT_LIBRARY}
            ${CORE_FOUNDATION_LIBRARY}
            ${CORE_VIDEO_LIBRARY}
    )
endif()
