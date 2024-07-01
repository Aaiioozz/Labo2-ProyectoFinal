#include "PowerUp.h"
PowerUp::PowerUp(){
texture.loadFromFile("rayo_galaga.png");
sprite.setTexture(texture);
sprite.setPosition(0, 0);
}
void PowerUp::update(){
sprite.move(0, velocity);
if(sprite.getPosition().y>800){
    sprite.setPosition(rand()%900, -sprite.getGlobalBounds().height);
}
}
sf::FloatRect PowerUp::getBounds() const{
    return sprite.getGlobalBounds();
}
void PowerUp::draw(sf::RenderTarget& target, sf::RenderStates states) const{
target.draw(sprite, states);
}
