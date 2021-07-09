#include "disco.hpp"
#include <string.h>

disco :: disco(){
	for (int i=0;i<tamL;i++){
		for (int j=0;j<tamC;j++){
			this -> matrizDisco [i] [j] = -1;
		}
		this -> end[i] = "-";
	}
}


 double disco :: getValor (string y, int x){
 	int z;
 	
 	for (int i=0;i<l;i++){
 		if (y == end[i]){
 			z= i;
		 }
	 }
	return this -> matrizDisco [z] [x];
}


void disco :: setValor (string y,int x, double valor){
	int z;
 	
 	for (int i=0;i<l;i++){
 		if (y == end[i]){
 			z= i;
		 }
	 }
	this -> matrizDisco [z] [x] = valor;
}


string disco :: getEnd(int i){
	return this -> end[i];
}


void disco :: carregar (){
	FILE *arq;
	int col=0;
	
	arq = fopen ("arquivos_exemplo.txt","r");
	
	if (arq == NULL){
		cout<<"Erro na abertura do arquivo.\n\n";
	}
	char linha[tamL], *resultado;
	string::size_type st;
	char *tokens;
	const char sep[] = ", ' '";
	int cont = 0, cont2 = 1;
	
	while(not feof(arq)){
			
		resultado = fgets (linha,tamL,arq);
		
		tokens = strtok(resultado, sep);
		this -> end[cont] = tokens;
		
		tokens = strtok (NULL, sep);
		matrizDisco[cont][0] = stod(tokens,&st);
		
		while (tokens != NULL){
			tokens = strtok (NULL, sep);
			if (tokens != NULL){
				this -> matrizDisco[cont][cont2] = stod (tokens,&st);
				cont2++;
				if (cont2>col){
					col = cont2;
				}
			}
		}
		cont2 = 1;
		cont++;
	}
	fclose (arq);
	this -> l = cont;
	this -> c = col;
}


void disco ::  imprimir(){

	for (int i=0;i<l;i++){
		cout<<end[i]<<" -> ";
		for (int j=0;j<c;j++){
			if (matrizDisco[i][j] != -1){
				cout<<"["<<matrizDisco[i][j]<<"] ";
			}
			else{
				cout<<"[-] ";
			}	
		}
		cout<<endl;
	}
}


int disco :: tamLinha (string ender){
	int cont=0,val;
	
	for (int i=0;i<l;i++){
		if (ender == end[i]){
			val = i+1;
			break;
		}
	}
	
	for (int i=0;i<c;i++){
		if (matrizDisco[val][i] != -1){
			cont++;
		}
	}
	return cont;
}


void disco :: devolver (string ender,double valor){
	string::size_type st;
	bool ver = false,ver2 = false;
	int k=0,qz=0;
	
	string add ="";
	
	while (not ver2){
		if (ender[k] == '0'){
			ver = true;
			qz++;
		}
		if (ver and (ender[k] != '0')){
			ver2 = true;
		}
		k++;
	}
	
	for (int i=0;i<qz;i++){
		add = add + '0';
	}	
	
	
	int z;
	for (int i=0;i<=l;i++){
		for (int j=1;j<=c;j++){
 			if (ender == (end[i]+add+to_string(j))){		
 				this -> matrizDisco [i][j-1] = valor;	
		 	}
		}
	}	
}


