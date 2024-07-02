#pragma once
#include <SFML/Graphics.hpp>
#include "Colision.h"

class PowerUp: public sf::Drawable, public Colision{
private:
sf::Sprite sprite;
sf::Texture texture;
float velocity=2.0f;
bool act=false;
public:
    PowerUp();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;
    void setPosition(float x, float y){sprite.setPosition(x, y);}
    bool Activo()const{return act;}
    void Desactivo(){act=false;}
    void Activate(float x, float y){act=true; sprite.setPosition(x, y);}
};
