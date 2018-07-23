#ifndef HEADER_H
#define HEADER_H


#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <cctype>
using namespace std;

namespace rational{


class NumerosRacional{
	public:
		
		NumerosRacional();
  		NumerosRacional(int a, int b);
  		NumerosRacional(int a);
		~NumerosRacional();
		//destructor
		void SetNum(int a);
		//set numerador
  		int GetNum();
  		//return numerador
  		void SetDen(int b);
  		//set denominador
  		int GetDen();
  		//return denominador
  		
  
		friend NumerosRacional operator +(const NumerosRacional& a,const NumerosRacional& b);
		//operador sobrecarga reacionales.
    	friend NumerosRacional operator -(const NumerosRacional& a,const NumerosRacional& b);
	    friend NumerosRacional operator /(const NumerosRacional& a,const NumerosRacional& b);
    	friend NumerosRacional operator *(const NumerosRacional& a,const NumerosRacional& b);
  		friend bool operator ==(const NumerosRacional& a, const int& cero);
  		friend bool operator ==(const NumerosRacional& a, const NumerosRacional& b);
    	friend ostream& operator <<(ostream &salida , const NumerosRacional &a);
    	friend istream& operator >>(istream&salida, NumerosRacional &a);
  		friend bool operator <(const NumerosRacional& a,const NumerosRacional& b);
  		friend bool operator >(const NumerosRacional& a,const NumerosRacional& b);
  		friend bool operator !=(const NumerosRacional& a,const NumerosRacional& b);
		
	//Private numerador y denominador
	private:
		int num;
		int den;
	};
	
}
	
	#endif //HEADER_H
