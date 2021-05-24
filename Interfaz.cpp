#include "Interfaz.h"

void Interfaz::cargar_textura(std::string texto)
{
	_texturafondo.loadFromFile(texto);
}

void Interfaz::cargar_fuente(std::string texto)
{
	_fuente.loadFromFile(texto);
}

Interfaz::Interfaz(){    
	_opcion_elegida = false;
	_opcion_m = Jugar;
	_opcion = 0;
	_integrantes.loadFromFile("imagenes/Integrantes.jpg");
	_tutorial.loadFromFile("imagenes/Tutorial.jpg");
	cargar_textura("imagenes/Menu.jpeg");
	cargar_fuente("fuente/fuente.ttf");

	_text = new sf::Text[maxtext];
	
	for (int x = 0; x < maxtext;x++)_text[x].setFont(_fuente);

	_spfondo.setTexture(_texturafondo);
	_spfondo.setScale(0.65, 0.85);
	_text[Jugar].setString("JUGAR");
	_text[Jugar].setPosition(385,250);
	_text[Jugar].setFillColor(sf::Color::Yellow);
	_text[ComoJugar].setString("COMO JUGAR");
	_text[ComoJugar].setPosition(350,300);
	_text[Salir].setString("SALIR");
	_text[Salir].setPosition(385,400);
	_text[Integrantes].setString("INTEGRANTES");
	_text[Integrantes].setPosition(335, 350);
}

opcion_menu Interfaz::get_opcion(){
	return _opcion_m;
}

bool Interfaz::get_opcion_elegida()
{
	return _opcion_elegida;
}

void Interfaz::set_opcion_elegida(bool valor){
	_opcion_elegida = valor;
}



sf::Sprite& Interfaz::getdrawfondo(){

	return _spfondo;
}

sf::Text* Interfaz::getdrawtextos()
{
	return _text;
}


void Interfaz::cmd(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		_text[_opcion].setFillColor(sf::Color::White);
		if (_opcion > 0) {
			_opcion--;
		}
		else _opcion = 3;
		_text[_opcion].setFillColor(sf::Color::Yellow);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		_text[_opcion].setFillColor(sf::Color::White);
		if (_opcion < 3) {
			_opcion++;
		}
		else _opcion = 0;
		_text[_opcion].setFillColor(sf::Color::Yellow);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) _opcion_elegida=true;

	switch (_opcion_m)
	{
	case Jugar:
		break;
	case ComoJugar:
		if (_opcion_elegida){
		_spfondo.setTexture(_tutorial);
		_spfondo.setScale(1, 1);
		
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			_opcion_elegida = false;
			reset_sprite();
		}
			break;
	case Integrantes:
		if (_opcion_elegida){
		_spfondo.setTexture(_integrantes);
		_spfondo.setScale(0.9, 0.8);
		
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			_opcion_elegida = false;
			reset_sprite();
		}
		    break;
	case Salir:
		break;
	default:
		break;
	}

	


}

void Interfaz::update()
{
	switch (_opcion) {

	case 0: _opcion_m = Jugar;

		break;

	
	case 1: _opcion_m = ComoJugar;


		break;

	case 2: _opcion_m = Integrantes;
		
		break;

	case 3: _opcion_m = Salir;
		break;
	}
}

void Interfaz::reset_sprite(){
	_spfondo.setTexture(_texturafondo);
	_spfondo.setScale(0.65, 0.85);
}
