//COMP 3075 Project 1
//Luis G. Sierra

//20 August 2018
// Prof. Flor Narciso


#include <iostream>
#include <string>
#include "Pro1func.cpp"
using namespace std;



int main()
{
	int choice;
	int NumOfNodes = 0;
	romanType ListHead;
	
		do{
		menu();
		cin >> choice;
	
		switch(choice){
			case 1:
				ListHead.add(NumOfNodes);
				//enter roman number
				break;
			case 2:
				ListHead.getArabic(NumOfNodes);
				//show all numbers in linked list as arabic
				break;
			case 3:
				ListHead.getRoman(NumOfNodes);
				//show all numbers in linked list as roman
				
			default:;
		}
	} while (choice != 0);
	
	
	
	
	
	return 0;
}
