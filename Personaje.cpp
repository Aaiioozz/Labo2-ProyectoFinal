#include "Personaje.h"
#include <SFML/Audio.hpp>

 Personaje::Personaje(){
    texture.loadFromFile("avion_galaga.png");
    sprite.setTexture(texture);
    sprite.setPosition(400, 700);
    VidaT.loadFromFile("avion_vida.png");
    Vida.setTexture(VidaT);

}

 void Personaje::update(){
     ///Mueve el personaje (arriba, abajo, etc) segun la tecla que se presione
     // Arriba y abajo no son necesarias, estan de prueba
//         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
//            sprite.move(0, -velocity);
//        }
//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
//            sprite.move(0, velocity);
//        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            sprite.move(-velocity, 0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            sprite.move(velocity, 0);
        }
    ///Si se presiona el espacio dispara (se llama a la funcion de Shoot())
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            Shoot();
        }
    ///Permite que el Personaje no se salga de los limites de la pantalla
        if(sprite.getPosition().x<0){
            sprite.setPosition(0, sprite.getPosition().y);
        }
        if(sprite.getPosition().y<0){
            sprite.setPosition(sprite.getPosition().x, 0);
        }
        if(sprite.getPosition().x+sprite.getGlobalBounds().width>880){
            sprite.setPosition(880-sprite.getGlobalBounds().width, sprite.getPosition().y);
        }
        if(sprite.getPosition().y+sprite.getGlobalBounds().height>800){
            sprite.setPosition( sprite.getPosition().x, 800-sprite.getGlobalBounds().height);
        }
    ///Actualiza el disparo
        disp.update();
 }

void Personaje::Shoot(){
    if(disp.IsActive()==false){
        ///Si el disparo no esta activo, lo activa ubicandolo donde esta el personaje
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
///Creamos una copia nueva y le asignamos una posicion
sf::Sprite VidaSP=Vida;
<<<<<<< Updated upstream
VidaSP.setPosition(895+i*(VidaSP.getGlobalBounds().width+2), 200);
=======
///Se posiciona y dibuja 3 vidas horizontalmente
VidaSP.setPosition(895+i*(VidaSP.getGlobalBounds().width+1), 200);
>>>>>>> Stashed changes
 target.draw(VidaSP, states);
 }
}

sf::FloatRect Personaje::getBounds() const{
    return sprite.getGlobalBounds();
}

void Personaje::ResetearPosicion(){
///Vuelve a posicionar al personaje en la posicion inicial y desactiva del disparo
    sprite.setPosition(400, 700);
    disp.setActive(false);
}

void Personaje::BajarVida(){
///Se van quitando vidas y cada vez se reinicia el personaje en la posicion original
vidas--;
ResetearPosicion();
}



