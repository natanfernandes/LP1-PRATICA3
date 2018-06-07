/**
*@file interface.cpp
*@brief Contém toda interface da corrida
*@author Natanael Fernandes T. Araujo
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "../include/sapo.hpp"
#include "../include/pista.hpp"
#include "../include/interface.hpp"
#include "../include/corrida.hpp"
#include "../include/lerArquivos.hpp"
#include "../include/escreverArquivo.hpp"
using namespace std;


/**     
*@brief Funcão que mostra um cabecalho visual
*/
void cabecalho()
{
	cout << "|-------------------------------------------------------------------------------------------------------------|" << endl;
	cout << "|                                                                                                             |" << endl;
	cout << "|                                                                                                             |" << endl;
	cout << "|                                              CORRIDA DE SAPOS!                                              |" << endl;
	cout << "|                                                                                                             |" << endl;
	cout << "|                                                                                                             |" << endl;
	cout << "|-------------------------------------------------------------------------------------------------------------|" << endl
		 << endl;
}


/**     
*@brief Funcão que começa e mostra toda a interface do projeto
*/
void interface()
{
	bool out = false;
	corrida Corrida;
	lerArquivoSapos(Corrida);
	lerArquivoPistas(Corrida);
	cabecalho();
	while (out == false)
	{
		cout << "-Bem-vindo a corrida de sapos, oque deseja fazer?" << endl;
		cout << "  a) Ver estatísticas dos sapos." << endl;
		cout << "  b) Ver estatísticas das pistas." << endl;
		cout << "  c) Iniciar corrida." << endl;
		cout << "  d) Criar um sapo." << endl;
		cout << "  e) Criar uma pista." << endl;
		cout << "  f) Fechar corrida." << endl;
		cout << "-Digite a letra correspondente a ação, ex: 'a' para ver as estatísticas dos sapos!" << endl;
		char primeiraOpcao;
		cin >> primeiraOpcao;
		if (primeiraOpcao == 'a')
		{
			cout << " a) Estatísticas dos Sapos : " << endl;
			Corrida.verEstatisticasSapos();
		}
		else if (primeiraOpcao == 'b')
		{
			cout << " a) Estatísticas das Pistas : " << endl;
			Corrida.verEstatisticasPistas();
		}
		else if (primeiraOpcao == 'c')
		{
			cout << " a) Iniciar a corrida : " << endl;
			Corrida.verDisponiveis();
			Corrida.escolherPista();
			Corrida.startcorrida();
			Corrida.verRanking();
			cout << "Corrida Finalizada, fechando ..."<<endl;
			out = true;
		}
		else if (primeiraOpcao == 'd')
		{
			cout << " d) Criar Novo Sapo : " << endl;
			Corrida.criarSapo();
			escreverArquivoSapos(Corrida);
			lerArquivoSapos(Corrida);
		}
		else if (primeiraOpcao == 'e')
		{
			cout << " e) Criar Nova Pista : "<<endl;
			Corrida.criarPista();
			escreverArquivoPistas(Corrida);
			lerArquivoPistas(Corrida);
		}
		else if (primeiraOpcao == 'f')
		{
			cout << "Fechando..." << endl;
			out = true;
		}
	}
}