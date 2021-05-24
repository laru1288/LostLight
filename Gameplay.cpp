#include "gameplay.h"


gameplay::gameplay(){
	faro=farocreado=lampara_creada = false;
	lamparita = true;
	_estado = Estado_Gameplay::Interfaz;
	numero = 0;
	encuentro = false;
	_num_faro = 0;
}


void gameplay::cmd() {

	switch (_estado)
	{
	case Estado_Gameplay::Interfaz:
		_menu.cmd();

		if (_menu.get_opcion() == Jugar && _menu.get_opcion_elegida()) {
			_estado = Estado_Gameplay::Intro;
		}

		break;
	case Estado_Gameplay::Intro:
		_intro.cmd();
		if (_intro.get_estado() == Estado_Intro::end) _estado = Estado_Gameplay::Juego;
		break;
	case Estado_Gameplay::Juego:

		if (_fondo.get_estado() == Estado_Fondo::ultima_luz) {
			_estado = Estado_Gameplay::Escena_Final;
		}

		if (lamparita) {
			_lamparita = new Lampara;
			lamparita = false;
			lampara_creada = true;
			
			_faro = new Faro;


		}
		_fondo.cmd();
		_velita.cmd();
		_map.cmd(_velita.get_draw_velita().getPosition());
		_rec.cmd();


		if (lampara_creada) {
			if (collision(_velita.get_draw_velita(), _lamparita->get_draw_Lampara())) {
				farocreado = true;
				lampara_creada = false;
				_faro->set_position(1 + rand() % 6);
				_estado = Estado_Gameplay::Encuentro;
			}
		}

		if (farocreado) {
			if (collision(_velita.get_draw_velita(), _faro->get_draw_Faro())) {
				_fondo.set_estado((Estado_Fondo)+numero);
				farocreado = false;
				if (_fondo.get_estado() != Estado_Fondo::ultima_luz) {
					lampara_creada = true;
					_lamparita->set_position(1 + rand() % 6);
				}
				numero++;
				_num_faro++;

				_fondo.set_estado((Estado_Fondo)+numero);
				_map.cambiar_mapa();
				
				switch (_num_faro)
				{
				case 1:
					_estado = Estado_Gameplay::puzzle2;
				
					create_puzzle2(1);
					break;
				case 2:
					_estado = Estado_Gameplay::puzzle;
					_puzzle = new puzzle;
					break;
				case 3:
					_estado = Estado_Gameplay::slider_puzzle;
					_slider_puzzle = new Slider_puzzle;
					_slider_puzzle->numero_de_puzzle(1);
					_slider_puzzle->cargar_sprite();
					_slider_puzzle->cambiar_sprite(0);
					break;
				case 4:
					_estado = Estado_Gameplay::puzzle2;
					create_puzzle2(2);
					break;
				case 5:
					_estado = Estado_Gameplay::puzzle;
					_puzzle = new puzzle;
					break;
				case 6:
					delete(_slider_puzzle);
					_estado = Estado_Gameplay::slider_puzzle;
					_slider_puzzle = new Slider_puzzle;
					_slider_puzzle->numero_de_puzzle(2);
					_slider_puzzle->cargar_sprite();
					_slider_puzzle->cambiar_sprite(1);

					break;
				default:
					
					break;
				}


			}
		}
		

		colision_paredes();

		break;
	case Estado_Gameplay::Escena_Final:
		_final.cmd();
		if (_final.get_estado() == Estado_Final::end) _estado = Estado_Gameplay::Interfaz;
		break;
	case Estado_Gameplay::Encuentro:
		_encuentro.cmd();
		if (_encuentro.get_estado() == Estado_Encuentro::end) {
			_estado = Estado_Gameplay::Juego;
			_encuentro.reset_encuentro();

		}
		break;
	
	case Estado_Gameplay::puzzle:
		if (_puzzle->get_fin()) {
			_estado = Estado_Gameplay::Juego;
			delete(_puzzle);
		} else{
		if (_puzzle->reset()) {
			delete(_puzzle);
			_puzzle = new puzzle;

		}
		_puzzle->cmd();
		}
		

		break;
	case Estado_Gameplay::puzzle2:
		if (_puzzle2->get_fin()) {
			_estado = Estado_Gameplay::Juego;
			_puzzle2->cambiar_sprite(2);
			delete(_puzzle2);
		}
		else {
			if (_puzzle2->reset()) {
				delete(_puzzle2);
				if (_num_faro == 1) {
				
					create_puzzle2(1);
				}
				if (_num_faro == 4) {
					create_puzzle2(2);
				}
			}
			_puzzle2->cmd();
		}
		break;

	case Estado_Gameplay::slider_puzzle:
		if (_slider_puzzle->get_estado()==Estado_slider::armado){
			_estado = Estado_Gameplay::Juego;
			delete(_slider_puzzle);
		}
		else { 
			
			_slider_puzzle->cmd(); 
		}
		
		break;

	default:
		break;
	}


}


void gameplay::update(sf::RenderWindow& window){
	switch (_estado)	{
	case Estado_Gameplay::Interfaz:
		_menu.update();
		if (_menu.get_opcion() == Salir && _menu.get_opcion_elegida()) {
			window.close();
		}
		break;
	case Estado_Gameplay::Intro:
		_intro.update();
		break;
	case Estado_Gameplay::Juego:
		_fondo.update();
		_velita.update();		
		_map.update((int)_fondo.get_estado());		
		break;
	case Estado_Gameplay::Escena_Final:
		_final.update();
		break;
	case Estado_Gameplay::Encuentro:
		_encuentro.update();
		break;
	case Estado_Gameplay::puzzle :
		_puzzle->update();
		break;
	case Estado_Gameplay::puzzle2:
		_puzzle2->update();
		break;
	case Estado_Gameplay::slider_puzzle:
		 _slider_puzzle->update(); 
		break;
	default:
		break;
	}
	
}

void gameplay::draw(sf::RenderWindow& window){
	switch (_estado)
	{
	case Estado_Gameplay::Interfaz:

		    window.clear();
		if ((_menu.get_opcion() == Integrantes && _menu.get_opcion_elegida()) || (_menu.get_opcion() == ComoJugar && _menu.get_opcion_elegida())) {
			
			window.draw(_menu.getdrawfondo());
		}

		else {
			window.draw(_menu.getdrawfondo());

			if ((_menu.get_opcion_elegida() && _menu.get_opcion() == Integrantes) || (_menu.get_opcion_elegida() && _menu.get_opcion() == ComoJugar)) { sf::sleep(sf::seconds(5.0)); }
			else { for (int x = 0; x < maxtext; x++)window.draw(_menu.getdrawtextos()[x]); }
		}
		break;
	case Estado_Gameplay::Intro:
		window.draw(_intro.get_draw_fondo());
		sf::sleep(sf::seconds(5.0));
		break;
	case Estado_Gameplay::Juego:
		window.draw(_fondo.get_draw1());
		window.draw(_fondo.get_draw2());
		window.draw(_fondo.get_draw3());
		window.draw(_map.get_draw());
		window.draw(_velita.get_draw_velita());
		for (int x = 0; x < 20; x++) window.draw(_rec.get_draw()[x]);
		if (lampara_creada) window.draw(_lamparita->get_draw_Lampara());
		
		if (farocreado==true) window.draw(_faro->get_draw_Faro());



		break;
	case Estado_Gameplay::Escena_Final:
		window.draw(_final.get_draw_fondo());
		sf::sleep(sf::seconds(5.0));
		break;
	case Estado_Gameplay::Encuentro:
		window.draw(_fondo.get_draw1());
		window.draw(_fondo.get_draw2());
		window.draw(_fondo.get_draw3());
		window.draw(_map.get_draw());
		window.draw(_velita.get_draw_velita());
		if (lampara_creada) window.draw(_lamparita->get_draw_Lampara());
		window.draw(_encuentro.get_draw_fondo());
		sf::sleep(sf::seconds(2.0));
		
		break;

	case Estado_Gameplay::puzzle:
		
		if (_puzzle->reset()) {

			_puzzle->cambiar_sprite(0);
			window.draw(_puzzle->get_draw_sprite());
			window.display();
			sf::sleep(sf::seconds(4.0));
		}
		else if (_puzzle->get_fin()) {
			_puzzle->cambiar_sprite(1);
			window.draw(_puzzle->get_draw_sprite());
			window.display();
			sf::sleep(sf::seconds(4.0));

		}
		else{
		
		window.draw(_puzzle->get_draw_fondo());
		window.draw(_puzzle->get_draw_faro());
		window.draw(_puzzle->get_draw_barrita());
		for (int x = 0; x < 30; x++) { 
			window.draw(_puzzle->get_draw_fueguito()[x].get_draw_Fueguito());
		}
		}
		break;

	case Estado_Gameplay::puzzle2:

		window.clear();
		if (_puzzle2->get_fin()) {

			_puzzle2->cambiar_sprite(2);
			window.draw(_puzzle2->getdrawsprite());
			
			window.display();
			sf::sleep(sf::seconds(4.0));
		}
		else if (_puzzle2->reset()) {
			 
			_puzzle2->cambiar_sprite(rand() % 2);
			window.draw(_puzzle2->getdrawsprite());
			window.display();
			//sf::sleep(sf::seconds(2.0));
		}  
		else{
		window.draw(_puzzle2->getdrawfondo());
		for (int i = 0; i < 4; i++) {
			
			window.draw(_puzzle2->getdrawtextos()[i]);

		}
		}

		
		if(_puzzle2->reset() || _puzzle2->get_fin()) sf::sleep(sf::seconds(4.0));

		break;

	case Estado_Gameplay::slider_puzzle:
		
		if (_slider_puzzle->get_estado() == Estado_slider::armado) {

			window.draw(_slider_puzzle->get_sprite());
			window.display();
			sf::sleep(sf::seconds(4.0));
			
		}
		else { _slider_puzzle->draw(window); }

		break;
	default:
		break;
	}
}

bool gameplay::collision(sf::Sprite& vela, sf::Sprite& objeto){
	bool resultado = false;

	if(vela.getGlobalBounds().intersects(objeto.getGlobalBounds())) resultado=true;


	return resultado;
}



void gameplay::colision_paredes() {

	sf::FloatRect playerbounds = _velita.get_draw_velita().getGlobalBounds();
	for (int i = 0; i < 20; i++) {


		sf::FloatRect rectbounds = _rec.get_draw()[i].getGlobalBounds();

		if (rectbounds.intersects(playerbounds)) {
			//bottom
			if (playerbounds.top < rectbounds.top &&
				playerbounds.top + playerbounds.height < rectbounds.top + rectbounds.height &&
				playerbounds.left < rectbounds.left + rectbounds.width &&
				playerbounds.left + playerbounds.width > rectbounds.left) {
				_velita.get_draw_velita().setPosition(playerbounds.left, rectbounds.top - playerbounds.height);

			}
			//top
			if (playerbounds.top > rectbounds.top &&
				playerbounds.top + playerbounds.height > rectbounds.top + rectbounds.height &&
				playerbounds.left < rectbounds.left + rectbounds.width &&
				playerbounds.left + playerbounds.width > rectbounds.left) {
				_velita.get_draw_velita().setPosition(playerbounds.left, rectbounds.top + rectbounds.height);
			}
			//izquiera
			if (playerbounds.left < rectbounds.left &&
				playerbounds.left + playerbounds.width < rectbounds.left + rectbounds.width &&
				playerbounds.top < rectbounds.top + rectbounds.height &&
				playerbounds.top + playerbounds.height > rectbounds.top) {
				_velita.get_draw_velita().setPosition(rectbounds.left - playerbounds.width, playerbounds.top);

			}
			//derecha
			if (playerbounds.left > rectbounds.left &&
				playerbounds.left + playerbounds.width > rectbounds.left + rectbounds.width &&
				playerbounds.top < rectbounds.top + rectbounds.height &&
				playerbounds.top + playerbounds.height > rectbounds.top) {
				_velita.get_draw_velita().setPosition(rectbounds.left + rectbounds.width, playerbounds.top);
			}

		}
	}
}

void gameplay::create_puzzle2(int preg)
{
	switch (preg)
	{
	case 1: _puzzle2 = new Puzzle2a;
		break;
	case 2: _puzzle2 = new Puzzle2b;
		break;
	default:
		break;
	}
	
	
}

