#ifndef Arbol_h
#define Arbol_h
#include "Cola.h"
#include "Estructura.h"
#include "Pila.h"
#include <iostream>
#include <cstdlib>

using namespace std;


template <class T>
class Arbol{
		nodo<T> *raiz = new nodo<T>;
			int tam;
			Pila<T> pila;
public:	Arbol( ){raiz=NULL;
				 tam=0;
//				 queue<T> *inOrden = new queue<T>;	
				}
	nodo<T> *raiz_arbol( ); /**/
	int ins_arbol (T ins); /**/
	nodo<T> *buscar_arbol (int , nodo<T> *, nodo<T> *); /**/
	bool isEmptyTree(); /**/
	int getTam();/**/
	void preorden(nodo<T> *); 
	void borrar_nodo(nodo<T> * , nodo<T> *, int);/**/
	nodo<T> *buscar(int info, nodo<T> *, nodo<T> *);/**/
	int retira_arbol(int info);/**/
};


//Falta mejorar que No retorne nada al ser la Raiz
template <class T> //Retorna el nodo padre de n
nodo<T> *Arbol<T>::buscar(int n, nodo<T> *p, nodo<T> *q){
	if (p==NULL) return NULL;

	if (n < (p)->info){
	          q=p;
	           p=(p)->izq;
	          q=buscar(n,p,q);
	          return q;}
	else if (n>(p)->info){
		q=p;
		p=(p)->der;
		q =buscar(n,p,q);
		return q;}
		else{
		
		   	return q;
		   } 
		   
}

template <class T>
void Arbol<T>::borrar_nodo(nodo<T> *q, nodo<T>*p, int n){
//Tenemos el antecesor del que vamos a eliminar, debemos encontrar el menor de los mayores.
nodo<T> *r, *s, *t;
//SI TIENE HIJOS POR LA DERECHA
if(q==NULL){//Si es la raiz
	q=p;
	s=q->der;
	r=s->izq;
	t= r->izq;
	while(t!=NULL){
		s=r; r=t; t=t->izq;
	}
	cout<<"[El reemplazo es: "<<r->info<<"]"<<endl;
	s->izq = NULL;
	
	r->der = q->der;
	r->izq = q->izq;
	raiz=r;
	//Delete q
	
}else{

	cout<<"[!](Padre de eliminar) "<<q->info<<endl;	
	//Nos toca comparar para asignar al padre, por derecha o izq, y luego buscar al mínimo
	if(n>q->info){
		s=q->der;
		if(s->der==NULL && s->izq==NULL){ //Si es hoja, menor que el padre
			q->der=NULL;
			//FALTA BORRARLO [!]
		}else if(s->der==NULL && s->izq){
			r = s->izq;
			q->der = r;
		}
		else{
			r=s->der;
			t=r->izq;
			while(t!=NULL){
				s=r; r=t; t=t->izq;
			}
			cout<<"[El reemplazo es: "<<r->info<<"]"<<endl;
			
			r->izq = q->der->izq;
			r->der = q->der->der;
			q->der = r;
			s->izq=NULL;
			
		}
	
		
	}else if(n<q->info){
		s=q->izq;
		if(s->der==NULL && s->izq==NULL){ //Si es hoja, menor que el padre
			q->izq=NULL;
			//FALTA BORRARLO [!]
		}else{
			r=s->der;
			t=r->izq;
		
			while(t!=NULL){
				s=r; r=t; t=t->izq;
			}
			cout<<"[El reemplazo es: "<<r->info<<"]"<<endl;
			
			
			r->izq = q->izq->izq;
			if(q->izq->der == r){
				q->izq = r;
				s->izq=NULL;
			}else{
				r->der = q->izq->der;
				q->izq = r;
				s->izq=NULL;	
			}
			
			
			
			
		}
		
	}
//FIN SI TIENE HIJOS POR LA DERECHA


	
	
	
}
cout<<"[!](Raiz)"<<p->info<<endl;

	
}

template <class T>
int Arbol<T>::retira_arbol(int n){
nodo<T> *q, *p = raiz;
q=buscar(n,p,NULL); 
if (p==NULL) return -1;
borrar_nodo(q, p, n);
return 0;
}


template <class T>
void Arbol<T>::preorden(nodo<T> *p){
	nodo<T> *q;
	q=p;
	while(q->der){
	pila.meter(q->der);
	cout<<q->izq->info<<endl;
	q=q->izq;
	if(q->der==NULL &&q->izq==NULL){
		cout<<"ENTRO AL 1"<<endl;
		q = pila.sacar();
	}
	if(q->izq==NULL){
		q=q->der;
	}
	}
	
}


template <class T>
int Arbol<T>::getTam(){
	return tam;
}

template <class T>
bool Arbol<T>::isEmptyTree(){
	return raiz==NULL;
}

template <class T>
nodo<T> *Arbol<T>::buscar_arbol(int ins, nodo<T> *p/*Raiz*/, nodo<T> *q/*NULL*/){
	if (p==NULL) return q;
	if (ins < p->info){
	q=p; //Toma el valor de raiz como NODO
	q=buscar_arbol(ins ,p->izq, q);
	return q;}
	else if (ins > p->info) {
		q=p;
		q=buscar_arbol(ins ,p->der,q);
		return q;
		}
    else return NULL;
}



template <class T>
int Arbol<T>::ins_arbol(T ins){
	nodo<T> *q;
	if (raiz == NULL){
		raiz= new nodo<T>;
		raiz->info = ins;
		raiz->izq=raiz->der=NULL;
		tam++;
		return 0;}
	
	q = buscar_arbol(ins,raiz,NULL);
	if (q==NULL) return -1; //Cuando se repite
	
	//Se crea el nuevo nodo
	nodo<T> *nuevo;
	nuevo= new nodo<T>;
	nuevo->info = ins;
	nuevo->izq=nuevo->der=NULL;
	
	
	if (ins<q->info){
		tam++;
        q->izq=nuevo;	
	}
	else{
		tam++;
		q->der=nuevo;
			
}  
return 0;
}
		


template <class T>
nodo<T> *Arbol<T>::raiz_arbol( ){
	//cout<<"[!] "<<raiz->info<<endl;
	return raiz;
}




#endif

