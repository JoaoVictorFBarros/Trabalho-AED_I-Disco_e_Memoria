#ifndef __disco_hpp
#define __disco_hpp

#include <iostream>
using namespace std;

#define tamL 100
#define tamC 100

class disco{
	
	private:
		int l, c;
		double matrizDisco[tamL][tamC];
		string end[tamL];
		
	public:
		disco ();
		
		double getValor (string y, int x);
		void setValor (string y,int x, double valor);
		
		string getEnd (int i);
		
		void carregar ();
		
		void imprimir ();
		
		int tamLinha (string ender);
		
		void devolver (string ender, double valor);
		
};

#endif

