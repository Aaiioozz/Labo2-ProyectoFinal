#pragma once
#include <SFML/Graphics.hpp>
enum EstadoJuego{
MENU,
JUEGO,
RANKING,
GAMEOVER
};
class Menu{
private:
    ///Fuente
    sf::Font font;
    ///Textos del menu
    sf::Text titulo;
    sf::Text subtitulo;
    sf::Text menu1;
    sf::Text menu2;
    sf::Text menu3;
    sf::Text integrante;
    ///Botones del menu(Rectangulos)
    sf::RectangleShape BotonMenu1;
    sf::RectangleShape BotonMenu2;
    sf::RectangleShape BotonMenu3;
    ///Fondo
    sf::Sprite Fondo;
    sf::Texture texture;

public:
    ///Constructor con las medidas de la pantalla
    Menu(float x, float y);
    ///Actualiza el Menu
    void update();

    void draw(sf::RenderWindow  &windows);

    ///Maneja eventos o los estados del menu
    void Eventos(sf::RenderWindow &windows, sf::Event &evento, EstadoJuego &EstadoActual);
};
