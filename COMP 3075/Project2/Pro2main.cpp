#include <iostream>
#include <cmath>
#include <cstdlib>
#include "Pro2func.cpp"
using namespace std;
using namespace CircleNamespace;


/*
	MISSING:
	-Linked list structure
	-Function definitions
	-Object declaration

	PROGRAM NOT COMPLETE

*/

int main()
{
	//declare circle object
	//constructor por defecto will activate
	int max = 0;
	circulo object;
	int choice;
	do{

		choice = menu();

		switch(choice){
			case 1:
				object.capturarCirculo(max);
				break;
			case 2:
				if(max == 0){
					cout << "Lista esta vacia!" << endl;
				}

				else{

					int selection; //selected node
					//print linked list with coordinates and radius
					object.printList(max);
					if(max==1){
						selection = 1;
					}

					else{
						cout << "Seleccione un circulo de la lista a ser calculado:" << endl;
						cin >> selection;//something to validate later
					}

					if(selection <=0 || selection > max){
						cout << "seleccion invalida." << endl;
					}
					else{

						//choose circle function here
						int selectX=0, selectY=0;
						double selectR=0.0;

						object.selectExtract(max, selection, selectX, selectY, selectR);

						//if there is only one node, select by default
						//create a temp object and fill it up with constructor

						circulo temp(selectX, selectY, selectR);

						cout.setf(ios::fixed);
						cout.setf(ios::showpoint);
						cout.precision(3);

						cout << "El area del circulo es: " << temp.obtenerArea() << " unidades cuadradas." << endl;
						//object.obtenerArea();
					}

				}
				break;


			case 3:
				if(max == 0){
					cout << "Lista esta vacia!" << endl;
				}

				else{

					int selection; //selected node
					//print linked list with coordinates and radius
					object.printList(max);
					if(max==1){
						selection = 1;
					}

					else{
						cout << "Seleccione un circulo de la lista a ser calculado:" << endl;
						cin >> selection;//something to validate later
					}

					if(selection <=0 || selection > max){
						cout << "seleccion invalida." << endl << endl;
					}
					else{
						//choose circle function here
						int selectX=0, selectY=0;
						double selectR=0.0;

						object.selectExtract(max, selection, selectX, selectY, selectR);

						//if there is only one node, select by default
						//create a temp object and fill it up with constructor

						circulo temp(selectX, selectY, selectR);

						cout.setf(ios::fixed);
						cout.setf(ios::showpoint);
						cout.precision(3);


						cout << "La circumsferencia del circulo es: " << temp.obtenerCircunsferencia() << " unidades." << endl;
						//object.obtenerCircunsferencia();
					}
				}
				break;
			case 4:
				if(max == 0){
					cout << "Lista esta vacia!" << endl;
				}

				else{

				int selection; //selected node
				//print linked list with coordinates and radius
				object.printList(max);
				if(max==1){
					selection = 1;
				}

				else{
					cout << "Seleccione un circulo de la lista a ser calculado:" << endl;
					cin >> selection;//something to validate later
				}

				if(selection <=0 || selection > max){
						cout << "seleccion invalida." << endl << endl;
				}
				else{

					//choose circle function here
					int selectX=0, selectY=0;
					double selectR=0.0;

					object.selectExtract(max, selection, selectX, selectY, selectR);

					//if there is only one node, select by default
					//create a temp object and fill it up with constructor

					circulo temp(selectX, selectY, selectR);

					cout.setf(ios::fixed);
					cout.setf(ios::showpoint);
					cout.precision(3);

					cout << "El diametro del circulo es " << temp.obtenerDiametro() << " unidades." << endl;
				}
				}
				break;


			case 5:
				if(max == 0){
					cout << "Lista esta vacia!" << endl;
				}

				else{
					object.printList2(max);
				}

				//some function to loop void circulo::imprimirCirculo()
				//maybe use a for loop? to print out the whole linked list

				break;
			case 6:
				if(max == 0){
					cout << "Lista esta vacia!" << endl;
				}

				else{
					object.imprimirCirculo(max);
				}
				// same as case 5 but using void punto::imprimir()  m a y b e
				break;
			default:
				if(choice==0){
					//cout << "opcion invalida, intente de nuevo" << endl;
				}
				else{
					cout << "opcion invalida, intente de nuevo" << endl;
				}
		}


	} while(choice !=0);
	cout << "Fin del programa" << endl;
	return 0;
}
