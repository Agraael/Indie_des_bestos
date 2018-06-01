set(MAP_ROOT_DIR Game/Map)

set(MAP_INC_DIR
  ${MAP_ROOT_DIR} )
set( MAP_SRC_DIR
  ${MAP_ROOT_DIR} )

set( MAP_INC
  ${MAP_INC_DIR}/Map.hpp
  ${MAP_INC_DIR}/Gen.hpp
  ${MAP_INC_DIR}/MapGenerator.hpp
  ${MAP_INC_DIR}/Procedural.hpp
  ${MAP_INC_DIR}/InterpreteGeneration.hpp)

set( MAP_SRC
  ${MAP_SRC_DIR}/Map.cpp
  ${MAP_SRC_DIR}/MapGenerator.cpp
  ${MAP_SRC_DIR}/Procedural.cpp
  ${MAP_SRC_DIR}/InterpreteGeneration.cpp)
