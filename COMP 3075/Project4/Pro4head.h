#ifndef H_Pro4head
#define H_Pro4head

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;


struct node{
    string name;
    node* link;
};

typedef node* Npointer;


class list{
  public:

      list();
      ~list();
      bool empty();
      void insertNode();
      void searchNode();//not implemented
      void deleteLoop(int selection);
      void deleteNode(Npointer& previous, Npointer& temp);
      void printList();
      void printNode(Npointer& pointer);
      void countNode(); //unwritten
      void beginGame();



  private:
      Npointer head;

};


int menu();



#endif
