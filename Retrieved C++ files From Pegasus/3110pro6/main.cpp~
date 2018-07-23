#include <iostream>
#include <cstdlib>
#include "header.cpp"

using namespace std;
using namespace pares;

/*


MISSING OVERLOAD, VERIFICATION OF DUPLICATED PAIRS(semi complete)

INVALID OPTION ERROR MSG
EMPTY LIST ERROR MSG



*/
int main()
{
	ParPtr ListHead = NULL, temporary;
	int number;
	int choice;
	int max=0;
	
	do{
		
		choice = menu();
		
		switch(choice)
		{
			case 1:
				agregar_principio(ListHead,temporary);
				max++;
				break;
				
			case 2:
				agregar_final(ListHead, temporary);
				max++;
				break;
				
			case 3:
				sumar(ListHead,max);
				break;
				
			case 4:
				restar(ListHead,max);
				break;
				
			case 5:
				mostrar(ListHead);
				break;
				
				
		}
		
		
	}while(choice!=6);
	
	
	
	
	
	
	
	
	return 0;
}
