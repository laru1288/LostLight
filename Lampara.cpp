#include "Lampara.h"

Lampara::Lampara(){
	_textura.loadFromFile("imagenes/Lamparita/Lamparita_triste.png");
	_lampara.setTexture(_textura);
	
	set_position(1 + rand() % 6);
	
}



sf::Sprite& Lampara::get_draw_Lampara() {
	return _lampara;
}

void Lampara::update()
{
}

void Lampara::set_position(int num) {
	switch (num) {
	case 1:_lampara.setPosition(780, 500);
		break;
	case 2:_lampara.setPosition(0, 100);
		break;
	case 3:_lampara.setPosition(430, 400);
		break;
	case 4:_lampara.setPosition(430, 100);
		break;
	case 5:_lampara.setPosition(0, 500);
		break;
	case 6:_lampara.setPosition(780, 50);
		break;
	}
}

void Lampara::cmd()
{
}
