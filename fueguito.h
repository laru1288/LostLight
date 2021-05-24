#pragma once
#include <SFML/Graphics.hpp>
#define gravedad 9.8;

enum class  Estado_Fueguito {
	caida,
	quieto

};

class Fueguito
{
private:
	sf::Texture _textura;
	sf::Sprite  _fueguito;
	Estado_Fueguito _estado;
	float velocidad_caida;
	float posicion_x;
	float limite;
public:
	Fueguito();
	void update();
	void set_position_x();
	void cambiar_estado(Estado_Fueguito);
	void cmd();
	sf::Sprite& get_draw_Fueguito();
};
