include(CMakeSources.cmake)

set(INDIE_BIN_NAME bomberman)

set(IRRLICHT_INC_DIR ../irrlicht-1.8.4/include)
set(IRRKLANG_INC_DIR ../irrKlang-64bit-1.6.0/include)

if(UNIX)
	set(IRRLICHT_LIB_DIR ${IRRLICHT_LIB_DIR} ../irrlicht-1.8.4/lib/Linux /usr/X11R6/lib)
	set(IRRLICHT_INC_DIR ${IRRLICHT_INC_DIR} /usr/X11R6/include)

	set(IRRKLANG_LIB_DIR ../irrKlang-64bit-1.6.0/bin/linux-gcc-64)

	FIND_PACKAGE(X11)
	FIND_PACKAGE(GLUT)
	FIND_PACKAGE(ZLIB)
elseif(WIN32)
	set(IRRLICHT_LIB_DIR ../irrlicht-1.8.4/lib/Win32-visualstudio ../irrKlang-64bit-1.6.0/lib/Winx64-visualStudio)
elseif(WIN64)
	set(IRRLICHT_LIB_DIR ../irrlicht-1.8.4/lib/Win64-visualstudio ../irrKlang-64bit-1.6.0/lib/Winx64-visualStudio)
endif()

include_directories(${INDIE_INC_DIR})

# utilise -isytem au lieux de -I ,ce qui enleve les flags sur les includes
include_directories(SYSTEM
  ${IRRLICHT_INC_DIR}
  ${IRRKLANG_INC_DIR})

link_directories(
  ${IRRLICHT_LIB_DIR}
  ${IRRKLANG_LIB_DIR})

add_executable( ${INDIE_BIN_NAME}
				${INDIE_SRC} )

if(UNIX)
	target_link_libraries(${INDIE_BIN_NAME} Irrlicht GL Xxf86vm Xext X11 Xcursor IrrKlang ikpFlac ikpMP3)
endif()
