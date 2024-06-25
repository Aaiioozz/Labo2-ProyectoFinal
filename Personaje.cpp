#include"Personaje.h"

 Personaje::Personaje(){
    texture.loadFromFile("avion_galaga.png");
    sprite.setTexture(texture);
 }
 void Personaje::update(){
         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            sprite.move(0, -velocity);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            sprite.move(0, velocity);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            sprite.move(-velocity, 0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            sprite.move(velocity, 0);
        }

        if(sprite.getPosition().x<0){
            sprite.setPosition(0, sprite.getPosition().y);
        }
        if(sprite.getPosition().y<0){
            sprite.setPosition(sprite.getPosition().x, 0);
        }
        if(sprite.getPosition().x+sprite.getGlobalBounds().width>800){
            sprite.setPosition(800-sprite.getGlobalBounds().width, sprite.getPosition().y);
        }
        if(sprite.getPosition().y+sprite.getGlobalBounds().height>600){
            sprite.setPosition( sprite.getPosition().x, 600-sprite.getGlobalBounds().height);
        }
 }

 void Personaje::draw(sf::RenderTarget& target, sf::RenderStates states)const{
 target.draw(sprite, states);
 }
