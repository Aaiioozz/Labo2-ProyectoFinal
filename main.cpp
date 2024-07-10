#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Gameplay.h"
#include "Puntaje.h"

#include <cstdlib>
#include <ctime>
#include <cstring>
#include <iostream>

using namespace std;

// ESTA PARTE ES EL DIRECTOR
int main()
{
    ///Funcion de la libreria ctime
    std::srand(std::time(nullptr));
<<<<<<< Updated upstream
    ///inicializacion de la ventana
    sf::RenderWindow window(sf::VideoMode(1100, 800), "Prueba de juego");
=======
    ///Inicializacion de la ventana
    sf::RenderWindow window(sf::VideoMode(1100, 800), "Proyecto Laboratorio II");
>>>>>>> Stashed changes
    window.setFramerateLimit(60);
    EstadoJuego EstadoActual=MENU;
    ///Usamos el tamaño de la ventana
    Menu menu(window.getSize().x, window.getSize().y);
    Escena Gameplay;
    Ranking RankingP;
    ///Game Loop (update del juego)
    while (window.isOpen()){
        ///ReadInput actualiza los estados de los perifericos de entrada
        ///Leer la cola de mensajes
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
            }

                switch(EstadoActual){
            case MENU:
                menu.Eventos(window, event, EstadoActual);
                break;
            case JUEGO:
                if(Gameplay.EstadoGameOver()){
                    EstadoActual=GAMEOVER;
                }
                break;
            case RANKING:
                if(event.type==sf::Event::KeyPressed&&event.key.code==sf::Keyboard::Escape){
                    EstadoActual=MENU;
                }
                break;
            case GAMEOVER:
                bool VolverAlMenu=false;
                Gameplay.Eventos(window, event, VolverAlMenu);
                if(VolverAlMenu){
                    EstadoActual=MENU;
                    Gameplay.ReiniciarJuego();
                }
                break;
                }
        }
        window.clear();
        switch(EstadoActual){
    case MENU:
        menu.draw(window);
        break;
    case JUEGO:
        Gameplay.update();
        window.draw(Gameplay);
        if(Gameplay.EstadoGameOver()){
            EstadoActual=GAMEOVER;
        }
        break;
    case RANKING:
        RankingP.MostrarRanking();
        RankingP.draw(window);
        break;
    case GAMEOVER:
        window.draw(Gameplay);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)||sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            EstadoActual=MENU;
            Gameplay.ReiniciarJuego();
        }
        break;
        }
        window.display();
    }
}
