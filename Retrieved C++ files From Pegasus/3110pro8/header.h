#ifndef HEADER_H
#define HEADER_H


//header file
#include <iostream>
#include <cstdlib>

using namespace std; 
namespace pilas{

template <class T>
struct node{
	T A;
	node<T> *link;
};

//typedef node* ParPtr;


template <class T>
class Pila{
	
public:
	Pila();
	Pila(const Pila& una_pila);
	~Pila();
	
	void mostrar(ofstream& out, int& max);
	//mostar todos los pares ordenados añadidos hasta ahora
	
	
	void agregar(int& max);
	//agregar en cualquier sitio
	
	void eliminar(int& max, int choice, bool bypass);
	
	
	bool repetido();
	//revisar si hay pares ordenados repetidos
	
	bool IsEmpty();
	//revisar si la lista esta vacia
	
	void primero(int& max, bool bypass);
	//escribre primer elemento en la pila
	
	private:	
	node<T>* ListHead;
	node<T>* temporary;
	int max;
};

	template<class T>
	inline ostream &operator <<(ostream& salida, node<T>*& x);
	//overload operator para par ordenado
	
	template <class T>
	inline istream &operator >>(istream& entrada, node<T>*& x);
	//overload operator para par ordenado

void menu(int& opc);
void menu2(int& opc2);

}



#endif //HEADER_H
