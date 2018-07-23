#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <cctype>
#include "header.h"

//*******************************
//AÑADE NAMESPACE
//*********************************

using namespace std;


namespace rational{


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
		

/*
bool operator ==(const NumerosRacional& a,const int &cero){
  if(a.den == 0){
    return true;
  }
  else{
    return false;
  }
} */

bool operator ==(const NumerosRacional& a, const NumerosRacional& b){
	if ((a.num == b.num) && (a.den == b.den) )
		return true;
	else
		return false;
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
			<< "8. Modificar algun Racional." << endl
			<< "9. Eliminar algun Racional." << endl
			<< "10. Salir del Programa." << endl;
		cin >> opc;
		if (opc < 1 || opc >10)
			cout << "ERROR: favor repetir" << endl;
	} while (opc < 1 || opc >10);
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


void MenuModify(NumerosRacional p[], int& opc, int a){
	
	do {


		cout << "Selecione una de los siguientes." << endl;
		for (int i = 0; i<a; i++) {
			cout << "Racional " << i + 1 << endl;
			cout << p[i] << endl;

		}
		cin >> opc;
		if (opc < 1 || opc >a)
			cout << "ERROR: favor repetir" << endl;
	} while (opc < 1 || opc >a);
	
}


bool repeated (NumerosRacional p[], int& a){
	bool v = false;
	//returns false if not repeated
	//returns true if repeated
	for (int z =0; (z < a-1 && v == false); z++){
		if(p[z] == p[a-1]){
			cout << "Cierto" << endl;
			v = true;
		}
		
		else{
			cout << "Falso" << endl;
		}
		
	}
	return v;
	
}


void agregar (int& max, NumerosRacional p[],int& a, ofstream& out){
		
		do{
			cout << "Introduca un numerador  y denominador." << endl;
			cout << "Si numerador es entero, favor marcar denominador como (1)." << endl;	
    		cin >> p[a++];
    		if(p[a -1].GetDen() == 0){
    			cout << "Error: denominador es cero, favor repetir" << endl;
    			a--;}
    			
    		else{
    			
    			if(repeated(p, a)){
    			cout << "Numero repetido, intente de nuevo" << endl;
    			a--;
				}
		
				else{
					out << "Racional nuevo: " << p[a-1];	
		
				}
		
		
			}
    	}while (p[a -1].GetDen() == 0);
    	//needs to fix repeat loop
    	
    	
}





void eliminar(NumerosRacional p[], int opc, int& a){
	//eliminate chosen slot of rational number
	//rodar los demas numeros para cubrir espacio vacio
	//a--	
	int num, den, t = opc-1;
	p[t].SetNum(0);
	p[t].SetDen(0);
	
	for(NumerosRacional temp;t < a; t++){
		temp = p[t];
		p[t] = p[t+1];
		p[t+1] = temp;
	}
	a--;
	cout << "Racional eliminado del arreglo." << endl;
}


void modificar(NumerosRacional p[], int opc, int& a){
	int num, den;
	bool validar;
	
	do{
		validar = false;
		cout << "introduzca el numerador y denominador para cambiar" << endl;
		cin >> num >> den;
		if(den == 0)
			cout << "Error, favor repetir." << endl;
	
	if(num == 0){
		den = 1;
		cout << "Racional modificado a 0/1" << endl;
	}
	
	
	for(int i =0; i < a-1; i++){
		//cout << "fro loop" << endl;
		if (p[i].GetNum() == num && p[i].GetDen() == den){
			cout << "Error, valor ya existe, favor repetir." << endl;
			validar = true;
		}
			
	}	
	} while(den == 0 || validar == true);	
	
	
		
	
	

	p[opc-1].SetNum(num);
	p[opc-1].SetDen(den);
	
	cout << "Numero modificado: " << p[opc-1] << endl;
	

	//please add some verification plox
	
	//choose slot of rational number
	//allow user to change number. (num and den)
	//verify if changes are not allowed. If not allowed, either return numbers to original or repeat
	//save modified numbers into the slot
}



void close(ifstream &in) {
	in.close();
}

void close(ofstream &out) {
	out.close();
}

}
