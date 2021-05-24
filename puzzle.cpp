#include "puzzle.h"

puzzle::puzzle(){
    for (auto &p: _fueguitoscreado){
        p= false;
    }

    x = 0;
    _cantidad_fuego = 0;
    _reset = _fin = false;
    _tics = 0;
    _tex_fondo.loadFromFile("imagenes/fondo_puzzle1.jpeg");
    _sp_fondo.setTexture(_tex_fondo);
    _sp_fondo.setScale(2.8, 3);
    _texture[0].loadFromFile("imagenes/GameOver.jpeg");
    _texture[1].loadFromFile("imagenes/Congratuletion.jpeg");
    
}

void puzzle::cmd(){
    _tics++;

    if (_tics == 1) {
        _faro.cambiar_estado(Estado_Faro::movimiento);
       
       
    }

   
   
    crear_fueguitos();
   
        _faro.cmd();
    for (int x = 0; x < 30; x++) {
        if (_fueguitoscreado[x]) _fueguito[x].cmd();
    }

    collision();

    _barrita.setvida(_cantidad_fuego);
    _barrita.cmd();

    
    if (_cantidad_fuego < 5 && x == 29) _reset = true;
   
}

void puzzle::update() {
    _faro.update();
    for (int x = 0; x < 30; x++) {
        if (_fueguitoscreado[x]) _fueguito[x].update();
    }

    _barrita.setframe();
}

sf::Sprite& puzzle::get_draw_faro(){
    return _faro.get_draw_Faro();
}

Fueguito* puzzle::get_draw_fueguito(){
   
    return _fueguito;
}

sf::Sprite& puzzle::get_draw_barrita(){
    return _barrita.get_draw();
}

sf::Sprite& puzzle::get_draw_fondo() { return _sp_fondo; }

sf::Sprite& puzzle::get_draw_sprite(){

    return _sprite;
}

void puzzle::collision() {
    for (int x = 0; x < 30; x++) {
        if (_fueguitoscreado[x]) {
            if (_faro.get_draw_Faro().getGlobalBounds().intersects(_fueguito[x].get_draw_Fueguito().getGlobalBounds())) {
                _fueguito[x].get_draw_Fueguito().setPosition(_fueguito[x].get_draw_Fueguito().getPosition().x, 900);
                _cantidad_fuego++;
                if (_cantidad_fuego == 5) _fin = true;
                _fueguitoscreado[x] = false;
            }
            
            
           
           
        }
         
        
    
    }
    if (_cantidad_fuego < 5) _fin = false;

}

void puzzle::crear_fueguitos(){
    if ((int)_tics%100==0) {
        _fueguito[x].cambiar_estado(Estado_Fueguito::caida);
        _fueguitoscreado[x] = true;
        if (x<29) x++;
    }
}

bool puzzle::get_fin(){
    return _fin;
}

bool puzzle::reset()
{
    
    return _reset;
}

void puzzle::cambiar_sprite(int numero){

    _sprite.setTexture(_texture[numero]);

    if (numero == 0) { _sprite.setScale(1.23,1.40); }

    if (numero == 1) { _sprite.setScale(3, 3.5); }

    

}


