#pragma once
#include <SFML/Graphics.hpp>

enum class Estado_Fondo{

	oscuro,
	primera_luz,
	segunda_luz,
	tercera_luz,
	cuarta_luz,
	quinta_luz,
	ultima_luz

};

class Fondo{
private:
	Estado_Fondo _estado;
	sf::Texture _tex_map;
	sf::Sprite _spri_map1, _spri_map2, _spri_map3;
	sf::Vector2i _frame_origen, _frame_limite;
public:
	Fondo();
	void cmd();
	void update();
	void setframe();
	sf::Sprite& get_draw1();
	sf::Sprite& get_draw2();
	sf::Sprite& get_draw3();
	void set_estado(Estado_Fondo);
	Estado_Fondo get_estado();
};

