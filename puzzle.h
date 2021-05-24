#pragma once
#include <SFML/Graphics.hpp>
#include "Faro.h"
#include "Fueguito.h"
#include "Barra.h"



class puzzle{
	unsigned int _tics;
private:
	Faro _faro;
	Fueguito _fueguito[30];
	Barra _barrita;
	sf::Texture _tex_fondo;
	sf::Texture _texture[2];
	sf::Sprite _sprite;
	sf::Sprite _sp_fondo;
	int _cantidad_fuego,x;
	bool _fueguitoscreado[30];
	bool _fin;
	bool _reset;
	

public:
	puzzle();
	void cmd();
	void update();
	sf::Sprite& get_draw_faro();
	Fueguito* get_draw_fueguito();
	sf::Sprite& get_draw_barrita();
	sf::Sprite& get_draw_fondo();
	sf::Sprite& get_draw_sprite();
	void collision();
	void crear_fueguitos();
	bool get_fin();
	bool reset();
	void cambiar_sprite(int);




};

