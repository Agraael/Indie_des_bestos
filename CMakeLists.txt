cmake_minimum_required( VERSION 3.9 )

project( IndieStudio CXX)

set(CMAKE_CONFIGURATION_TYPES build)

if (UNIX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -pedantic -fno-builtin")
endif()

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

add_subdirectory(Sources)
