#include <SFML/Graphics.hpp>
#include"Personaje.h"
#include"Enemigo.h"
int main()
{
    ///inicializacion de la ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Prueba de juego");
    window.setFramerateLimit(60);

    Personaje Galaga;
    Enemigo DeathStar;
    ///Game Loop (update del juego)
    while (window.isOpen()){

        ///ReadInput actualizar los estados de los perifericos de entrada
        ///Leer la cola de mensajes
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        ///CMD - Joy
        Galaga.update();
        DeathStar.update();

        ///Update - actualiza los estados del juego
        window.clear();
        ///Draw (Dibuja)
        window.draw(Galaga);

        window.draw(DeathStar);

        ///Display - Flip
        window.display();
    }
    ///Liberacion del juego
    return 0;
}
