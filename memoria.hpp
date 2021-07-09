#ifndef __memoria_hpp
#define __memoria_hpp

#include <iostream>
#include "disco.hpp"
using namespace std;

#define tamL 100
#define tamP 100

struct mem{
	double valor;
	string end;
};

class memoria{
	private:
		mem matrizMemoria[tamL][5];
		string processo[tamL];
		
		int tp;
		int pagemiss;
		bool aco;
		
	public:
		memoria ();
		
		int getTp ();
		int getPagemiss();
		void setAco(bool b);
		
		double getValor (int y, int x);
		void setValor (int y, int x, double valor);
		
		void carregarProcesso(int lin);
		void imprimirProcesso();
		void corrigirProcesso();
		double lerProcesso(int i,disco *d);
		int tamArqProcesso ();
		
		double buscarNoDisco(disco *d,mem m);
		double buscar (string end,string end2, int val, disco *d);
		
		void addNaMatriz(int p,double x, disco *d,int y);
		void imprimirMemoria ();
		
		void esvaziarMemoria (disco *d);
		void zerarProcessos ();
};

#endif
