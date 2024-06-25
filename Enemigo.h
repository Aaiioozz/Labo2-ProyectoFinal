#ifndef ENEMIGO_H_INCLUDED
#define ENEMIGO_H_INCLUDED
#include <SFML/Graphics.hpp>
#include"Disparo.h"
class Enemigo: public sf::Drawable{
sf::Sprite sprite;
sf::Texture texture;
float velocity=5.0f;
Disparo disp;
public:
    Enemigo();
    void update();
    void Shoot();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


#endif // ENEMIGO_H_INCLUDED
