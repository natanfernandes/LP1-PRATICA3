/**
* @author Natanael Fernandes T. Araujo
* @file pista.hpp
* @since 06/06/18
* @date 06/06/18
* @brief HPP da classe pista
*/
#ifndef  PISTA_H
#define PISTA_H
#include <string>
using namespace std;

class pista {
    private:
        int distancia;
        string nomePista;
        int qtCorridas;
    public:
        //CONSTUTOR
        pista(int distanciaAux,string nomePistaAux,int qtCorridasAux);
        //GETTERS
        int getDistancia();
        string getNomePista();
        int getQtCorridas();
        //SETTERS
        void setDistancia(int distanciaAux);
        void setNomePista(string nomePistaAux);
        void setQtCorridas(int qtCorridasAux);

        void infosGerais();
};  
#endif 
