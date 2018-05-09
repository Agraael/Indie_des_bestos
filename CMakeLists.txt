cmake_minimum_required( VERSION 3.9 )

project( IndieStudio CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -pedantic")

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

set( AUTOGEN_BUILD_DIR build)

add_subdirectory(Sources)
