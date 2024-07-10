#pragma once
#include <SFML/Graphics.hpp>
#include "Personaje.h"
#include "Enemigo.h"
#include "Disparo.h"
#include "PowerUp.h"
#include "Puntaje.h"

/// Director -> Escena -> Actores
///                    -> Fondos

class Escena: public sf::Drawable{
    public:
        Escena();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        ///Actualiza el Gameplay
        void update();
        ///Si el power up esta desactivo, lo activamos y hacemos que aparezca con una probabilidad del 15%
        void SpawnPowerUp(float x, float y){
        if(_powerup.Activo()==false&&rand()%100<15){
            _powerup.Activate(x, y);
        }
        }
        ///Verificamos que el juego termino
        bool EstadoGameOver(){return Perdiste;}
        ///Manejamos los eventos o los estados para poder volver al menu;
        void Eventos(sf::RenderWindow& windows, sf::Event& evento, bool& VolverAlMenu);
        ///Reinciamos el juego(constructores, estados, etc)
        void ReiniciarJuego();
        ///Chequeamos si el juego termino despues de perder todas las vidas
        void ChequearGameOver();
        void ReiniciarEscenario();
    private:
        ///Clases
        Personaje _jugador;
        Enemigo _enemigo;
        Enemigo _enemigo2;
        EnemigoAvanzado _enemigoavanzado;
        PowerUp _powerup;
        Disparo _disparo;
        ArchivoPuntaje archivoP;
        Ranking RankingP;
        ///Puntos
        int Puntos=0;
<<<<<<< Updated upstream
        int Obj=0;
=======
        int getPuntos(){return Puntos;}
        ///Fuente
>>>>>>> Stashed changes
        sf::Font font;
        ///Textos
        sf::Text text;
        sf::Text textNum;
        sf::Text tObjeto;
<<<<<<< Updated upstream
        sf::RectangleShape Rectangulo;
        sf::Sprite Fondo, Fondo2;
        sf::Texture texture;
        float fondoGalaga=1.0f;
        void AgregarObjs();
        sf::Sprite Objetos[9];
        sf::Texture tObjetos;
        void SpawnPowerUp(float x, float y){
        if(_powerup.Activo()==false&&rand()%100<15){
            _powerup.Activate(x, y);
        }
        }
=======
        ///Rectangulo para la seccion del puntaje, vidas y los objetos que tenemos
        sf::RectangleShape Rectangulo;
        ///Fondos
        sf::Sprite Fondo, Fondo2, Fondo3;
        sf::Texture texture, texture2;
        ///Velocidad del fondo
        int fondoGalaga=1;
        ///Agregar los objetos (Power Ups) que se van agarrando durante el gameplay
        void AgregarObjs();
        ///Objetos(Power Ups)
        int Obj=0;
        sf::Sprite Objetos[9];
        sf::Texture tObjetos;
        ///Texto de lo que hace el PowerUp
        sf::Text textNombrePowerup;
        sf::Text textVelocidad;
        bool textV=false;
        sf::Clock textVClock;
        ///Texto GameOver
        sf::Text GameOver;
        sf::Text PuntajeF;
        sf::Text VolverMenu;
        ///Boton de Volver al menu
        sf::RectangleShape BotonVolverM;
        ///booleano para verificar si perdimos o no
        bool Perdiste=false;
>>>>>>> Stashed changes
};
