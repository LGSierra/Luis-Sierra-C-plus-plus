#include <iostream>
#include <fstream>
#include <string>
#include "Pro3func.cpp"
#include <iomanip>
using namespace std;
using namespace Ventas;

//**************************Completed version


int main()
{
	int choice;
	ifstream in;
	ofstream out;
	//file open function
	elemento ***array;
	int vendedores, productos, dias;
	string *nombre;
	string *producto;

	openFile(in);
	openFile(out);
	bool verify = readFile(in, vendedores, productos, dias, nombre, producto);
	if(verify == false){
		return 0;
	}

	//declaring and allocating space.****************
	array = new elemento**[vendedores];
	for(int i = 0; i < vendedores; i++)
	{
		array[i] = new elemento*[productos];
		for(int j = 0; j < productos; j++)
		{
      		array[i][j] = new elemento[dias];
    	}
	}
	//************************************************

	verify = fillArray(in, vendedores, productos, dias, array, nombre, producto);
	if(verify == false){
		return 0;
	}
	cout << endl;

	//switch statement for the menu
	do{
		choice = menu();
		switch(choice){
			case 1:
				//total de unidades vendidas al mes
				ventasmes(vendedores, productos, dias, array, producto, out);
				break;
			case 2:
				productodia(vendedores, productos, dias, array, producto, out);
				break;
			case 3:
				ventaproductodia(vendedores, productos, dias, array, producto, nombre, out);
				//choose a day, a product, and output all vendor names with stats of that product and day
				break;
			case 0:
				cout << "Fin de programa." << endl;
				break;
			default:
				cout << "Entrada invalida, favor repetir." << endl;
		}

	} while(choice != 0);

	//file close function
	closeFile(in);
	closeFile(out);

	delete [] array;
	return 0;
}
