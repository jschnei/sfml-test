#include <SFML/Network.hpp>

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

typedef pair<sf::IpAddress, unsigned short> iaddr;

int main()
{
    sf::UdpSocket socket;
    unsigned short def_port = 54000;
    // bind the socket to a port

    if (socket.bind(54000) != sf::Socket::Done)
    {
        // error...
        cout << "error binding socket to port" << endl;
    }


    map <string, vector<iaddr> > users;
    map <iaddr, string> games;

    sf::Packet packet;
    sf::IpAddress sender;
    unsigned short port;

    while(true){
        socket.receive(packet, sender, port);
        
        string cmd;
        if(packet >> cmd){
            if(cmd == "join"){
                string gname;
                packet >> gname;
                
                iaddr send_addr = iaddr(sender, port);
                users[gname].push_back(send_addr);
                games[send_addr] = gname;
                cout << sender << ":" << port << " joined game " << gname << endl;
            }else if(cmd == "send"){
                string msg;
                packet >> msg;
                
                cout << "received message " << msg << " from sender " << sender << ":" << port << endl;
                iaddr send_addr = iaddr(sender, port);
                
                string gname = games[send_addr];
                for(int u=0;u<users[gname].size();u++){
                    if(users[gname][u]!=send_addr){
                        sf::Packet pack_out;
                        pack_out << msg;
                        
                        socket.send(pack_out, users[gname][u].first, users[gname][u].second);
                    }
                }
            }
        }
    }

    return 0;
}