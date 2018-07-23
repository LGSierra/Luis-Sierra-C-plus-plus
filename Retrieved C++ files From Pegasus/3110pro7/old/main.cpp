#include <iostream>
#include <cstdlib>
#include "header.cpp"
#include <fstream>

using namespace std;
using namespace pares;

/*
 maybe use counting the nodes again...

*/

int main()
{
	ParOrdenado<int> ListHead;
	ParOrdenado<double> reales;
	ParOrdenado <char> caracteres;
	int choice, choice2;
	int max=0;
	ofstream salida;
	salida.open("ParesOrdenados.txt");
	
	do{
		
		menu(choice, choice2);
		
		switch(choice)
		{
			case 1:
				if(choice2 == 1){
					ListHead.agregar_principio(max);	
				}
				else if(choice2 == 2){
					reales.agregar_principio(max);
				}
				else if(choice2 == 3){
					caracteres.agregar_principio(max);
				}
				break;
				
			case 2:
				if(choice2 == 1){
				ListHead.agregar_final(max);
				}
				else if(choice2 == 2){
					reales.agregar_final(max);
				}
				else if(choice2 == 3){
					caracteres.agregar_final(max);
				}
				break;
				
			case 3:
				if(choice2 == 1){
				ListHead.agregar(max);
				}
				else if(choice2 == 2){
					reales.agregar(max);
				}
				else if(choice2 == 3){
					caracteres.agregar(max);
				}
				break;
			case 4:
				if(choice2 == 1){
				ListHead.eliminar(max);
				}
				else if(choice2 == 2){
					reales.eliminar(max);
				}
				else if(choice2 == 3){
					caracteres.eliminar(max);
				}
				break;
			case 5:
				if(choice2 == 1){
				ListHead.ordenar();
				}
				else if(choice2 == 2){
					reales.ordenar();
				}
				else if(choice2 == 3){
					caracteres.ordenar();
				}
				break;
			case 6:
				if(choice2 == 1){
					ListHead.sumar(max);
				}
				
				else if(choice2 ==2){
					reales.sumar(max);
				}
				
				else if(choice2 == 3){
					cout << "Lista es de caracteres, no se pueden sumar." << endl;
				}
				
				break;
				
			case 7:
				if(choice2 == 1){
					ListHead.restar(max);
				}
				
				else if(choice2 ==2){
					reales.restar(max);
				}
				else if(choice2 == 3){
					cout << "Lista es de caracteres, no se pueden restar." << endl;
				}
				break;
				
			case 8:
				if(choice2 == 1){
					ListHead.mostrar2(salida);
				}
				
				else if(choice2 ==2){
					reales.mostrar2(salida);
				}
				else if(choice2 == 3){
					caracteres.mostrar2(salida);
				}
				break;
			case 9:
				cout << "Fin del programa" << endl << endl;
						
		}
		
		
	}while(choice!=9);
	
	
	salida.close();
	return 0;
}
