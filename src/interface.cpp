#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "../include/sapo.hpp"
#include "../include/pista.hpp"
#include "../include/interface.hpp"
#include "../include/corrida.hpp"
#include "../include/lerArquivos.hpp"
using namespace std;


void cabecalho(){
	cout <<"|-------------------------------------------------------------------------------------------------------------|"<<endl;
	cout <<"|                                                                                                             |"<<endl;
	cout <<"|                                                                                                             |"<<endl;      
	cout <<"|                                              CORRIDA DE SAPOS!                                              |"<<endl;
	cout <<"|                                                                                                             |"<<endl;
	cout <<"|                                                                                                             |"<<endl;
	cout <<"|-------------------------------------------------------------------------------------------------------------|"<<endl<<endl;	
}

void interface(){
	bool out = false;
	corrida Corrida;
	lerArquivoSapos(Corrida);
	lerArquivoPistas(Corrida);
	cabecalho();
	while(out == false){
		cout << "-Bem-vindo a corrida de sapos, oque deseja fazer?"<<endl;
		cout <<"  a) Ver estatísticas dos sapos."<<endl;
		cout <<"  b) Ver estatísticas das pistas."<<endl;
		cout <<"  c) Iniciar corrida."<<endl;
		cout <<"  d) Criar um sapo."<<endl;
		cout <<"  e) Criar uma pista."<<endl;
		cout <<"-Digite a letra correspondente a ação, ex: 'a' para ver as estatísticas dos sapos!"<<endl;
		char primeiraOpcao;
		cin >> primeiraOpcao;
		if(primeiraOpcao == 'a'){
			Corrida.verEstatisticasSapos();
		}
		else if(primeiraOpcao =='d'){
			Corrida.criarSapo();
		}
	}
}