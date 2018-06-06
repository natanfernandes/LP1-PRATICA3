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
using namespace std;
//g++ -o corrida -Wall -ansi -pedantic -O0 -g main.cpp sapo.cpp cabecalho.cpp

int main(){
	sapo jeronimo(1);
	sapo bento(2);
	corrida corrida;
	corrida.addParticipante(jeronimo);
	corrida.addParticipante(bento);
	cabecalho();
	corrida.startcorrida();
	
return 0;
}
