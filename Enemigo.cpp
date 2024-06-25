#include"Enemigo.h"

 Enemigo::Enemigo(){
    texture.loadFromFile("enemigo_galaga.png");
    sprite.setTexture(texture);
    sprite.setPosition(400-sprite.getGlobalBounds().width/2, -sprite.getGlobalBounds().height);
 }
 void Enemigo::update(){
    if(sprite.getPosition().y<50){
        sprite.move(0, velocity);
    } else{
        if(sprite.getPosition().x<=0||sprite.getPosition().x+sprite.getGlobalBounds().width>=800){
            velocity=-velocity;
        }
        sprite.move(velocity, 0);
    }
 }

 void Enemigo::draw(sf::RenderTarget& target, sf::RenderStates states)const{
 target.draw(sprite, states);
 }

