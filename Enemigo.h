#pragma once
#include <SFML/Graphics.hpp>
#include "Disparo.h"
#include "Colision.h"

class Enemigo: public sf::Drawable, public Colision{
private:
sf::Sprite sprite;
sf::Texture texture;
float velocity=5.0f;

public:
    Enemigo();
    void update();
    void Shoot();
    Disparo disp;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;
    void ResetearPosicion();
    sf::Vector2f getPosition() const{return sprite.getPosition();}
};

class EnemigoAvanzado : public sf::Drawable, public Colision{

    public:
    EnemigoAvanzado();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;
    void ResetearPosicion();
    Disparo disp;
    sf::Vector2f getPosition() const{return sprite.getPosition();}

    private:
    float velocity = 3.0f;

    sf::Sprite sprite;
    sf::Texture texture;
};
