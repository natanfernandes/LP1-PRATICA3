#include <iostream>
#include <ctime>
#include <cstdlib>
#include "../include/corrida.hpp"
using namespace std;

void corrida::startcorrida()
{
	while (checagem() == true)
	{
		for (int i = 0; i < (int)this->participantes.size(); i++)
		{
			this->participantes[i].pular();
			this->participantes[i].somaDistPercorrida();
		}
	}
	vervencedor();
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
			cout << "O sapo	 " << this->participantes[i].getID() << " atingiu o ponto de chegada primeiro!" << endl
				 << endl;
			int vencedor = this->participantes[i].getID();
			setChegouPrimeiro(vencedor);
			this->participantes[i].infos();
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
	cout << "|           O vencedor foi o sapo : " << getChegouPrimeiro() << "                  |" << endl;
	cout << "|------------------------------------------------------|" << endl;
}
/**     
*@brief Funcão que atribui o sapo que chegou primeiro
*@param winner Variavel que recebe o id do sapo que chegou primeiro
*/
void corrida::setChegouPrimeiro(int winner)
{
	chegouprimeiro = winner;
}
/**     
*@brief Funcão que retorna o sapo que chegou primeiro
*@param Esta funcão nao recebe parâmetros
*/
int corrida::getChegouPrimeiro()
{
	return chegouprimeiro;
}

void corrida::addParticipante(sapo novoParticipante)
{
	this->participantes.push_back(novoParticipante);
}

