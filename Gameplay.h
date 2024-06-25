#pragma once
#include <SFML/Graphics.hpp>
#include "Personaje.h"
#include "Enemigo.h"
#include "Disparo.h"

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

};
