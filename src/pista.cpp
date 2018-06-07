#include "../include/pista.hpp"
#include <iostream>
#include <string>
using namespace std;


pista::pista(int distanciaAux,string nomePistaAux){
    this->distancia = distanciaAux;
    this->nomePista = nomePistaAux;
}

int pista::getDistancia(){
    return this->distancia;
}
string pista::getNomePista(){
    return this->nomePista;
}

void pista::setDistancia(int distanciaAux){
    this->distancia = distanciaAux;
}

void pista::setNomePista(string nomePistaAux){
    this->nomePista = nomePistaAux;
}
