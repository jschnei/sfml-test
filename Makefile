all: main

main: main.o
	g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c main.cpp
	
keyboard: keyboard.o
	g++ keyboard.o -o keyboard -lsfml-graphics -lsfml-window -lsfml-system

keyboard.o: keyboard.cpp
	g++ -c keyboard.cpp
	
keyserver: keyserver.o
	g++ keyserver.o -o keyserver -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network
	
keyserver.o: keyserver.cpp
	g++ -c keyserver.cpp	

keyclient: keyclient.o
	g++ keyclient.o -o keyclient -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network
	
keyclient.o: keyclient.cpp
	g++ -c keyclient.cpp	
	
receiver: receiver.o
	g++ receiver.o -o receiver -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network
	
receiver.o: receiver.cpp
	g++ -c receiver.cpp
	
sender: sender.o
	g++ sender.o -o sender -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network
	
sender.o: sender.cpp
	g++ -c sender.cpp
	
server: server.o
	g++ server.o -o server -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network
	
server.o: server.cpp
	g++ -c server.cpp	

client: client.o
	g++ client.o -o client -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network
	
client.o: client.cpp
	g++ -c client.cpp	

