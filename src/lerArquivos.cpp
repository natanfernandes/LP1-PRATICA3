/**
*@file lerArquivos.cpp
*@brief Contém o contéudo das funções de ler sapos e pistas
*@author Natanael Fernandes T. Araujo
*/
#include "../include/lerArquivos.hpp"


/**     
*@brief Funcão que lê do arquivo os sapos
*@param Corrida ponteiro pra um objeto da classe corrida
*/
void lerArquivoSapos(corrida &Corrida){
    string linha,pulosAux,provasAux,empatesAux,derrotasAux,vitoriasAux;
    ifstream myFileSapos("docs/sapos.txt");

    if(!myFileSapos.is_open()){
        cout << "Erro na abertura do arquivo sapos.txt !"<<endl;
        return;
    }
    string nomeSapo;
    int vitoriasSapo,qtPulos,provasDisp,empatesSapo,derrotasSapo;
    while(!myFileSapos.eof()){
        getline(myFileSapos,linha);
        if(linha == "Nome"){
            getline(myFileSapos,nomeSapo);
        }
        else if(linha == "QtPulos"){
            getline(myFileSapos,pulosAux);
            qtPulos = stod(pulosAux);
        }
        else if(linha == "Corridas"){
            getline(myFileSapos,provasAux);
            provasDisp = stod(provasAux);
        }
        else if(linha == "Vitorias"){
            getline(myFileSapos,vitoriasAux);
            vitoriasSapo = stod(vitoriasAux);
        }
        else if(linha == "Derrotas"){
            getline(myFileSapos,derrotasAux);
            derrotasSapo = stod(derrotasAux);
        }
         else if(linha == "Empates"){
            getline(myFileSapos,empatesAux);
            empatesSapo = stod(empatesAux);
            sapo NovoSapo(nomeSapo,provasDisp,vitoriasSapo,derrotasSapo,empatesSapo,qtPulos);
            Corrida.addParticipante(NovoSapo);
        }
    }
    myFileSapos.close();
}


/**     
*@brief Funcão que lê do arquivo as pistas
*@param Corrida ponteiro pra um objeto da classe corrida
*/
void lerArquivoPistas(corrida &Corrida){
    string linha,distanciaAux,qtCorridasAux;
    ifstream myFilePistas("docs/pistas.txt");
    string nomePista;
    int distanciaPista,qtCorridasPista;
    if(!myFilePistas.is_open()){
        cout << "Erro na abertura do arquivo sapos.txt !"<<endl;
        return;
    }

    while(!myFilePistas.eof()){
        getline(myFilePistas,linha);
        if(linha == "Nome"){
            getline(myFilePistas,nomePista);
        }
        else if(linha == "QtCorridas"){
            getline(myFilePistas,qtCorridasAux);
            qtCorridasPista = stod(qtCorridasAux);
        }
        else if(linha == "Distancia"){
            getline(myFilePistas,distanciaAux);
            distanciaPista = stod(distanciaAux);
            pista NovaPista(distanciaPista,nomePista,qtCorridasPista);
            Corrida.addPista(NovaPista);
        }
    }
}