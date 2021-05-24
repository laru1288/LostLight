#include "Puzzle2b.h"


void Puzzle2b::cargar_textura(std::string texto)
{
	_texturafondo.loadFromFile(texto);

}

void Puzzle2b::cargar_fuente(std::string texto)
{
	_fuente.loadFromFile(texto);
}

Puzzle2b::Puzzle2b() {

	_opcion_elegida = false;
	_opcion_m = a;
	_opcion = 0;
	_opcion_correcta = b;
	_reset = _fin = false;
	cargar_textura("imagenes/pregunta2.jpeg");
	cargar_fuente("fuente/fuente.ttf");

	_text = new sf::Text[maxtext]; 
	for (int x = 0; x < maxtext; x++)_text[x].setFont(_fuente);

	_texture[0].loadFromFile("imagenes/incorrecta1.jpeg");
	_texture[1].loadFromFile("imagenes/incorrecta2.jpeg");
	_texture[2].loadFromFile("imagenes/Respuesta2.jpeg");

	_spfondo.setTexture(_texturafondo);
	_spfondo.setScale(1, 0.77);
	_text[a].setString("1760");
	_text[a].setPosition(300, 250);
	_text[a].setFillColor(sf::Color::Yellow);
	_text[b].setString("1690");
	_text[b].setPosition(300, 300);
	_text[b].setFillColor(sf::Color::Black);
	_text[c].setString("1750");
	_text[c].setPosition(300, 350);
	_text[c].setFillColor(sf::Color::Black);
	_text[d].setString("1752");
	_text[d].setPosition(300, 400);
	_text[d].setFillColor(sf::Color::Black);


}

respuesta Puzzle2b::get_opcion() {
	return _opcion_m;
}

bool Puzzle2b::get_opcion_elegida()
{
	return _opcion_elegida;
}

void Puzzle2b::set_opcion_elegida(bool valor) {
	_opcion_elegida = valor;
}



sf::Sprite& Puzzle2b::getdrawfondo() {

	return _spfondo;
}

sf::Text* Puzzle2b::getdrawtextos()
{
	return _text;
}


void Puzzle2b::cmd() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		_text[_opcion].setFillColor(sf::Color::Black);
		if (_opcion > 0) {
			_opcion--;
		}
		else _opcion = 3;
		_text[_opcion].setFillColor(sf::Color::Yellow);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		_text[_opcion].setFillColor(sf::Color::Black);
		if (_opcion < 3) {
			_opcion++;
		}
		else _opcion = 0;
		_text[_opcion].setFillColor(sf::Color::Yellow);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) _opcion_elegida = true;

	if (_opcion_elegida == true) {
		switch (_opcion_m)
		{
		case a:
			_reset = true;
			break;
		case b:
			_reset = true;
			break;
		case c:
			_reset = true;
			break;
		case d:
			_fin = true;
			break;
		default:

			break;
		}
	}



}

void Puzzle2b::update()
{
	switch (_opcion) {

	case 0: _opcion_m = a;

		break;


	case 1: _opcion_m = b;


		break;

	case 2: _opcion_m = c;

		break;

	case 3: _opcion_m = d;
		break;
	}
}

 
void Puzzle2b::reset_sprite() {
	_spfondo.setTexture(_texturafondo);
	_spfondo.setScale(0.65, 0.85);
}

bool Puzzle2b::get_fin() {
	return _fin;
}

bool Puzzle2b::reset()
{

	return _reset;
}

void Puzzle2b::cambiar_sprite(int numero){
	_sprite.setTexture(_texture[numero]);
	if (numero == 0) _sprite.setScale(1.4, 1.2);
	if (numero == 1) _sprite.setScale(2.05, 2.1);
	if (numero == 2) _sprite.setScale(1, 1.2);
}

sf::Sprite& Puzzle2b::getdrawsprite(){
	return _sprite;
}
