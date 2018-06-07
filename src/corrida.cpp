/**
*@file corrida.cpp
*@brief Contém todos os metodos e atributos da classe corrida
*@author Natanael Fernandes T. Araujo
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "../include/corrida.hpp"
using namespace std;


/**     
*@brief Funcão que começa a corrida
*/
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
*@brief Funcão que faz a checagem para ver se algum sapo atingiu a distancia
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

/**     
*@brief Funcão que verifica o vencedor
*/
void corrida::vervencedor()
{
	for (int i = 0; i < (int)this->participantes.size(); i++)
	{
		if (this->participantes[i].getDistPercorrida() >= sapo::distTotal)
		{
			cout << "O sapo " << this->participantes[i].getNome() << "(ID = " << this->participantes[i].getID() << ") atingiu o ponto de chegada primeiro!" << endl
				 << endl;
			int vencedorID = this->participantes[i].getID();
			string vencedorNome = this->participantes[i].getNome();
			setChegouPrimeiro(vencedorID, vencedorNome);
			this->ranking.push_back(this->participantes[i]);
			for (int k = 0; k < (int)this->participantes.size(); k++)
			{
				if (this->participantes[i].getNome() == this->participantes[k].getNome())
				{
					continue;
				}
				else
				{
					this->ranking.push_back(this->participantes[k]);
				}
			}
			this->participantes[i].infosFimCorrida();
			printavencedor();
			break;
		}
	}
}

/**     
*@brief Funcão que imprime o sapo vencedor 
*/
void corrida::printavencedor()
{
	cout << "|------------------------------------------------------|" << endl;
	cout << "|           O vencedor foi o sapo : " << getChegouPrimeiroNome() << "(ID = " << getChegouPrimeiroID() << ")   |" << endl;
	cout << "|------------------------------------------------------|" << endl
		 << endl;
}
/**     
*@brief Funcão que atribui o sapo que chegou primeiro
*@param winner Variavel que recebe o id do sapo que chegou primeiro
*/
void corrida::setChegouPrimeiro(int winnerID, string winnerNome)
{
	chegouprimeiroID = winnerID;
	chegouprimeiroNome = winnerNome;
}
/**     
*@brief Funcão que retorna o ID do sapo que chegou primeiro
*/
int corrida::getChegouPrimeiroID()
{
	return chegouprimeiroID;
}

/**     
*@brief Funcão que retorna o nome do sapo que chegou primeiro
*/
string corrida::getChegouPrimeiroNome()
{
	return chegouprimeiroNome;
}

/**     
*@brief Funcão que verifica se ja existe e adciona participante ao vector de sapos
*@param novoParticipante Objeto que será adcionado
*/
void corrida::addParticipante(sapo novoParticipante)
{
	for (int i = 0; i < (int)this->participantes.size(); i++)
	{
		if (novoParticipante.getNome() == this->participantes[i].getNome())
		{
			return;
		}
	}
	this->participantes.push_back(novoParticipante);
}

/**     
*@brief Funcão que verifica se ja existe e adciona uma pista ao vector de pistas
*@param novaPista Objeto que será adcionado
*/
void corrida::addPista(pista novaPista)
{
	for (int i = 0; i < (int)this->pistas.size(); i++)
	{
		if (novaPista.getNomePista() == this->pistas[i].getNomePista())
		{
			return;
		}
	}
	this->pistas.push_back(novaPista);
}

/**     
*@brief Funcão que cria um novo sapo
*/
void corrida::criarSapo()
{
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
	sapo NovoSapo(nomeSapo, qtProvas, vitorias, derrotas, empates, qtPulos);
	addParticipante(NovoSapo);
}

/**     
*@brief Funcão que cria uma nova pista
*/
void corrida::criarPista()
{
	cin.ignore();
	cout << "-Digite o nome da pista : ";
	string nomePista;
	getline(cin, nomePista);
	cout << "-Digite a quantidade de provas que já aconteceram nesta pista : ";
	int qtProvas;
	cin >> qtProvas;
	cin.ignore();
	cout << "-Digite a distancia dessa pista : ";
	int distanciaPista;
	cin >> distanciaPista;
	cin.ignore();
	pista NovaPista(distanciaPista, nomePista, qtProvas);
	addPista(NovaPista);
}

/**     
*@brief Funcão que mostra as estatísticas dos sapos atuais
*/
void corrida::verEstatisticasSapos()
{
	for (int i = 0; i < (int)this->participantes.size(); i++)
	{
		this->participantes[i].infosGerais();
		cout << "" << endl;
	}
	cout << "" << endl
		 << endl;
}

/**     
*@brief Funcão que mostra as estatísticas das pistas atuais
*/
void corrida::verEstatisticasPistas()
{
	for (int i = 0; i < (int)this->pistas.size(); i++)
	{
		this->pistas[i].infosGerais();
		cout << "" << endl;
	}
	cout << "" << endl
		 << endl;
}


/**     
*@brief Funcão que mostra quais pistas e sapos estão disponíveis para a corrida
*/
void corrida::verDisponiveis()
{
	cout << "-Pistas e Sapos disponíveis para a corrida : " << endl
		 << endl;
	cout << "---Pistas :" << endl;
	for (int i = 0; i < (int)this->pistas.size(); i++)
	{
		this->pistas[i].infosGerais();
	}
	cout << "---Sapos :" << endl;
	for (int i = 0; i < (int)this->participantes.size(); i++)
	{
		this->participantes[i].infosGerais();
	}
	cout << "" << endl
		 << endl;
}


/**     
*@brief Funcão que escolhe a pista da corrida
*/
void corrida::escolherPista()
{
	cin.ignore();
	cout << "Escolha a pista para a corrida digitando o nome que foi mostrado anteriormente." << endl
		 << "Ex:'Brazil' para escolher a pista Brazil: " << endl;
	string nomePista;
	getline(cin, nomePista);
	for (int i = 0; i < (int)this->pistas.size(); i++)
	{
		if (nomePista == this->pistas[i].getNomePista())
		{
			cout << "Pista selecionada : " << this->pistas[i].getNomePista() << endl
				 << endl;
			sapo::distTotal = this->pistas[i].getDistancia();
			return;
		}
	}
	cout << "Pista não encontrada!" << endl;
}


/**     
*@brief Funcão que mostra o ranking da corrida ao final
*/
void corrida::verRanking()
{
	cout << "---RANKING---" << endl;
	for (int i = 0; i < (int)this->ranking.size(); i++)
	{
		cout << (i + 1) << " Lugar vai para : " << this->ranking[i].getNome() << endl;
	}
}