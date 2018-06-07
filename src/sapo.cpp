/**
*@file sapo.cpp
*@brief Contém todos os metodos e atributos da classe sapo
*@author Natanael Fernandes T. Araujo
*/
#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>
#include "../include/sapo.hpp"
using namespace std;

std::random_device sapo::rd{};
std::mt19937 sapo::gen(sapo::rd());
std::uniform_int_distribution<> sapo::dis(1, 10);

/**     
*@brief Operador estático distancia total da corrida definido globalmente
*/
int sapo::distTotal = 30;

/**     
*@brief Operador estático que serve para atribuir ids aos sapos
*/
int sapo::idGeral = 1;

/**     
	*@brief Construtor da classe sapo
	*@param nomeSapoAux nome recebido para o sapo
	*@param	qtProvasAux quantidade de provas disputadas pelo sapo que foi recebida
	*@param vitoriasAux quantidade de vitorias do sapo que foi recebida
	*@param derrotasAux quantidade de derrotas do sapo que foi recebida
	*@param empatesAux quantidade de empates do sapo que foi recebida
	*@param qtPulosTotalAux quantidade de pulos totais dado pelo sapo recebida
	*/
sapo::sapo(string nomeSapoAux,int qtProvasAux,int vitoriasAux,int derrotasAux,int empatesAux,int qtPulosTotalAux)
{
	qtPulos = 0;
	nome = nomeSapoAux;
	qtProvas = qtProvasAux;
	vitorias = vitoriasAux;
	derrotas = derrotasAux;
	empates = empatesAux;
	qtPulosTotal = qtPulosTotalAux;
	distpercorrida = 0;
	id = idGeral;
	idGeral++;
}
/**     
	*@brief Funcão que retorna distância total
	*@param Esta funcão não tem parâmetros
	*/
int sapo::getdistTotal()
{
	return distTotal;
}
/**     
	*@brief Funcão que retorna o numero de pulos dados
	*@param Esta funcão não tem parâmetros
	*/
int sapo::getnumPulos()
{
	return this->qtPulos;
}
/**     
	*@brief Funcão que retorna a distancia percorrida pelo sapo
	*@param Esta funcão nao recebe parâmetros
	*/
int sapo::getDistPercorrida()
{
	return this->distpercorrida;
}
/**     
	*@brief Funcão que retorna o id do sapo
	*@param Esta funcao nao recebe parametros
	*/
int sapo::getID()
{
	return id;
}

/**     
	*@brief Funcão que retorna o nome do sapo
	*@param Esta funcao nao recebe parametros
	*/
string sapo::getNome(){
	return this->nome;
}

/**     
	*@brief Funcão que retorna a quantidade de provas disputadas pelo sapo
	*@param Esta funcao nao recebe parametros
	*/
int sapo::getQtProvas(){
	return this->qtProvas;
}

/**     
	*@brief Funcão que retorna a quantidade de vitorias do sapo
	*@param Esta funcao nao recebe parametros
	*/
int sapo::getVitorias(){
	return this->vitorias;
}


/**     
	*@brief Funcão que retorna a quantidade de derrotas do sapo
	*@param Esta funcao nao recebe parametros
	*/
int sapo::getDerrotas(){
	return this->derrotas;
}

/**     
	*@brief Funcão que retorna a quantidade de empates do sapo
	*@param Esta funcao nao recebe parametros
	*/
int sapo::getEmpates(){
	return this->empates;
}

/**     
	*@brief Funcão que retorna a quantidade total de pulos dados pelo sapo
	*@param Esta funcao nao recebe parametros
	*/
int sapo::getQtPulosTotal(){
	return this->qtPulosTotal;
}

/**     
	*@brief Funcão que atribui valor as vitorias do sapo
	*@param vitoriasAux quantidade de vitorias a ser atribuida
	*/
void sapo::setVitorias(int vitoriasAux){
	vitorias = vitoriasAux;
}

/**     
	*@brief Funcão que atribui valor as derrotas do sapo
	*@param derrotasAux quantidade de derrotas a ser atribuida
	*/
void sapo::setDerrotas(int derrotasAux){
	derrotas = derrotasAux;
}

/**     
	*@brief Funcão que atribui valor a quantidade de pulos totais do sapo
	*@param qtPulosTotalAux quantidade total de pulos a ser atribuida
	*/
void sapo::setQtPulosTotal(int qtPulosTotalAux){
	qtPulosTotal = qtPulosTotalAux;
}
/**     
	*@brief Funcão que atribui a distância percorrida
	*@param distAux É a variável que recebe o valor da distância percorrida para repassar ao atributo privado
	*/
void sapo::setDistPercorrida(int distAux)
{
	distpercorrida = distAux;
}
/**     
	*@brief Funcão que imprime as informações do sapo
	*@details A funcão diz a distancia percorrida e a quantidade de pulos de cada sapo
	*@param sapos Classe que tem todas os atributos do sapo	
	*/
void sapo::infosFimCorrida()
{
	cout << "O Sapo " << this->getNome()<<" (ID ="<< this->getID() <<")"<<" pulou " << this->getnumPulos() << " vezes e a distancia percorrida nesta corrida foi " << this->getDistPercorrida() << endl;
}
/**     
	*@brief Funcão que faz os sapos pularem
	*@details A funcão gera um valor de distancia randomico para cada sapo pular e enquanto nenhum sapo antigir a distancia total a corrida não acaba
	*/
void sapo::pular()
{
	int v;
	srand(time(NULL));
	v = std::round(dis(gen));

	this->IncNumPulos();
	this->valordospulos.push_back(v);
	cout << "Sapo " << this->getNome() << "(ID ="<<this->getID() << ") pulou : " << v << endl;
	cout << "-------------------------------------------------" << endl;
}

/**     
	*@brief Funcão que soma a distancia que está sendo percorrida pelo sapo
	*/
void sapo::somaDistPercorrida()
{
	int d = 0;
	for (int i = 0; i < (int)this->valordospulos.size(); i++)
	{
		d += this->valordospulos[i];
	}
	setDistPercorrida(d);
}
/**     
	*@brief Funcão que incrementa o número de pulos
	*@param Esta funcão não tem parâmetros
	*/
void sapo::IncNumPulos()
{
	qtPulos++;
}

/**     
	*@brief Funcão que mostra todas as informações do sapo
	*/
void sapo::infosGerais(){
	cout << "---Nome : "<<this->getNome()<< " | ID : " <<this->getID()<<" | Provas Disputadas : "<<this->getQtProvas() <<" | Vitorias : "<<this->getVitorias() <<" | Derrotas : " <<this->getDerrotas() <<" | Empates : " <<this->getEmpates() << " | Total de Pulos : "<<this->getQtPulosTotal() <<endl;
}