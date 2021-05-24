#pragma once
#include <SFML/Graphics.hpp>
class Obstaculos{
private:
	sf::RectangleShape rectangulo[20];
	sf::Vector2i aux1, aux2, aux3;
	
public:
	Obstaculos();
	void cmd();
	sf::RectangleShape *get_draw();

};

