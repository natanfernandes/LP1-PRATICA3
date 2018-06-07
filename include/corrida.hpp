#ifndef CORRIDA_H
#define CORRIDA_H

#include <vector>
#include "../include/sapo.hpp"
#include "../include/pista.hpp"
#include "../include/escreverArquivo.hpp"
using namespace std;

class corrida
{
  private:
    int chegouprimeiroID;
    string chegouprimeiroNome;
  public:
    std::vector<sapo> participantes;
    std::vector<pista> pistas;
    void addParticipante(sapo novoParticipante);
    void addPista(pista novaPista);
    void startcorrida();
    void vervencedor();
    void setChegouPrimeiro(int winnerID,string winnerNome);
    int getChegouPrimeiroID();
    string getChegouPrimeiroNome();
    void printavencedor();
    bool checagem();
    void criarSapo();
    void verEstatisticasSapos();
};

#endif