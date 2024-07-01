#include "Gameplay.h"
#include <iostream>

using namespace std;

        Escena::Escena(){
            font.loadFromFile("EarlyGameBoy.ttf");
            text.setFont(font);
            text.setPosition(615, 10);
            text.setString("Puntos: "+std::to_string(Puntos));
            texture.loadFromFile("fondo_galaga.png ");
            Fondo.setTexture(texture);
            Fondo.setPosition(0, 0);
            Fondo2.setTexture(texture);
            Fondo2.setPosition(0, -texture.getSize().y);
        }

        void Escena::draw(sf::RenderTarget& target, sf::RenderStates states) const{
            target.draw(Fondo, states);
            target.draw(Fondo2, states);
            target.draw(_jugador, states);
            target.draw(_enemigo, states);
            target.draw(_powerup, states);
            target.draw(text, states);
        }

        void Escena::update(){
        _jugador.update();
        _enemigo.update();
        _powerup.update();


        if(_enemigo.disp.IsActive()&&_enemigo.disp.isCollision(_jugador)){
        _jugador.BajarVida();
        _enemigo.disp.setActive(false);
        }
        if(_jugador.disp.IsActive()&&_jugador.disp.isCollision(_enemigo)){
        _enemigo.ResetearPosicion();
        _jugador.disp.setActive(false);
        Puntos++;
        text.setString("Puntos: "+std::to_string(Puntos));
        }
        if(_jugador.isCollision(_enemigo)){
        _jugador.BajarVida();
        _enemigo.ResetearPosicion();
        }
        if(_jugador.isCollision(_powerup)){
            _jugador.setVelocity(_jugador.getVelocity()+0.5);
            _powerup.setPosition(rand()%900, -_powerup.getBounds().height);
        }
        Fondo.move(0, fondoGalaga);
        Fondo2.move(0, fondoGalaga);
        if(Fondo.getPosition().y>=texture.getSize().y) {
        Fondo.setPosition(0, Fondo2.getPosition().y-texture.getSize().y);
        }
        if(Fondo2.getPosition().y>=texture.getSize().y) {
        Fondo2.setPosition(0, Fondo.getPosition().y-texture.getSize().y);
        }
    }



