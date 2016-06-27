#ifndef Fila_H
#define Fila_H

#define TAM 10

class Fila{
	
	private:
		int nElementos;
		int primeiro;
		int ultimo;
		int Elementos[TAM];
		
	public:
		Fila();
		bool Vazia();
		bool Cheia();
		void Insere(int X, bool &OK);
		void Retira(int &X, bool &OK);	
		void Imprime();
};

#endif
