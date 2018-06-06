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
#include "../include/cabecalho.hpp"
#include "../include/corrida.hpp"
#include "../include/lerArquivos.hpp"
using namespace std;
//g++ -o corrida -Wall -ansi -pedantic -O0 -g main.cpp sapo.cpp cabecalho.cpp

int main()
{
	corrida Corrida;
	cabecalho();
	lerSapo(Corrida);
	Corrida.startcorrida();

	return 0;
}
