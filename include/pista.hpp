#ifndef  PISTA_H
#define PISTA_H
#include <string>
using namespace std;

class pista {
    private:
        int distancia;
        string nomePista;
    public:
        //CONSTUTOR
        pista(int distanciaAux,string nomePistaAux);
        //GETTERS
        int getDistancia();
        string getNomePista();
        //SETTERS
        void setDistancia(int distanciaAux);
        void setNomePista(string nomePistaAux);
};  
#endif 
