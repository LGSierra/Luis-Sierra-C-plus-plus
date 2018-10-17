#include <iostream>
#include <vector>
using namespace std;

void menu(int& choice);
void insertVector(vector<int>& myVector);
void showVector(vector<int>& myVector);
int addVector(vector<int> myVector, int size);
int multiplyVector(vector<int> myVector, int size);
  
int main (){
  int choice, add, multiply;
  vector<int> myVector;
  int size= 0;
  
  do{
    menu(choice);
    
    switch(choice){
      case 1:
        insertVector(myVector);
        break;
      case 2:
        showVector(myVector);
        break;
      case 3:
      	size = myVector.size();
        add = addVector(myVector, size);
        cout << "Resultado: " << add <<endl;
        break;
      case 4:
      	size = myVector.size();
      	cout << size << endl;
        multiply = multiplyVector(myVector, size);
        cout << "Resultado: " << multiply <<endl;
        break;
      case 0:
        cout << "Fin del programa. " <<endl;
        break;
      default:
        cout << "ERROR: entrada invaldia, favor repetir. " << endl;
        break;
    }
    
  } while(choice != 0);

  return 0;
}

void menu(int& choice){
  cout << "**********************************************************" << endl;
  cout << "* [1] Agregar elementos de vector                        *" << endl;
  cout << "* [2] Mostrar vector                                     *" << endl;
  cout << "* [3] Sumar elementos de vector                          *" << endl;
  cout << "* [4] Multiplicar elementos de vector                    *" << endl;
  cout << "*                                                        *" << endl;
  cout << "* [0] Salir del programa                                 *" << endl;
  cout << "**********************************************************" << endl;
  cin >> choice;
}

//iterativa
void insertVector(vector<int>& myVector){
  int entrada;
  char ans = 's';
  
  while(ans == 's' || ans == 'S'){
    cout << "Favor escribir una entrada entero." << endl;
  	cin >> entrada;
    myVector.push_back(entrada);
  	cout << "Desea introducir otro elemento?" << endl;
  	cout << "(s/n)" << endl;
  	cin >> ans;
  	while(ans != 's' && ans != 'n'){
   	 cout << "Respuesta invalida. Trate de nuevo (s/n)" << endl;
   	 cin >> ans;
  	}
    
  }
    
}

void showVector(vector<int>& myVector){
  cout << "Entradas en el vector:" << endl;
  
  for(int i = 0; i < myVector.size(); i++){
    cout << myVector[i] << endl;
  }  
}




//recursiva
int addVector(vector<int> myVector, int size){
  if (size == 0){
   	cout << "if " <<endl;
    return 0;    
  }
  else{
  	cout << "else " <<endl;
    return (addVector(myVector, size-1)+ myVector[size-1]);
  }
}

//recursiva
int multiplyVector(vector<int> myVector, int size){
    if (size == 0){
    	cout << "if " <<endl;
    return 1;    
	}
    else{
    cout << "else " <<endl;
      return (multiplyVector(myVector, size-1) * myVector[size-1]) ;
    }
}








