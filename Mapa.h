#pragma once
#include <SFML/Graphics.hpp>

enum class Estado_Mapa{

	mostar_entero,
	oscuro

};

class Mapa{
private:
	Estado_Mapa _estado;
	sf::Texture _tex_map[7];
	sf::Sprite _spri_map;
	sf::Vector2i _frame_origen, _frame_limite;
	std::string _path;
	int _mapa;
public:
	Mapa();
	void cmd(sf::Vector2f);
	void update(int);
	void setframe();
	void cargar_textura(int);
	void cambiar_mapa();
	sf::Sprite& get_draw();
	void set_estado(Estado_Mapa);
	Estado_Mapa get_estado();
};

