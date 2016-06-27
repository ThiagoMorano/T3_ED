
#ifndef Pilha_H
#define Pilha_H

#include "fila.h"
 
#define TAM 10

class Pilha{
	
	private:
		int Topo;
		int Elementos[TAM];
	
	public:
		Pilha();
		bool Vazia();
		bool Cheia();
		void Empilha(int X, bool &OK);
		void Desempilha(int &X, bool &OK);
		bool PilhasIguais(Fila &_p2);
		void Imprime();
};

#endif
