#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>

using namespace std;

int main()
{
    sf::UdpSocket socket;
    sf::IpAddress def_ip = "54.210.36.90";
    unsigned short def_port = 54000;
    unsigned short port = def_port;

    cout << "Choose different port (default 54000)? (y/n)" << endl;
    string opt;
    cin >> opt;
    if(opt=="y"){
        cout << "Enter new port number: " << endl;
        cin >> port;
    }

    cout << "Choose different server ip (default 54.210.36.90)? (y/n)" << endl;
    cin >> opt;
    if(opt=="y"){
        cout << "Enter new port number: " << endl;
        cin >> def_ip;
    }

    // set the socket to be non-blocking
    socket.setBlocking(false);

    // bind the socket to a port
    if (socket.bind(port) != sf::Socket::Done)
    {
        cout << "Error binding socket to port (is another copy of this program already running?)" << endl;
    }

    cout << "Enter game to join: " << endl;

    sf::Packet packet;
    string msg;
    cin >> msg;
    packet << "join" << msg;

    socket.send(packet, def_ip, def_port);
    packet.clear();
  
    sf::RenderWindow window(sf::VideoMode(200, 200), "Keyboard test!");
    window.setFramerateLimit(60); 

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    vector<sf::Keyboard::Key> keys;
    keys.push_back(sf::Keyboard::Left);
    keys.push_back(sf::Keyboard::Right);
    keys.push_back(sf::Keyboard::Up);
    keys.push_back(sf::Keyboard::Down);
//    sf::Clock clock;
    
    sf::IpAddress inc_ip;
    unsigned short inc_port;

    while (window.isOpen())
    {
        int keymask = 0;
        for(int i=0;i<keys.size();i++){
            if(sf::Keyboard::isKeyPressed(keys[i])){
                keymask += (1<<i);
            }
        }
        
        packet << "send";
        packet << keymask;
        
        socket.send(packet, def_ip, def_port);
        packet.clear();

        if(socket.receive(packet, inc_ip, inc_port) != sf::Socket::NotReady){
            int rkmask;
            if(packet >> rkmask){
                string ip;
                unsigned short port;
                packet >> ip >> port;
                cout << ip << ":" << port << ": " << rkmask << endl;
            }
        }
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
        
//         float fps = 1.f / (clock.getElapsedTime().asSeconds());
//         cout << fps << endl;
//         clock.restart();
    }



    return 0;
}