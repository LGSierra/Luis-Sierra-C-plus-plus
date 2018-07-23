#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <cctype>
#include "header.cpp"
using namespace std;

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
  	for(i=0;(!in.eof()); i++){
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
    	agregar(max,p,a,out); 
    	break;
    case 7:
    	int m, n;
    	int num, den;
    	out << "Opcion 7 elegida" << endl;
    	if(a < max){
    	do{
			cout << "Introduca numerador, denominador." << endl;
			cout << "Si numerador es entero, favor marcar denominador como (1)." << endl;	
    		cin >> p[a++];
    		if(p[a -1].GetDen() == 0)
    			cout << "Error: denominador es cero, favor repetir" << endl;
    	}while (p[a -1].GetDen() == 0);
    
    		cout << "Introduzca exponentes."<< endl;
    		cin >> m >> n;
    		j=a-1;
    		
    		num = p[j].GetNum();
    		den = p[j].GetDen();
    		cout << pow(num, m) << "/" << pow(den, n) << endl;
    		out<< "Valores introducidos: " << num <<", "<< den <<", "<< m <<", "<< n << endl;
    		out << "Racional nuevo: " << p[a-1];
    		out << "Resultado: " << pow(num, m) << "/" << pow(den, n) << endl;
    			
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
