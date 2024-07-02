#include "Gameplay.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

        Escena::Escena(){
            ///Puntaje
            font.loadFromFile("EarlyGameBoy.ttf");
            text.setFont(font);
            text.setPosition(900, 10);
            text.setString("Puntos");
            textNum.setFont(font);
            textNum.setPosition(960, 50);
            textNum.setString(std::to_string(Puntos));
            ///Objetos
            tObjeto.setFont(font);
            tObjeto.setPosition(888, 400);
            tObjeto.setString("Objetos");
            tObjetos.loadFromFile("rayo_galaga.png");
            ///Rectangulo
            Rectangulo.setSize(sf::Vector2f(216, 798));
            Rectangulo.setPosition(880, 1);
            Rectangulo.setFillColor(sf::Color::Black);
            Rectangulo.setOutlineColor(sf::Color::White);
            Rectangulo.setOutlineThickness(4);
            ///Fondo
            texture.loadFromFile("fondo_galaga.png ");
            Fondo.setTexture(texture);
            Fondo.setPosition(0, 0);
            Fondo2.setTexture(texture);
            Fondo2.setPosition(0, -texture.getSize().y);
        }
        void Escena::AgregarObjs(){
        if(Obj<9){
            sf::Sprite NuevoObj;
            NuevoObj.setTexture(tObjetos);
            int x=880+(Obj%5)*48;
            int y=440+(Obj/5)*48;
            NuevoObj.setPosition(x, y);
            Objetos[Obj]=NuevoObj;
            Obj++;
        }
        }
        void Escena::draw(sf::RenderTarget& target, sf::RenderStates states) const{
            target.draw(Fondo, states);
            target.draw(Fondo2, states);
            target.draw(Rectangulo, states);
            target.draw(_jugador, states);
            target.draw(_enemigo, states);
            target.draw(_enemigoavanzado, states);
            target.draw(_powerup, states);
            target.draw(text, states);
            target.draw(textNum, states);
            target.draw(tObjeto, states);
            for(int i=0; i<Obj; i++){
                target.draw(Objetos[i], states);
            }
        }
        void Escena::update(){
        _jugador.update();
        _enemigo.update();
        _enemigoavanzado.update();
        _powerup.update();

        // ENEMIGO NORMAL
        if(_enemigo.disp.IsActive()&&_enemigo.disp.isCollision(_jugador)){
        _jugador.BajarVida();
        _enemigo.disp.setActive(false);
        }

        if(_jugador.disp.IsActive()&&_jugador.disp.isCollision(_enemigo)){
        _enemigo.ResetearPosicion();
        _jugador.disp.setActive(false);
        Puntos++;
        textNum.setString(std::to_string(Puntos));
        SpawnPowerUp(_enemigo.getPosition().x, _enemigo.getPosition().y);
        }
        /// ENEMIGO AVANZADO
        if(_jugador.isCollision(_enemigoavanzado)){
        _jugador.BajarVida();
        }

        if(_jugador.disp.IsActive()&&_jugador.disp.isCollision(_enemigoavanzado)){
        _jugador.disp.setActive(false);
        _enemigoavanzado.ResetearPosicion();
        Puntos++;
        textNum.setString(std::to_string(Puntos));
        SpawnPowerUp(_enemigoavanzado.getPosition().x, _enemigoavanzado.getPosition().y);
        }

        ///POWERUP
        if(_powerup.Activo()&&_jugador.isCollision(_powerup)){
            _jugador.setVelocity(_jugador.getVelocity()+0.5);
            _powerup.Desactivo();
            AgregarObjs();
        }
        _powerup.update();

        Fondo.move(0, fondoGalaga);
        Fondo2.move(0, fondoGalaga);
        if(Fondo.getPosition().y>=texture.getSize().y) {
        Fondo.setPosition(0, Fondo2.getPosition().y-texture.getSize().y);
        }
        if(Fondo2.getPosition().y>=texture.getSize().y) {
        Fondo2.setPosition(0, Fondo.getPosition().y-texture.getSize().y);
        }
    }



