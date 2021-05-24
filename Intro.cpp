#include "Intro.h"

Intro::Intro(){
	_numero_de_fondo =0;
	cargar_textura(14);
	
	_estado = Estado_Intro::play;
}

void Intro::cargar_textura(int num){
	for (int i = 0; i <num; i++) {
		_path = "imagenes/Intro/" + std::to_string(i) + ".jpg";
		_sp_fondo[i].loadFromFile(_path);
				
	}
}

void Intro::cmd(){
	_numero_de_fondo++;
	if (_numero_de_fondo == 15) _estado = Estado_Intro::end;

}

void Intro::update(){
	_fondo.setTexture(_sp_fondo[_numero_de_fondo]);
	
}

Estado_Intro Intro::get_estado(){

	return _estado;
}

sf::Sprite& Intro::get_draw_fondo(){
	return _fondo;
}

