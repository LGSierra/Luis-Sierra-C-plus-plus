#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include "Pro4head.h"
using namespace std;



/*

1. Inicializar la lista.
2. Determinar si la lista está o no vacía.
3. Escribir los elementos de la lista.
4. Determinar la longitud de la lista.
5. Destruir la lista.
6. Devolver la información contenida en un elemento de la lista.
7. Buscar un elemento en la lista.
8. Insertar un elemento en la lista.
9. Eliminar un element de la lista.

*/
//all these functions need updating on the header file
list::list(){
    head = NULL;
}

list::~list(){
    //destruccion de objeto
}

bool list::empty(){
    if(head==NULL){
        return true;
    }
    else{
        return false;
    }
}

void list::insertNode(){
    string nom;
    Npointer temp;
    cout << "Cual es el nombre del jugador?" << endl;
    cin.ignore();
    getline(cin, nom);
    
    cout << nom << endl;

    if(head == NULL){
        temp = new node;
        temp->name = nom;
        head = temp;
        head->link = head;
    }
    else{
        Npointer q = new node;
        q->name = nom;
        q->link = NULL;
        temp = head;

        while(temp ->link != head){
            temp = temp->link;
        }
        q->link = head;
        temp ->link = q;
        //needs evaluation to not lose node
	}
}

void list::printList(){
    Npointer temp;
    temp = head;
    int number = 1;
    cout << "Lista de jugadores: " << endl << endl;
    do{
        cout << "[" << number << "]";
        printNode(temp);
        temp = temp->link;
        number++;
    }while(temp != head);
    cout << "----------------------------------------" << endl;
}

void list::printNode(Npointer& pointer){
    cout << "Nombre: " << pointer->name << endl;
}

void list::deleteLoop(int selection){
    int index = 1;
    Npointer temp = head;
    Npointer previous = temp;
    
    //just in case the selection is the first node... duh
    while(previous ->link != head){
            previous = previous->link;
        }
    
    do{
        if(index == selection){
            deleteNode(previous, temp);
			break;
            //delete the node and re-arrange links
        }
        else{
            previous = temp;
            temp = temp->link;
            index++;
        }
    } while(temp!= head);
}

void list::deleteNode(Npointer &previous, Npointer &temp){
	if(previous->link == head){
		head = previous->link->link;
	}
    previous->link = temp->link;
    
    if(temp == head && previous == head){
    	head = NULL;
    //	delete previous;
    //	delete temp;
	}
  //  delete temp;
}


void list::beginGame(){
	Npointer temp;
	Npointer previous;
    vector<string> sentence;
    vector<string> input;
    string word;
    int WordCount = 0;
    int inputCount = 0;
    bool equal = true;
    temp = head;
    previous = temp;
    
    while(previous ->link != head){
            previous = previous->link;
        }
    
    
	if(head->link == head){
		cout << "No se puede comenzar el juego, Solo un jugador." <<endl;
	}
	else{
		cout << "==================================================================================" << endl;
		cout << "==================================================================================" << endl;
	    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Comienza el juego!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
	    cout << "Advertencia: Favor de no agregar un espacio a la ultima palabra, ya que esto" << endl << "lo descalifica" << endl << endl;
	    cout << "|||     El primero en turno introduce la primera palabra de a oracion          |||" << endl;
	    
	    printNode(temp);
	    cout << "Introduzca la primera palabra." << endl;
	    cin.ignore();
	    getline(cin, word);
	        
	    string str;
	    for(int i=0;i<word.length();i++){
		    if(word[i] == ' '){
		        WordCount++;
		        i++;
		        sentence.push_back(str);
		        str.erase(0, str.length());
		    }
		    str+= word[i];	
		}
		WordCount++;
		sentence.push_back(str);
		str.erase(0, str.length());
		
		//************TESTING PURPOSES***************
        for(int i=0; i < sentence.size(); i++){
        	cout << sentence[i] << endl;
		}
		cout << WordCount <<endl;
		//*******************************************
			
	        
	    do{
	    	equal = true;
	    	inputCount = 0;
	    	previous = temp;
	    	temp = temp->link;
	    	cout << "--------------proximo jugador-----------------" << endl;
	    	printNode(temp);
	        cout << "Introduzca las palabras." << endl << endl;
	        //cin.ignore();
		    getline(cin, word);
		        
		    string str;
		    for(int i=0;i<word.length();i++){
		    	
			    if(word[i] == ' '){
			        inputCount++;
			        i++;
			        input.push_back(str);
			        str.erase(0, str.length());
			    }
			    str+= word[i];	
			}
			inputCount++;
			input.push_back(str);
			str.erase(0, str.length());
	        
	        //************TESTING PURPOSES***************
	        for(int i=0; i < input.size(); i++){
	        	cout << input[i] << endl;
			}
			cout << inputCount <<endl;
			//*******************************************
			
			for(int i= 0 ; i< sentence.size(); i++) //used to have a -1, replace it back if there are errors
			{
				if(sentence[i] != input [i]){
					equal = false;
					break;
				}
				
			}
			
			if(inputCount != (WordCount + 1)){
				equal = false;
			}
			 
			if(equal == false){
				cout << "Jugador " << temp->name << " queda eliminado/a." <<endl;
			//	Npointer NodeToBeDeleted = temp;
				deleteNode(previous, temp);
				//Eliminade node here
			}
			else{
				sentence = input;
				WordCount = inputCount;
			}
			
			input.clear();
	
		if(head->link == head){
			cout << "El Jugador " << head->name << " gano el juego!" << endl;
			cout << "FELICIDADES" << endl << endl << endl;
		}
	    }while(head->link != head);
	}
   


}


int menu(){
		int choice;
		cout << "***************************************************************************" << endl;
		cout << "* [1] Introducir los nombres de los participantes                         *" << endl; //getline should be fine
		cout << "* [2] Imprimir lista de jugadores                                         *" << endl; //print the whole list
		cout << "* [3] Eliminar a un jugador(edicion de lista de participantes)            *" << endl; //if the user makes a mistake
        cout << "* [4] COMENZAR EL JUEGO!                                                  *" << endl; //MUST NOT ALLOW TO START THE GAME IF THERE'S ONLY 1 PLAYER
		cout << "*                                -----                                    *" << endl;
		cout << "* [0] Salir del programa.                                                 *" << endl;
		cout << "***************************************************************************" << endl; // u know what to do >u>
		cin >> choice;
		return choice;
	}
