#pragma once
#include <SFML/Graphics.hpp>
#define WIDTH 816 
#define HEIGHT 624

enum class Estado_Faro{

	quieto,
	movimiento

};

class Faro{
private:
	Estado_Faro _estado;
	sf::Texture _textura1, _textura2;
	sf::Sprite  _Faro;
	bool prendido;
	sf::Vector2i _velocidad;
public:
	Faro();
	~Faro();
	void set_faro(bool);
	void set_tex_sprite();
	void set_position(int);
	void update();
	void cmd();
	void cambiar_estado(Estado_Faro);
	sf::Sprite& get_draw_Faro();
};

