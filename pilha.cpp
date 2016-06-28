#include <iostream>
#include "pilha.h"
#include "fila.h"

#define TAM 100

using std::cout;
using std::endl;

Pilha::Pilha(){
	Topo = -1;
}

bool Pilha::Vazia(){
	if(Topo == -1)
		return true;
	else
		return false;
}

bool Pilha::Cheia(){
	if(Topo == (TAM - 1))
		return true;
	else
		return false;
}

void Pilha::Empilha(int X, bool &OK){
	if(Cheia()){
		OK = false;
	} else{
		OK = true;
		Topo = Topo + 1;
		Elementos[Topo] = X;
	}
}

void Pilha::Desempilha(int &X, bool &OK){
	if(Vazia()){
		OK = false;
	}else{
		OK = true;
		X = Elementos[Topo];
		Topo = Topo - 1;
	}
}

bool Pilha::PilhasIguais(Fila &f2){
	bool OK1, OK2, Iguais=true;
	int x1, x2;
	Pilha Aux1;
	Fila Aux2;
	
	while(Vazia() == false && f2.Vazia() == false && Iguais == true){
		Desempilha(x1, OK1);
		f2.Retira(x2, OK2);
		if(OK1)
			Aux1.Empilha(x1, OK1);
		if(OK2)
			Aux2.Insere(x2, OK2);
		if((OK1 == true && OK2 == false) || (OK1 == false && OK2 == true)){
			Iguais == false;
		}
		if(OK1 == true && OK2 == true){
			if(x1 != x2)
				Iguais = false;
		}
	}
	
	while(Aux1.Vazia() == false){
		Aux1.Desempilha(x1, OK1);
		Empilha(x1, OK1);
	}
	
	while(Aux2.Vazia() == false){
		Aux2.Retira(x2, OK2);
		f2.Insere(x2, OK2);
	}
	
	if(Iguais == true)
		return true;
	else
		return false;
}

void Pilha::Imprime(){
	int X;
	bool OK;
	Pilha PAux;
	
	while(Vazia() == false){
		Desempilha(X, OK);
		if(OK)
			PAux.Empilha(X, OK);
	}
	cout << "Mostrando Pilha\n";
	while(PAux.Vazia() == false){
		PAux.Desempilha(X, OK);
		if(OK)
			cout << X << "\n";
			Empilha(X, OK);
	}
}
