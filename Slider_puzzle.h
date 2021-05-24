#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Vela.h"
#include "Mapa.h"
#include "Lampara.h"
#include "Fondo.h"
#include "Faro.h"
#include "Intro.h"
#include "Interfaz.h"
#include "Final.h"
#include "Encuentro.h"
#include "Obstaculos.h"
#include<iostream>

enum Estado_slider {
	desarmado,
	armado
};

class Slider_puzzle{
private:
	int A, B, C , X , Y , PHOTO[3][3], _veri[3][3];
	bool _armado;
	sf::Texture	_P, _auxiliar, _tutorial,_textura[2] ;
	sf::Sprite  _S, _S1, _S2, _S3, _S4, _S5, _S6, _S7, _S8, _S9 , _Temp, _aux, _tuto,_sprite;
	Estado_slider _event;
	int aux, _vec[9];


public:
	Slider_puzzle();
	void numero_de_puzzle(int);
	void cargar_sprite();
	void update();
	void draw(sf::RenderWindow& window);	
	void cmd();	
	void verificacion();
	void cambiar_sprite(int);
	Estado_slider get_estado();
	sf::Sprite& get_sprite();
	sf::Sprite& get__S();
	sf::Sprite& get__S1();
	sf::Sprite& get__S2();
	sf::Sprite& get__S3();
	sf::Sprite& get__S4();
	sf::Sprite& get__S5();
	sf::Sprite& get__S6();
	sf::Sprite& get__S7();
	sf::Sprite& get__S8();
	sf::Sprite& get__S9();
	sf::Sprite& get__Temp();

	

};

