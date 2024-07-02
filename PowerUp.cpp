#include "PowerUp.h"

PowerUp::PowerUp(){
texture.loadFromFile("rayo_galaga.png");
sprite.setTexture(texture);
sprite.setPosition(0, 0);
}
void PowerUp::update(){
if(act){
sprite.move(0, velocity);
if(sprite.getPosition().y>800){
    Desactivo();
}
}
}
sf::FloatRect PowerUp::getBounds() const{
    return sprite.getGlobalBounds();
}
void PowerUp::draw(sf::RenderTarget& target, sf::RenderStates states) const{
if(act){
target.draw(sprite, states);
}
}
