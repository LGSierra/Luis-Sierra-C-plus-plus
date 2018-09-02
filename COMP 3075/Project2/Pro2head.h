#ifndef H_Pro2head
#define H_Pro2head

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;


namespace CircleNamespace{
	
struct node{
	int x;
	int y;
	double radio;
	node* link;
};
typedef node* Npointer;
class punto{
	
	public:
		punto();
		punto(int x, int y);
		~punto();
		void capturarPunto();
		void fijarX(int& Xcoord);
		void fijarY(int& Ycoord);
		int obtenerX();
		int obtenerY();
		void imprimir();
		
		
	protected:
		int x;
		int y;
	//protected here
	
	
};

class circulo: public punto{
	
	public:
		circulo();
		circulo(int x, int y, double r);
		~circulo();
		void capturarCirculo(int& max);
		void fijarRadio(double& rd); //contains double parameter
		double obtenerRadio();
		double obtenerArea();
		double obtenerCircunsferencia();
		double obtenerDiametro();
		void imprimirCirculo(int max);
		
		void add(int& NumOfNodes);//undefined
		void printList(int max);
		void selectExtract(int max, int selection, int& selectX, int& selectY, double& selectR);
		void printList2(int max);
		
		
	private:
		double radio;
		Npointer Head;
	
};

}
#endif
