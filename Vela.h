#pragma once
#include <SFML/Graphics.hpp>
#define WIDTH 816 
#define HEIGHT 624

enum class Estado_Vela {
	quieto,
	move_izq,
	move_der,
	move_up,
	move_down
};
class Vela{
private:
	Estado_Vela _estado_vela;
	sf::Vector2i _frame_der,_frame_actual;
	sf::Vector2i _frame_izq; 
	sf::Texture _textura;
	sf::Sprite  _velita;
public:
	Vela();
	void set_estado(bool est);
	void set_estado(Estado_Vela);
	void set_frame();
	void update();
	void cmd();
	Estado_Vela get_estado();
	sf::Sprite& get_draw_velita();
};

