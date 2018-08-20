#include <iostream>
#include <string>
#include "Pro1head.h"
using namespace std;



romanType::romanType(){
	Head = NULL;
}

romanType::~romanType(){
	//intentionally blank. Destroys object.
}


void romanType::getArabic(int NumOfNodes){
	Npointer temp;
	if(Head == NULL){
		cout << "List is empty!" << endl;
	}
	else{
		cout << "List of numbers stored in linked list in their arabic form: " << endl << endl;
		temp = Head;
		for(int i = 0; i<= NumOfNodes; i++){
			cout << temp->num << endl;
			temp = temp->link;
		}
		cout << "End of list" << endl;
	}
	
}

void romanType::getRoman(int NumOfNodes){
	Npointer temp;
	if(Head == NULL){
		cout << "List is empty!" << endl;
	}
	else{
		cout << "List of numbers stored in linked list in their roman form: " << endl << endl;
		temp = Head;
		for(int i = 0; i<= NumOfNodes; i++){
			cout << temp->roman << endl;
			temp = temp->link;
		}
		cout << "End of list" << endl;
	}
}

void romanType::add(int& NumOfNodes){
	string romanInput;
	int arabic;
	cout << "Enter a number written in roman in capital letters ONLY" << endl;
	cin >> romanInput;
	arabic = translate(romanInput);
	
	cout << endl << "Your number in arabic is " << arabic << "." << endl << endl;;
	
	
	
	Npointer temp;
	
	if(Head == NULL){
		Head = new node;
		Head->roman = romanInput;
		Head->num = arabic;
		Head->link = NULL;
	}
	
	else{
		temp = new node;
		temp->roman = romanInput;
		temp->num = arabic;
		temp->link = Head;
		Head = temp;
		NumOfNodes++;
	}
	
	
	
}


void menu(){
	cout << "****************************************************************************" << endl;
	cout << "*[1] Enter number in roman, and get it translated to arabic.               *" << endl;
	cout << "*[2] Display all numbers in the linked list in arabic.                     *" << endl;
	cout << "*[3] Display all numbers in the linked list in roman.                      *" << endl;
	cout << "*                                                                          *" << endl;
	cout << "*[0] Exit this program.                                                    *" << endl;
	cout << "****************************************************************************" << endl;
	
	
}

int translate(string rmIn){
	
	
	
	int sum = 0;

	int i;
	int length = rmIn.length();

	int previous = 1000;
	string strpos;
	char extract;

	for(i = 0; i < length; i++)
	{
		//extract = ;
		
		if(rmIn.substr(i, 1) == "M"){
			sum += 1000;
			if(previous < 1000)
			{
				sum -= 2 * previous;
			}
			previous = 1000;
		}
		
		else if(rmIn.substr(i, 1) =="D"){
			sum += 500;
			if(previous < 500)
			{
				sum -= 2 * previous;
			}
			previous = 500;
		}
		else if(rmIn.substr(i, 1) =="C"){
			sum += 100;
			if(previous < 100)
			{
				sum -= 2 * previous;
			}
			previous = 100;
		}
		else if(rmIn.substr(i, 1) =="L"){
			sum += 50;
			if(previous < 50)
			{
				sum -= 2 * previous;
			}
			previous = 50;
		}
		else if(rmIn.substr(i, 1) =="X"){
			sum += 10;
			if(previous < 10)
			{
				sum -= 2 * previous;
			}
			previous = 10;
		}
		else if(rmIn.substr(i, 1) =="V"){
			sum += 5;
			if(previous < 5)
			{
				sum -= 2 * previous;
			}
			previous = 5;
		}
		else if(rmIn.substr(i, 1) =="I"){
			sum += 1;
			if(previous < 1)
			{
				sum -= 2 * previous;
			}
			previous = 1;
		}
		else{
			cout << "Number entered contains character that is not roman. This number will be saved as a zero" << endl;
			return 0;
		}
		
	}
		
	return sum;
	//return the arabic int
	
}

//insert functions here
