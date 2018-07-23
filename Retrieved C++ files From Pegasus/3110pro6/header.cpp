//header cpp
#include <iostream>
#include <cstdlib>
#include "header.h"
using namespace std;


namespace pares{

int menu(){
	int opc;
	
	do{
		cout << "elige una alternativa." << endl;
		cout << "1. Agregar un par ordenado a principio de lista." << endl;
		cout << "2. Agredar par ordenado a final de lista." << endl;
		cout << "3. Sumar dos pares ordenados." << endl;
		cout << "4. Restar dos pares ordenados." << endl;
		cout << "5. Mostrar lista." << endl;
		cout << "6. Fin de programa." << endl;
		cin >> opc;
	}while(opc < 0 || opc > 6);
	
	return opc;
}

void agregar_final(ParPtr& ListHead, ParPtr& temporary ){
	//repeated, installed
	int number1, number2;
	ParPtr q = new node;
	
	cout << "Introduzca numeros de un par ordenado, separados por un espacio, para agregarlo a la lista." << endl;
	cin >> number1 >> number2;
	
	q->A= number1;
	q->B=number2;
	q->link = NULL;
	
	if(ListHead == NULL){
		ListHead = new node;
		ListHead = q;
		cout << "Cabeza de lista creada." << endl;
	}
	
	else{
		
		if(repetido(ListHead,number1,number2)){
			cout << "El par ordenado ya existe en la lista. Favor de introducir otro par diferente. Este par no sera almacenado." << endl;
		}
		
		else{
			
			temporary = new node;
			temporary = ListHead;
			
			while(temporary ->link != NULL){
				temporary = temporary->link;
			}
			temporary ->link = q;
			
			
			
		}
		
		
	}
}

void agregar_principio(ParPtr& ListHead, ParPtr& temporary){
	// repeated check, installed

	int number1, number2;
	
	cout << "Introduzca numeros de un par ordenado, separados por un espacio, para agregarlo a la lista." << endl;
	cin >> number1 >> number2;
	if(ListHead == NULL){
		ListHead = new node;
		ListHead->A = number1;
		ListHead->B = number2;
		ListHead->link = NULL;
		cout << "Cabeza de lista creada." << endl;
	}
	
	else{
		if(repetido(ListHead,number1,number2)){
			cout << "El par ordenado ya existe en la lista. Favor de introducir otro par diferente. Este par no sera almacenado." << endl;
		}
		
		else{
			
			temporary = new node;
			temporary->A = number1;
			temporary->B = number2;
			temporary->link = ListHead;
			ListHead = temporary;
			
		}
		
	}
}

void sumar(ParPtr& ListHead,int& max){
	ParPtr cursor = new node;
	ParPtr cursor2 = new node;
	int count = 1, a, b, c, d, x=1, y=1;
	
	//suma
	
	do{
	mostrar(ListHead);
	cout << "Eliga los numeros marcando el par ordenado que desea sumar. " << endl;
	cin >> x >> y;
	
	if(x> max || y > max || x < 1 || y < 1){
		cout << "Opcion invalida dentro de las alternativas provistas. Favor de elegir pares dentro de la lista." << endl;
	}
	
	} while (x> max || y > max || x < 1 || y < 1);
	
	cursor = ListHead;
	
	while(cursor->link !=NULL ){
		if(count == x){
			a = cursor ->A;
			b = cursor ->B;
			count++;
		}
		else{
			count++;
			cursor=cursor->link;
		}
	}
	
	
	cursor = ListHead;
	count = 1;
	while(cursor ->link != NULL){
	//	cout << "entro2" << endl;

		if(count == y){
//			cout << " entro if2" << endl;
			c = cursor ->A; 
			d = cursor ->B;
			count++;
		}
		else{
	//		cout<< "entreo else 2" <<endl;
			count++;
			cursor=cursor->link;
		}
	}
	 int uno, dos;
	 uno  = a+c;
	 dos = b+d;
	 cout << "Resultado de la suma de los dos pares ordenados: " << uno << ", " << dos << endl;
	
	if(repetido(ListHead,uno,dos)){
		cout << "numero repetido, no sera guardado." << endl;
	}
	
	
	else{
		
	ParPtr q = new node;
	max++;
	
	q->A= uno;
	q->B= dos;
	q->link = NULL;
	
	
	ParPtr temporary = new node;
	temporary = ListHead;
		
		while(temporary ->link != NULL){
			temporary = temporary->link;
		}
		temporary ->link = q;
	}
	
	

	
}

void restar(ParPtr& ListHead, int& max){
	//resta
	ParPtr cursor = new node;
	ParPtr cursor2 = new node;
	int count = 1, a, b, c, d, x=1, y=1;
	
	do{
	mostrar(ListHead);
	cout << "Eliga los numeros marcando el par ordenado que desea sumar. " << endl;
	cin >> x >> y;
	
	if(x> max || y > max || x < 1 || y < 1){
		cout << "Opcion invalida dentro de las alternativas provistas. Favor de elegir pares dentro de la lista." << endl;
	}
	
	} while (x> max || y > max || x < 1 || y < 1);
	
	cursor = ListHead;
	
	while(cursor->link !=NULL ){
//		cout << "entro1" << endl;
		if(count == x){
//			cout << "entro if" << endl;
			a = cursor ->A;
			b = cursor ->B;
			count++;
		}
		else{
	//		cout << "entro else" << endl;
			count++;
			cursor=cursor->link;
		}
	}
	
	cursor = ListHead;
	count = 1;
	while(cursor ->link != NULL){
	//	cout << "entro2" << endl;

		if(count == y){
	//		cout << " entro if2" << endl;
			c = cursor ->A; 
			d = cursor ->B;
			count++;
		}
		else{
//			cout<< "entreo else 2" <<endl;
			count++;
			cursor=cursor->link;
		}
	}
	 int uno, dos;
	 uno  = a-c;
	 dos = b-d;
	cout << "Resultado de la suma de los dos pares ordenados: " << uno << ", " << dos << endl;
	
	if(repetido(ListHead,uno,dos)){
		cout << "numero repetido, no sera guardado." << endl;
	}
	
	else{	
	ParPtr q = new node;
	max++;
	q->A= uno;
	q->B= dos;
	q->link = NULL;
	
	
	ParPtr temporary = new node;
	temporary = ListHead;
		
		while(temporary ->link != NULL){
			temporary = temporary->link;
		}
		temporary ->link = q;
	}
}

void mostrar(ParPtr& ListHead){
	//modify to overload the output
	ParPtr cursor = ListHead;
	int count = 1;
	while(cursor != NULL){
		cout << "Par ordenado " << count << ":" << endl; 
		cout << "(" << cursor->A << "/" << cursor->B << ")" << endl;
		cursor = cursor->link;
		count++;
	} cout << endl;
	
	
}





bool repetido(ParPtr& ListHead, int a, int b){
	
	ParPtr temporary = new node;
	temporary = ListHead;
	bool repeated=false;
	
	do{
		
		
		if((a == temporary->A && b== temporary->B)){
			cout << "entra while"<< endl;
			repeated = true;
			
			
			
			if(temporary->link==NULL){
					// empty a proposito
				}
				
				
			else{
					temporary = temporary->link;
				}
		
			
		}
		
		else{
	
				if(temporary->link==NULL){
					// empty a proposito
				}
				
				else{
					temporary = temporary->link;
				}
		}
	}while 	(temporary->link != NULL);
	
	
	
	
	if(repeated == true){
		return true;
	}
	
	else{
		return false;

	}
	delete temporary;
}


istream &operator >>(istream& entrada, node& x){
    entrada >> x.A >> x.B;
    return entrada;
}

ostream &operator <<(ostream& salida , const node& x){
    salida << "(" << x.A << "/" << x.B << ")" << endl;
    return salida;
}
}


