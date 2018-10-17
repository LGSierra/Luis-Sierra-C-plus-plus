#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "Pro4func.cpp"
using namespace std;

//idea: use a vector list to store the words!!
//that way we can check each word and keep adding
//infinately during runtime
//node insertion will be at the end. head will not
// be re-assigned

int main()
{
    int choice;
    list object;



    do{
        choice = menu();
        while(choice < 0){
            cout << "Opcion invalida. Intente de nuevo." << endl;
            choice = menu();
        }

        switch(choice){

        case 1:
            object.insertNode();
            //will tell you how many players are
            break;

        case 2:
            if(object.empty()){
                cout << "No hay jugadores en lista." << endl;
            }
            else{
                object.printList();
            }

            //will tell you how many players are
            break;

        case 3:
            int selection;
            if(object.empty()){
                cout << "No hay jugadores en lista." << endl;
            }
            else{
                object.printList();
                cout << "Elige a un jugador para eliminar de la lista:" << endl;
           		 cin >> selection;
            	object.deleteLoop(selection);
            	// update the count?
                
                
            }
            
            break;

        case 4:
        	if(object.empty()){
                cout << "No hay jugadores en lista." << endl;
            }
            else{
            	 object.beginGame();
			}
        	
           
            //a loop that will start taking in string
            // while filling up the vectors and using all
            //other functions
            break;

        default:;
		}


    } while (choice !=0);




  return 0;
}
