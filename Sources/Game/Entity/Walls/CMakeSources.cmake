set(WALLS_ROOT_DIR Game/Entity/Walls)

set(WALLS_INC_DIR
  ${WALLS_ROOT_DIR})
set( WALLS_SRC_DIR
  ${WALLS_ROOT_DIR})

set( WALLS_INC
  ${WALLS_INC_DIR}/Walls.hpp
  ${WALLS_INC_DIR}/DestructibleWalls.hpp
  ${WALLS_INC_DIR}/IndestructibleWalls.hpp)

set( WALLS_SRC
  ${WALLS_SRC_DIR}/Walls.cpp
  ${WALLS_SRC_DIR}/DestructibleWalls.cpp
  ${WALLS_SRC_DIR}/IndestructibleWalls.cpp)
