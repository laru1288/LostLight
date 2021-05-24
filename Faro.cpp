#include "Faro.h"

Faro::Faro() {
	_textura1.loadFromFile("imagenes/Faro/Faro.png");
	_Faro.setTexture(_textura1);
	set_position(1 + rand() % 6);
	_estado = Estado_Faro::quieto;
	_velocidad = { -1,1 };
}

Faro::~Faro(){
}

void Faro::set_faro(bool pren){
	prendido = pren;
}

void Faro::set_tex_sprite(){
	if (prendido) {
		_Faro.setTexture(_textura1);
	}
	else {
		if(!prendido) _Faro.setTexture(_textura2);
	}
	
	
	_Faro.setPosition(300, 300);

}



void Faro::cmd(){
	switch (_estado){

	case Estado_Faro::quieto:

		break;
	case Estado_Faro::movimiento:

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			if(_velocidad.x>-10)_velocidad.x--;
			_Faro.move(_velocidad.x, 0);
		}
		else {

			_velocidad.x=0;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			if (_velocidad.y < 10)_velocidad.y++;
			_Faro.move(_velocidad.y, 0);
		}
		else {

			_velocidad.y = 0;
		}

		if (_Faro.getPosition().x < 0) _Faro.setPosition(0, _Faro.getPosition().y);
		//Derecha
		if (_Faro.getPosition().x + _Faro.getGlobalBounds().width > WIDTH) _Faro.setPosition(WIDTH - _Faro.getGlobalBounds().width, _Faro.getPosition().y);
		break;
	default:
		break;
	}
}

void Faro::cambiar_estado(Estado_Faro estado){
	_estado = estado;

	if (estado == Estado_Faro::movimiento) { _Faro.setPosition(0, 624 - _Faro.getTexture()->getSize().y); }
}

sf::Sprite& Faro::get_draw_Faro(){
	return _Faro;
}

void Faro::set_position(int num) {
	switch (num) {
	case 1:_Faro.setPosition(770, 450);
		break;
	case 2:_Faro.setPosition(0, 100);
		break;
	case 3:_Faro.setPosition(0, 500);
		break;
	case 4:_Faro.setPosition(770, 0);
		break;
	case 5:_Faro.setPosition(430, 400);
		break;
	case 6:_Faro.setPosition(430, 100);
		break;
	}

}

void Faro::update()
{
}
