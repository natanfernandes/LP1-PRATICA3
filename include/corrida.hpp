/**
* @author Natanael Fernandes T. Araujo
* @file corrida.hpp
* @since 06/06/18
* @date 06/06/18
* @brief HPP da classe corrida
*/
#ifndef CORRIDA_H
#define CORRIDA_H

#include <vector>
#include "../include/sapo.hpp"
#include "../include/pista.hpp"
using namespace std;

class corrida
{
  private:
    int chegouprimeiroID;
    string chegouprimeiroNome;
  public:
    //VECTORS
    std::vector<sapo> participantes;
    std::vector<pista> pistas;
    std::vector<sapo> ranking;
    //ADD ITENS AOS VECTORS
    void addParticipante(sapo novoParticipante);
    void addPista(pista novaPista);
    //DEMAIS METODOS
    void startcorrida();
    void vervencedor();
    bool checagem();
    void escolherPista();
    //GETTERS E SETTERS
    void setChegouPrimeiro(int winnerID,string winnerNome);
    int getChegouPrimeiroID();
    string getChegouPrimeiroNome();
    void printavencedor();
    //CRIAM SAPOS E PISTAS
    void criarSapo();
    void criarPista();
    //VER ESTATISTICAS E RANKING
    void verEstatisticasSapos();
    void verEstatisticasPistas();
    void verDisponiveis();
    void verRanking();
};

#endif