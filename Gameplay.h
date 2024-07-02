#pragma once
#include <SFML/Graphics.hpp>
#include "Personaje.h"
#include "Enemigo.h"
#include "Disparo.h"
#include "PowerUp.h"

/// Director -> Escena -> Actores
///                    -> Fondos

class Escena: public sf::Drawable{
    public:
        Escena();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        void update();
    private:
        Personaje _jugador;
        Enemigo _enemigo;
        EnemigoAvanzado _enemigoavanzado;
        PowerUp _powerup;

        int Puntos=0;
        int Obj=0;
        sf::Font font;
        sf::Text text;
        sf::Text textNum;
        sf::Text tObjeto;
        sf::RectangleShape Rectangulo;
        sf::Sprite Fondo, Fondo2;
        sf::Texture texture;
        float fondoGalaga=1.0f;
        void AgregarObjs();
        sf::Sprite Objetos[9];
        sf::Texture tObjetos;
        void SpawnPowerUp(float x, float y){
        if(_powerup.Activo()==false&&rand()%100<15){
            _powerup.Activate(x, y);
        }
        }
};
