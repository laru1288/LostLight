#include "Obstaculos.h"

Obstaculos::Obstaculos(){
	
	aux1={ 45,140 };
	aux2 = { 45,49 };
	aux3 = { 625,140 };
	
	for (int i = 0; i < 20; i++) {
		if (i <= 11) { 
			rectangulo[i].setSize(sf::Vector2f(100, 100));
			rectangulo[i].setPosition((sf::Vector2f)aux1);
			if(i==2 || i==5 || i==8 || i==11) aux1.x += 145;
			aux1.y += 145;
			if (i == 2 || i == 5 || i == 8 || i == 11) aux1.y = 140;
		}
		if (i == 12) { 
			rectangulo[i].setSize(sf::Vector2f(149, 51));
			rectangulo[i].setPosition(625, 49);
		}
		if (i > 12 && i < 16) {
			rectangulo[i].setSize(sf::Vector2f(149, 100));
			rectangulo[i].setPosition((sf::Vector2f)aux3);
			aux3.y += 145;

		}
		if (i > 15) { 
			rectangulo[i].setSize(sf::Vector2f(100, 51)); 
			rectangulo[i].setPosition((sf::Vector2f)aux2);
			aux2.x += 145;
		}
		rectangulo[i].setFillColor(sf::Color::Transparent);	

	}
}

void Obstaculos::cmd(){
	
}


sf::RectangleShape *Obstaculos::get_draw(){
	return rectangulo;
}
