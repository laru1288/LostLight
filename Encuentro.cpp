#include "Encuentro.h"

Encuentro::Encuentro() {
	_numero_de_fondo = 0;
	cargar_textura(5);
	_estado = Estado_Encuentro::play;
}

void Encuentro::cargar_textura(int num) {
	for (int i = 0; i < num; i++) {
		_path = "imagenes/Encuentro/" + std::to_string(i) + ".png";
		_sp_fondo[i].loadFromFile(_path);
	}
}

void Encuentro::cmd() {
	_numero_de_fondo++;
	if (_numero_de_fondo == 6) {
		_estado = Estado_Encuentro::end;
	}
	}

void Encuentro::update() {
	_fondo.setTexture(_sp_fondo[_numero_de_fondo]);
}

void Encuentro::reset_encuentro(){
	_estado = Estado_Encuentro::play;
	_numero_de_fondo = 0;
}

Estado_Encuentro Encuentro::get_estado() {

	return _estado;
}

sf::Sprite& Encuentro::get_draw_fondo() {
	return _fondo;
}

void Encuentro::set_estado(Estado_Encuentro est){
	_estado = est;
}


