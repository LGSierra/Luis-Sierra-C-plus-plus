
//Annamary 
//Luis
//Proyecto1
//Comp3110 Profa FLor
//Feb 27, 2018

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cstdlib>

#define N 120
#define M 5
using namespace std;

struct Fecha {
	int mes;
	int dia;
	int anio;};
	
struct ciclista {
    string nombre;
    int tiempoTotal;
	Fecha fechaNacimiento;
};
/* struct calification{
	bool entrar = true;
}; */

void numeroCiclistas(ifstream& entrada, int& num); //Lee numero de ciclistas participando de entrada
void leerDatosCiclistas(ciclista vector[], int matriz[][M], int num, int etapas, ifstream& entrada);
void tiempoTotal(ciclista vector[], int matriz[][M], int num, int etapas);
void escribirDatosCiclistas(ciclista vector[], int num);
void ganadorEtapa(ciclista vector[], int matriz[][M], int num, int etapas);
int numeroEtapa();
int TiempoEtapa(int matriz[][M]);
int menu();
int Ganador(int matriz[][M], ciclista vector[], int numCiclistas);



int main(){
	int numCiclistas = 0, matrizTiempos[N][M], opcion;
    ciclista vectorCiclista[M];
	ifstream entrada;
    entrada.open("ciclistas.txt");
    
    if(entrada.fail()){
    cout << "No pudo abrirse el archivo de entrada." << endl;
    exit (1);
  }
    
    numeroCiclistas(entrada, numCiclistas);
    
    if(numCiclistas <= 0)
    	cout << "Error 1: numero de ciclistas menor o igual que cero" << endl;
    else{
    	leerDatosCiclistas(vectorCiclista, matrizTiempos, numCiclistas, M, entrada);
	   do {
	        opcion = menu();
	        switch (opcion) {
	            case 1:
	                tiempoTotal(vectorCiclista, matrizTiempos, numCiclistas, M);
	                escribirDatosCiclistas(vectorCiclista, numCiclistas);
	                break;
	            case 2:
	                ganadorEtapa(vectorCiclista, matrizTiempos, numCiclistas, M);
	                break;
	            case 3:
	            	TiempoEtapa(matrizTiempos);
	            	break;
	            case 4:
	            	Ganador(matrizTiempos, vectorCiclista, numCiclistas);
	            	break;
				case 5:
	                cout << "FIN DEL PROGRAMA" << endl;
	                return 0;
	                break;
	            }
	    } while (opcion != 5);
		
    }

	 
	
	return 0;
}

void numeroCiclistas(ifstream& entrada, int& num) {
	
        entrada >> num;
        if (num <= 0 || num > N){
            cout << "El numero de ciclistas debe ser mayor que cero y menor o igual que " << N << endl;
            cout << "Fin Programa" << endl;
        }
        cout << "Numero de ciclistas: " << num << endl;
}

void leerDatosCiclistas(ciclista vector[], int matriz[][M], int num, int etapas, ifstream& entrada){
	int i, j;
	bool x = true;
	
	entrada.ignore();
	for (i = 0; i < num; i++) {
	entrada >> vector[i].nombre;
	//getline(entrada, vector[i].nombre);
	cout << endl<<"Nombre del ciclista " << i + 1 << ": ";
	cout << vector[i].nombre << endl;
	
	entrada >> vector[i].fechaNacimiento.mes;
	entrada>> vector [i].fechaNacimiento.dia;
	entrada >> vector[i].fechaNacimiento.anio;
	cout << "Mes: " << vector[i].fechaNacimiento.mes << endl;
	cout << "Dia: " << vector[i].fechaNacimiento.dia << endl;
	cout << "Anio: " << vector[i].fechaNacimiento.anio << endl;
	
	switch(vector[i].fechaNacimiento.mes){
	case 1 : case 3: case 5: case 7: case 8: case 10: case 12:
		if (vector[i].fechaNacimiento.dia > 31){
			x = false;}
		break;
	case 2:
		break;
		if (vector[i].fechaNacimiento.dia > 29){ 
			x = false;}	
	case 4: case 6: case 9: case 11:
		if (vector[i].fechaNacimiento.dia > 30){ 
			x = false;}	
		break;
	default:
		x = false;
		break;
	}
	
	if(x == false)
		cout << "ERROR: fecha incorrecta" << endl;
	x = true;
	for (j = 0; j < etapas; ){
	        entrada >> matriz[i][j];
	        if (matriz[i][j] < 0){
	            cout << "ERROR en tiempo: " <<j+1 << endl;
				cout << "El tiempo debe ser mayor o igual que cero." << endl;
	            cout << "Tiempo modificado a 0." << endl;
	            matriz[i][j] = 0;
	            cout << "Tiempo " << j+1 << ": " << matriz[i][j] << endl;
	            j++;
	            
	                
	            /*if (matriz[i][j] == 0){
	                for(;j<etapas; j++){
	                matriz[i][j] = 0;
	                cout << "Descalificado" << endl;
	                }
				}*/
	        }
	        else{
	        	cout << "Tiempo "<< j+1 << ": " << matriz[i][j] << endl;
	        	j++;}
	        
		}
	}
}


int menu() {
    int op;
    
    do {
        cout << endl;
		cout << "*** CAMPEONATO NACIONAL DE CICLISMO ***" << endl;
        cout << "1. Nombre y tiempo total de cada ciclista" << endl;
        cout << "2. Ganador de una etapa" << endl;
        cout << "3. Tiempo total de cada etapa" << endl;
        cout << "4. Ganador del campeonato" << endl;
        cout << "5. Salir" << endl << endl;
        cout << "Introduzca la opcion: ";
        cin >> op;
        if (op < 1 || op > 5)
            cout << "Escriba un numero entre 1 y 4" << endl << endl;
    } while (op < 1 || op > 5);
    cout << endl;
    return op;
}

void ganadorEtapa(ciclista vector[], int matriz[][M], int num, int etapas) {
    int i, ganador = 0 , cualEtapa = 0, ciclistaGanador = 0;
    
    cualEtapa = numeroEtapa();
    ciclistaGanador = 0;
    ganador = matriz[0][cualEtapa - 1];
    for (i = 0; i < num; i ++ )
        if (matriz[i][cualEtapa - 1] < ganador) {
            ganador = matriz[i][cualEtapa - 1];
            ciclistaGanador = i;
        }
    cout << "Ciclista ganador " << ciclistaGanador << endl;
    cout << "El ganador de la etapa " << cualEtapa << " es " << vector[ciclistaGanador].nombre << endl << endl;
}

void escribirDatosCiclistas(ciclista vector[], int num){
    int i;
    
    for (i = 0; i < num; i++) {
        cout << "Ciclista " << i + 1 << ": "  << endl;
        cout << "Nombre: " << vector[i].nombre << endl;
        cout << "Tiempo total: " << vector[i].tiempoTotal << endl << endl;
    }
}

void tiempoTotal(ciclista vector[], int matriz[][M], int num, int etapas) {
    int total=0;
    
    for (int i = 0; i < num; i++){
    	for (int j = 0; j < etapas; j++){
    		total  +=   matriz[i][j];
		}
		
        vector[i].tiempoTotal = total;
        total = 0;
	}
        
            
            
            
    
}

int numeroEtapa() {
    int num;
    
    do {
        cout << "Introduzca la etapa: ";
        cin >> num;
        if (num <= 0 || num > M)
            cout << "La etapa debe ser mayor que cero y menor o igual que " << M << endl << endl;
    } while (num <= 0 || num > M);
    cout << endl;
    return num;
}

int TiempoEtapa(int matriz[][M]){ //sume 5 etapas
	int i,j, num = 0, Suma[5], cualEtapa =1;  

	
	for (int a =0; a < 5; a++){
		for(i = 0; i < 5; i++){
			num += matriz[i][cualEtapa - 1];
			//cout << num << endl;
			}
		matriz[i][cualEtapa++];
		cout << "Tiempo total de todos lo ciclistas en etapa " << cualEtapa-1 << ": " << num << endl;
		Suma[a] = num;
		num= 0;
	}
	/*for(int a= 0; a<5; a++){
		cout << "Tiempo total: " << Suma[a] << endl;        //Hace lo mismo que lo previo
	}*/

	cout << endl;
	
}

int Ganador(int matriz[][M], ciclista vector[], int numCiclistas){
	int i,j, num = 0, Suma[5], espacioEtapa =0, a=0;
	
	for (int i =0; i < numCiclistas; i++){
		for(espacioEtapa = 0; espacioEtapa < 4; espacioEtapa++){ // menor que 4, espacioEtapa comienza en cero. Ocurren 5 repeticiones. (0,1,2,3,4)
			num += matriz[i][espacioEtapa];
			//cout << num << endl;
			}
		matriz[i][espacioEtapa];
		cout << "Tiempo total de Ciclista " << vector[i].nombre << ": " << num << endl;
		Suma[i] = num;
		num= 0;
	}
	
	for(i=1; i<numCiclistas; i++){
		if (Suma[i-1] > Suma[i] && Suma[i] != 0)
			a = i;
	}
	cout << endl << "Ganador del Campeonato!: " << vector[a].nombre<< endl;
	}
