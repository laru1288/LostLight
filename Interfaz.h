#pragma once
#include <SFML/Graphics.hpp>
#define maxtext 4

enum opcion_menu {
	Jugar,
	ComoJugar,
	Integrantes,
	Salir
};

class Interfaz{

private:
	sf::Texture _texturafondo,_tutorial,_integrantes ;
	sf::Sprite _spfondo;
	sf::Font _fuente;
	sf::Text *_text;
	int _opcion;
	bool _opcion_elegida;
	opcion_menu _opcion_m;
public:
	void cargar_textura(std::string);
	void cargar_fuente(std::string);
	Interfaz();
	opcion_menu get_opcion();
	bool get_opcion_elegida();
	void set_opcion_elegida(bool);
	void cmd();
	void update();
	void reset_sprite();
	sf::Sprite& getdrawfondo();
	sf::Text* getdrawtextos();


};

