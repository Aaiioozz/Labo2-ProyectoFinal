#include <SFML/Graphics.hpp>
#include "Gameplay.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main()
{
    std::srand(std::time(nullptr));
    ///inicializacion de la ventana
    sf::RenderWindow window(sf::VideoMode(1100, 800), "Prueba de juego");
    window.setFramerateLimit(60);

    Escena Gameplay;

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

        ///Update - actualiza los estados del juego
        Gameplay.update();
        window.clear();
        ///Draw (Dibuja)
        window.draw(Gameplay);

        ///Display - Flip
        window.display();
    }
    ///Liberacion del juego
    return 0;
}
