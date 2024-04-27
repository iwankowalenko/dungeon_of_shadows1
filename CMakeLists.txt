add_executable(dungeon_of_shadows src/main.cpp
                                  src/enemy.cpp)

cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_definitions(-DMY_DEBUG_MACROS)

include_directories("../nana/include")

