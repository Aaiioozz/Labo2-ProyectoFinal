#pragma once
#include <SFML/Graphics.hpp>
#include "Colision.h"

class PowerUp: public sf::Drawable, public Colision{
private:
sf::Sprite sprite;
sf::Texture texture;
<<<<<<< Updated upstream
float velocity=2.0f;
=======
///Velocidad del power up
int velocity=2;
///true=Power up activo, false=Power up desactivo
>>>>>>> Stashed changes
bool act=false;
public:
    PowerUp();
    ///Actualiza el PowerUp
    void update();
    ///GetTexture retorna la textura y el setTexture la establece
    sf::Texture& getTexture(){return texture;}
    void setTexture(){sprite.setTexture(texture);}

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;

    ///Le asigna la posicion
    void setPosition(float x, float y){sprite.setPosition(x, y);}
<<<<<<< Updated upstream
    bool Activo()const{return act;}
    void Desactivo(){act=false;}
=======
    ///Verifica si esta activo
    bool Activo()const{return act;}
    ///Lo Desactiva
    void Desactivo(){act=false;}
    ///Lo activa y le asigna su posicion
>>>>>>> Stashed changes
    void Activate(float x, float y){act=true; sprite.setPosition(x, y);}
};
