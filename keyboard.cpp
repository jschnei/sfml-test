#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "Keyboard test!");
    window.setFramerateLimit(60); 
    
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Clock clock;

    while (window.isOpen())
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            cout << "LEFT" << endl;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            cout << "RIGHT" << endl;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            cout << "UP" << endl;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            cout << "DOWN" << endl;
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
        
        float fps = 1.f / (clock.getElapsedTime().asSeconds());
        cout << fps << endl;
        clock.restart();
    }

    return 0;
}