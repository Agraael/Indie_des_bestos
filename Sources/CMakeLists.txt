include(CMakeSources.cmake)

set(INDIE_BIN_NAME bomberman)

include_directories( ${INDIE_INC_DIR} )

add_executable( ${INDIE_BIN_NAME}
  ${INDIE_SRC} )
