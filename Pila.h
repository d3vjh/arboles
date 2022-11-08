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
		T sacar();
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
		cout<<":C"<<endl;
		cabeza2->sig = NULL;
	}
	nodoP<T> *t= new nodoP<T>;
		cout<<"1"<<endl;
	t->dato=v;
	cout<<"holxx"<<(t->dato->info)<<endl;
	
	t->sig=cabeza2->sig;
	cout<<"3"<<endl;
	cabeza2->sig=t;
	cout<<"con mi ultimo aliento maldigo los nodos"<<endl;
} 

template <class T>

T Pila<T>:: sacar(){
	T x;
	nodoA *t = cabeza->siguiente;
	cabeza->siguiente = t->siguiente;
	x=t->clave;
	delete t;
	return x;
}

template <class T>

int Pila<T>::vacia(){
	return cabeza->siguiente==z;
}

#endif
