#pragma once
#include <SFML/Graphics.hpp>

class Barra
{
	int cant_fueguitos;
	int aux_frame;
private:
	sf::Texture _textura;
	sf::Sprite  _barra;
	 
public:
	Barra();
	void cmd();
	void setvida(int num);
	int getvida();
	void setframe();
	sf::Sprite& get_draw();

};

