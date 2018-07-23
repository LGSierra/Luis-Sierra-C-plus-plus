//
//header cpp
#include <iostream>
#include <cstdlib>
#include "header.h"
#include <fstream>
using namespace std;

namespace pilas{
	
	template<class T>
	Pila<T>::Pila(){
		ListHead = NULL;
	}
	
	template<class T>
	Pila<T>::Pila(const Pila& una_pila){
		if (una_pila.ListHead == NULL){
			ListHead = NULL;
		}
		else{
			temporary = una_pila.ListHead;
			node<T>* fin;
			fin = new node<T>;
			ListHead = fin;
			
			temporary = temporary->link;
			while(temporary != NULL){
				fin->link = new node<T>;
				fin = fin->link;
				fin->A = temporary->A;
				temporary->link;
			}
		fin->link = NULL;
		}
	}
	
	template<class T>
	Pila<T>::~Pila(){
	}




template<class T>
void Pila<T>::agregar(int& max){
	// repeated check, installed
	node<T>* temporary;
	T number;
	
	cout << "Introduzca elemento a la pila." << endl;
	cin >> number;
	if(ListHead == NULL){
		ListHead = new node<T>;
		ListHead->A = number;
		ListHead->link = NULL;
		cout << "Pila creada." << endl;
		max++;
	}
	
	else{
		temporary = new node<T>;
		temporary->A= number;
		temporary->link = ListHead;
		ListHead = temporary;
		max++;
	}
}



template<class T>
void Pila<T>::mostrar(ofstream& out, int& max){
	//modify to overload the output
	
	if(IsEmpty()){
		cout << "Pila esta vacia." << endl <<endl;
	}
	else{
		node<T>* cursor = ListHead;
		int count = 1;
		while(cursor != NULL){
			cout << "Elemento" << count << ":" << endl; 
			cout << "(" << cursor->A <<  ")" << endl;
			out << "Elemento " << count << ":" << endl; 
			out << "(" << cursor->A << ")" << endl;
			cursor = cursor->link;
			count++;
			
		} cout << endl;
		int choice = max;
		bool bypass = true;			
		eliminar(max, choice, bypass);
		cout << "Pila eliminada." << endl << endl;
}
}

template<class T>
bool Pila<T>::repetido(){
	
	node<T>* temporary = new node<T>;
	temporary = ListHead;
	bool repeated=false;
	
	int counter =0;
	T value;
	
	if(IsEmpty()){
		cout << "Pila esta vacia." << endl << endl;
	}
	else{
		cout << "Indique que valor del elemento desea revisar por ocurrencias." << endl;
		cin >> value;
		
		while(temporary != NULL){  //revisa toda la lista
			if(value == temporary->A){	//si valor = valor en la lista, aumenta counter
				counter++;	
				temporary = temporary->link;	
			}
			else{
				temporary = temporary->link;
			}
		}
		if(counter == 0){				//si counter termina en cero despues de checkear la lista, pues valor no existe en la lsita
			cout << "Valor indicado no aparece en la pila." << endl << endl;
		}
		else{							//demuestra counter del valor elegido
			cout << "Cantidad de ocurrencias para el valor: " << value << endl;
			cout <<counter << endl << endl;
		}
	}
}


template<class T>
istream &operator >>(istream& entrada, node<T>*& x){
    entrada >> x.A;
    return entrada;
}

template<class T>
ostream &operator <<(ostream& salida , const node<T>*& x){
    salida << "(" << x.A <<  ")" << endl;
    return salida;
}

template<class T>
bool Pila<T>::IsEmpty(){
	if(ListHead == NULL)
		{
		return true;
		}
	else{
		return false;
	}
}


template<class T>
	void Pila<T>::eliminar(int& max, int choice, bool bypass){
	//deleting stuff
	//T resultado = ListHead->A;

	if(IsEmpty()){
		cout << "La pila ya esta vacia. No se puede eliminar nodos." << endl << endl;
	}
	else if(bypass==true){
		
		for(int i=1; i<= choice; i++){
			temporary = ListHead;
			ListHead = ListHead->link;
			delete temporary;
			max--;	
		}
	}
	
	
	else{
	cout << "Indicar cantidad a eliminar" << endl;
	cin >> choice;
	
	if(choice <1){
		cout<< "Error: numero invalido. Favor repetir." << endl << endl;
	}
	else if(choice > max){
		cout<< "Error: cantidad de elementos en la pila que desea eliminar exede cantidad total de la pila." << endl << endl;
	}
	else{
		for(int i=1; i<= choice; i++){
			temporary = ListHead;
			ListHead = ListHead->link;
			delete temporary;
			max--;	
		}
		
		cout << choice << " valores han sido eliminados de la pila." << endl << endl;
	//	return resultado;
		}	
	}
}
	template<class T>
	void Pila<T>::primero(int& max, bool bypass){
		node<T>* cursor = ListHead;
		int choice = 1;
		
		if(IsEmpty()){
			cout << "Pila esta vacia, no se puede mostrar." << endl;
		}
		
		else{
			cout << "Elemento al principio de la pila:" << endl;
			cout << "(" << cursor->A <<  ")" << endl;
			bypass = true;
			cout << "Primer elemento en la pila sera eliminado" << endl << endl;
			eliminar(max, choice, bypass);	
			
		}
		
		
	}	
	
void menu(int& opc){
	
	
	do{
		cout << "Eliga una alternativa para hacer su lista." << endl << endl;
		cout << "1. Crear Pila. " << endl;
		cout << "2. Mostrar Primer elemento de la pila." << endl;
		cout << "3. Eliminar n elementos de una pila." << endl;
		cout << "4. Calcular cantidad de ocurrencias de un elemento." << endl;
		cout << "5. Mostrar elementos de una pila." << endl;
		cout << "6. Cambiar Elemento." << endl;
		cout << "7. Fin de programa." << endl << endl;
		cin >> opc;
		
		if (opc < 0 || opc >7){
			cout << "Error: opcion invalida. Favor repetir." << endl << endl;
		}
	}while(opc < 0 || opc > 7);
}	

void menu2(int& opc2){
	do{
		cout << "Elige entre estar tres alternativas para crear una pila." << endl;
		cout << "1. Enteros \t(X) " << endl;
		cout << "2. Reales \t(X.0) " << endl;
		cout << "3. Caracteres \t(\"A\") " << endl;
		cout << "4. Fin de programa." << endl << endl;
		cout << "**Para mostrar pila en archivo, selecione mostrar en menu**" << endl;
		cin >> opc2;
		
		if(opc2 < 1 || opc2 >4){
			cout << "Opcion invalida, favor repetir." << endl << endl;
		}
		
	}while(opc2 < 1 || opc2 >4);
	
}


}


