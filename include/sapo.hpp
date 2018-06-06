#ifndef SAPO_HPP
#define SAPO_HPP
#include <iostream>
#include <random>
#include <vector>
#include <string>
using namespace std;

class sapo {
	private:
		string nome;
		int qtProvas;
		int vitorias;
		int derrotas;
		int empates;
		int id;
		double distpercorrida;
		int qtPulos;
		int qtPulosTotal;
	public:
		static int distTotal;
		static int getdistTotal();
		std::vector<double> valordospulos;
		sapo(int sapoID,string nomeSapo);
		void setDistPercorrida(int d);
		int getDistPercorrida();
		int getID();				
		void IncNumPulos();
		int getnumPulos();
		void infos();			
		void pular();
		void somaDistPercorrida();
		
		static std::random_device rd;
		static std::mt19937 gen;
		static std::uniform_int_distribution<> dis;
	};
#endif