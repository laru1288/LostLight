#include "Barra.h"

Barra::Barra() {
	_textura.loadFromFile("imagenes/barra.png");
	_barra.setTexture(_textura);
	_barra.setTextureRect(sf::IntRect(0, 0, 551, 125));
	_barra.setScale(0.5, 0.5);
	_barra.setPosition(550, 0);
	cant_fueguitos = 0;
}

sf::Sprite& Barra::get_draw() {
	return _barra;
}

void Barra::cmd() {

	if (cant_fueguitos == 0) { aux_frame = 0; }
	if (cant_fueguitos == 1) { aux_frame = 1; }
	if (cant_fueguitos == 2) { aux_frame = 2; }
	if (cant_fueguitos == 3) { aux_frame = 3; }
	if (cant_fueguitos == 4) { aux_frame = 4; }
	if (cant_fueguitos == 5) { aux_frame = 5; }
	
}


void Barra::setvida(int num) {
	cant_fueguitos = num;
}

int Barra::getvida() {
	return cant_fueguitos;
}

void Barra::setframe() {

	sf::IntRect posicion(0, aux_frame * 125, 551, 125);

	_barra.setTextureRect(posicion);
}