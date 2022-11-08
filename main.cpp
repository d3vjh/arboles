#include <iostream>
#include "arbol.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main(int argc, char** argv) {
	
	Arbol<int> enteros;
	
	
	cout<<"Esta vacio?: "<<enteros.isEmptyTree()<<endl;
	
	enteros.ins_arbol(15);
	enteros.ins_arbol(7);
	enteros.ins_arbol(20);
	enteros.ins_arbol(24);
	enteros.ins_arbol(18);
	enteros.ins_arbol(9);
	enteros.ins_arbol(3);
	enteros.ins_arbol(1);
	enteros.ins_arbol(4);
	enteros.ins_arbol(8);
	enteros.ins_arbol(12);
	enteros.ins_arbol(17);
	enteros.ins_arbol(19);
	enteros.ins_arbol(21);
	enteros.ins_arbol(5);
	enteros.ins_arbol(10);
	

	
	enteros.retira_arbol(3);

	enteros.preorden(enteros.raiz_arbol());

	return 0;
}
