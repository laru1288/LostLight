#include "Mapa.h"

Mapa::Mapa(){
	_mapa = 0;
	cargar_textura(7);
	_spri_map.setTexture(_tex_map[_mapa]);
	_estado = Estado_Mapa::oscuro;
}

void Mapa::cmd(sf::Vector2f posicion){

	switch (_estado)
	{
	case Estado_Mapa::mostar_entero:
		_frame_origen = { 0,0 };
		_frame_limite = { 720, 405 };
		break;
	case Estado_Mapa::oscuro:
		_spri_map.setPosition(posicion.x - 10, posicion.y - 15);
		_frame_origen = {(int) posicion.x-10,(int)posicion.y-15 };
		_frame_limite = { 40,60 };

		break;
	default:
		break;
	}
	
}

void Mapa::update(int numero){
	setframe();
}

void Mapa::setframe(){

	sf::IntRect posicion(_frame_origen, _frame_limite);

	_spri_map.setTextureRect(posicion);
}

sf::Sprite& Mapa::get_draw(){

	return _spri_map;
}

void Mapa::set_estado(Estado_Mapa estado){

	_estado = estado;

}

Estado_Mapa Mapa::get_estado(){

	return _estado;
}

void Mapa::cargar_textura(int num) {
	for (int i = 0; i < num; i++) {
		_path = "imagenes/Map/Map " + std::to_string(i) + ".jpg";
		_tex_map[i].loadFromFile(_path);

	}
}

void Mapa::cambiar_mapa(){
	_mapa++;
	_spri_map.setTexture(_tex_map[_mapa]);
	if (_mapa == 6)_mapa = 0;
}

