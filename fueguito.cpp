#include "Fueguito.h"

Fueguito::Fueguito() {
	_textura.loadFromFile("imagenes/Fueguito.png");
	_fueguito.setTexture(_textura);
	_fueguito.setScale(0.05, 0.05);
	limite=816- _fueguito.getTexture()->getSize().x;
	velocidad_caida = -5;
	set_position_x();
	_fueguito.setPosition(posicion_x, -100);
	_estado = Estado_Fueguito::quieto;
}

sf::Sprite& Fueguito::get_draw_Fueguito() {
	return _fueguito;
}

void Fueguito::update(){
	if(_estado==Estado_Fueguito::caida){
	_fueguito.setPosition(posicion_x, velocidad_caida);
	}
}

void Fueguito::set_position_x() {

	posicion_x =  rand() % 601;
}

void Fueguito::cambiar_estado(Estado_Fueguito estado){

	_estado = estado;
}

void Fueguito::cmd(){
	if (_estado == Estado_Fueguito::caida) {
		velocidad_caida = _fueguito.getPosition().y + 5;
	}
}