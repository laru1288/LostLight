#include "Final.h"
Final::Final() {
	_numero_de_fondo = 0;
	cargar_textura(11);
	_estado = Estado_Final::play;
}

void Final::cargar_textura(int num) {
	for (int i = 0; i < num; i++) {
		_path = "imagenes/Final/" + std::to_string(i) + ".jpg";
		_sp_fondo[i].loadFromFile(_path);

	}
}

void Final::cmd() {
	_numero_de_fondo++;
	if (_numero_de_fondo == 12) _estado = Estado_Final::end;
}

void Final::update() {
	_fondo.setTexture(_sp_fondo[_numero_de_fondo]);
}

Estado_Final Final::get_estado() {

	return _estado;
}

sf::Sprite& Final::get_draw_fondo() {
	return _fondo;
}
