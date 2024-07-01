#pragma once
#include <SFML/Graphics.hpp>
#include "Colision.h"

class Disparo: public sf::Drawable, public Colision{
sf::Sprite sprite;
sf::Texture texture;
float velocity=-10.0f;
float velocityEnem=10.0f;
bool active=false;

public:
    Disparo();
    void update();
    void updateEnemigo();
    void setPosition(float x, float y);
    void setActive(bool active);
    bool IsActive() const;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;
};
