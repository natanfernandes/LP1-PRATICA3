#include <vector>
#include "../include/sapo.hpp"
using namespace std;

class corrida {
    private:
        int chegouprimeiro;
        std::vector<sapo> participantes;
    public:
        void addParticipante(sapo novoParticipante);
        void startcorrida();   
        void vervencedor();
        void setChegouPrimeiro(int winner);		
		int getChegouPrimeiro();
        void printavencedor();
        bool checagem();
};