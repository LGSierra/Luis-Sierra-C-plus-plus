
// Ejercicio 1: arreglos y estructuras
//  Created by Flor Eugenia on 2/5/18.
//  Copyright © 2018 Flor Eugenia. All rights reserved.

// El Campeonato Nacional de Ciclismo consta de 5 etapas en las que participan 120 ciclistas.
// Los resultados de cada etapa se almacenan en una matriz (arreglo bidimensional) de 120 filas y
// 5 columnas (etapas) en el que cada elemento contiene el tiempo en segundos que ha tardado el ciclista
// en realizar la etapa. Si un ciclista no ha finalizado una etapa aparecerá un 0 en el elemento
// correspondiente.
// La informacion de los ciclistas se almacena en un vector (arreglo unidimensional) de 120
// elementos en el que se almacenara el nombre del ciclista y el tiempo total realizado.
// Se desea escribir un programa en C++ que presente un menu para:
// Escribir el nombre de cada ciclista y su tiempo total
// Determinar y escribir, a partir de un número de etapa, el nombre del ganador de la etapa.



#include <iostream>
#include <cstdlib>
#include <string>

#define N 120
#define M 5


using namespace std;

struct ciclista {
    string nombre;
    int tiempoTotal;
};

int numeroCiclistas() {
    int num;
    
    do {
        cout << "Introduzca el numero de cilistas: ";
        cin >> num;
        if (num <= 0 || num > N)
            cout << "El numero de ciclistas debe ser mayor que cero y menor o igual que " << N << endl;
    } while (num <= 0 || num > N);
    cout << endl;
    return num;
}

void leerDatosCiclistas(ciclista vector[], int matriz[][M], int num, int etapas){
    int i, j;
    
    cin.ignore();
    for (i = 0; i < num; i++) {
        cout << "Nombre del ciclista " << i + 1 << ": ";
        getline(cin, vector[i].nombre);
        vector[i].tiempoTotal = 0;
        for (j = 0; j < etapas; j++)
            do {
                cout << "Tiempo en segundos que ha tardado el ciclista en realizar la etapa " << j + 1 << ": ";
                cin >> matriz[i][j];
                if (matriz[i][j] < 0)
                    cout << "El tiempo debe ser mayor o igual que cero" << endl;
            } while (matriz[i][j] < 0);
        cout << endl;
        cin.ignore();
    }
    cout << endl;
}

void tiempoTotal(ciclista vector[], int matriz[][M], int num, int etapas) {
    int i, j;
    
    for (i = 0; i < num; i++)
        for (j = 0; j < etapas; j++)
            vector[i].tiempoTotal  = vector[i].tiempoTotal  + matriz[i][j];
}

void escribirDatosCiclistas(ciclista vector[], int num){
    int i;
    
    for (i = 0; i < num; i++) {
        cout << "Ciclista " << i + 1 << ": "  << endl;
        cout << "Nombre: " << vector[i].nombre << endl;
        cout << "Tiempo total: " << vector[i].tiempoTotal << endl << endl;
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

void ganadorEtapa(ciclista vector[], int matriz[][M], int num, int etapas) {
    int i, ganador, cualEtapa, ciclistaGanador;
    
    cualEtapa = numeroEtapa();
    ciclistaGanador = 0;
    ganador = matriz[0][cualEtapa - 1];
    for (i = 1; i < num; i ++ )
        if (matriz[i][cualEtapa - 1] > ganador) {
            ganador = matriz[i][cualEtapa - 1];
            ciclistaGanador = i;
        }
    cout << "Ciclista ganador " << ciclistaGanador << endl;
    cout << "El ganador de la etapa " << cualEtapa << " es " << vector[ciclistaGanador].nombre << endl << endl;
}

int menu() {
    int op;
    
    do {
        cout << "*** CAMPEONATO NACIONAL DE CICLISMO ***" << endl;
        cout << "1. Nombre y tiempo total de cada ciclista" << endl;
        cout << "2. Ganador de una etapa" << endl;
        cout << "3. Salir" << endl << endl;
        cout << "Introduzca la opcion: ";
        cin >> op;
        if (op < 1 || op > 3)
            cout << "Escriba un numero entre 1 y 4" << endl << endl;
    } while (op < 1 || op > 3);
    cout << endl;
    return op;
}

int main() {
    int numCiclistas, matrizTiempos[N][M], opcion;
    ciclista vectorCiclista[M];
    
    numCiclistas = numeroCiclistas();
    leerDatosCiclistas(vectorCiclista, matrizTiempos, numCiclistas, M);
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
                cout << "FIN DEL PROGRAMA" << endl;
        }
    } while (opcion != 3);
    
    
    return 0;
}
