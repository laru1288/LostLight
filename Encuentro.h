#pragma once
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
enum class Estado_Encuentro {
	play,
	end	
};
class Encuentro{
private:
	sf::Texture _sp_fondo[5];
	sf::Sprite  _fondo;
	std::string _path;
	Estado_Encuentro _estado;
	int _numero_de_fondo;
public:
	Encuentro();
	~Encuentro() {};
	void cargar_textura(int);
	void cmd();
	void update();
	void reset_encuentro();
	Estado_Encuentro get_estado();
	sf::Sprite& get_draw_fondo();
	void set_estado(Estado_Encuentro);
};

