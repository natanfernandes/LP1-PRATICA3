/**
* @author Natanael Fernandes T. Araujo
* @file escreverArquivos.hpp
* @since 06/06/18
* @date 06/06/18
* @brief HPP das funções que escrevem arquivos
*/

#ifndef ESCREVER_H
#define ESCREVER_H
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
#include "../include/corrida.hpp"
#include "../include/sapo.hpp"
#include "../include/pista.hpp"	
    

void escreverArquivoSapos(sapo Sapo);
void escreverArquivosPistas();

#endif