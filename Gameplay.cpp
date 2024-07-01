#include "Gameplay.h"
#include <iostream>

using namespace std;

        Escena::Escena(){
        }

        void Escena::draw(sf::RenderTarget& target, sf::RenderStates states) const{
            target.draw(_jugador, states);
            target.draw(_enemigo, states);
        }

        void Escena::update(){
        _jugador.update();
        _enemigo.update();


        if(_enemigo.disp.IsActive()&&_enemigo.disp.isCollision(_jugador)){
        _jugador.BajarVida();
        _enemigo.disp.setActive(false);
        }
        if(_jugador.disp.IsActive()&&_jugador.disp.isCollision(_enemigo)){
        _enemigo.ResetearPosicion();
        _jugador.disp.setActive(false);
        }
        if(_jugador.isCollision(_enemigo)){
        _jugador.BajarVida();
        _enemigo.ResetearPosicion();
        }
        }


