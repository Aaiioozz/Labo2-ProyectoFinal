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
        PowerUp _powerup;
        int Puntos=0;
        sf::Font font;
        sf::Text text;
        sf::Sprite Fondo, Fondo2;
        sf::Texture texture;
        float fondoGalaga=1.0f;
};
