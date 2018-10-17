#include <iostream>
#include <fstream>
#include <string>
#include "Pro3head.h"
using namespace std;
using namespace Ventas;

// member functions go here

elemento::elemento(){
	ventas = 0;
}

elemento::~elemento(){
}

void elemento::setVentas(int venta){
	ventas = venta;
}

void elemento::setVendedor(string nombre){
	vendedor = nombre;
}

void elemento::setProducto(string productos){
	producto = productos;
}

int elemento::getVentas(){
	return ventas;
}

string elemento::getProducto(){
	return producto;
}
string elemento::getVendedor(){
	return vendedor;
}
//ordinary functions go here

int menu(){
		int choice;
		cout << "***************************************************************************" << endl;
		cout << "* [1] Total de unidades vendidas de cada producto en el mes.              *" << endl;
		cout << "* [2] Producto con el mayor numero de unidades vendidas durante un dia.   *" << endl;
		cout << "* [3] Vendedores con el numero de ventas de un producto en dia especifico.*" << endl;
		cout << "*                                -----                                    *" << endl;
		cout << "* [0] Salir del programa.                                                 *" << endl;
		cout << "***************************************************************************" << endl;
		cin >> choice;
		return choice;
	}


	void openFile(ifstream& in){
		in.open("entrada.txt");
	}
	void openFile(ofstream& out){
		out.open("salida.txt");
	}

	bool readFile(ifstream& in,int& vendedores,int& productos,int& dias, string *&nombre, string *&producto){
		string unnombre;
		
		in >> vendedores;
		in >> productos;
		in >> dias;

		
		if(dias > 31){
			cout << "ERROR EN ARCHIVO: Hay mas de 31 dias en el archivo, favor arreglar adentro del archivo." <<endl;
			return false;
		}
		else if(dias <= 0){
			cout << "ERROR EN ARCHIVO: Hay menos de 1 dia, favor arreglar adentro del archivo." <<endl;
			return false;
		}
		else if(vendedores <= 0){
			cout << "ERROR EN ARCHIVO: Hay menos de 1 vendedor, favor arreglar adentro del archivo." <<endl;
			return false;
		}
		else if(productos <= 0){
			cout << "ERROR EN ARCHIVO: Hay mas de 31 dias en el archivo, favor arreglar adentro del archivo." <<endl;
			return false;
		}
		else{
			producto = new string [productos];
			in.ignore();
			for(int i = 0; i<productos; i++){
			//	in >> producto[i];
				getline(in, producto[i], '.');
				in.ignore();
				producto[i].at(0) = toupper(producto[i].at(0));
				
		//		cout << producto[i]<<endl;
			}
			
			nombre = new string [vendedores];
			for(int i = 0; i<vendedores; i++){
				getline(in, nombre[i], '.');
				nombre[i].at(1) = toupper(nombre[i].at(1));//at changed
				for(int j = 0; j < nombre[i].length(); j++){
					if(nombre[i].at(j) == ' '){
						nombre[i].at(j+1) = toupper(nombre[i].at(j+1));
					}
				}
		//		cout << nombre[i];
			}
		return true;
		}
	}

	bool fillArray(ifstream& in,int& vendedores,int& productos,int& dias, elemento ***&array, string *&nombre, string *&producto){
		int i = 0, j =0, k = 0;
		int ventas = 0;
		for(i = 0; i < vendedores; i++)
		{
			for(j = 0; j < productos; j++)
			{
	      		for(k= 0; k< dias; k++)
				{
					in >> ventas;
					if(ventas < 0){
						cout << "ERROR EN ARCHIVO: Existe una variable negativa en ventas, favor arreglar adentro de archivo." << endl;
						return false;
					}
					else{
						array[i][j][k].setVentas(ventas);
			      		array[i][j][k].setVendedor(nombre[i]);
			      		array[i][j][k].setProducto(producto[j]);
			      		//cout << array[i][j][k].getProducto() << " " << array[i][j][k].getVendedor() << " " << array[i][j][k].getVentas() << " " << endl;
					}
		    	}
	    	}
		}
		return true;
	}
	
	void ventasmes(int vendedores,int productos,int dias, elemento ***array, string *producto, ofstream& out){
		int *ventames;
		int i = 0, j =0, k = 0;
		ventames = new int[productos];

		for(j = 0; j < productos; j++){
			ventames[j] = 0;
		}

		for(i = 0; i < vendedores; i++)
		{
			for(j = 0; j < productos; j++)
			{
		   		for(k= 0; k< dias; k++)
				{
		      		ventames[j] += array[i][j][k].getVentas();
		    	}
	    	}
		}
		
		out<< "Opcion 1 elegido." << endl;
		for(j = 0; j < productos; j++){
			cout << "Para el producto \"" << producto[j] << "\" se vendio esta cantidad en un total de "<< dias << " dias: " << ventames[j] << endl;
			out << "Para el producto \"" << producto[j] << "\" se vendio esta cantidad en un total de "<< dias << " dias: " << ventames[j] << endl;
		}
		out<<endl;
	}
	
	void ventaproductodia(int vendedores,int productos,int dias, elemento ***array, string *producto, string *nombre, ofstream& out){
		int *productodia;
		productodia = new int[productos];
		
		int dia, productoexacto;
		
		
		cout<< "Favor elegir un dia." <<endl;
		cin>> dia;
		while(dia<1 || dia>dias){
			cout << "Entrada erronea, intente de nuevo:" << endl;
			cin >> dia;
		}
		
		
		cout<< "Favor elegir un producto." <<endl;
		for(int i=0; i<productos; i++){
			cout << "[" << i+1 << "] " << producto[i] <<endl;
		}
		cin >> productoexacto;
		
		while(productoexacto<1 || productoexacto>productos){
			cout << "Entrada erronea, intente de nuevo:" << endl;
			cin >> productoexacto;
		}
		
		out << "Opcion 3 elegido."<<endl;
		for(int i= 0; i< vendedores; i++)
		{
			cout << "El vendedor/a \"" << nombre[i] << "\" pudo vender: " <<endl;
			out <<  "El vendedor/a \"" << nombre[i] << "\" pudo vender: " <<endl;
			
	      	cout << "El producto \"" << producto[productoexacto-1] <<"\" " << array[i][productoexacto-1][dia-1].getVentas() << " veces en el dia " << dia << "."<<endl;
	      	out << "El producto \"" << producto[productoexacto-1] <<"\" " << array[i][productoexacto-1][dia-1].getVentas() << " veces en el dia " << dia << "."<<endl;
		   		
			
			cout << endl;
			out << endl;
	 	}
	 	out<<endl;
		
	}
	
	void productodia(int vendedores,int productos,int dias, elemento ***array, string *producto, ofstream& out){
		int diaentrada;
		int productovendido = 0;
		string nombreproducto;
		int *productodia;
		productodia = new int[productos];
		
		do{
			cout << "Entre el dia que desea ver." << endl;
			cin >> diaentrada;
			if(diaentrada <=0 || diaentrada > dias){
				cout << "Error. Entrada invaliva, favor repetir." << endl;
			}
		}while(diaentrada <=0 || diaentrada > dias);
		
		
		for(int j = 0; j < productos; j++){
			productodia[j] = 0;
		}
		
		for(int i = 0; i < vendedores; i++)
		{
			for(int j = 0; j < productos; j++)
			{
		     		productodia[j] += array[i][j][diaentrada-1].getVentas();
		   	}
		}
		
		out << "Opcion 2 elegido" <<endl;
		for(int j = 0; j < productos; j++)
		{
		 	cout << "Para dia " << diaentrada << " de vendio el producto \" " <<   producto[j] << "\" " << productodia[j] << " veces " << endl;
		 	out << "Para dia " << diaentrada << " de vendio el producto \" " <<   producto[j] << "\" " << productodia[j] << " veces " << endl;

			if(productovendido < productodia[j]){
		    	productovendido = productodia[j];
		    	nombreproducto = producto[j];
			}
		}
		    	
		cout <<endl<< "Producto que mas se vendio es \"" << nombreproducto << "\" con " << productovendido << " ventas." << endl;    
		out <<endl<< "Producto que mas se vendio es \"" << nombreproducto << "\" con " << productovendido << " ventas." << endl;  
		out <<endl;  	
	
	}


	void closeFile(ifstream& in){
		in.close();
	}
	void closeFile(ofstream& out){
		out.close();
	}
