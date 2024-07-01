#pragma once
#include <SFML/Graphics.hpp>
#include "Disparo.h"
#include "Colision.h"

class Personaje: public sf::Drawable, public Colision{
sf::Sprite sprite;
sf::Texture texture;
float velocity=5;
sf::Sprite Vida;
sf::Texture VidaT;
int vidas=3;

public:
    Personaje();
    void update();
    void Shoot();
    Disparo disp;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;
    void ResetearPosicion();
    void BajarVida();
    int getVidas() const;
};

