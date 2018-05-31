include(Core/CMakeSources.cmake)
include(Game/CMakeSources.cmake)
include(Graphics/CMakeSources.cmake)

set(INDIE_INC_DIR
  ${CORE_INC_DIR}
  ${GAME_INC_DIR}
  ${GRAPHICS_INC_DIR})

set(INDIE_SRC_DIR
  ${CORE_SRC_DIR}
  ${GAME_SRC_DIR}
  ${GRAPHICS_SRC_DIR})

set(INDIE_INC
  ${CORE_INC}
  ${GAME_INC}
  ${GRAPHICS_INC})

set(INDIE_SRC
  ${CORE_SRC}
  ${GAME_SRC}
  ${GRAPHICS_SRC})
