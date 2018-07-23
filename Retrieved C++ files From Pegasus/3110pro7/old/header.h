#ifndef HEADER_H
#define HEADER_H


//header file
#include <iostream>
#include <cstdlib>

using namespace std; 
namespace pares{

template <class T>
struct node{
	T A;
	T B;
	node<T> *link;
};

//typedef node* ParPtr;
//pointer

template <class T>
class ParOrdenado{
	
public:
	ParOrdenado();
	~ParOrdenado();
	void agregar_principio(int& max);
	//añade par ordenado al principio de la lista
	// crea cabeza si no existe
	// elimina duplicaciones
	
	void agregar_final(int& max);
	//añade par ordenado al final de la lista
	// crea cabeza si no existe
	// elimina duplicaciones
	
	void sumar(int& max);
	//suma dos pares ordenados
	// de una selecion ya establecida
	//añade el resultado a la lista, sino esta duplicada
	
	void restar(int& max);
	//
	
	void mostrar2(ofstream& out);
	//mostrar todos los pares
	//los pone a un archivod e salida
	
	void mostrar();
	//mostar todos los pares ordenados añadidos hasta ahora
	
	
	void agregar(int& max);
	//agregar en cualquier sitio
	
	void eliminar(int& max);
	
	void ordenar();
	
	bool repetido(T a, T b);
	//revisar si hay pares ordenados repetidos
	
	bool IsEmpty();
	//revisar si la lista esta vacia
	
	
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

void menu(int& opc, int&opc2);

}



#endif //HEADER_H
