#ifndef ESTRUCTURA_H     
#define ESTRUCTURA_H 

template <class T>
struct nodo{T dato;
       	int ID; 
		T info;
        nodo<T> *izq, *der;
        nodo<T> *sig, *ant;

       };
       
template <class T>
struct nodoP{nodo<T> *dato;
        nodoP<T> *sig;

       };
#endif
