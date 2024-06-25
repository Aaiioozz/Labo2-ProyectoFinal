#include"Enemigo.h"

 Enemigo::Enemigo(){
    texture.loadFromFile("enemigo_galaga.png");
    sprite.setTexture(texture);
 }
 void Enemigo::draw(sf::RenderTarget& target, sf::RenderStates states)const{
 target.draw(sprite, states);
 }

