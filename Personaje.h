#pragma once
#include <SFML/Graphics.hpp>
#include "Disparo.h"
#include "Colision.h"

class Personaje: public sf::Drawable, public Colision{
private:
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
    void setVelocity(float vel){velocity=vel;}
    float getVelocity()const{return velocity;}

};

