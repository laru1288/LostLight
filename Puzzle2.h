#pragma once
#include <SFML/Graphics.hpp>


#define maxtext 4


enum respuesta {
	a,
	b,
	c,
	d
};

class Puzzle2 {

protected:
	sf::Texture _texturafondo;
	sf::Sprite _spfondo;
	sf::Font _fuente;
	sf::Text* _text;
	int _opcion;
	bool _opcion_elegida;
	respuesta _opcion_m;
	respuesta _opcion_correcta;
	bool _fin;
	bool _reset;
	
public:
	virtual void cargar_textura(std::string)=0;
	virtual void cargar_fuente(std::string)=0;
	virtual respuesta get_opcion()=0;
	virtual bool get_opcion_elegida()=0;
	virtual void set_opcion_elegida(bool valor)=0;
	virtual void cmd()=0;
	virtual void update()=0;
	virtual void reset_sprite()=0;
	virtual sf::Sprite& getdrawfondo()=0;
	virtual sf::Sprite& getdrawsprite() = 0;
	virtual sf::Text* getdrawtextos()=0;
	virtual bool get_fin()=0;
	virtual bool reset()=0;
	virtual void cambiar_sprite(int)=0;


};
