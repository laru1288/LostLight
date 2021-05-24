#pragma once
#include "Puzzle2.h"
#include <SFML/Graphics.hpp>

class Puzzle2b:public Puzzle2 {
private:
	sf::Texture _texturafondo;
	sf::Texture _texture[3];
	sf::Sprite _sprite;
	sf::Sprite _spfondo;
	sf::Font _fuente;
	sf::Text* _text;
	int _opcion;
	bool _opcion_elegida;
	respuesta _opcion_m;
	respuesta _opcion_correcta;
	bool _fin;
	bool _reset;

public:
	
	Puzzle2b();
	void cargar_textura(std::string);
	void cargar_fuente(std::string);
	respuesta get_opcion();
	bool get_opcion_elegida();
	void set_opcion_elegida(bool valor);
	void cmd();
	void update();
	void reset_sprite();
	sf::Sprite& getdrawfondo();
	sf::Text* getdrawtextos();
	bool get_fin();
	bool reset();
	void cambiar_sprite(int);
	sf::Sprite& getdrawsprite();

};

