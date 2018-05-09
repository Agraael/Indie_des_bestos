set(ENTITY_ROOT_DIR Game/Entity)

include(${ENTITY_ROOT_DIR}/Bonuses/CMakeSources.cmake)
include(${ENTITY_ROOT_DIR}/IA/CMakeSources.cmake)
include(${ENTITY_ROOT_DIR}/Player/CMakeSources.cmake)
include(${ENTITY_ROOT_DIR}/Walls/CMakeSources.cmake)

set(ENTITY_INC_DIR
  ${BONUSES_INC_DIR}
  ${IA_INC_DIR}
  ${PLAYER_INC_DIR}
  ${WALLS_INC_DIR})

set(ENTITY_SRC_DIR
  ${BONUSES_SRC_DIR}
  ${PLAYER_SRC_DIR}
  ${IA_SRC_DIR}
  ${WALLS_SRC_DIR})

set(ENTITY_INC
  ${BONUSES_INC}
  ${PLAYER_INC}
  ${IA_INC}
  ${WALLS_INC})

set(ENTITY_SRC
  ${BONUSES_SRC}
  ${PLAYER_SRC}
  ${IA_SRC}
  ${WALLS_SRC})

