#pragma once
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

enum class Estado_Intro{
	play,
	end
};

class Intro{
private:
	sf::Texture _sp_fondo[14];
	sf::Sprite  _fondo;
	std::string _path;
	Estado_Intro _estado;
	int _numero_de_fondo;
public:
	Intro();
	~Intro() {};
	void cargar_textura(int);
	void cmd();
	void update();
	Estado_Intro get_estado();
	sf::Sprite& get_draw_fondo();


};

