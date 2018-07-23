#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
using namespace std;


class NumerosRacional{
	public:
		
		NumerosRacional();
  		NumerosRacional(int a, int b);
  		NumerosRacional(int a);
		~NumerosRacional();
		void SetNum(int a);
  		int GetNum();
  		void SetDen(int b);
  		int GetDen();
  		
  
		
		friend NumerosRacional operator +(const NumerosRacional& a,const NumerosRacional& b);
    	friend NumerosRacional operator -(const NumerosRacional& a,const NumerosRacional& b);
	    friend NumerosRacional operator /(const NumerosRacional& a,const NumerosRacional& b);
    	friend NumerosRacional operator *(const NumerosRacional& a,const NumerosRacional& b);
  		friend bool operator ==(const NumerosRacional& a, const int& cero);
    	friend ostream& operator <<(ostream &salida , const NumerosRacional &a);
    	friend istream& operator >>(istream&salida, NumerosRacional &a);
  		friend bool operator <(const NumerosRacional& a,const NumerosRacional& b);
  		friend bool operator >(const NumerosRacional& a,const NumerosRacional& b);
  		friend bool operator !=(const NumerosRacional& a,const NumerosRacional& b);
		
	private:
		int num;
		int den;
	};
	

	
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





int menu ();
int menu2(NumerosRacional p[], int &opc, int &opc2, int max);
void close(ifstream &in);
void close(ofstream &out);

int main (){
	int max, j;
	NumerosRacional resultado, temp;
	int ans, ans2;
	int opc;
	ifstream in;
	ofstream out;
	in.open("racionales.txt");
	out.open("salida.txt");
	
	
	cout << "Introduzca cantidad de racionales que le gustaria usar." << endl;
  	cin >> max;
	
	
  	NumerosRacional *p;
  	p = new NumerosRacional [max];
	
	int i;
  	for(i=0;((!in.eof())&& (i<max)); i++){
	int num, den;
	bool missingDen=false;
	
  in >> num;
  
  
  // evaluacion de numero racional si tiene denominador(si no tiene, se considera un entero/1)
  if(in.peek()== '\n'){
  	missingDen = true;
  	cout << "End of line detected" << endl;
  	cout << "Racional " << i+1 << " es un entero sobre uno." << endl<< endl; 
  }
  else{
  	in >> den;
  }
  
  
  
  
  if(num==0){
  	if(missingDen==true){
  		NumerosRacional objeto(num);
	  	p[i] =objeto;
	  }
	  
	else if(den == 0){
		cout << "Sobreescrito aqui" << endl;
 		 i--;
	}
	
	else{
		den = 1;
  		NumerosRacional objeto(num,den);
 		 p[i] = objeto;	
	}
  
  }
  
  else if(missingDen == true){
  NumerosRacional objeto(num);
  p[i] =objeto;
  }
  
  else if(den==0){
  //debug valor sobreescrito
  cout << "Sobreescrito" << endl;
  i--;
  }
  
  
  else{
  	NumerosRacional objeto(num, den);
    p[i] = objeto;
  }
  
}
int a = i;
  	
  	for(int i=0; i<a; i++){
  cout << "Racional " << i+1 << endl;
  cout << p[i] << endl;
  }

		do{
		opc = menu();
		
		switch(opc){
		case 1:
		
    	  out << "Opcion 1 elegida" << endl;
    	  menu2(p, ans, ans2, a);
     
     
		 resultado = p[ans-1] + p[ans2-1];   
        
    		cout << "Sumar de fracciones: " << resultado.GetNum() << "/" << resultado.GetDen() << endl << endl;  
			out << "Sumar de fracciones: " << resultado.GetNum() << "/" << resultado.GetDen() << endl << endl;
			break;
		case 2:
			out << "Opcion 2 elegida" << endl;
     	 menu2(p, ans, ans2, a);
      
      resultado = p[ans-1] - p[ans2-1];   
        
    	cout << "Resta de fracciones: " << resultado.GetNum() << "/" << resultado.GetDen() << endl << endl;  
			out << "Resta de fracciones: " << resultado.GetNum() << "/" << resultado.GetDen() << endl << endl;
			break;
		case 3:
			out << "Opcion 3 elegida" << endl;
       		menu2(p, ans, ans2, a);
        
	        if(p[ans2-1].GetNum() == 0){
	        	cout << "Numerador de segundo numero racional es cero. No se puede completar division" << endl;
	        	out << "Numerador de segundo numero racional es cero. No se puede completar division" << endl;	
			}
			else{
	        	resultado = p[ans-1] / p[ans2-1];   
	      		cout << "Division de fracciones: " << resultado.GetNum() << "/" << resultado.GetDen() << endl << endl;  
				out << "Division de fracciones: " << resultado.GetNum() << "/" << resultado.GetDen() << endl << endl;
			}
      	break;
		case 4:
			out << "Opcion 4 elegida" << endl;
      	 	menu2(p, ans, ans2, a);
        	resultado = p[ans-1] * p[ans2-1];   
        
      		cout << "Multiplicacion de fracciones: " << resultado.GetNum() << "/" << resultado.GetDen() << endl << endl;  
			out << "Multiplicacion de fracciones: " << resultado.GetNum() << "/" << resultado.GetDen() << endl << endl;
			break;
		case 5:
			out << "Opcion 5 elegida"<< endl << endl;
			menu2(p, ans, ans2, a);
        if(p[ans-1] != p[ans2-1]){
          out << "Fraccion 1 es diferente a fraccion 2." << endl<<endl;
          cout << "Fraccion 1 es diferente a fraccion 2." << endl<<endl;}
        else{
          out <<"Fraccion 1 es igual a fraccion 2." << endl <<endl;
          cout <<"Fraccion 1 es igual a fraccion 2." << endl <<endl;}
  
        if(p[ans-1] < p[ans2-1]){
          cout << "Fraccion 1 es menor que fraccion 2." << endl << endl;
          out << "Fraccion 1 es menor que fraccion 2." << endl << endl;
        }
        
        if(p[ans-1] > p[ans2-1]){
          cout << "Fraccion 1 es mayor que fraccion 2." << endl << endl;
          out << "Fraccion 1 es mayor que fraccion 2." << endl << endl;
        }
        
        
			break;
    case 6:
    	out << "Opcion 6 elegida" << endl;
    	if(a < max){
		
		do{
			cout << "Introduca un numerador  y denominador separados por un espacio." << endl;
			cout << "Si numerador es entero, favor marcar denominador como (1)." << endl;	
    		cin >> p[a++];
    		if(p[a -1].GetDen() == 0){
    			cout << "Error: denominador es cero, favor repetir" << endl;
    			a--;}
    		if(p[a-1].GetNum() == 0)
    			p[a-1].SetDen(1); 
    	}while (p[a -1].GetDen() == 0);
    	out << "Racional nuevo: " << p[a-1];
    }
    else
    	cout << "Error: entradas de valor llego a maxima capacidad." << endl<<endl; 
    	break;
    case 7:
    	int m, n;
    	int num, den;
    	out << "Opcion 7 elegida" << endl;
    	if(a < max){
    	do{
			cout << "Introduca numerador, denominador separados por un espacio." << endl;
			cout << "Si numerador es entero, favor marcar denominador como (1)." << endl;	
    		cin >> p[a++];
    		if(p[a -1].GetDen() == 0)
    			cout << "Error: denominador es cero, favor repetir" << endl;
    		if(p[a-1].GetNum() == 0 && (p[a-1].GetDen() != 0))
    			p[a-1].SetDen(1);
    			cout << "Denominador cambiado a uno." << endl;
    	}while (p[a -1].GetDen() == 0);
    	NumerosRacional extra, extra2;
    
    		cout << "Introduzca exponentes."<< endl;
    		cin >> m >> n;
    		j=a-1;
    		
    		num = p[j].GetNum();
    		den = p[j].GetDen();
    		if(m <0){
    			extra.SetNum(1);
    			extra.SetDen(pow(num, -m));
			}
			else{
				extra.SetNum(pow(num, m));
    			extra.SetDen(1);
			}
			
			if (n<0){
				extra2.SetNum(1);
    			extra2.SetDen(pow(den, -n));	
			}
			
			else{
				extra2.SetNum(pow(den, n));
    			extra2.SetDen(1);
			}
    		cout << extra/extra2 << endl;
    		out<< "Valores introducidos: " << num <<", "<< den <<", "<< m <<", "<< n << endl;
    		out << "Racional nuevo: " << p[a-1];
    		out << "Resultado: " << extra/extra2 << endl;
    			
    	}
    else
    	cout << "Error: entradas de valor llego a maxima capacidad." << endl << endl; 
    	break;
	case 8:
		cout << "Fin del programa." << endl;
      	out << "Fin del programa." << endl;
		break;
	
	default:;
		}
	}while (opc != 8);


delete [] p;
in.close();
out.close();
	return 0;
}


int menu(){
	int opc;
	do{
		cout << "Selecione uno de los siguientes." << endl
			 << "1. Suma numeros Racionales." << endl
			 <<"2. Resta numeros Racionales." << endl
			 << "3. dividir numeros Racionales." << endl
			 << "4. Multiplicar numeros racionales." << endl
			 << "5. Comparar numeros racionales." << endl
       		 << "6. Anadir otro racional." << endl
       		 <<"7. Operacion (a^n)/(b^n)." << endl
			 <<"8. Salir del Programa." << endl;
		cin >> opc;
		if(opc < 1 || opc >8)
			cout << "ERROR: favor repetir" << endl;
}while (opc < 1 || opc >8 );
	return opc;
}


int menu2( NumerosRacional p[], int& opc, int& opc2, int max){
  do{
  
  
		cout << "Selecione el numero de dos de los siguientes en orden preferido, separado por un espacio." << endl;
    	for(int i=0; i<max; i++){
  			cout << "Racional :" << i+1 << endl;
  			cout << p[i] << endl;
  			
  		}
		cin >> opc >> opc2;
		if(opc < 1 || opc >max ||opc2 < 1 || opc2 >max)
			cout << "ERROR: favor repetir" << endl;
}while (opc < 1 || opc >max || opc2 < 1 || opc2 >max);
}


void close(ifstream &in){
	in.close();
}

void close(ofstream &out){
	out.close();
}




