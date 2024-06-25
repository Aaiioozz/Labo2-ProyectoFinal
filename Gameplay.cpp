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

        if(_jugador.isCollision(_enemigo)){
        cout<<"Hay colision"<<endl; // Borrar, esta solo de prueba para comprobar si los objetos colisionaron
        }else{ cout<<"NO HAY COLISION"<<endl; }
        /// ADENTRO DEL IF HACER LO QUE OCURRE CUANDO COLISIONAN.
    }


