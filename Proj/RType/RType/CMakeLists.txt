cmake_minimum_required(VERSION 2.8)
project(RType)

if(WIN32)
	include_directories(../client/SFML-2.1/include)
	if(CMAKE_SIZEOF_VOID_P EQUAL 8)
		link_directories(${CMAKE_BINARY_DIR}/client/SFML-2.1-x64/lib)
	else(CMAKE_SIZEOF_VOID_P EQUAL 8)
		link_directories(${CMAKE_BINARY_DIR}/client/SFML-2.1/lib)
	endif(CMAKE_SIZEOF_VOID_P EQUAL 8)
else(WIN32)
	include_directories(${CMAKE_BINARY_DIR}/client/SFML-2.1-Unix/include)
	link_directories(${CMAKE_BINARY_DIR}/client/SFML-2.1-Unix/lib)
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
	)

add_executable (Client
	../client/ClientCommunication.hpp
	../client/ClientCommunication.cpp
	Packet.hpp
	../client/main.cpp
	../client/Background.h
	../client/Background.cpp
	../client/Drawable.h
	../client/Drawable.cpp
	../client/GameLoop.h
	../client/GameLoop.cpp
	../client/Menu.h
	../client/Menu.cpp
	../client/MenuManager.h
	../client/MenuManager.cpp
	../client/PlayerShip.h
	../client/PlayerShip.cpp
	../client/SpriteManager.h
	../client/SpriteManager.cpp
	)

add_executable (DebugClient
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
	)

target_link_libraries (Server
	${CMAKE_THREAD_LIBS_INIT}
	Abstract
	)
target_link_libraries (DebugClient
	${CMAKE_THREAD_LIBS_INIT}
	Abstract
	)

if(WIN32)
	target_link_libraries(Abstract Ws2_32.lib)
	target_link_libraries(Server Ws2_32.lib)
	target_link_libraries(Client sfml-graphics sfml-system sfml-window)
	target_link_libraries(DebugClient sfml-graphics sfml-system sfml-window)
else(WIN32)
	target_link_libraries(Abstract
		dl)
	target_link_libraries(Client
		sfml-graphics
		sfml-system
		sfml-window
		GLEW
		dl)
endif(WIN32)
