#include "Gameplay.h"
#include "Puntaje.h"
#include <iostream>
#include <cstdlib>
<<<<<<< Updated upstream
=======
#include <cstring>
>>>>>>> Stashed changes
#include <ctime>

using namespace std;

<<<<<<< Updated upstream
        Escena::Escena(){
            ///Puntaje
            font.loadFromFile("EarlyGameBoy.ttf");
            text.setFont(font);
            text.setPosition(900, 10);
            text.setString("Puntos");
            textNum.setFont(font);
            textNum.setPosition(960, 50);
            textNum.setString(std::to_string(Puntos));
            ///Objetos
            tObjeto.setFont(font);
            tObjeto.setPosition(888, 400);
            tObjeto.setString("Objetos");
            tObjetos.loadFromFile("rayo_galaga.png");
            ///Rectangulo
            Rectangulo.setSize(sf::Vector2f(216, 798));
            Rectangulo.setPosition(880, 1);
            Rectangulo.setFillColor(sf::Color::Black);
            Rectangulo.setOutlineColor(sf::Color::White);
            Rectangulo.setOutlineThickness(4);
            ///Fondo
            texture.loadFromFile("fondo_galaga.png ");
            Fondo.setTexture(texture);
            Fondo.setPosition(0, 0);
            Fondo2.setTexture(texture);
            Fondo2.setPosition(0, -texture.getSize().y);
        }
        void Escena::AgregarObjs(){
        if(Obj<9){
            sf::Sprite NuevoObj;
            NuevoObj.setTexture(tObjetos);
            int x=880+(Obj%5)*48;
            int y=440+(Obj/5)*48;
            NuevoObj.setPosition(x, y);
            Objetos[Obj]=NuevoObj;
            Obj++;
        }
        }
        void Escena::draw(sf::RenderTarget& target, sf::RenderStates states) const{
            target.draw(Fondo, states);
            target.draw(Fondo2, states);
            target.draw(Rectangulo, states);
            target.draw(_jugador, states);
            target.draw(_enemigo, states);
            target.draw(_enemigoavanzado, states);
            target.draw(_powerup, states);
            target.draw(text, states);
            target.draw(textNum, states);
            target.draw(tObjeto, states);
            for(int i=0; i<Obj; i++){
                target.draw(Objetos[i], states);
            }
        }
        void Escena::update(){
=======
// ENCARGADO DE MANEJAR LAS ESCENAS Y ACTORES
Escena::Escena()
{
    ///Puntaje
    font.loadFromFile("EarlyGameBoy.ttf");
    text.setFont(font);
    text.setPosition(900, 10);
    text.setString("Puntos");
    textNum.setFont(font);
    textNum.setPosition(960, 50);
    textNum.setString(std::to_string(Puntos));
    ///Objetos
    tObjeto.setFont(font);
    tObjeto.setPosition(888, 400);
    tObjeto.setString("Objetos");
    tObjetos.loadFromFile("rayo_galaga.png");
    ///Texto Velocidad

    textNombrePowerup.setFont(font);
    textNombrePowerup.setPosition(275, 740); // 275 , 775
    textNombrePowerup.setCharacterSize(20);
    textNombrePowerup.setString("Capsula de Plasma");

    textVelocidad.setFont(font);
    textVelocidad.setPosition(250, 775);
    textVelocidad.setCharacterSize(20);
    textVelocidad.setString("Aumenta tu velocidad");
    ///Rectangulo
    Rectangulo.setSize(sf::Vector2f(216, 798));
    Rectangulo.setPosition(880, 1);
    Rectangulo.setFillColor(sf::Color::Black);
    Rectangulo.setOutlineColor(sf::Color::White);
    Rectangulo.setOutlineThickness(4);
    ///Fondo
    texture.loadFromFile("fondo_galaga.png");
    Fondo.setTexture(texture);
    Fondo.setPosition(0, 0);
    Fondo2.setTexture(texture);
    Fondo2.setPosition(0, -texture.getSize().y);
    ///Game Over
    GameOver.setFont(font);
    GameOver.setString("Perdiste");
    GameOver.setPosition(400, 200);
    GameOver.setCharacterSize(40);
    ///Puntaje Final
    PuntajeF.setFont(font);
    PuntajeF.setPosition(340, 300);
    PuntajeF.setCharacterSize(25);
    ///Opcion Volver al menu
    VolverMenu.setFont(font);
    VolverMenu.setString("Volver al Menu");
    VolverMenu.setPosition(365, 500);
    VolverMenu.setCharacterSize(30);
    ///Boton Volver al menu
    BotonVolverM.setSize(sf::Vector2f(415, 50));
    BotonVolverM.setOutlineThickness(2);
    BotonVolverM.setOutlineColor(sf::Color::White);
    BotonVolverM.setFillColor(sf::Color::Black);
    BotonVolverM.setPosition(350, 495);
    ///Fondo del GameOver
    texture2.loadFromFile("fondo_gameover.png");
    Fondo3.setTexture(texture2);
    Fondo3.setPosition(0, 0);
    ///Ponemos en false para verificar que no perdimos
    Perdiste=false;
    archivoP.CargarPuntaje();
}
void Escena::AgregarObjs()
{
    ///Solo podemos tener un maximo de 10 objetos
    if(Obj<10)
    {
        ///Creamos un nuevo obj, y lo posicionamos en una fila uno al lado de otro
        sf::Sprite NuevoObj;
        NuevoObj.setTexture(tObjetos);
        int x=880+(Obj%5)*48;
        int y=440+(Obj/5)*48;
        NuevoObj.setPosition(x, y);
        ///Vamos incrementando los objetos mientras los almacenamos y los posicionamos en la siguiente posicion de la fila
        Objetos[Obj]=NuevoObj;
        Obj++;
    }
}
///Chequeamos que el jugador haya perdido sus vidas y cambiamos el estado de "Perdiste" a true
void Escena::ChequearGameOver() {
    if (_jugador.getVidas() <= 0) {
        Perdiste = true;
        PuntajeF.setString("Puntos obtenidos: " + std::to_string(Puntos));
        Puntaje PuntajeN;
        PuntajeN.setPuntos(Puntos);
        archivoP.AgregarPuntaje(PuntajeN);
        archivoP.GuardarPuntaje();
    }
}
void Escena::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(Fondo, states);
    target.draw(Fondo2, states);
    target.draw(Rectangulo, states);

    target.draw(_jugador, states);

    target.draw(_enemigo, states);
    target.draw(_enemigo2, states);
    target.draw(_enemigoavanzado, states);

    target.draw(_powerup, states);
    target.draw(text, states);
    target.draw(textNum, states);
    target.draw(tObjeto, states);
    ///Dibujamos los objetos que se van agarrando 1x1
    for(int i=0; i<Obj; i++)
    {
        target.draw(Objetos[i], states);
    }
    ///Si se agarra un objeto(Power Up) se muestra el texto de lo que hace
    if(textV==true)
    {
        target.draw(textNombrePowerup, states);
        target.draw(textVelocidad, states);
    }
    ///Si perdemos sale la pantalla de Game Over, el puntaje final y la opcion de volver al menu
    if(Perdiste==true)
    {
        target.draw(Fondo3, states);
        target.draw(GameOver, states);
        target.draw(PuntajeF, states);
        target.draw(BotonVolverM, states);
        target.draw(VolverMenu, states);
    }
}

void Escena::update()
{
    if(Perdiste==false)
    {
>>>>>>> Stashed changes
        _jugador.update();
        _enemigo.update();
        _enemigoavanzado.update();
        _powerup.update();

        /// ENEMIGO NORMAL
        if(_enemigo.disp.IsActive()&&_enemigo.disp.isCollision(_jugador))
        {
            _jugador.BajarVida();
            _enemigo.disp.setActive(false);
            ReiniciarEscenario();
        }

<<<<<<< Updated upstream
        if(_jugador.disp.IsActive()&&_jugador.disp.isCollision(_enemigo)){
        _enemigo.ResetearPosicion();
        _jugador.disp.setActive(false);
        Puntos++;
        textNum.setString(std::to_string(Puntos));
        SpawnPowerUp(_enemigo.getPosition().x, _enemigo.getPosition().y);
=======
        if(_jugador.disp.IsActive()&&_jugador.disp.isCollision(_enemigo))
        {
            SpawnPowerUp(_enemigo.getPosition().x, _enemigo.getPosition().y);
            _enemigo.ResetearPosicion();
            _jugador.disp.setActive(false);
            Puntos=Puntos+50;
            textNum.setString(std::to_string(Puntos));
>>>>>>> Stashed changes
        }
        /// ENEMIGO AVANZADO
        if(_jugador.isCollision(_enemigoavanzado))
        {
            _jugador.BajarVida();
            ReiniciarEscenario();
        }

<<<<<<< Updated upstream
        if(_jugador.disp.IsActive()&&_jugador.disp.isCollision(_enemigoavanzado)){
        _jugador.disp.setActive(false);
        _enemigoavanzado.ResetearPosicion();
        Puntos++;
        textNum.setString(std::to_string(Puntos));
        SpawnPowerUp(_enemigoavanzado.getPosition().x, _enemigoavanzado.getPosition().y);
        }

        ///POWERUP
        if(_powerup.Activo()&&_jugador.isCollision(_powerup)){
            _jugador.setVelocity(_jugador.getVelocity()+0.5);
            _powerup.Desactivo();
            AgregarObjs();
        }
        _powerup.update();

=======
        if(_jugador.disp.IsActive()&&_jugador.disp.isCollision(_enemigoavanzado))
        {
            SpawnPowerUp(_enemigoavanzado.getPosition().x, _enemigoavanzado.getPosition().y);
            _enemigoavanzado.ResetearPosicion();
            _jugador.disp.setActive(false);
            Puntos=Puntos+100;
            textNum.setString(std::to_string(Puntos));
        }
        // NUEVO ENEMIGO NORMAL SI SE LLEGA A PUNTOS REQUERIDOS
        if(getPuntos()>=1500)
        {
            _enemigo2.update();
            if(_enemigo2.disp.IsActive()&&_enemigo2.disp.isCollision(_jugador))
            {
                _jugador.BajarVida();
                _enemigo2.disp.setActive(false);
                ReiniciarEscenario();
            }

            if(_jugador.disp.IsActive()&&_jugador.disp.isCollision(_enemigo2))
            {
                SpawnPowerUp(_enemigo.getPosition().x, _enemigo.getPosition().y);
                _enemigo2.ResetearPosicion();
                _jugador.disp.setActive(false);
                Puntos=Puntos+50;
                textNum.setString(std::to_string(Puntos));
            }
        }

        ///POWERUP
        if(_powerup.Activo()&&_jugador.isCollision(_powerup))
        {
            _jugador.setVelocity(_jugador.getVelocity()+0.5);
            _powerup.Desactivo();
            AgregarObjs();
            textV=true;
            textVClock.restart();
        }
        _powerup.update();
        if(textV==true&&textVClock.getElapsedTime().asSeconds()>2)
        {
            textV=false;
        }
        ///FONDOS
>>>>>>> Stashed changes
        Fondo.move(0, fondoGalaga);
        Fondo2.move(0, fondoGalaga);
        if(Fondo.getPosition().y>=texture.getSize().y)
        {
            Fondo.setPosition(0, Fondo2.getPosition().y-texture.getSize().y);
        }
        if(Fondo2.getPosition().y>=texture.getSize().y)
        {
            Fondo2.setPosition(0, Fondo.getPosition().y-texture.getSize().y);
        }
        ///Chequeamos si perdimos durante el update del gameplay
        ChequearGameOver();
    }
}
///Manejamos los eventos o estados, para saber si
///el mouse del usuario hace click para volver al menu
void Escena::Eventos(sf::RenderWindow& windows, sf::Event& evento, bool& VolverAlMenu)
{
    if(evento.type==sf::Event::MouseButtonPressed)
    {
        if(evento.mouseButton.button==sf::Mouse::Left)
        {
            sf::Vector2i PosMouse=sf::Mouse::getPosition(windows);
            if(BotonVolverM.getGlobalBounds().contains(PosMouse.x, PosMouse.y))
            {
                VolverAlMenu=true;
            }
        }
    }
}
void Escena::ReiniciarJuego()
{
    ///Se establecen los puntos y los objetos de vuelta a 0, como tambien el estado pasa a ser False
    Puntos=0;
    Obj=0;
    Perdiste=false;
    textNum.setString(std::to_string(Puntos));
    ///Llamamos al constructor y los estados del personaje, enemigo, disparo, etc
    _jugador=Personaje();
    _enemigo=Enemigo();
    _enemigoavanzado=EnemigoAvanzado();
    _powerup=PowerUp();
    _disparo=Disparo();
    ///Reiniciamos las texturas y volvemos a agregarlas
    _jugador.getTexture().loadFromFile("avion_galaga.png");
    _jugador.setTexture();
    _jugador.disp.getTexture().loadFromFile("disparo.png");
    _jugador.disp.setTexture();
    _jugador.getTextureV().loadFromFile("avion_vida.png");
    _jugador.setTextureV();
    _enemigo.getTexture().loadFromFile("enemigo_galaga.png");
    _enemigo.setTexture();
    _enemigo.disp.getTexture().loadFromFile("disparo.png");
    _enemigo.disp.setTexture();
    //
    _enemigo2.getTexture().loadFromFile("enemigo_galaga.png");
    _enemigo2.setTexture();
    _enemigo2.disp.getTexture().loadFromFile("disparo.png");
    _enemigo2.disp.setTexture();
    //
    _enemigoavanzado.getTexture().loadFromFile("enemigoavanzado_galaga.png");
    _enemigoavanzado.setTexture();
    _powerup.getTexture().loadFromFile("rayo_galaga.png");
    _powerup.setTexture();
}
// VERSION MODIFICADA PARA REINICIAR EL ESCENARIO Y MANTENER LAS DEMAS COSAS.
void Escena::ReiniciarEscenario()
{
    _enemigo=Enemigo();
    _enemigoavanzado=EnemigoAvanzado();
    _disparo=Disparo();

    _enemigo.ResetearPosicion();
    _enemigo.disp.setActive(false);
    _enemigoavanzado.ResetearPosicion();
    if(getPuntos()>=1500)
    {
        _enemigo2.ResetearPosicion();
    }

    ///Reiniciamos las texturas y volvemos a agregarlas
    _jugador.getTexture().loadFromFile("avion_galaga.png");
    _jugador.setTexture();
    _jugador.disp.getTexture().loadFromFile("disparo.png");
    _jugador.disp.setTexture();
    _jugador.getTextureV().loadFromFile("avion_vida.png");
    _jugador.setTextureV();
    _enemigo.getTexture().loadFromFile("enemigo_galaga.png");
    _enemigo.setTexture();
    _enemigo.disp.getTexture().loadFromFile("disparo.png");
    _enemigo.disp.setTexture();
    //
    _enemigo2.getTexture().loadFromFile("enemigo_galaga.png");
    _enemigo2.setTexture();
    _enemigo2.disp.getTexture().loadFromFile("disparo.png");
    _enemigo2.disp.setTexture();
    //
    _enemigoavanzado.getTexture().loadFromFile("enemigoavanzado_galaga.png");
    _enemigoavanzado.setTexture();
    _powerup.getTexture().loadFromFile("rayo_galaga.png");
    _powerup.setTexture();
}
