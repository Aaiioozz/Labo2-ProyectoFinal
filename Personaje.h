#pragma once
#include <SFML/Graphics.hpp>
#include "Disparo.h"
#include "Colision.h"

class Personaje: public sf::Drawable, public Colision{
sf::Sprite sprite;
sf::Texture texture;
float velocity=5;
Disparo disp;

public:
    Personaje();
    void update();
    void Shoot();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;
};

