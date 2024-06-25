#ifndef PERSONAJE_H_INCLUDED
#define PERSONAJE_H_INCLUDED
#include <SFML/Graphics.hpp>
#include"Disparo.h"
class Personaje: public sf::Drawable{
sf::Sprite sprite;
sf::Texture texture;
float velocity=5;
Disparo disp;
public:
    Personaje();
    void update();
    void Shoot();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};



#endif // PERSONAJE_H_INCLUDED
