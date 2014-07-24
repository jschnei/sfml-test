#include <SFML/Network.hpp>

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
  
  // set the socket to be non-blocking
  socket.setBlocking(false);
  
  // bind the socket to a port
  if (socket.bind(port) != sf::Socket::Done)
  {
      // error...
      cout << "error binding socket to port" << endl;
  }
  
  // UDP socket:
  
  /*
  string ip;
  cout << "Enter IP address of recipient:" << endl;
  cin >> ip;
  sf::IpAddress recipient = ip;
  unsigned short port = 54000;*/
  
  cout << "Enter game to join: " << endl;
  
  sf::Packet packet;
  string msg;
  cin >> msg;
  packet << "join" << msg;
  
  socket.send(packet, def_ip, def_port);
  packet.clear();
  
  cout << "Enter messages:" << endl;
  
  sf::IpAddress inc_ip;
  unsigned short inc_port;
  
  while(true){
    cin >> msg;
    packet << "send" << msg;

    socket.send(packet, def_ip, def_port);
    packet.clear();

    
    if(socket.receive(packet, inc_ip, inc_port) != sf::Socket::NotReady){
        if(packet >> msg){
            cout << msg << endl;
        }
    }
  }
  
  return 0;
}