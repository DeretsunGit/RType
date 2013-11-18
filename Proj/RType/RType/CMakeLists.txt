cmake_minimum_required(VERSION 2.8)
project(RType)

macro(set_option var default type docstring)
    if(NOT DEFINED ${var})
        set(${var} ${default})
    endif()
    set(${var} ${${var}} CACHE ${type} ${docstring} FORCE)
endmacro()

set_option(SFML_PATH "${CMAKE_BINARY_DIR}/SFML" STRING "The path to the SFML lib")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin/")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin/")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/lib/")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/lib/")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/lib/")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/lib/")

include_directories(${SFML_PATH}/include)
link_directories(${SFML_PATH}/lib)
link_directories("${CMAKE_BINRAY_DIR}/lib")
add_definitions(-DSFML_STATIC)
link_directories(${CMAKE_BINARY_DIR})

set_option(CMAKE_BUILD_TYPE "Debug" STRING "Type of build (Debug or Release)")

if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
	set(SFML_LIBS sfml-graphics-s-d sfml-window-s-d sfml-system-s-d)
else("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
	set(SFML_LIBS sfml-graphics-s sfml-window-s sfml-system-s)
endif("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")

if(WIN32)
	set(CompilerFlags
			CMAKE_CXX_FLAGS
			CMAKE_CXX_FLAGS_DEBUG
			CMAKE_CXX_FLAGS_RELEASE
			CMAKE_C_FLAGS
			CMAKE_C_FLAGS_DEBUG
			CMAKE_C_FLAGS_RELEASE
			)
	foreach(CompilerFlag ${CompilerFlags})
	  string(REPLACE "/MD" "/MT" ${CompilerFlag} "${${CompilerFlag}}")
	endforeach()
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
	link_directories(${SFML_PATH}/extlibs/libs-msvc/x64)
	if(CMAKE_SIZEOF_VOID_P EQUAL 8)
#		include_directories(../client/SFML-2.1-vc10-x64/include)
#		link_directories(${CMAKE_BINARY_DIR}/client/SFML-2.1-vc10-x64/lib)
	else(CMAKE_SIZEOF_VOID_P EQUAL 8)
#		include_directories(../client/SFML-2.1/include)
#		link_directories(${CMAKE_BINARY_DIR}/client/SFML-2.1/lib)
	endif(CMAKE_SIZEOF_VOID_P EQUAL 8)
else(WIN32)
#	include_directories(${CMAKE_BINARY_DIR}/client/SFML-2.1-Unix/include)
#	link_directories(${CMAKE_BINARY_DIR}/client/SFML-2.1-Unix/lib)
endif(WIN32)

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_BINARY_DIR}/client)
include_directories(${CMAKE_BINARY_DIR}/Abstract)

add_library(Abstract
	${CMAKE_BINARY_DIR}/Abstract/DynLib.h
	${CMAKE_BINARY_DIR}/Abstract/IDynLib.h
	${CMAKE_BINARY_DIR}/Abstract/UnixDynLib.cpp
	${CMAKE_BINARY_DIR}/Abstract/UnixDynLib.h
	${CMAKE_BINARY_DIR}/Abstract/WinDynLib.cpp
	${CMAKE_BINARY_DIR}/Abstract/WinDynLib.h
	${CMAKE_BINARY_DIR}/Abstract/ThreadPool.h
	${CMAKE_BINARY_DIR}/Abstract/ThreadPool.cpp
	${CMAKE_BINARY_DIR}/Abstract/SocketStack.h
	${CMAKE_BINARY_DIR}/Abstract/Hash.h
	${CMAKE_BINARY_DIR}/Abstract/MD5.h
	${CMAKE_BINARY_DIR}/Abstract/MD5.cpp
	${CMAKE_BINARY_DIR}/Abstract/UDPBindedClient.cpp
	${CMAKE_BINARY_DIR}/Abstract/SystemException.h
	${CMAKE_BINARY_DIR}/Abstract/WinSysException.h
	${CMAKE_BINARY_DIR}/Abstract/UnixSysException.h
	${CMAKE_BINARY_DIR}/Abstract/UnixHostException.h
	Caller.hpp
	IReadableSocket.h
	IMutex.h
	UnixCondVar.cpp
	UnixCondVar.h
	IThread.h
	UnixMutex.cpp
	IOBuff.h
	CircularBuffer.h
	Mutex.h
	UnixMutex.h
	UnixThread.cpp
	UnixThread.h
	CondVar.h
	WinCondVar.cpp
	WinCondVar.h
	WinMutex.cpp
	WinMutex.h
	WinThread.cpp
	WinThread.h
	Singleton.h
	Packet.hpp
	Socket.h
	SocketPool.cpp
	SocketPool.h
	Thread.h
	WinTCPSocketClient.cpp
	WinTCPSocketClient.h
	WinTCPSocketServer.cpp
	WinTCPSocketServer.h
	ICondVar.h
	ITCPSocketClient.h
	ITCPSocketServer.h
	UnixTCPSocketClient.h
	UnixTCPSocketClient.cpp
	WinUDPSocketServer.h
	WinUDPSocketClient.h
	WinUDPSocketClient.cpp
	WinUDPSocketServer.cpp
	IUDPSocketServer.h
	IUDPSocketClient.h
	TCPSocketServer.h
	TCPSocketClient.h
	UnixTCPSocketServer.cpp
	UnixTCPSocketServer.h
	UDPSocketClient.h
	UDPSocketServer.h
	UnixUDPSocketClient.cpp
	UnixUDPSocketClient.h
	UnixUDPSocketServer.cpp
	UnixUDPSocketServer.h
	)

add_executable (Server
	${CMAKE_BINARY_DIR}/Abstract/SocketStack.h
	Debug.h
	IReadableSocket.h
	CondVar.h
	Packet.hpp
	Mutex.h
	Thread.h
	TCPSocketServer.h
	TCPSocketClient.h
	UDPSocketClient.h
	UDPSocketServer.h
	Bullet.cpp
	Bullet.h
	Client.cpp
	Player.cpp
	Client.h
	Player.h
	Clock.cpp
	Vector2.hpp
	Clock.h
	Wave.cpp
	RTypeServer.cpp
	Wave.h
	RTypeServer.h
	Element.cpp
	Room.cpp
	Element.h
	Room.h
	Ennemy.cpp
	ServerCommunication.hpp
	ServerCommunication.cpp
	Ennemy.h
	Event.cpp
	Event.h
	main.cpp
	Game.cpp
	rtype_common.h
	Game.h
	Wall.cpp
	Wall.h
	Script.h
	Script.cpp
	Randomisation.h
	Randomisation.cpp
	ESprites.h
	)

add_executable (Client
	${CMAKE_BINARY_DIR}/client/Background.h
	${CMAKE_BINARY_DIR}/client/ClientCommunication.hpp
	${CMAKE_BINARY_DIR}/client/Drawable.h
	${CMAKE_BINARY_DIR}/client/GameLoop.h
	${CMAKE_BINARY_DIR}/client/Menu.h
	${CMAKE_BINARY_DIR}/client/PlayMenu.h
	${CMAKE_BINARY_DIR}/client/MainMenu.h
	${CMAKE_BINARY_DIR}/client/Background.h
	${CMAKE_BINARY_DIR}/client/SpriteManager.h
	Packet.hpp
	${CMAKE_BINARY_DIR}/client/PlayerShip.h
	${CMAKE_BINARY_DIR}/client/SpriteManager.h
	${CMAKE_BINARY_DIR}/client/Background.cpp
	${CMAKE_BINARY_DIR}/client/ClientCommunication.cpp
	${CMAKE_BINARY_DIR}/client/Drawable.cpp
	${CMAKE_BINARY_DIR}/client/GameLoop.cpp
	${CMAKE_BINARY_DIR}/client/Menu.cpp
	${CMAKE_BINARY_DIR}/client/MainMenu.cpp
	${CMAKE_BINARY_DIR}/client/PlayMenu.cpp
	${CMAKE_BINARY_DIR}/client/Background.cpp
	${CMAKE_BINARY_DIR}/client/PlayerShip.cpp
	${CMAKE_BINARY_DIR}/client/SpriteManager.cpp
	${CMAKE_BINARY_DIR}/client/main.cpp
	${CMAKE_BINARY_DIR}/client/BackGameButton.h
	${CMAKE_BINARY_DIR}/client/BackGameButton.cpp
	${CMAKE_BINARY_DIR}/client/Button.h
	${CMAKE_BINARY_DIR}/client/Button.cpp
	${CMAKE_BINARY_DIR}/client/BackMainButton.h
	${CMAKE_BINARY_DIR}/client/BackMainButton.cpp
	${CMAKE_BINARY_DIR}/client/CreditsButton.h
	${CMAKE_BINARY_DIR}/client/CreditsButton.cpp
	${CMAKE_BINARY_DIR}/client/PlayButton.h
	${CMAKE_BINARY_DIR}/client/PlayButton.cpp
	${CMAKE_BINARY_DIR}/client/QuitButton.h
	${CMAKE_BINARY_DIR}/client/QuitButton.cpp
	${CMAKE_BINARY_DIR}/client/RoomButton.h
	${CMAKE_BINARY_DIR}/client/RoomButton.cpp
	${CMAKE_BINARY_DIR}/client/SettingsButton.h
	${CMAKE_BINARY_DIR}/client/SettingsButton.cpp
	)

add_executable (DebugClient
	${CMAKE_BINARY_DIR}/Abstract/SocketStack.h
	${CMAKE_BINARY_DIR}/client_debug/main.cpp
	${CMAKE_BINARY_DIR}/client_debug/Debugger.h
	${CMAKE_BINARY_DIR}/client_debug/Debugger.cpp
	${CMAKE_BINARY_DIR}/client/ClientCommunication.hpp
	${CMAKE_BINARY_DIR}/client/ClientCommunication.cpp
	rtype_common.h
	Opcodes.h
	Thread.h
	TCPSocketClient.h
	UDPSocketClient.h
	)

find_package (Threads REQUIRED)

target_link_libraries (Abstract
	${CMAKE_THREAD_LIBS_INIT}
	)

target_link_libraries (Client
	Abstract
	${SFML_LIBS}
	jpeg
	freetype
	)

target_link_libraries (Server
	${CMAKE_THREAD_LIBS_INIT}
	Abstract
	)
target_link_libraries (DebugClient
	${CMAKE_THREAD_LIBS_INIT}
	Abstract
	${SFML_LIBS}
	jpeg
	)

if(WIN32)
	target_link_libraries(Abstract Ws2_32.lib)
	target_link_libraries(Server Ws2_32.lib)
	target_link_libraries(DebugClient opengl32 glew Winmm.lib)
	target_link_libraries(Client opengl32 glew Winmm.lib)
#	target_link_libraries(Client sfml-graphics sfml-system sfml-window)
#	target_link_libraries(DebugClient sfml-graphics sfml-system sfml-window)
else(WIN32)
	target_link_libraries(Abstract
		dl
		crypto)
	target_link_libraries(Client GL X11 GLEW rt Xrandr)
	target_link_libraries(DebugClient GL X11 GLEW rt Xrandr)
#	target_link_libraries(Client
#		sfml-graphics
#		sfml-system
#		sfml-window
#		GLEW
#		dl)
endif(WIN32)
