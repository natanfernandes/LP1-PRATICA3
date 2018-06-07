#include <iostream>
#include <ctime>
#include <cstdlib>
#include "../include/corrida.hpp"
using namespace std;

void corrida::startcorrida()
{
	while (this->checagem() == true)
	{
		for (int i = 0; i < (int)this->participantes.size(); i++)
		{
			this->participantes[i].pular();
			this->participantes[i].somaDistPercorrida();
		}
	}
	this->vervencedor();
}
/**     
*@brief Funcão que faz a checagem de qual sapo é o vencedor
*@param sapos Classe que tem todas os atributos do sapo
*/

bool corrida::checagem()
{
	for (int j = 0; j < (int)this->participantes.size(); j++)
	{
		if (this->participantes[j].getDistPercorrida() >= sapo::distTotal)
		{
			return false;
		}
	}
	return true;
}
void corrida::vervencedor()
{
	for (int i = 0; i < (int)this->participantes.size(); i++)
	{
		if (this->participantes[i].getDistPercorrida() >= sapo::distTotal)
		{
			cout << "O sapo "<<this->participantes[i].getNome() << "(ID = " << this->participantes[i].getID() << ") atingiu o ponto de chegada primeiro!" << endl
				 << endl;
			int vencedorID = this->participantes[i].getID();
			string vencedorNome = this->participantes[i].getNome();
			setChegouPrimeiro(vencedorID,vencedorNome);
			this->participantes[i].infosFimCorrida();
			printavencedor();
			break;
		}
	}
}
/**     
*@brief Funcão que imprime o sapo vencedor 
*@param Esta funcão nao recebe parâmetros
*/
void corrida::printavencedor()
{
	cout << "|------------------------------------------------------|" << endl;
	cout << "|           O vencedor foi o sapo : " << getChegouPrimeiroNome() <<"(ID = "<< getChegouPrimeiroID() << ")   |" << endl;
	cout << "|------------------------------------------------------|" << endl;
}
/**     
*@brief Funcão que atribui o sapo que chegou primeiro
*@param winner Variavel que recebe o id do sapo que chegou primeiro
*/
void corrida::setChegouPrimeiro(int winnerID,string winnerNome)
{
	chegouprimeiroID = winnerID;
	chegouprimeiroNome = winnerNome;
}
/**     
*@brief Funcão que retorna o sapo que chegou primeiro
*@param Esta funcão nao recebe parâmetros
*/
int corrida::getChegouPrimeiroID()
{
	return chegouprimeiroID;
}
string corrida::getChegouPrimeiroNome()
{
	return chegouprimeiroNome;
}

void corrida::addParticipante(sapo novoParticipante)
{
	this->participantes.push_back(novoParticipante);
}

void corrida::addPista(pista novaPista){
	this->pistas.push_back(novaPista);
}	

void corrida::criarSapo(){
	cin.ignore();
	cout << "-Digite o nome do sapo : ";
	string nomeSapo;
	getline(cin, nomeSapo);
	cout << "-Digite a quantidade de provas que esse sapo já disputou : ";
	int qtProvas;
	cin >> qtProvas;
	cin.ignore();
	cout << "-Digite a quantidade de vitórias desse sapo : ";
	int vitorias;
	cin >> vitorias;
	cin.ignore();
	cout << "-Digite a quantidade de derrotas desse sapo : ";
	int derrotas;
	cin >> derrotas;
	cin.ignore();
	cout << "-Digite a quantidade de empates desse sapo : ";
	int empates;
	cin >> empates;
	cin.ignore();
	cout << "-Digite a quantidade total de pulos que esse sapo já deu : ";
	int qtPulos;
	cin >> qtPulos;
	cin.ignore();
	sapo NovoSapo(nomeSapo,qtProvas,vitorias,derrotas,empates,qtPulos);
	addParticipante(NovoSapo);
	escreverArquivoSapos(NovoSapo);
}

void corrida::verEstatisticasSapos(){
	for(int i = 0; i < (int)this->participantes.size(); i++){
		this->participantes[i].infosGerais();
	}
}