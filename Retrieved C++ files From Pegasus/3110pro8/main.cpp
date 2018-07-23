//Annamary W. Cartagena
//Luis Sierra
//Proyecto8
//Profa. Flor Narciso
#include <iostream>
#include <cstdlib>
#include "header.cpp"
#include <fstream>

using namespace std;
using namespace pilas;
/*
Agregar 						*COMPLETED*
mostrar todos elementos			*COMPLETED*
eliminar n elementos			*COMPLETED* 
alcular ocurrencias				*COMPLETED*
mostrar primer elemento			*COMPLETED, ADDED DELETE DE PRIMER NODO*

--------------------------------------------------------------------------

**BUGS**

Eliminating empty crash bug     *FIXED*
-commented T resultado = ListHead->A;
-commented return resultado;
-changed function return from type T to type void.
-added else{} if the function wasn't empty. Function used to run with an empty list.
-added max--, for each time a node was eliminated. Function ran while using an incorrect max value if it had run before.

Change element, no exit bug     *FIXED*
-added a copy of the if statement that evaluated if choice was 4, to the inside of the do while loop.

*/


int main()
{
	Pila<int> enteros;
	Pila<double> reales;
	Pila <char> caracteres;
	int choice, choice2, opc;
	ofstream salida;
	salida.open("Pilas.txt");
	int max=0;
	bool bypass = false;
	
	menu2(choice2);
	
	if (choice2 == 4){
		cout << "Fin de programa." << endl;
		return 0;
	}
	else{
		do{
			
			if (choice2 == 4){
				cout << "Fin de programa." << endl;
				return 0;
			}
			
			
			menu(choice);
			
			switch(choice)
			{
				case 1:
					if(choice2 == 1){
						 enteros.agregar(max);	
					}
					else if(choice2 == 2){
						reales.agregar(max);
					}
					else if(choice2 == 3){
						caracteres.agregar(max);
					}
					break;
					
				case 2:
					if(choice2 == 1){
						 enteros.primero(max, bypass);	
					}
					else if(choice2 == 2){
						reales.primero(max, bypass);
					}
					else if(choice2 == 3){
						caracteres.primero(max, bypass);
					}
					break;
				case 3:
					
					if(choice2 == 1){
						enteros.eliminar(max, opc, bypass);
					}
					else if(choice2 == 2){
						reales.eliminar(max, opc, bypass);
					}
					else if(choice2 == 3){
						caracteres.eliminar(max, opc, bypass);
					}
					break;
				case 4:
					if(choice2 == 1){
						enteros.repetido();
					}
					else if(choice2 == 2){
						reales.repetido();
					}
					else if(choice2 == 3){
						caracteres.repetido();
					}
					break;
					
				case 5:
					if(choice2 == 1){
						 enteros.mostrar(salida, max);	
					}
					else if(choice2 == 2){
						reales.mostrar(salida, max);
					}
					else if(choice2 == 3){
						caracteres.mostrar(salida, max);
					}
					break;
				case 6:
					menu2(choice2);
					break;
				case 7:
					cout << "Fin del programa" << endl << endl;
					break;
							
			}
		}while(choice!=7);
	}
	salida.close();
	return 0;
}
