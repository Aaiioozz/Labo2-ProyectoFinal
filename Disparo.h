#pragma once
#include <SFML/Graphics.hpp>
#include "Colision.h"

class Disparo: public sf::Drawable, public Colision{
private:
sf::Sprite sprite;
sf::Texture texture;
///Velocidad Del disparo (Jugador)
int velocity=-10;
///Velocidad del disparo (Enemigo)
int velocityEnem=10;
///true=Disparo activo, false=Disparo desactivo
bool active=false;

public:
    Disparo();
    ///Actualiza el disparo del jugador
    void update();
    ///Actualiza el disparo del enemigo
    void updateEnemigo();
    ///GetTexture retorna la textura y el setTexture la establece
    sf::Texture& getTexture(){return texture;}
    void setTexture(){sprite.setTexture(texture);}
    ///Posiciona el disparo
    void setPosition(float x, float y);
    ///Activa o lo desactiva al disparo
    void setActive(bool active);
    ///Verifica si el disparo esta activo o no
    bool IsActive() const;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;
};
