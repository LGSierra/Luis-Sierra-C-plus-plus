#include <iostream>
#include <string>
using namespace std;
struct node{
	int num;
	string roman;
	node* link;
};

typedef node* Npointer;

class romanType{
	
	private:
		Npointer Head;
	//	Npointer temp;
		
	public:
		
	romanType();
	~romanType();
	void add(int& NumOfNodes);
	void getRoman(int NumOfNodes);
	void getArabic(int NumOfNodes);
	//add and show,use two functions to print	
	
	
};

void menu();
int translate(string rmIn);
