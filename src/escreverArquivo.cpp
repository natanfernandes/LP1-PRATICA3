#include "../include/escreverArquivo.hpp"

void escreverArquivoSapos(sapo Sapo){
    ofstream myFileSapos("docs/sapos.txt",ios::out | ios::app);
    if(myFileSapos.is_open()){
        myFileSapos <<"\n"<< "Nome" <<"\n";
        myFileSapos << Sapo.getNome() <<"\n";
        myFileSapos << "QtPulos" <<"\n";
        myFileSapos << Sapo.getQtPulosTotal() <<"\n";
        myFileSapos << "Corridas" <<"\n";
        myFileSapos << Sapo.getQtProvas() <<"\n";
        myFileSapos << "Vitorias" <<"\n";
        myFileSapos << Sapo.getVitorias() <<"\n";
        myFileSapos << "Derrotas" <<"\n";
        myFileSapos << Sapo.getDerrotas() <<"\n";
        myFileSapos << "Empates" <<"\n";
        myFileSapos << Sapo.getEmpates();
        myFileSapos.close();
    }
    else 
        cout << "Erro na abertura do arquivo sapos.txt !"<<endl;
}