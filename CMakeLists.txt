#cmake_minimum_required( VERSION 3.9 )

project( IndieStudio CXX)

set(CMAKE_CONFIGURATION_TYPES build)

option(NAZI "Use NAZI cpp flags for unix" OFF) #OFF by default : use -DNAZ
option(MDR "Use MDR for no flags" OFF)
if (UNIX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -pedantic -Wextra -fno-builtin -ffast-math")

  if(NAZI)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wfloat-equal -Wshadow \
      -Weffc++ -Wstrict-overflow=5 -Wcast-align -Wconversion -ftrapv \
      -Wuninitialized -Wuseless-cast -Wold-style-cast -Wnon-virtual-dtor")
  endif(NAZI)

  if(MDR)
    set(CMAKE_CXX_FLAGS "")
  endif(MDR)
endif()
unset(NAZI CACHE)
unset(MDR CACHE)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

add_subdirectory(Sources)

if(UNIX)
  add_custom_target( irrlicht
    COMMAND make
    WORKING_DIRECTORY irrlicht-1.8.4/source/Irrlicht)
endif()