set( GAME_ROOT_DIR Game)

include(${GAME_ROOT_DIR}/Entity/CMakeSources.cmake)
include(${GAME_ROOT_DIR}/Map/CMakeSources.cmake)
include(${GAME_ROOT_DIR}/Multiplayer/CMakeSources.cmake)

set(GAME_INC_DIR
  ${ENTITY_INC_DIR}
  ${MAP_INC_DIR}
  ${MULTIPLAYER_INC_DIR})

set(GAME_SRC_DIR
  ${ENTITY_SRC_DIR}
  ${MAP_SRC_DIR}
  ${MULTIPLAYER_SRC_DIR})

set(GAME_INC
  ${ENTITY_INC}
  ${MAP_INC}
  ${MULTIPLAYER_INC})

set(GAME_SRC
  ${ENTITY_SRC}
  ${MAP_SRC}
  ${MULTIPLAYER_SRC})
