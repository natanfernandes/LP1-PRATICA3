/**
*@file escreverArquivo.cpp
*@brief Contém o contéudo das funções de escrever pistas e sapos
*@author Natanael Fernandes T. Araujo
*/
#include "../include/escreverArquivo.hpp"

/**     
*@brief Funcão que escreve no arquivo os sapos
*@param Corrida ponteiro pra um objeto da classe corrida
*/
void escreverArquivoSapos(corrida &Corrida){
    ofstream myFileSapos("docs/sapos.txt",ios::trunc);
    if(myFileSapos.is_open()){
        for(int i = 0; i < (int)Corrida.participantes.size(); i++){
            myFileSapos << "Nome" <<"\n";
            myFileSapos << Corrida.participantes[i].getNome() <<"\n";
            myFileSapos << "QtPulos" <<"\n";
            myFileSapos << Corrida.participantes[i].getQtPulosTotal() <<"\n";
            myFileSapos << "Corridas" <<"\n";
            myFileSapos << Corrida.participantes[i].getQtProvas() <<"\n";
            myFileSapos << "Vitorias" <<"\n";
            myFileSapos << Corrida.participantes[i].getVitorias() <<"\n";
            myFileSapos << "Derrotas" <<"\n";
            myFileSapos << Corrida.participantes[i].getDerrotas() <<"\n";
            myFileSapos << "Empates" <<"\n";
            myFileSapos << Corrida.participantes[i].getEmpates()<<"\n";
        }
        myFileSapos.close();
    }
    else 
        cout << "Erro na abertura do arquivo sapos.txt !"<<endl;
}


/**     
*@brief Funcão que escreve no arquivo as pistas
*@param Corrida ponteiro pra um objeto da classe corrida
*/
void escreverArquivoPistas(corrida &Corrida){
    ofstream myFilePistas("docs/pistas.txt",ios::trunc);
    if(myFilePistas.is_open()){
        for(int i = 0; i < (int)Corrida.pistas.size(); i++){
            myFilePistas << "Nome" <<"\n";
            myFilePistas << Corrida.pistas[i].getNomePista() <<"\n";
            myFilePistas << "\n"<< "QtCorridas" <<"\n";
            myFilePistas << Corrida.pistas[i].getQtCorridas() <<"\n";
            myFilePistas << "\n"<< "Distancia" <<"\n";
            myFilePistas << Corrida.pistas[i].getDistancia() <<"\n";
        }
    myFilePistas.close();
    }
    else 
        cout << "Erro na abertura do arquivo pistas.txt !"<<endl;
}