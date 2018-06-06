#ifndef CORRIDA_H
#define CORRIDA_H

#include <vector>
#include "../include/sapo.hpp"
using namespace std;

class corrida
{
  private:
    int chegouprimeiro;

  public:
    std::vector<sapo> participantes;
    void addParticipante(sapo novoParticipante);
    void startcorrida();
    void vervencedor();
    void setChegouPrimeiro(int winner);
    int getChegouPrimeiro();
    void printavencedor();
    bool checagem();
};

#endif