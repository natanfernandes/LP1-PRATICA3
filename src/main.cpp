/**
*@file main.cpp
*@brief Corrida de sapos
*@author Natanael Fernandes T. Araujo
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "../include/sapo.hpp"
#include "../include/pista.hpp"
#include "../include/interface.hpp"
#include "../include/corrida.hpp"
#include "../include/lerArquivos.hpp"
using namespace std;
//g++ -o corrida -Wall -ansi -pedantic -O0 -g main.cpp sapo.cpp cabecalho.cpp

int main()
{
	interface();
	
	//Corrida.startcorrida();

	return 0;
}
