#include "disco.hpp"
#include "memoria.hpp"

int main (){
	setlocale (LC_ALL,"portuguese");
	disco  d, *pd;
	
	pd = &d;
	memoria m;
	
	int pro=1;
	int qtde;
	bool acomp;
	
	cout<<"----------------------Disco-e-memória----------------------\n";
	cout<<"\nDeseja acompanhar o processamento passo a passo?";
	cout<<"\n\n0-Não";
	cout<<"\n1-Sim";
	cout<<"\n\nResposta: ";
	cin>>acomp;
	m.setAco(acomp);
	cout<<"\n\n";
	
	if (acomp){
		system ("cls");
		cout<<"----------------------Disco-e-memória----------------------\n\n";
	}
	
	cout<<"Carregando disco...";
	d.carregar();
	cout<<"\n\nDisco carregado:";
	if (acomp){
		cout<<"\n\n";
		d.imprimir();
	}

	qtde = m.tamArqProcesso();
	if (acomp){
		cout<<"\n\n"<<qtde<<" processos indetificados\n\n";
		system ("pause");
	}

	while (pro<=qtde){	
	
		if (acomp){
			system ("cls");
			cout<<"----------------------Disco-e-memória----------------------\n";
		}	
			
		cout<<"\n\nLendo processo "<<pro<<"...";
		m.carregarProcesso(pro);

		for (int i=0;i<m.getTp();i= i+2){
				
			m.addNaMatriz(pro-1,m.lerProcesso(i,pd),pd,i);
			
			if (acomp){
				system ("cls");
				cout<<"----------------------Disco-e-memória----------------------\n";
				cout<<"\n\nLendo processo "<<pro<<"...";
				cout<<"\nProcesso "<<pro<<" carregado:\n\n";
				m.imprimirProcesso();
	
				cout<<"\n\nAdicionando processo "<<pro<<" na memória...\n\n";
			
				cout<<"Memoria:\n";
				m.imprimirMemoria();
				cout<<"\n\n\nDisco:\n";
				d.imprimir();
				cout<<"\n";
				system ("pause");
				system ("cls");
			}	
		}
		cout<<"Processo "<<pro<<" executado.";
		pro++;
	}
	
	if (acomp){
		system ("cls");
		cout<<"----------------------Disco-e-memória----------------------\n";
	}
	
	if (acomp){
		cout<<"\nLiberando a memória e zerando processo...\n\n";
		system ("pause");
	}
	m.esvaziarMemoria(pd);
	m.zerarProcessos();
	
	if (acomp){
		cout<<"Concluído";
	}
	cout<<"\n\nMemória final:\n\n";
	m.imprimirMemoria();
	
	cout<<"\n\nProcessos final:\n\n";
	m.imprimirProcesso();
	
	cout<<"\n\nDisco final:\n\n";
	d.imprimir();
	
	cout<<"\nOcorreram "<<m.getPagemiss()<<" page miss\n\n";
	
	system ("pause");

	return 0;
}


