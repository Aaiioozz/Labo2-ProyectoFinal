#pragma once
#include <SFML/Graphics.hpp>
#include <cstring>

class Puntaje{
private:
    int puntos;
public:
    int getPuntos()const {return puntos;}
    void setPuntos(int p){puntos=p;}
};


class ArchivoPuntaje{
private:
    char nombre[30];
    Puntaje Puntajes[10];
    int CantPuntaje;
public:
    ArchivoPuntaje(const char *n="RankingPuntaje.dat");
    void CargarPuntaje();
    void GuardarPuntaje();
    void OrdenarPuntaje();
    void AgregarPuntaje(const Puntaje& PuntajeN);
    const Puntaje* ObtenerPuntaje() const{
    return Puntajes;
    }
    int getCantPuntaje() const{
    return CantPuntaje;
    }
};

class Ranking{
private:
    sf::Font font;
    sf::Text Titulo;
    sf::Text Puntajes[10];
    sf::Texture texture;
    sf::Sprite Fondo;
    ArchivoPuntaje ArchivoP;
public:
    Ranking();
    void MostrarRanking();
    void ActualizarRanking();
    void draw(sf::RenderTarget& target) const;
};
