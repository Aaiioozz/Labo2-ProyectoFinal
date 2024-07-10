#pragma once
#include <SFML/Graphics.hpp>
#include "Disparo.h"
#include "Colision.h"

class Enemigo: public sf::Drawable, public Colision{
private:
sf::Sprite sprite;
sf::Texture texture;
///Velocidad del enemigo
int velocity=5;

public:
    Enemigo();
    ///Actualiza al enemigo
    void update();
    ///Maneja el disparo
    void Shoot();
    ///GetTexture retorna la textura y el setTexture la establece
    sf::Texture& getTexture(){return texture;}
    void setTexture(){sprite.setTexture(texture);}
    ///Esto ayuda a manejar los disparos del personaje facilmente
    Disparo disp;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;

    ///Reinicia la posicion del enemigo
    void ResetearPosicion();
<<<<<<< Updated upstream
=======
    ///Retorna la posicion del enemigo
>>>>>>> Stashed changes
    sf::Vector2f getPosition() const{return sprite.getPosition();}
};

class EnemigoAvanzado : public sf::Drawable, public Colision{
public:
    EnemigoAvanzado();
    ///Actualiza al enemigo avanzado
    void update();
    ///GetTexture retorna la textura y el setTexture la establece
    sf::Texture& getTexture(){return texture;}
    void setTexture(){sprite.setTexture(texture);}

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;

    ///Reinicia la posicion del enemigo avanzado
    void ResetearPosicion();
    ///Esto ayuda a manejar los disparos del personaje facilmente
    Disparo disp;
<<<<<<< Updated upstream
=======
    ///Retorna la posicion del enemigo
>>>>>>> Stashed changes
    sf::Vector2f getPosition() const{return sprite.getPosition();}

private:
    ///velocidad del enemigo avanzado
    int velocity = 3;
    sf::Sprite sprite;
    sf::Texture texture;
};
