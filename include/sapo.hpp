/**
* @author Natanael Fernandes T. Araujo
* @file lerArquivos.hpp
* @since 06/06/18
* @date 06/06/18
* @brief HPP da classe sapo
*/
#ifndef SAPO_HPP
#define SAPO_HPP
#include <iostream>
#include <random>
#include <vector>
#include <string>
using namespace std;

class sapo
{
  private:
	string nome;
	int qtProvas;
	int vitorias;
	int derrotas;
	int empates;
	int id;
	double distpercorrida;
	int qtPulos;
	int qtPulosTotal;

  public:
	//STATICS
	static int distTotal;
	static int idGeral;
	//VECTOR
	std::vector<double> valordospulos;
	//CONSTRUCTOR
	sapo(string nomeSapoAux,int qtProvasAux,int vitoriasAux,int derrotasAux,int empatesAux,int qtPulosTotalAux);
	//SETTERS
	void setDistPercorrida(int distAux);
	void setVitorias(int vitoriasAux);
	void setDerrotas(int derrotasAux);
	void setQtPulosTotal(int qtPulosTotalAux);
	//GETTERS
	static int getdistTotal();
	int getDistPercorrida();
	int getID();
	int getnumPulos();
	string getNome();
	int getQtProvas();
	int getVitorias();
	int getDerrotas();
	int getEmpates();
	int getQtPulosTotal();
	//OTHER METHODS
	void infosFimCorrida();
	void infosGerais();
	void pular();
	void somaDistPercorrida();
	void IncNumPulos();
	//RANDOM NUMBER GEN
	static std::random_device rd;
	static std::mt19937 gen;
	static std::uniform_int_distribution<> dis;
};
#endif