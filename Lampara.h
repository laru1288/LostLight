#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
class Lampara {
private:
	sf::Texture _textura;
	sf::Sprite  _lampara;
public:
	Lampara();

	void update();
	void set_position(int);
	void cmd();
	sf::Sprite& get_draw_Lampara();
};

