#include "Puntaje.h"
#include <cstring>

ArchivoPuntaje::ArchivoPuntaje(const char *n) {
    strncpy(nombre, n, sizeof(nombre) - 1);
    nombre[sizeof(nombre) - 1] = '\0';
    CantPuntaje = 0;
    CargarPuntaje();
}

void ArchivoPuntaje::CargarPuntaje(){
FILE *p=fopen(nombre, "rb");
if(p!=NULL){
    fread(&CantPuntaje, sizeof(int), 1, p);
    if(CantPuntaje>10) CantPuntaje=10;
    fread(Puntajes, sizeof(Puntaje), CantPuntaje, p);
    fclose(p);
}
}
void ArchivoPuntaje::GuardarPuntaje(){
FILE *p=fopen(nombre, "wb");
if(p!=NULL){
    fwrite(&CantPuntaje, sizeof(int), 1, p);
    fwrite(Puntajes, sizeof(Puntaje), CantPuntaje, p);
    fclose(p);
}
}

void ArchivoPuntaje::OrdenarPuntaje(){
for(int i=0; i<CantPuntaje-1; i++){
    for(int j=0; j<CantPuntaje-i-1;j++){
        if(Puntajes[j].getPuntos()<Puntajes[j+1].getPuntos()){
            Puntaje obj=Puntajes[j];
            Puntajes[j]=Puntajes[j+1];
            Puntajes[j+1]=obj;
        }
    }
}
}
void ArchivoPuntaje::AgregarPuntaje(const Puntaje& PuntajeN){
if(CantPuntaje<10){
    Puntajes[CantPuntaje]=PuntajeN;
    CantPuntaje++;
} else if(PuntajeN.getPuntos()>Puntajes[10-1].getPuntos()){
    Puntajes[10-1]=PuntajeN;
}
OrdenarPuntaje();
GuardarPuntaje();
}

Ranking::Ranking(){
font.loadFromFile("Crang.ttf");
texture.loadFromFile("fondo_ranking.png"); // fondo original, fondoRankingNOHUD
Fondo.setTexture(texture);
Fondo.setPosition(0, 0);
Titulo.setFont(font);
Titulo.setString("Ranking de Puntajes");
Titulo.setPosition(130, 20);

ArchivoP.CargarPuntaje();
const Puntaje* puntajeV=ArchivoP.ObtenerPuntaje();
int cantp=ArchivoP.getCantPuntaje();
for(int i=0; i<10; i++){
    Puntajes[i].setFont(font);
    Puntajes[i].setPosition(50, 120+i*45);
    if(i<cantp){
        std::string text=std::to_string(i+1)+". "+ std::to_string(puntajeV[i].getPuntos());
        Puntajes[i].setString(text);
    } else {
        Puntajes[i].setString(std::to_string(i+1)+". ---");
    }
}
}
void Ranking::draw(sf::RenderTarget& target)const{
target.draw(Fondo);
target.draw(Titulo);
for(int i=0; i<10; i++){
    target.draw(Puntajes[i]);
}
}

void Ranking::MostrarRanking(){
ArchivoP.CargarPuntaje();
ActualizarRanking();
}

void Ranking::ActualizarRanking(){
const Puntaje* puntajeV=ArchivoP.ObtenerPuntaje();
int cantp=ArchivoP.getCantPuntaje();
for(int i=0; i<10; i++){
    if(i<cantp){
        std::string text=std::to_string(i+1)+". "+ std::to_string(puntajeV[i].getPuntos());
        Puntajes[i].setString(text);
    } else {
        Puntajes[i].setString(std::to_string(i+1)+". ---");
    }
}
}
