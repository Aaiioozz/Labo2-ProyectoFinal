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
        // Direccion Aleatoria del Enemigo.
//        if(std::rand() % 2 + 1){}
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
        sprite.move(velocity, 0); // Movimiento EJE X
        // Probabilidad de Disparo
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

// ARRIBA EL ENEMIGO NORMAL
// ABAJO EMPIEZA EL OTRO ENEMIGO

 EnemigoAvanzado::EnemigoAvanzado(){
    texture.loadFromFile("enemigoavanzado_galaga.png");
    sprite.setTexture(texture);
    sprite.setPosition(450-sprite.getGlobalBounds().width/2, -sprite.getGlobalBounds().height);
 }

 void EnemigoAvanzado::update(){
//     COMPORTAMIENTO variado ENEMIGO.
    if(sprite.getPosition().y<=100.0f){
        sprite.move(0, velocity);
    }else{
        sprite.move(velocity,0);
         if(sprite.getPosition().x<=200 || sprite.getPosition().x+sprite.getGlobalBounds().width>=700){
            velocity=-velocity;
            if(sprite.getPosition().x / 2 >= 4){
                sprite.move(0,30);
            }

        }

    }

}



 void EnemigoAvanzado::draw(sf::RenderTarget& target, sf::RenderStates states)const{
    target.draw(sprite, states);
}

sf::FloatRect EnemigoAvanzado::getBounds() const{
    return sprite.getGlobalBounds();
}

void EnemigoAvanzado::ResetearPosicion(){
    sprite.setPosition(450-sprite.getGlobalBounds().width/2, -sprite.getGlobalBounds().height); // De prueba, realmente debe aparecer en la posicion donde fue disparado
    velocity=8.5f;
    disp.setActive(false);
}
