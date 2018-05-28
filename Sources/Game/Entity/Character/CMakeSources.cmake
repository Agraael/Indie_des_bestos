set(CHARACTER_ROOT_DIR Game/Entity/Character)

include(${CHARACTER_ROOT_DIR}/IA/CMakeSources.cmake)
include(${CHARACTER_ROOT_DIR}/Player/CMakeSources.cmake)

set(CHARACTER_INC_DIR
  ${IA_INC_DIR}
  ${PLAYER_INC_DIR})

set(CHARACTER_SRC_DIR
  ${IA_SRC_DIR}
  ${PLAYER_SRC_DIR})

set(CHARACTER_INC
  ${IA_INC}
  ${PLAYER_INC}
  ${CHARACTER_ROOT_DIR}/Character.hpp)

set(CHARACTER_SRC
  ${IA_SRC}
  ${PLAYER_SRC})
