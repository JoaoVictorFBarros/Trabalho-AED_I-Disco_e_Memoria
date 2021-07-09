#include "memoria.hpp"
#include <string.h>

memoria :: memoria(){
	for (int i=0;i<tamL;i++){
		for (int j=0;j<5;j++){
			this -> matrizMemoria [i][j].valor = -1;
			this -> matrizMemoria [i][j].end = "-";
		}
	}
	for (int i=0;i<tamP;i++){
		processo[i] = "-";
	}
	tp=0;
	pagemiss = 0;
	this -> aco = false;
}


int memoria :: getTp (){
	return this -> tp;
}


int memoria :: getPagemiss(){
	return this -> pagemiss;
}


void memoria :: setAco (bool b){
	this -> aco = b;
}


double memoria :: getValor(int y, int x){
	return this -> matrizMemoria [y][x].valor;
}


void memoria :: setValor (int y, int x, double valor){
	this -> matrizMemoria[y][x].valor = valor;
}


void memoria :: carregarProcesso (int lin){
	FILE *arq;
	
	arq = fopen("processos_exemplo.txt","r");
	
	if (arq == NULL){
		cout<<"Erro na abertura do arquivo.\n\n";
	}
	
	char linha[tamP], *resultado;
	string::size_type st;
	char *tokens, processo[tamP];
	const char sep[] = "' '<>,";
	int cont = 1;
	
	for (int i=0;i<lin;i++){
		resultado = fgets (linha,tamP,arq);
	}
	
	tokens = strtok(resultado, sep);
		
	tokens = strtok (NULL, sep);
	this -> processo[0] = tokens;
		
	while (tokens != NULL){
		tokens = strtok (NULL, sep);
		if (tokens != NULL){
			this -> processo[cont] = tokens;
			cont++;
		}
	}
	
	fclose (arq);
	this -> tp = cont;
	corrigirProcesso ();
}


void memoria :: imprimirProcesso (){
	for (int i=0;i<tp;i= i+2){
		
		cout<<"<["<<processo[i]<<"],["<<processo[i+1]<<"]> ";
	}
}


double memoria :: lerProcesso (int i, disco *d){
	disco *pd;
	
	pd = d;
	
	string::size_type st;
	return buscar(processo[i],processo[i+1],stod (processo[i+1],&st),pd);
}



int memoria :: tamArqProcesso (){
	FILE *arq;
	char linha[tamL];
	int cont=0;
	
	arq = fopen ("processos_exemplo.txt","r");
	
	if (arq == NULL){
		cout<<"Erro na abertura do arquivo.\n\n";
	}
	
	while(not feof(arq)){
		fgets (linha,tamL,arq);
		cont++;
	}
	
	return cont;
}


void memoria :: corrigirProcesso (){
	for (int i=0;i<tp;i++){
		if (processo[i] == "\n"){
			tp--;
		}
	}
}


void memoria :: addNaMatriz (int p,double x, disco *d,int y){
	int i=4;
	mem dev;
	
	dev.valor = -1;
	dev.end = "-";
	
	while (i>-1){
		if (i==4){
			dev = matrizMemoria[p][i];
		}
		else{
			matrizMemoria[p][i+1] = matrizMemoria[p][i];
		}
		i--;
		
		bool emMemoria = false;
		
		if ((matrizMemoria[p][0].valor != -1) and (dev.valor != -1)){
			
			for (int k=0;k<tamL;k++){
				for (int j=0;j<5;j++){
					if ((matrizMemoria[k][j].end == dev.end) and ((k != p) or (j != (i+1))) and (dev.end != "-")){		
						emMemoria = true;
					}
				}
			}
			if (not emMemoria){
				d->devolver(dev.end,dev.valor);
			}
		}
	}
	matrizMemoria[p][0].valor = x;
	matrizMemoria[p][0].end = processo[y]+processo[y+1];
}


double memoria :: buscarNoDisco(disco *d,mem m){
	
	int x;
	

	for (int i=0;i<tamL;i++){
		for (int j=0;j<m.valor;j++){
			if (m.end == d->getEnd(i)){
				x = j;	
			}
		}
	}
	double r = d->getValor(m.end,x);
	d->setValor(m.end,x,-1);
	
	
	return r;
}


double memoria :: buscar (string end,string end2, int val, disco *d){
	
	for (int i=0;i<tamL;i++){
		for (int j=0;j<5;j++){
		
			if ((matrizMemoria[i][j].end) == (end+end2)){	
				return this -> matrizMemoria[i][j].valor;
			}
		}
	}
	
	mem m;
	m.end = end;
	m.valor = val;
	pagemiss++;
	return buscarNoDisco(d,m);	
}


void memoria :: imprimirMemoria (){

	for (int i=0;i<4;i++){
		for (int j=0;j<5;j++){
			if (matrizMemoria[i][j].valor != -1){
				cout<<" [0"<<matrizMemoria[i][j].valor<<"] ";
			}
			else{
				cout<<" ["<<matrizMemoria[i][j].valor<<"] ";
			}
		}
		cout<<"\n";
	}
}


void memoria :: esvaziarMemoria (disco *d){
	for (int i=0;i<tamL;i++){
		for (int j=0;j<5;j++){
			if (matrizMemoria[i][j].valor != -1){
				d->devolver(matrizMemoria[i][j].end,matrizMemoria[i][j].valor);
				matrizMemoria[i][j].end = "-";
				matrizMemoria[i][j].valor = -1;
				
				if (aco){
					system ("cls");
					cout<<"Memoria:\n\n";
					imprimirMemoria();
					cout<<"\n\nDisco:\n\n";
					d->imprimir();
					cout<<"\n\n";
					system ("pause");
					system ("cls");
				}
			}
		}
	}
}


void memoria :: zerarProcessos (){
	for (int i=0;i<tp;i++){
		this -> processo [i] = "-";
		if (aco){
			system ("cls");
			cout<<"Processo:\n\n";
			imprimirProcesso();
			cout<<"\n\n";
			system ("pause");
			system ("cls");
		}
	}
}


