#ifndef H_Pro3head
#define H_Pro3head

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

namespace Ventas{

	class elemento{

		public:
			elemento();
			~elemento();
			void setProducto(string productos);
			void setVendedor(string nombre);
			void setVentas(int venta);
			string getProducto();
			string getVendedor();
			int getVentas();
			//the set and get stuff

			void ventasmes(int vendedores,int productos,int dias, elemento ***array, string *product);
			void productodia(int vendedores,int productos,int dias, elemento ***array, string *producto);
			void ventaproductodia(int vendedores,int productos,int dias, elemento ***array, string *producto, string *nombre);

		private:
			// the stuff that gives the info. Name of product, or vendor name
			string producto;
			string vendedor;
			int ventas;

	};

//	int menu();
//	void openFile(ifstream& in);
//	void openFile(ofstream& out);
//	void closeFile(ifstream& in);
//	void closeFile(ofstream& out);
//	void readFile(ifstream& in,int& vendedores,int& productos,int& dias, string *&nombre, string *&producto);
//	void readFile2(ifstream& in,int& vendedores,int& productos,int& dias, elemento ***&array);




}

#endif
