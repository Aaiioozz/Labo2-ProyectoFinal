#include "Enemigo.h"
#include <ctime>
#include <iostream>

using namespace std;

 Enemigo::Enemigo(){
    texture.loadFromFile("enemigo_galaga.png");
    sprite.setTexture(texture);
    sprite.setPosition(450-sprite.getGlobalBounds().width/2, -sprite.getGlobalBounds().height);
 }

 void Enemigo::update(){
      bool directionChange = false;
    if(sprite.getPosition().y<50){
        sprite.move(0, velocity);
    } else{
        // Direccion Aleatoria del Enemigo.
//        if(std::rand() % 2 + 1){}
        if(sprite.getPosition().x<=0||sprite.getPosition().x+sprite.getGlobalBounds().width>=860){
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
                    if(sprite.getPosition().y == 50.0f){
                    directionChange = false;
                    }
                    sprite.move(0,-50);
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
    sprite.setPosition(rand()%600-sprite.getGlobalBounds().width/2, -sprite.getGlobalBounds().height);
    velocity=5;
    disp.setActive(false);
}

// ARRIBA EL ENEMIGO NORMAL
// ABAJO EMPIEZA EL OTRO ENEMIGO

 EnemigoAvanzado::EnemigoAvanzado(){
    texture.loadFromFile("enemigoavanzado_galaga.png");
    sprite.setTexture(texture);
    sprite.setPosition(rand()%860-sprite.getGlobalBounds().width/2, -sprite.getGlobalBounds().height);
 }

 void EnemigoAvanzado::update(){
    // Si se va fuera del mapa regresa
    if(sprite.getPosition().y >= 800) {
        ResetearPosicion();
    }
//     COMPORTAMIENTO variado ENEMIGO.
    if(sprite.getPosition().y<=100){
        sprite.move(0, velocity);
    }else{
        sprite.move(velocity,0);
         if(sprite.getPosition().x<=200 || sprite.getPosition().x+sprite.getGlobalBounds().width>=700){
            velocity=-velocity;
            if(sprite.getPosition().x >= 400 || sprite.getPosition().x <= 400){
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
    sprite.setPosition(rand()%860-sprite.getGlobalBounds().width, -sprite.getGlobalBounds().height);
    velocity=9.5f;
}
