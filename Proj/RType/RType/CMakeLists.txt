cmake_minimum_required(VERSION 2.8)
project(RType)

if(WIN32)
	include_directories(../client/SFML-2.1/include)
else(WIN32)
	include_directories(../client/SFML-2.1-Unix/include)
	link_directories(${CMAKE_BINARY_DIR}/client/SFML-2.1-Unix/lib)
endif(WIN32)

add_executable (Server
	Bullet.cpp
	IMutex.h
	UnixCondVar.cpp
	Bullet.h
	IOBuff.h
	UnixCondVar.h
	Caller.hpp
	IThread.h
	UnixMutex.cpp
	CircularBuffer.h
	Mutex.h
	UnixMutex.h
	Client.cpp
	Player.cpp
	UnixThread.cpp
	Client.h
	Player.h
	UnixThread.h
	Clock.cpp
	Vector2.hpp
	Clock.h
	Wave.cpp
	CondVar.h
	RTypeServer.cpp
	Wave.h
	RTypeServer.h
	WinCondVar.cpp
	Element.cpp
	Room.cpp
	WinCondVar.h
	Element.h
	Room.h
	WinMutex.cpp
	Ennemy.cpp
	ServerCommunication.cpp
	WinMutex.h
	Ennemy.h
	ServerCommunication.h
	WinThread.cpp
	Event.cpp
	Singleton.h
	WinThread.h
	Event.h
	Socket.h
	main.cpp
	Game.cpp
	SocketPool.cpp
	rtype_common.h
	Game.h
	SocketPool.h
	ICondVar.h
	Thread.h
	WinTCPSocketClient.cpp
	WinTCPSocketClient.h
	WinTCPSocketServer.cpp
	WinTCPSocketServer.h
	Wall.cpp
	Wall.h
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
	UnixTCPSocketServer.cpp
	UnixTCPSocketServer.h
	RType/UDPSocketClient.h
	RType/UDPSocketServer.h
	RType/UnixUDPSocketClient.cpp
	RType/UnixUDPSocketClient.h
	RType/UnixUDPSocketServer.cpp
	RType/UnixUDPSocketServer.h
	)

add_executable (Client
	../client/ClientCommunication.h
	../client/ClientCommunication.cpp
	../client/Packet.hpp
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

find_package (Threads REQUIRED)

target_link_libraries (Server
	${CMAKE_THREAD_LIBS_INIT}
	)

if(WIN32)
	target_link_libraries(Server Ws2_32.lib)
else(WIN32)
	target_link_libraries(Client sfml-graphics sfml-system sfml-window GLEW)
endif(WIN32)
