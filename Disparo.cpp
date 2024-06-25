#include "Disparo.h"

Disparo::Disparo() {
    texture.loadFromFile("disparo.png");
    sprite.setTexture(texture);
 }

void Disparo::update() {
    if (active==true) {
        sprite.move(0, velocity);
        if (sprite.getPosition().y+sprite.getGlobalBounds().height<0) {
            active = false;
        }
    }
}
void Disparo::updateEnemigo() {
    if (active==true) {
        sprite.move(0, velocityEnem);
        if (sprite.getPosition().y>800) {
            active = false;
        }
    }
}

void Disparo::setActive(bool active){
    this->active=active;
}

bool Disparo::IsActive() const{
    return active;
}

void Disparo::setPosition(float x, float y){
sprite.setPosition(x, y);
active=true;
}

void Disparo::draw(sf::RenderTarget& target, sf::RenderStates states)const{
 if(active==true){
 target.draw(sprite, states);
 }
}
