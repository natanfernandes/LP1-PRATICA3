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
	*@brief Operado estático distancia total da corrida definido globalmente
	*/
int sapo::distTotal = 30;

int sapo::idGeral = 1;
/**     
	*@brief Construtor
	*@param Este construtor não tem parâmetros
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
	*@brief Funcão que retorna a distancia percorrida
	*@param Esta funcão nao recebe parâmetros
	*/
int sapo::getDistPercorrida()
{
	return this->distpercorrida;
}
/**     
	*@brief Funcão que retorna o id
	*@param Esta funcao nao recebe parametros
	*/
int sapo::getID()
{
	return id;
}
string sapo::getNome(){
	return this->nome;
}

int sapo::getQtProvas(){
	return this->qtProvas;
}

int sapo::getVitorias(){
	return this->vitorias;
}

int sapo::getDerrotas(){
	return this->derrotas;
}

int sapo::getEmpates(){
	return this->empates;
}

int sapo::getQtPulosTotal(){
	return this->qtPulosTotal;
}
void sapo::setVitorias(int vitoriasAux){
	vitorias = vitoriasAux;
}

void sapo::setDerrotas(int derrotasAux){
	derrotas = derrotasAux;
}

void sapo::setQtPulosTotal(int qtPulosTotalAux){
	qtPulosTotal = qtPulosTotalAux;
}
/**     
	*@brief Funcão que atribui a distância percorrida
	*@param d É a variável que recebe o valor da distância percorrida para repassar ao atributo privado
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
void sapo::infos()
{
	cout << "Sapo de ID = " << this->getID() <<" com nome = " << this->getNome() <<" pulou " << this->getnumPulos() << " vezes e a sua distancia percorrida foi " << this->getDistPercorrida() << endl;
}
/**     
	*@brief Funcão que faz os sapos pularem
	*@details A funcão gera um valor de distancia randomico para cada sapo pular e enquanto nenhum sapo antigir a distancia total a corrida não acaba
	*@param sapos Classe que tem todas os atributos do sapo
	*/
void sapo::pular()
{
	int v;
	srand(time(NULL));
	v = std::round(dis(gen));

	this->IncNumPulos();
	this->valordospulos.push_back(v);
	cout << "Sapo " << this->getID() << " pulou : " << v << endl;
	cout << "-------------------------------------------------" << endl;
}

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