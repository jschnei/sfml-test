#include <SFML/Network.hpp>

#include <iostream>
#include <string>

using namespace std;

int main()
{
  sf::UdpSocket socket;
  // bind the socket to a port
  
  if (socket.bind(54000) != sf::Socket::Done)
  {
      // error...
      cout << "error binding socket to port" << endl;
  }
  
  sf::Packet packet;
  sf::IpAddress sender;
  unsigned short port;
  
  while(true){
    socket.receive(packet, sender, port);
    
    string s;
    if(packet >> s){
      cout << s << endl;
    }
  }
   
  return 0;
}