#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include"gameplay.h"
#include<SFML/Audio.hpp>
int main() {

    sf::RenderWindow window(sf::VideoMode(816, 624), "Lost Light");
    srand(time(NULL));
    window.setFramerateLimit(60);
    float deltatime = 0.0f;
    sf::Clock clock;
    sf::SoundBuffer _buffer;
    sf::Sound _sound;
    sf::Texture textura;
    sf::Sprite sprite;
    _buffer.loadFromFile("imagenes/Music.ogg");
    _sound.setBuffer(_buffer);
   gameplay gp;
    
  

    _sound.play();
    while (window.isOpen()) {
        deltatime = clock.getElapsedTime().asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) {
            
            if (event.type == sf::Event::Closed) {
                window.close();
                exit(1);
            }

            
           gp.cmd();
           gp.update(window);
           
            window.clear();
            gp.draw(window);
            window.display();


        }

    }

    return 0;
}
