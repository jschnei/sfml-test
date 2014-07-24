all: main

main: main.o
	g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c main.cpp
	
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

