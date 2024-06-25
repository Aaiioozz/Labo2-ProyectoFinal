#ifndef ENEMIGO_H_INCLUDED
#define ENEMIGO_H_INCLUDED
#include <SFML/Graphics.hpp>
class Enemigo: public sf::Drawable{
sf::Sprite sprite;
sf::Texture texture;
float velocity=3;
public:
    Enemigo();
    //void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


#endif // ENEMIGO_H_INCLUDED
