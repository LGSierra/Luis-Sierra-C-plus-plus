#ifndef HEADER_H
#define HEADER_H


//header file
#include <iostream>
#include <cstdlib>

using namespace std; 
namespace pares{


struct node{
	int A;
	int B;
	node *link;
	friend ostream &operator <<(ostream& salida , const node& x);
	friend istream &operator >>(istream& entrada, node& x);
};


typedef node* ParPtr;



void agregar_principio(ParPtr& ListHead, ParPtr& temporary);
void agregar_final(ParPtr& ListHead, ParPtr& temporary);
void sumar(ParPtr& ListHead);
void restar(ParPtr& ListHead);
void mostrar(ParPtr& ListHead);


int menu();
bool repetido(ParPtr& ListHead, int a, int b);

}



#endif //HEADER_H
