set(ENTITY_ROOT_DIR Game/Entity)

include(${ENTITY_ROOT_DIR}/Bonuses/CMakeSources.cmake)
include(${ENTITY_ROOT_DIR}/Walls/CMakeSources.cmake)
include(${ENTITY_ROOT_DIR}/Character/CMakeSources.cmake)
include(${ENTITY_ROOT_DIR}/Bombs/CMakeSources.cmake)

set(ENTITY_INC_DIR
  ${BONUSES_INC_DIR}
  ${WALLS_INC_DIR}
  ${ENTITY_ROOT_DIR}
  ${CHARACTER_INC_DIR}
  ${BOMBS_INC_DIR})

set(ENTITY_SRC_DIR
  ${BONUSES_SRC_DIR}
  ${WALLS_SRC_DIR}
  ${ENTITY_ROOT_DIR}
  ${CHARACTER_SRC_DIR}
  ${BOMBS_SRC_DIR})

set(ENTITY_INC
  ${BONUSES_INC}
  ${WALLS_INC}
  ${CHARACTER_INC}
  ${BOMBS_INC}
  ${ENTITY_ROOT_DIR}/Entity.hpp
  ${ENTITY_ROOT_DIR}/MoveTo.hpp)

set(ENTITY_SRC
  ${BONUSES_SRC}
  ${WALLS_SRC}
  ${CHARACTER_SRC}
  ${BOMBS_SRC}
  ${ENTITY_ROOT_DIR}/Entity.cpp
  ${ENTITY_ROOT_DIR}/MoveTo.cpp)

