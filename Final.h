#pragma once
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
enum class Estado_Final {
	play,
	end
};

class Final{
private:
	sf::Texture _sp_fondo[11];
	sf::Sprite  _fondo;
	std::string _path;
	Estado_Final _estado;
	int _numero_de_fondo;
public:
	Final();
	~Final() {};
	void cargar_textura(int);
	void cmd();
	void update();
	Estado_Final get_estado();
	sf::Sprite& get_draw_fondo();
};

