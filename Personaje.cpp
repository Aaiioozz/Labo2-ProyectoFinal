#include "Personaje.h"

 Personaje::Personaje(){
    texture.loadFromFile("avion_galaga.png");
    sprite.setTexture(texture);
    sprite.setPosition(400, 700);
    VidaT.loadFromFile("avion_vida.png");
    Vida.setTexture(VidaT);
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
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            Shoot();
        }
        if(sprite.getPosition().x<0){
            sprite.setPosition(0, sprite.getPosition().y);
        }
        if(sprite.getPosition().y<0){
            sprite.setPosition(sprite.getPosition().x, 0);
        }
        if(sprite.getPosition().x+sprite.getGlobalBounds().width>900){
            sprite.setPosition(900-sprite.getGlobalBounds().width, sprite.getPosition().y);
        }
        if(sprite.getPosition().y+sprite.getGlobalBounds().height>800){
            sprite.setPosition( sprite.getPosition().x, 800-sprite.getGlobalBounds().height);
        }
        disp.update();
 }

void Personaje::Shoot(){
    if(disp.IsActive()==false){
        float x=sprite.getPosition().x+sprite.getGlobalBounds().width/2;
        float y=sprite.getPosition().y;
        disp.setPosition(x, y);
        disp.setActive(true);
    }
}

void Personaje::draw(sf::RenderTarget& target, sf::RenderStates states)const{
 target.draw(sprite, states);
 target.draw(disp, states);
 for(int i=0; i<vidas;i++){
sf::Sprite VidaSP=Vida;
VidaSP.setPosition(10+i*(VidaSP.getGlobalBounds().width+2), 10);
 target.draw(VidaSP, states);
 }
}

sf::FloatRect Personaje::getBounds() const{
    return sprite.getGlobalBounds();
}

void Personaje::ResetearPosicion(){
    sprite.setPosition(400, 700);
    disp.setActive(false);
}

void Personaje::BajarVida(){
vidas--;
ResetearPosicion();
if(vidas<=0){
    ///GAME OVER??
    vidas=3;
    ResetearPosicion();
}
}

