#include "Vela.h"

Vela::Vela(){
	_textura.loadFromFile("imagenes/Vela/VELA.png");
	_velita.setTexture(_textura);
	_velita.setPosition(0, 0);
	_velita.setScale(0.5, 0.5);
	_estado_vela = Estado_Vela::quieto;
	_frame_actual = { 0,0 };
}

void Vela::set_frame(){	
 //origen _frame_der
//limite _frame_izq
sf::IntRect recorte(_frame_der.x * _frame_izq.x, _frame_der.y * _frame_izq.y, _frame_izq.x, _frame_izq.y);
_velita.setTextureRect(recorte);	
}

void Vela::update(){
	set_frame();
}

sf::Sprite& Vela::get_draw_velita(){
	return _velita;
}

void Vela::cmd() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		_estado_vela = Estado_Vela::move_der;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		_estado_vela = Estado_Vela::move_izq;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		_estado_vela = Estado_Vela::move_up;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		_estado_vela = Estado_Vela::move_down;
	}

	switch (_estado_vela) {
	case Estado_Vela::quieto:
		_frame_der = _frame_actual;
		_frame_izq = { 49,67};
		break;
	case Estado_Vela::move_izq:
		_velita.move(-1, 0);
		_frame_der.x++;
		if (_frame_der.x == 2) _frame_der.x = 0;
		_frame_der.y = 4;
		_frame_actual = _frame_der;
		_estado_vela = Estado_Vela::quieto;
		break;
	case Estado_Vela::move_der:
		_velita.move(1, 0);
		_frame_der.x++;
		if (_frame_der.x == 2) _frame_der.x = 0;
		_frame_der.y = 3;
		_frame_actual = _frame_der;
		_estado_vela = Estado_Vela::quieto;
		break;
	case Estado_Vela::move_up:
		_velita.move(0,-1);
		_frame_der.x++;
		if (_frame_der.x == 2) _frame_der.x = 0;
		_frame_der.y = 2;
		_frame_actual = _frame_der;
		_estado_vela = Estado_Vela::quieto;
		break;
	case Estado_Vela::move_down:
		_velita.move(0, 1);
		_frame_der.x++;
		if (_frame_der.x == 2) _frame_der.x = 0;
		_frame_der.y = 1;
		_frame_actual= _frame_der;
		_estado_vela = Estado_Vela::quieto;
		break;		
	}
	//Izquierda
	if (_velita.getPosition().x < 0) _velita.setPosition(0, _velita.getPosition().y);
	//Derecha
	if (_velita.getPosition().x + _velita.getGlobalBounds().width > WIDTH) _velita.setPosition(WIDTH - _velita.getGlobalBounds().width, _velita.getPosition().y);
     //Arriba
	if (_velita.getPosition().y < 0) _velita.setPosition(_velita.getPosition().x,0);
	//corregir que no se vaya para abajo fuera del mapa.
	if (_velita.getPosition().y + _velita.getGlobalBounds().height > HEIGHT) _velita.setPosition(_velita.getPosition().x,HEIGHT- _velita.getGlobalBounds().height);
}
