#include "Disparo.h"

Disparo::Disparo() {
    texture.loadFromFile("disparo.png");
    sprite.setTexture(texture);
 }

void Disparo::update() {
    if (active==true) {
        sprite.move(0, velocity);
        ///Si el disparo sale de la pantalla se desactiva
        if (sprite.getPosition().y+sprite.getGlobalBounds().height<0) {
            active = false;
        }
    }
}

void Disparo::updateEnemigo() {
    if (active==true) {
        sprite.move(0, velocityEnem);
        ///Si el disparo sale de la pantalla se desactiva
        if (sprite.getPosition().y>800) {
            active = false;
        }
    }
}

void Disparo::setActive(bool active){
    ///Le asigna true o false a active para activarlo o desactivarlo
    this->active=active;
}

bool Disparo::IsActive() const{
    ///Devuelve el estado(true o false) del disparo
    return active;
}

void Disparo::setPosition(float x, float y){
///Le asigna la posicion
sprite.setPosition(x, y);
active=true;
}

void Disparo::draw(sf::RenderTarget& target, sf::RenderStates states)const{
    if(active==true){
    target.draw(sprite, states);
    }
}

sf::FloatRect Disparo::getBounds() const{
    return sprite.getGlobalBounds();
}
