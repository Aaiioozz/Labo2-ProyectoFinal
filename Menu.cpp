#include  "Menu.h"
Menu::Menu(float x, float y){
///Fuente
font.loadFromFile("Crang.ttf");
///Fondo
texture.loadFromFile("fondo_menu.png ");
Fondo.setTexture(texture);
Fondo.setPosition(0, 0);
///Titulo
titulo.setFont(font);
titulo.setString("AEGIS");
titulo.setCharacterSize(80);
titulo.setPosition(sf::Vector2f(360/2-titulo.getGlobalBounds().width/2, y/8));
///Subtitulo
subtitulo.setFont(font);
subtitulo.setString("Proyecto Laboratorio II");
subtitulo.setCharacterSize(25);
subtitulo.setPosition(sf::Vector2f(20/2-integrante.getGlobalBounds().width/2, 760-integrante.getGlobalBounds().height-30));
///Primer boton (Jugar)
BotonMenu1.setSize(sf::Vector2f(200, 50));
BotonMenu1.setOutlineThickness(2);
BotonMenu1.setOutlineColor(sf::Color::White);
BotonMenu1.setFillColor(sf::Color::Black);
BotonMenu1.setPosition(50, 350);
///Segundo Boton (Salir)
BotonMenu2.setSize(sf::Vector2f(200, 50));
BotonMenu2.setOutlineThickness(2);
BotonMenu2.setOutlineColor(sf::Color::White);
BotonMenu2.setFillColor(sf::Color::Black);
BotonMenu2.setPosition(50, 450);
///Tercer Boton (Ranking)
BotonMenu3.setSize(sf::Vector2f(200, 50));
BotonMenu3.setOutlineThickness(2);
BotonMenu3.setOutlineColor(sf::Color::White);
BotonMenu3.setFillColor(sf::Color::Black);
BotonMenu3.setPosition(50, 550);
///Opcion Jugar
menu1.setFont(font);
menu1.setString("Jugar");
menu1.setPosition(100, 355);
///Opcion Salir
menu2.setFont(font);
menu2.setString("Salir");
menu2.setPosition(105, 560);
///Opcion Ranking
menu3.setFont(font);
menu3.setString("Ranking");
menu3.setPosition(85, 460);
///Integrantes
integrante.setFont(font);
integrante.setString("Integrantes: Emanuel González, Martin Vasques.");
integrante.setCharacterSize(20);
integrante.setPosition(sf::Vector2f(630/2-integrante.getGlobalBounds().width/2, 830-integrante.getGlobalBounds().height-30));
}

void Menu::draw(sf::RenderWindow &windows){
windows.draw(Fondo);
windows.draw(titulo);
windows.draw(subtitulo);
windows.draw(BotonMenu1);
windows.draw(BotonMenu2);
windows.draw(BotonMenu3);
windows.draw(menu1);
windows.draw(menu2);
windows.draw(menu3);
windows.draw(integrante);
}
///Verificamos a traves del click del raton si seleccionamos el boton de Jugar(Estado=true) o Salir(close).
void Menu::Eventos(sf::RenderWindow &windows, sf::Event &evento, EstadoJuego &EstadoActual){
if(evento.type==sf::Event::MouseButtonPressed){
    sf::Vector2i PosMouse=sf::Mouse::getPosition(windows);
    if(BotonMenu1.getGlobalBounds().contains(PosMouse.x, PosMouse.y)){
            EstadoActual=JUEGO;
    } else if(BotonMenu2.getGlobalBounds().contains(PosMouse.x, PosMouse.y)){
            EstadoActual=RANKING;
    } else if(BotonMenu3.getGlobalBounds().contains(PosMouse.x, PosMouse.y)){
            windows.close();
    }
}
}
