#include <iostream>
#include <cmath>
#include <cstdlib>
#include "Pro2head.h"
using namespace std;
using namespace CircleNamespace;

//functions go here


punto::punto(){
	//blank
}
punto::punto(int x, int y){
}
punto::~punto(){
	//blank
}



void punto::capturarPunto(){
	int x, y;
	cout << "Ingrese puntos de coordenadas X:" << endl;
	cin >> x;
	cout << "Ingrese puntos de coordenadas Y:" << endl;
	cin >> y;
	fijarX(x);
	fijarY(y);
	
}
void punto::fijarX(int& Xcoord){
	x = Xcoord;
}
void punto::fijarY(int& Ycoord){
	y = Ycoord;
}
int punto::obtenerX(){
	return x;
}
int punto::obtenerY(){
	return y;
}
void punto::imprimir(){
	cout << "Coordenadas: (" << obtenerX() << "," << obtenerY() << ")" << endl;
}



circulo::circulo(){
	Head = NULL;
}
circulo::circulo(int x, int y, double r){
	Head = NULL;
	fijarX(x);
	fijarY(y);
	fijarRadio(r);
}
circulo::~circulo(){
	//blank
}


void circulo::capturarCirculo(int& max){
	punto::capturarPunto();
	double radio;
	cout << "Ingrese radio:" << endl;
	cin >> radio;
	while(radio<=0){
		cout << "Valor invalido, intente introducir un radio mayor que cero" << endl;
		cin >> radio;
	}
	fijarRadio(radio);
	add(max);
	//add to list undefined
	//max++;
}

void circulo::fijarRadio(double& rd){
	radio = rd;
} 
double circulo::obtenerRadio(){
	return radio;
}
double circulo::obtenerArea(){
	return  pow(obtenerRadio(), 2) * 3.1415926535897;
}
double circulo::obtenerCircunsferencia(){
	return ((obtenerRadio()*2) * 3.1415926535897);
}
double circulo::obtenerDiametro(){
	return obtenerRadio()*2;
}
void circulo::imprimirCirculo(int max){
	
	Npointer temp;
	temp = Head;
	for(int i = 1; i< max+1; i++){
			cout << "Circulo " << i << ":" << endl;
			cout << "Coordenadas del centro: ("<< temp->x << "," << temp->y << ")" << endl;
			cout << "----------------------------------------" << endl;
			temp = temp->link;
		}
}

void circulo::printList(int max){
	Npointer temp;
	temp = Head;
	for(int i = 1; i< max+1; i++){
			cout << "Circulo " << i << ":" << endl;
			cout << "Coordenadas del centro: ("<< temp->x << "," << temp->y << ")" << endl;
			cout << "radio: " << temp->radio << endl;
			cout << "----------------------------------------" << endl;
			temp = temp->link;
		}
	
	
}

void circulo::printList2(int max){
	Npointer temp;
	temp = Head;
	for(int i = 1; i< max+1; i++){
			circulo tempObj(temp->x, temp->y, temp->radio);
			cout << "Circulo " << i << ":" << endl;
			cout << "Coordenadas del centro: ("<< temp->x << "," << temp->y << ")" << endl;
			cout << "radio: " << temp->radio << endl;
			cout << "Area: " << tempObj.obtenerArea() << " unidades cuadradas." << endl;
			cout << "Circumsferencia: " << tempObj.obtenerCircunsferencia() << " unidades." << endl;
			cout << "Diametro: " << tempObj.obtenerDiametro() << " unidades." << endl;
			cout << "----------------------------------------" << endl;
			temp = temp->link;
			
		}
	
}

void circulo::selectExtract(int max, int selection, int& selectX, int& selectY, double& selectR){
	Npointer temp;
	temp = Head;
	for(int i = 1; i<= max+1; i++){
		if(i == selection){
			selectX = temp->x;
			selectY = temp->y;
			selectR = temp->radio;
			break;
		}
		else{
			temp = temp->link;
		}
	}
	
}

void circulo::add(int& NumOfNodes){
	Npointer temp;
	
	if(Head == NULL){
		Head = new node;
		Head->x = punto::obtenerX();
		Head->y = punto::obtenerY();
		Head->radio = obtenerRadio();
		Head->link = NULL;
		
		}
	else{
		temp = new node;
		temp->x = punto::obtenerX();
		temp->y = punto::obtenerY();
		temp->radio = obtenerRadio();
		temp->link = Head;
		Head = temp;
		//NumOfNodes++;
	}
	NumOfNodes++;
}


int menu(){
	int selection;
	cout << "Bienvenidos! Seleccione una opcion." << endl << endl;
	cout << "[1] Ingresar datos de un circulo." << endl;
	cout << "[2] Calcular area de un circulo." << endl;
	cout << "[3] Calcular circunsferencia de un circulo." << endl;
	cout << "[4] Calcular diametro de un circulo." << endl;
	cout << "[5] Escribir todos los circulos." << endl;
	cout << "[6] Escribir los puntos de todos los circulos." << endl;
	cout << "[0] Terminar el programa." << endl << endl;
	cin >> selection;
	return selection;
}
