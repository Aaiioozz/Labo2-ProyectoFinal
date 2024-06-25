#include"Enemigo.h"
#include<ctime>

 Enemigo::Enemigo(){
    texture.loadFromFile("enemigo_galaga.png");
    sprite.setTexture(texture);
    sprite.setPosition(450-sprite.getGlobalBounds().width/2, -sprite.getGlobalBounds().height);
 }
 void Enemigo::update(){
    if(sprite.getPosition().y<50){
        sprite.move(0, velocity);
    } else{
        if(sprite.getPosition().x<=0||sprite.getPosition().x+sprite.getGlobalBounds().width>=900){
            velocity=-velocity;
        }
        sprite.move(velocity, 0);
        if(std::rand()%100<2){
            Shoot();
        }
    }
    disp.updateEnemigo();
 }
void Enemigo::Shoot(){
    if(disp.IsActive()==false){
        disp.setPosition(sprite.getPosition().x+sprite.getGlobalBounds().width/2, sprite.getPosition().y+sprite.getGlobalBounds().height);
        disp.setActive(true);
    }
}
 void Enemigo::draw(sf::RenderTarget& target, sf::RenderStates states)const{
 target.draw(sprite, states);
 target.draw(disp, states);
 }

