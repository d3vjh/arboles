#ifndef QUEUE_H
#define QUEUE_H
#include "Estructura.h"


using namespace std;


template <class T>
class queue{nodo<T> *cab ;
			nodo<T> *fin ;
			int tam;
      public: queue(){
      	cab = new nodo<T>;
      	fin = new nodo<T>;
	  	tam =0;
	  	cab=fin=NULL;}
      void insertar(T dato, char lado);
      void eliminar(char lado);
      void printQueue(char lado);
      bool isEmptyQueue();
      int getSize();
      T getDate(int pos, char lado);
//    ~cola();
      
 };


template <class T>
void queue<T>::insertar(T inf, char lado){
	nodo<T> *nuevo = new nodo<T>;
	nuevo->info = inf;
	nuevo->ant = NULL;
	nuevo->sig = NULL;
	
 	if (tam == 0 && (lado=='I' || lado =='D')) {
  		cab = nuevo;
   		fin = nuevo;
   		tam++;
 	}else{
  		if (lado == 'I') {
   	   	/* ... fin nuevo */
   	   	fin->sig = nuevo;
   	   	nuevo->ant = fin;
    	fin = nuevo;
    	tam++;
   	 } else if (lado == 'D') {
   	   /* nuevo cab ... */
   	  	nuevo->sig = cab;
    	cab->ant = nuevo;
    	cab = nuevo;
    	tam++;
   	 }
  }
}


template <class T>
void queue<T>::eliminar(char lado){
	if(tam==1){
		cab = NULL;
		fin = NULL;
		tam--;
	}else if(tam == 0){
		cout<<"No hay elementos a sacar"<<endl;
	}else if(lado == 'I'){
		tam--;
		nodo<T> *aux = new nodo<T>;
		aux = cab->sig;
		cab = aux;
		//Delete aux; y si se realiza tambien cuando vale la variable a borrar
	}else if(lado == 'D'){
		tam--;
		nodo<T> *aux = new nodo<T>;
		aux = fin->ant;
		fin = aux;
		//Delete aux;
	}	
}


template <class T>
int queue<T>::getSize(){
	return tam;	
}


template <class T>
void queue<T>::printQueue(char lado){
	cout<<endl<<"[ ";
	if(lado == 'I'){
		for(int i=1; i<=tam; i++){
		cout<<getDate(i, 'I');
		}
	}else if(lado == 'D'){
		for(int i=1; i<=tam; i++){
		cout<<getDate(i, 'D');
		}
	}
	cout<<" ]";	
}



template <class T>
T queue<T>::getDate(int pos, char lado){
	nodo<T> *aux = new nodo<T>;
	
	if(lado == 'I'){
		aux = cab;
		if(pos == 1){
		
		return aux->info;
		}else{
			for(int i=1; i<pos; i++){
				aux = aux->sig;
			}
			cout<<" - ";
			return aux->info;	
		}
		cout<<endl;
	}else if(lado == 'D'){
		aux = fin;
		if(pos == 1){
		return aux->info;
		}else{
			for(int i=1; i<pos; i++){
				aux = aux->ant;
			}
			cout<<" - ";
			return aux->info;
		}
		cout<<endl;
	}else{
		cout<<"Ingresó mal un dato, revise de nuevo";
		return NULL;
	}
}


template <class T>
bool queue<T>::isEmptyQueue(){
	if(tam==0)
		return true;
	else
		return false;	
}


#endif
