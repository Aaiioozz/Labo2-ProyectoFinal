#ifndef DISPARO_H_INCLUDED
#define DISPARO_H_INCLUDED
#include <SFML/Graphics.hpp>
class Disparo: public sf::Drawable{
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
};


#endif // DISPARO_H_INCLUDED
