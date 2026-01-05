cmake_minimum_required(VERSION 3.23)
project(rayclicker)

# fetch raylib using FetchContent
include(FetchContent)
FetchContent_Declare(
  raylib
  URL https://github.com/raysan5/raylib/archive/refs/tags/5.0.tar.gz
)
FetchContent_MakeAvailable(raylib)

# add exe and sources
add_executable(rayclicker)
target_sources(rayclicker
PRIVATE
	src/main.c
  src/game.c
  src/ui.c
)

# C99
set_target_properties(rayclicker PROPERTIES
    C_STANDARD 99
    C_STANDARD_REQUIRED TRUE
)

# raylib for exe
target_link_libraries(rayclicker PRIVATE raylib)
