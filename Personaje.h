#pragma once
#include <SFML/Graphics.hpp>
#include "Disparo.h"
#include "Colision.h"

class Personaje: public sf::Drawable, public Colision{
private:
sf::Sprite sprite;
sf::Texture texture;
///Velocidad del personaje
int velocity=5;
sf::Sprite Vida;
sf::Texture VidaT;
///Cantidad de vidas
int vidas=3;

public:
    Personaje();
    ///Actualiza el personaje
    void update();
    ///Maneja el disparo
    void Shoot();
    ///GetTexture retorna la textura y el setTexture la establece
    sf::Texture& getTexture(){return texture;}
    sf::Texture& getTextureV(){return VidaT;}
    void setTexture(){sprite.setTexture(texture);}
    void setTextureV(){Vida.setTexture(VidaT);}
    ///Esto ayuda a manejar los disparos del personaje facilmente
    Disparo disp;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;

    ///Reiniciar la posicion del personaje
    void ResetearPosicion();
    ///Se baja la vida del personaje
    void BajarVida();
    ///Establece y le asigna la velocidad al personaje
    void setVelocity(float vel){velocity=vel;}
    ///Se retorna tanto la velocidad como las vidas
    float getVelocity()const{return velocity;}
    int getVidas()const{return vidas;}

};

