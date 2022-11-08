#ifndef ESTRUCTURA1_H     
#define ESTRUCTURA1_H 

template <class T>
struct nodo{char dato;
       	int ID; 
		int info;
        nodo<T> *izq, *der;
        nodo<T> *sig, *ant;

       };
       
#endif
