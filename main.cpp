#include <iostream>
#include "pilha.h"
#include "fila.h"

using std::cout;
using std::cin;

int main(){
	
	int x;
	bool ok;
	int valor;
	int num = 2;
	Pilha p1;
	Fila f2;
	
	for(int i=0; i<5; i++){
		cin >> x;
		p1.Empilha(x, ok);
		if(ok == true)
			cout << "Empilho\n";
		else
			cout << "Nao Empilho\n";
	}
	
	for(int i=0; i<5; i++){
		cin >> x;
		f2.Insere(x, ok);
		if(ok == true)
			cout << "Inseriu\n";
		else
			cout << "Nao Inseriu\n";
	}
	
	if(p1.PilhasIguais(f2))
		cout << "Pilhas Iguais\n";
	else
		cout << "Pilhas nao iguais\n";
	
	return 0;
}
