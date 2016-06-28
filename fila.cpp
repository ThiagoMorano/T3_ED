#include <iostream>
#include "fila.h"

#define TAM 100

using std::cout;

Fila::Fila(){
	primeiro = 1;
	ultimo = 1;
	nElementos = 0;	
}

bool Fila::Vazia(){
	if(nElementos == 0)
		return true;
	else
		return false;
	
}

bool Fila::Cheia(){
	if(nElementos == TAM)
		return true;
	else
		return false;
}

void Fila::Insere(int X, bool &OK){
	if(Cheia() == true)
		OK = false;
	else
	{
		OK = true;
		nElementos = nElementos + 1;
		Elementos[ultimo] = X;
		if(ultimo == TAM)
			ultimo = 1;
		else
			ultimo = ultimo + 1;
	}
			
}

void Fila::Retira(int &X, bool &OK){
	if(Vazia() == true)
		OK = false;
	else
	{
		OK = true;
		nElementos = nElementos - 1;
		X = Elementos[primeiro];
		if(primeiro == TAM)
			primeiro = 1;
		else
			primeiro = primeiro + 1;
	}
}

void Fila::Imprime(){
	int X;
	bool OK;
	Fila FAux;

	while(Vazia() == false){
		Retira(X, OK);
		if(OK)
			FAux.Insere(X, OK);
	}
	cout << "Mostrando Fila\n";
	while(FAux.Vazia() == false){
		FAux.Retira(X, OK);
		if(OK)
			cout << X << "\n";
			Insere(X, OK);
	}
}
