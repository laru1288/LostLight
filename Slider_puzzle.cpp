#include "Slider_puzzle.h"

Slider_puzzle::Slider_puzzle(){
	A = 0, B = 100, C = 200, X = 0, Y = 0;
	_armado= false;
	aux = 0;
	_event = Estado_slider::desarmado;

	_vec[0] = 7;
	_vec[1] = 8;
	_vec[2] = 6;
	_vec[3] = 4;
	_vec[4] = 1;
	_vec[5] = 3;
	_vec[6] = 5;
	_vec[7] = 2;
	_vec[8] = 9;

	PHOTO[0][0]=1;
	PHOTO[0][1]=2;
	PHOTO[0][2]=3;
	PHOTO[1][0]=4;
	PHOTO[1][1]=5;
	PHOTO[1][2]=6;
	PHOTO[2][0]=7;
	PHOTO[2][1]=8;
	PHOTO[2][2]=9;	
	
	_textura[0].loadFromFile("imagenes/ganaste1.jpeg");
	_textura[1].loadFromFile("imagenes/ganaste2.jpeg");
	_tutorial.loadFromFile("imagenes/Tutorialslider.jpg");
	_tuto.setTexture(_tutorial);	
	_tuto.setPosition(400, 0);
  //  _Temp.setPosition(C, C);
}

void Slider_puzzle::numero_de_puzzle(int num){
	if (num == 1) {
		_P.loadFromFile("imagenes/slidepuzzle.jpg");
	}
	if(num == 2){
		_P.loadFromFile("imagenes/slidepuzzle2.jpg");
	}
}

void Slider_puzzle::cargar_sprite(){
	_aux.setTexture(_P);
	_S.setTexture(_P);
	//_S1.setTexture(_P);
	_S2.setTexture(_P);
	_S3.setTexture(_P);
	_S4.setTexture(_P);
	_S5.setTexture(_P);
	_S6.setTexture(_P);
	_S7.setTexture(_P);
	_S8.setTexture(_P);
	_S9.setTexture(_P);
	_Temp.setTexture(_P);

	_S5.setTextureRect(sf::IntRect(0, 0, 100, 100));
	//_S5.setTextureRect(sf::IntRect(0, 0, 500, 167));
	_S8.setTextureRect(sf::IntRect(100, 0, 100, 100));
	_S6.setTextureRect(sf::IntRect(200, 0, 100, 100));
	_S4.setTextureRect(sf::IntRect(0, 100, 100, 100));
	_S7.setTextureRect(sf::IntRect(100, 100, 100, 100));
	_S3.setTextureRect(sf::IntRect(200, 100, 100, 100));
	_S1.setTextureRect(sf::IntRect(0, 200, 100, 100));
	_S2.setTextureRect(sf::IntRect(100, 200, 100, 100));
	_S9.setTextureRect(sf::IntRect(200, 200, 100, 100));
	//_Temp.setTextureRect(sf::IntRect(600, 500, 100, 100));

	_S1.setPosition(A, A);
	_S2.setPosition(B, A);
	_S3.setPosition(C, A);
	_S4.setPosition(A, B);
	_S5.setPosition(B, B);
	_S6.setPosition(C, B);
	_S7.setPosition(A, C);
	_S8.setPosition(B, C);
	_S9.setPosition(C, C);
	_aux.setPosition(400, 300);

}

void Slider_puzzle::update(){
	_S1.setPosition(A, A);
	_S2.setPosition(B, A);
	_S3.setPosition(C, A);
	_S4.setPosition(A, B);
	_S5.setPosition(B, B);
	_S6.setPosition(C, B);
	_S7.setPosition(A, C);
	_S8.setPosition(B, C);
	_S9.setPosition(C, C);
}

void Slider_puzzle::draw(sf::RenderWindow& window){
	window.draw(_aux);
	window.draw(_tuto);
	window.draw(_S1);
	window.draw(_S2);
	window.draw(_S3);
	window.draw(_S4);
	window.draw(_S5);
	window.draw(_S6);
	window.draw(_S7);
	window.draw(_S8);
	window.draw(_S9);
	
}

void Slider_puzzle::cmd(){	
	
	verificacion();
	
	if (_event == Estado_slider::desarmado) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && PHOTO[X][Y] == 9) {
			_Temp = _S9;
			
			_S9 = _S6;
			_S6 = _Temp;
			X = 1;
			Y = 2;
			
			aux = _vec[8];
			_vec[8] = _vec[5];
			_vec[5] = aux;
			std::cout << "vec [8] = " << _vec[8] << std::endl;
			std::cout << "vec [5] = " << _vec[5] << std::endl;
			
			
			sf::sleep(sf::seconds(0.5));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && PHOTO[X][Y] == 9) {
			_Temp = _S9;
			
			_S9 = _S8;
			_S8 = _Temp;
			X = 2;
			Y = 1;
			
			aux = _vec[8];
			_vec[8] = _vec[7];
			_vec[7] = aux;
			std::cout << "vec [8] = " << _vec[8] << std::endl;
			std::cout << "vec [7] = " << _vec[7] << std::endl;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && PHOTO[X][Y] == 8) {
			_Temp = _S8;
			
			_S8 = _S9;
			_S9 = _Temp;
			X = 2;
			Y = 2;
			
			aux = _vec[7];
			_vec[7] = _vec[8];
			_vec[8] = aux;
			std::cout << "vec [7] = " << _vec[7] << std::endl;
			std::cout << "vec [8] = " << _vec[8] << std::endl;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && PHOTO[X][Y] == 8) {
			_Temp = _S8;
			
			_S8 = _S7;
			_S7 = _Temp;
			X = 2;
			Y = 0;
			
			aux = _vec[7];
			_vec[7] = _vec[6];
			_vec[6] = aux;
			std::cout << "vec [7] = " << _vec[7] << std::endl;
			std::cout << "vec [6] = " << _vec[6] << std::endl;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && PHOTO[X][Y] == 8) {
			_Temp = _S8;
			
			_S8 = _S5;
			_S5 = _Temp;
			X = X - 1;
			
			aux = _vec[7];
			_vec[7] = _vec[4];
			_vec[4] = aux;
			std::cout << "vec [7] = " << _vec[7] << std::endl;
			std::cout << "vec [4] = " << _vec[4] << std::endl;
			sf::sleep(sf::seconds(0.5));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && PHOTO[X][Y] == 7) {
			_Temp = _S7;
			
			_S7 = _S4;
			_S4 = _Temp;
			X = 1;
			Y = 0;
			
			aux = _vec[6];
			_vec[6] = _vec[3];
			_vec[3] = aux;
			std::cout << "vec [6] = " << _vec[6] << std::endl;
			std::cout << "vec [3] = " << _vec[3] << std::endl;
			sf::sleep(sf::seconds(0.5));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && PHOTO[X][Y] == 7) {
			_Temp = _S7;
			
			_S7 = _S8;
			_S8 = _Temp;
			X = 2;
			Y = 1;
			
			aux = _vec[6];
			_vec[6] = _vec[7];
			_vec[7] = aux;
			std::cout << "vec [6] = " << _vec[6] << std::endl;
			std::cout << "vec [7] = " << _vec[7] << std::endl;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && PHOTO[X][Y] == 6) {
			_Temp = _S6;
			
			_S6 = _S9;
			_S9 = _Temp;
			X = 2;
			Y = 2;
		
			aux = _vec[5];
			_vec[5] = _vec[8];
			_vec[8] = aux;
			std::cout << "vec [5] = " << _vec[5] << std::endl;
			std::cout << "vec [8] = " << _vec[8] << std::endl;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && PHOTO[X][Y] == 6) {
			_Temp = _S6;
			
			_S6 = _S3;
			_S3 = _Temp;
			X = 0;
			Y = 2;
			
			aux = _vec[5];
			_vec[5] = _vec[2];
			_vec[2] = aux;
			std::cout << "vec [5] = " << _vec[5] << std::endl;
			std::cout << "vec [2] = " << _vec[2] << std::endl;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && PHOTO[X][Y] == 6) {
			_Temp = _S6;
			
			_S6 = _S5;
			_S5 = _Temp;
			X = 1;
			Y = 1;
			
			aux = _vec[5];
			_vec[5] = _vec[4];
			_vec[4] = aux;
			std::cout << "vec [5] = " << _vec[5] << std::endl;
			std::cout << "vec [4] = " << _vec[4] << std::endl;
			sf::sleep(sf::seconds(0.5));
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && PHOTO[X][Y] == 5) {
			_Temp = _S5;
			
			_S5 = _S8;
			_S8 = _Temp;
			X = 2;
			Y = 1;
			
			aux = _vec[4];
			_vec[4] = _vec[7];
			_vec[7] = aux;
			std::cout << "vec [4] = " << _vec[4] << std::endl;
			std::cout << "vec [7] = " << _vec[7] << std::endl;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && PHOTO[X][Y] == 5) {
			_Temp = _S5;
			
			_S5 = _S2;
			_S2 = _Temp;
			X = 0;
			Y = 1;
			
			aux = _vec[4];
			_vec[4] = _vec[1];
			_vec[1] = aux;
			std::cout << "vec [4] = " << _vec[4] << std::endl;
			std::cout << "vec [1] = " << _vec[1] << std::endl;
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && PHOTO[X][Y] == 5) {
			_Temp = _S5;
			
			_S5 = _S4;
			_S4 = _Temp;
			X = 1;
			Y = 0;
			
			aux = _vec[4];
			_vec[4] = _vec[3];
			_vec[3] = aux;
			std::cout << "vec [4] = " << _vec[4] << std::endl;
			std::cout << "vec [3] = " << _vec[3] << std::endl;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && PHOTO[X][Y] == 5) {
			_Temp = _S5;
			
			_S5 = _S6;
			_S6 = _Temp;
			X = 1;
			Y = 2;
			
			aux = _vec[4];
			_vec[4] = _vec[5];
			_vec[5] = aux;
			std::cout << "vec [4] = " << _vec[4] << std::endl;
			std::cout << "vec [5] = " << _vec[5] << std::endl;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && PHOTO[X][Y] == 4) {
			_Temp = _S4;
			
			_S4 = _S7;
			_S7 = _Temp;
			X = 2;
			Y = 0;
			
			aux = _vec[3];
			_vec[3] = _vec[6];
			_vec[6] = aux;
			std::cout << "vec [3] = " << _vec[3] << std::endl;
			std::cout << "vec [6] = " << _vec[6] << std::endl;
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && PHOTO[X][Y] == 4) {
			_Temp = _S4;
			
			_S4 = _S1;
			_S1 = _Temp;
			X = 0;
			Y = 0;
			
			aux = _vec[3];
			_vec[3] = _vec[0];
			_vec[0] = aux;
			std::cout << "vec [3] = " << _vec[3] << std::endl;
			std::cout << "vec [0] = " << _vec[0] << std::endl;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && PHOTO[X][Y] == 4) {
			_Temp = _S4;
			
			_S4 = _S5;
			_S5 = _Temp;
			X = 1;
			Y = 1;
			
			aux = _vec[3];
			_vec[3] = _vec[4];
			_vec[4] = aux;
			std::cout << "vec [3] = " << _vec[3] << std::endl;
			std::cout << "vec [4] = " << _vec[4] << std::endl;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && PHOTO[X][Y] == 3) {
			_Temp = _S3;
			
			_S3 = _S2;
			_S2 = _Temp;
			X = 0;
			Y = 1;
			
			aux = _vec[2];
			_vec[2] = _vec[1];
			_vec[1] = aux;
			std::cout << "vec [2] = " << _vec[2] << std::endl;
			std::cout << "vec [1] = " << _vec[1] << std::endl;
			sf::sleep(sf::seconds(0.5));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && PHOTO[X][Y] == 3) {
			_Temp = _S3;
			
			_S3 = _S6;
			_S6 = _Temp;
			X = 1;
			Y = 2;
			
			aux = _vec[2];
			_vec[2] = _vec[5];
			_vec[5] = aux;
			std::cout << "vec [2] = " << _vec[2] << std::endl;
			std::cout << "vec [5] = " << _vec[5] << std::endl;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && PHOTO[X][Y] == 2) {
			_Temp = _S2;
			
			_S2 = _S5;
			_S5 = _Temp;
			X = 1;
			Y = 1;
			
			aux = _vec[1];
			_vec[1] = _vec[4];
			_vec[4] = aux;
			std::cout << "vec [1] = " << _vec[1] << std::endl;
			std::cout << "vec [4] = " << _vec[4] << std::endl;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && PHOTO[X][Y] == 2) {
			_Temp = _S2;
			
			_S2 = _S3;
			_S3 = _Temp;
			X = 0;
			Y = 2;
			
			aux = _vec[1];
			_vec[1] = _vec[2];
			_vec[2] = aux;
			std::cout << "vec [1] = " << _vec[1] << std::endl;
			std::cout << "vec [2] = " << _vec[2] << std::endl;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && PHOTO[X][Y] == 2) {
			_Temp = _S2;
			
			_S2 = _S1;
			_S1 = _Temp;
			X = 0;
			Y = 0;
			
			aux = _vec[1];
			_vec[1] = _vec[0];
			_vec[0] = aux;
			std::cout << "vec [1] = " << _vec[1] << std::endl;
			std::cout << "vec [0] = " << _vec[0] << std::endl;
			
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && PHOTO[X][Y] == 1) {
			_Temp = _S1;
			
			_S1 = _S4;
			_S4 = _Temp;
			X = 1;
			Y = 0;
			
			aux = _vec[0];
			_vec[0] = _vec[3];
			_vec[3] = aux;
			std::cout << "vec [0] = " << _vec[0] << std::endl;
			std::cout << "vec [3] = " << _vec[3] << std::endl;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && PHOTO[X][Y] == 1) {
			_Temp = _S1;
			_S1 = _S2;
			_S2 = _Temp;
			X = 0;
			Y = 1;
			aux = _vec[0];
			_vec[0] = _vec[1];
			_vec[1] = aux;
			std::cout << "vec [0] = " << _vec[0] << std::endl;
			std::cout << "vec [1] = " << _vec[1] << std::endl;
			
		}

		

		sf::sleep(sf::seconds(0.5));
	}
 else {
 std::cout << "armado!!!!!!!!!" << _armado << std::endl;//
}

}

void Slider_puzzle::verificacion(){
	
	if (_vec[0] == 1 &&
		_vec[1] == 2 &&
		_vec[2] == 3 &&
		_vec[3] == 4 &&
		_vec[4] == 5 &&
		_vec[5] == 6 &&
		_vec[6] == 7 &&
		_vec[7] == 8 &&
		_vec[8] == 9) {
		_event = Estado_slider::armado ;
	}
		
}

void Slider_puzzle::cambiar_sprite(int numero){
	_sprite.setTexture(_textura[numero]);

	if (numero == 0){
		_sprite.setScale(3.151, 3.22);
	}
	else{
		_sprite.setScale(2.4, 1.56);
	}


}

Estado_slider Slider_puzzle::get_estado(){
	return _event;
}

sf::Sprite& Slider_puzzle::get_sprite(){	return _sprite; }

sf::Sprite& Slider_puzzle::get__S(){
	return _S;
}

sf::Sprite& Slider_puzzle::get__S1(){
	return _S1;
}

sf::Sprite& Slider_puzzle::get__S2(){
	return _S2;
}

sf::Sprite& Slider_puzzle::get__S3(){
	return _S3;
}

sf::Sprite& Slider_puzzle::get__S4(){
	return _S4;
}

sf::Sprite& Slider_puzzle::get__S5(){
	return _S5;
}

sf::Sprite& Slider_puzzle::get__S6(){
	return _S6;
}

sf::Sprite& Slider_puzzle::get__S7(){
	return _S7;
}

sf::Sprite& Slider_puzzle::get__S8(){
	return _S8;
}

sf::Sprite& Slider_puzzle::get__S9(){
	return _S9;
}

sf::Sprite& Slider_puzzle::get__Temp(){
	return _Temp;
}
