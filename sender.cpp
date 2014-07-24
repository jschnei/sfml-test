#include <SFML/Network.hpp>

#include <iostream>
#include <string>

using namespace std;

int main()
{
  sf::UdpSocket socket;
  // bind the socket to a port
  if (socket.bind(54001) != sf::Socket::Done)
  {
      // error...
      cout << "error binding socket to port" << endl;
  }
   
  // UDP socket:  
  string ip;
  cout << "Enter IP address of recipient:" << endl;
  cin >> ip;
  sf::IpAddress recipient = ip;
  unsigned short port = 54000;
  
  cout << "Enter messages:" << endl;
  
  while(true){
    sf::Packet packet;
    string s;
    cin >> s;
    packet << s;

    socket.send(packet, recipient, port);
  }
  
  return 0;
}