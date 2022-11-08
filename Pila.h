#ifndef PILA_H     
#define PILA_H    

template <class T>
struct Nodop{T dato;
        Nodop<T> *sig;
       };


template <class T>
class pila{Nodop<T> *cab;
      public: pila(){cab= new Nodop<T>;
            cab->dato=' ';
            cab->sig=NULL;}
             void Push(T v);
             T Pop();
             bool pilaVacia();
             //~pila();
      };


template <class T>    
void pila<T>::Push(T v){
     Nodop<T> *t = new Nodop<T>;
     t->dato=v; 
     t->sig=cab->sig;
     cab->sig= t;
     }


template <class T>
T pila<T>::Pop(){
     T x;
     Nodop<T> *t= cab->sig;
     cab->sig= t->sig; 
     x=t->dato;
     delete t;
     return x;
     }


template <class T>    
bool pila<T>::pilaVacia(){
      return cab->sig== NULL;
      }





#endif