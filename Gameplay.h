#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Vela.h"
#include "Mapa.h"
#include "puzzle.h"
#include "Lampara.h"
#include "Fondo.h"
#include "Faro.h"
#include "Intro.h"
#include "Interfaz.h"
#include "Final.h"
#include "Encuentro.h"
#include "Obstaculos.h"
#include "Puzzle2.h"
#include "Puzzle2a.h"
#include "Puzzle2b.h"
#include "Slider_puzzle.h"
#include<iostream>

enum class Estado_Gameplay{
	Interfaz,
	Intro,
	Juego,
	Escena_Final,
	Encuentro,
	puzzle,
	puzzle2,
	slider_puzzle
};

class gameplay{
private:
	//Time 5;
	Estado_Gameplay _estado;
	Interfaz _menu;
	Intro _intro;
	Lampara* _lamparita;
	Vela _velita;
	Fondo _fondo;
	Mapa _map;
	Faro* _faro;
	Final _final;
	Encuentro _encuentro;
	Obstaculos _rec;
	puzzle* _puzzle;
	bool lamparita,lampara_creada, faro,farocreado, encuentro;
	Puzzle2* _puzzle2;
	Slider_puzzle* _slider_puzzle;
	int _num_faro;


public:
	gameplay();	
	void update(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	bool collision(sf::Sprite&, sf::Sprite&);
	void cmd();
	void colision_paredes();
	int numero;
	void create_puzzle2(int);
	
};

