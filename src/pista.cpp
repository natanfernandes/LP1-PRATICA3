/**
*@file pista.cpp
*@brief Contém todos os metodos e atributos da classe pista
*@author Natanael Fernandes T. Araujo
*/
#include "../include/pista.hpp"
#include <iostream>
#include <string>
using namespace std;

/**     
*@brief Construtor da classe pista
*@param distanciaAux distancia recebida
*@param nomePistaAux nome da pista recebido
*@param qtCorridasAux quantidade de corridas da pista recebida
*/
pista::pista(int distanciaAux,string nomePistaAux,int qtCorridasAux){
    this->distancia = distanciaAux;
    this->nomePista = nomePistaAux;
    this->qtCorridas = qtCorridasAux;
}

/**     
*@brief Funcão que retorna a distancia da pista
*/
int pista::getDistancia(){
    return this->distancia;
}

/**     
*@brief Funcão que retorna o nome da pista
*/
string pista::getNomePista(){
    return this->nomePista;
}

/**     
*@brief Funcão que retorna a quantidade de corridas da pista
*/
int pista::getQtCorridas(){
    return this->qtCorridas;
}

/**     
*@brief Funcão que atribui o valor a distancia da pista
*/
void pista::setDistancia(int distanciaAux){
    this->distancia = distanciaAux;
}

/**     
*@brief Funcão que atribui o nome a pista
*/
void pista::setNomePista(string nomePistaAux){
    this->nomePista = nomePistaAux;
}

/**     
*@brief Funcão que atribui a quantidade de corridas a pista
*/
void pista::setQtCorridas(int qtCorridasAux){
    this->qtCorridas = qtCorridasAux;
}

/**     
*@brief Funcão que mostra todas as informações da pista
*/
void pista::infosGerais(){
    cout << "---Nome : "<<this->getNomePista() <<" | Distancia : "<< this->getDistancia()<<" | Quantidade de provas nessa pista : " << this->getQtCorridas()<<endl;
}