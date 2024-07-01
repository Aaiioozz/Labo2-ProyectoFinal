#include "Enemigo.h"
#include <ctime>
#include <iostream>

using namespace std;

 Enemigo::Enemigo(){
    texture.loadFromFile("enemigo_galaga.png");
    sprite.setTexture(texture);
    sprite.setPosition(450-sprite.getGlobalBounds().width/2, -sprite.getGlobalBounds().height);
 }

 bool directionChange = false;
 void Enemigo::update(){
    if(sprite.getPosition().y<50){
        sprite.move(0, velocity);
    } else{
        // Direccion del Enemigo Comun
        if(sprite.getPosition().x<=0||sprite.getPosition().x+sprite.getGlobalBounds().width>=900){
            velocity=-velocity;
            // Verifica en que direccion esta false = abajo | true = arriba
            if(!directionChange){
                if(sprite.getPosition().y<=300.0f){
                sprite.move(0,50);
                }
                if(sprite.getPosition().y==300.0f){
                    directionChange = true;
                }
            }
            else{
                    sprite.move(0,-50);
                    if(sprite.getPosition().y == 50.0f){
                    directionChange = false;
                    }
                }
            }

        }

        // Probabilidad de Disparo
        sprite.move(velocity, 0);
        if(std::rand()%100<2){
            Shoot();
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

sf::FloatRect Enemigo::getBounds() const{
    return sprite.getGlobalBounds();
}

void Enemigo::ResetearPosicion(){
    sprite.setPosition(450-sprite.getGlobalBounds().width/2, -sprite.getGlobalBounds().height);
    velocity=5.0f;
    disp.setActive(false);
}
