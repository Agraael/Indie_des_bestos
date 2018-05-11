include(CMakeSources.cmake)

set(INDIE_BIN_NAME bomberman)

if(UNIX)
  set(IRRLICHT_INC_DIR ../irrlicht-1.8.4/include /usr/X11R6/include)

  set(IRRLICHT_LIB_DIR ../irrlicht-1.8.4/lib/Linux /usr/X11R6/lib)
endif()

include_directories(
  ${INDIE_INC_DIR}
  ${IRRLICHT_INC_DIR})

link_directories(
  ${IRRLICHT_LIB_DIR})

add_executable( ${INDIE_BIN_NAME}
  ${INDIE_SRC})

target_link_libraries(${INDIE_BIN_NAME} Irrlicht GL Xxf86vm Xext X11 Xcursor)
