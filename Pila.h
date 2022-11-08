#ifndef PILA_H
#define PILA_H
#include "Estructura.h"
//Sebastian Moreno - Luis Bautista

template <class T>
class Pila{
	int tam;
	public:
		Pila();
		~Pila();
		void meter(nodo<T> *v);
		nodo<T> *sacar();
		int vacia();

		
	private:
		struct nodoA{
			T clave;
			nodoA *siguiente;
		};
		
		nodoA *cabeza, *z;
		nodoP<T> *cabeza2;

};

template <class T>
Pila<T>::Pila(){
	cabeza2 = new nodoP <T>;
	tam=0;
	cabeza = new nodoA;
	z = new nodoA;
	cabeza->siguiente=z;	
}


template <class T>
Pila<T>::~Pila(){
	nodoA *t =cabeza;
	while(t!=z){
		cabeza=t;
		t=t->siguiente;
		delete cabeza;
	}
	delete z;
}

template <class T>

void Pila<T>::meter(nodo<T> *v){
	if(tam==0){
		cabeza2->sig = NULL;
	}
	nodoP<T> *t= new nodoP<T>;
	t->dato=v;
	t->sig=cabeza2->sig;
	cabeza2->sig=t;
	
} 

template <class T>
nodo<T> *Pila<T>:: sacar(){
//	nodo<T> *x;
//	nodoP<T> *t = new nodoP<T>;
//	t = cabeza2->sig->dato;
//	cabeza2->sig = t->sig;
//	x=t->dato;
//	cout<<t->dato<<"[!]";
	
	return cabeza2->sig->dato;
}

template <class T>

int Pila<T>::vacia(){
	return cabeza->siguiente==z;
}

#endif
