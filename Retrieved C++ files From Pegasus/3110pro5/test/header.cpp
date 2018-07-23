#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <cctype>
#include "header.h"

using namespace std;

NumerosRacional::NumerosRacional(){
	num = 0;
	den = 0;
}

NumerosRacional::NumerosRacional(int a, int b){
num = a;
den = b;
}

NumerosRacional::NumerosRacional(int a){
	num = a;
	den = 1;
}

void NumerosRacional::SetNum(int a){
	num = a;
}

void NumerosRacional::SetDen(int b){
  den = b;
}

int NumerosRacional::GetNum(){
  return num;
}

int NumerosRacional::GetDen(){
  return den;
}

NumerosRacional::~NumerosRacional(){
}

istream &operator >>(istream& entrada, NumerosRacional& rac){
    entrada >> rac.num >> rac.den;
    return entrada;
}

ostream &operator <<(ostream& salida , const NumerosRacional& rac){
    salida << rac.num << "/" << rac.den << endl;
    return salida;
}


NumerosRacional operator +(const NumerosRacional& a,const NumerosRacional& b){
   NumerosRacional temporal;
  
  temporal.num = (a.num * b.den) + (b.num * a.den);
  temporal.den = (a.den * b.den);
  
  return temporal;
}

NumerosRacional operator -(const NumerosRacional& a,const NumerosRacional& b){
  NumerosRacional temporal;
  
  temporal.num = (a.num * b.den) - (b.num * a.den);
  temporal.den = (a.den * b.den);
  
  return temporal;
  
}

NumerosRacional operator /(const NumerosRacional& a,const NumerosRacional& b){
  NumerosRacional temporal;
  
  temporal.num = (a.num * b.den);
  temporal.den = (b.num * a.den);
    
  return temporal;
  
}

NumerosRacional operator *(const NumerosRacional& a,const NumerosRacional& b){
  NumerosRacional temporal;
  
  temporal.num = (a.num * b.num);
  temporal.den = (a.den * b.den);
	return temporal;
}

 bool operator <(const NumerosRacional& a,const NumerosRacional& b){
  float decimal, decimal2;
  float aNum = a.num, bNum = b.num, aDen = a.den, bDen = b.den;
   decimal = aNum/aDen;
   decimal2 = bNum/bDen;
   if(decimal < decimal2)
    return true;
  else
    return false;
}

bool operator >(const NumerosRacional& a,const NumerosRacional& b){
 float decimal, decimal2;
 float aNum = a.num, bNum = b.num, aDen = a.den, bDen = b.den;
   decimal = aNum/aDen;
   decimal2 = bNum/bDen;
   if(decimal > decimal2)
    return true;
  else
    return false;
}

bool operator !=(const NumerosRacional& a,const NumerosRacional& b){
  float decimal, decimal2;
  float aNum = a.num, bNum = b.num, aDen = a.den, bDen = b.den;
   decimal = aNum/aDen;
   decimal2 = bNum/bDen;
   if(decimal != decimal2)
    return true;
  else
    return false;
}
		


bool operator ==(const NumerosRacional& a,const int &cero){
  if(a.den == 0){
    return true;
  }
  else{
    return false;
  }
}


int menu() {
	int opc;
	do {
		cout << "Selecione uno de los siguientes." << endl
			<< "1. Suma numeros Racionales." << endl
			<< "2. Resta numeros Racionales." << endl
			<< "3. dividir numeros Racionales." << endl
			<< "4. Multiplicar numeros racionales." << endl
			<< "5. Comparar numeros racionales." << endl
			<< "6. Anadir otro racional." << endl
			<< "7. Operacion (a^n)/(b^m)." << endl
			<< "8. Salir del Programa." << endl;
		cin >> opc;
		if (opc < 1 || opc >8)
			cout << "ERROR: favor repetir" << endl;
	} while (opc < 1 || opc >8);
	return opc;
}

void menu2(NumerosRacional p[], int& opc, int& opc2, int max) {
	do {


		cout << "Selecione dos de los siguientes en orden preferido." << endl;
		for (int i = 0; i<max; i++) {
			cout << "Racional " << i + 1 << endl;
			cout << p[i] << endl;

		}
		cin >> opc >> opc2;
		if (opc < 1 || opc >max || opc2 < 1 || opc2 >max)
			cout << "ERROR: favor repetir" << endl;
	} while (opc < 1 || opc >max || opc2 < 1 || opc2 >max);
}

void agregar (int& max, NumerosRacional p[],int& a, ofstream& out){
	
		if(a < max){
		
		do{
			cout << "Introduca un numerador  y denominador." << endl;
			cout << "Si numerador es entero, favor marcar denominador como (1)." << endl;	
    		cin >> p[a++];
    		if(p[a -1].GetDen() == 0){
    			cout << "Error: denominador es cero, favor repetir" << endl;
    			a--;}
    	}while (p[a-1].GetDen() == 0);
    	out << "Racional nuevo: " << p[a-1];
    }
    else
    	cout << "Error: entradas de valor llego a maxima capacidad." << endl<<endl; 
	
	
}




void close(ifstream &in) {
	in.close();
}

void close(ofstream &out) {
	out.close();
}
