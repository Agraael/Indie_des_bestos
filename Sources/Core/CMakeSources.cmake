# ----- Core sources and include
set(CORE_ROOT_DIR Core)

set( CORE_INC_DIR
  ${CORE_ROOT_DIR})
set( CORE_SRC_DIR
  ${CORE_ROOT_DIR})

set( CORE_INC
  ${CORE_INC_DIR}/Core.hpp
  ${CORE_INC_DIR}/EventManager.hpp
  ${CORE_INC_DIR}/EventCore.hpp
  ${CORE_INC_DIR}/HandleGame.hpp
   ${CORE_INC_DIR}/TimeManager.hpp
   ${CORE_INC_DIR}/SaveGame.hpp
	 ${CORE_INC_DIR}/SoundManager.hpp)

set( CORE_SRC
  ${CORE_SRC_DIR}/Core.cpp
  ${CORE_SRC_DIR}/main.cpp
  ${CORE_SRC_DIR}/EventCore.cpp
  ${CORE_SRC_DIR}/HandleGame.cpp
   ${CORE_SRC_DIR}/TimeManager.cpp
   ${CORE_SRC_DIR}/SaveGame.cpp
	 ${CORE_INC_DIR}/SoundManager.cpp)
# -----
