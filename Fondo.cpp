#include "Fondo.h"

Fondo::Fondo(){
	_tex_map.loadFromFile("imagenes/Map/Map 6.jpg");
	_spri_map1.setTexture(_tex_map);
	_spri_map2.setTexture(_tex_map);
	_spri_map3.setTexture(_tex_map);
	_frame_origen = { 0,0 };
	_frame_limite = { 0,0 };
	_estado = Estado_Fondo::oscuro;
	
}

void Fondo::cmd(){
	switch (_estado)
	{
	case Estado_Fondo::oscuro:
		_frame_origen = { 0,0 };
		_frame_limite = { 0,0 };
		break;
	case Estado_Fondo::primera_luz:
		_frame_origen = { 600,312 };
		_frame_limite = { 216,312 };
		_spri_map1.setPosition((sf::Vector2f)_frame_origen);
		break;
	case Estado_Fondo::segunda_luz:
		_frame_origen = { 600,0 };
		_frame_limite = { 216,624 };
		_spri_map1.setPosition((sf::Vector2f)_frame_origen);
		break;
	case Estado_Fondo::tercera_luz:
		_frame_origen = { 300,312 };
		_frame_limite = { 300,624 };
		_spri_map2.setPosition((sf::Vector2f)_frame_origen);
		break;
	case Estado_Fondo::cuarta_luz:
		_frame_origen = { 300,0 };
		_frame_limite = { 300,624 };
		_spri_map2.setPosition((sf::Vector2f)_frame_origen);
		break;
	case Estado_Fondo::quinta_luz:
		_frame_origen = { 0,312 };
		_frame_limite = { 300,624 };
		_spri_map3.setPosition((sf::Vector2f)_frame_origen);
		break;
	case Estado_Fondo::ultima_luz:
		_frame_origen = { 0,0 };
		_frame_limite = { 300,624 };
		_spri_map3.setPosition((sf::Vector2f)_frame_origen);
		break;
	default:
		break;
	}

}

void Fondo::update(){
	setframe();
}

void Fondo::setframe(){

	sf::IntRect posicion(_frame_origen, _frame_limite);

	if(_estado==Estado_Fondo::oscuro || _estado == Estado_Fondo::primera_luz || _estado == Estado_Fondo::segunda_luz)_spri_map1.setTextureRect(posicion);

	if (_estado == Estado_Fondo::oscuro || _estado == Estado_Fondo::tercera_luz || _estado == Estado_Fondo::cuarta_luz)_spri_map2.setTextureRect(posicion);

	if (_estado == Estado_Fondo::oscuro || _estado == Estado_Fondo::quinta_luz || _estado == Estado_Fondo::ultima_luz)_spri_map3.setTextureRect(posicion);
}

sf::Sprite& Fondo::get_draw1(){	return _spri_map1; }

sf::Sprite& Fondo::get_draw2() { return _spri_map2; }

sf::Sprite& Fondo::get_draw3() { return _spri_map3; }

void Fondo::set_estado(Estado_Fondo estado){

	_estado = estado;

}

Estado_Fondo Fondo::get_estado(){

	return _estado;
}

