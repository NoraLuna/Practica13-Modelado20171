#include "arreglos_random.h"

#include <stdio.h>

#include <time.h>
#include <stdlib.h>

/*  Crea un arreglo de enteros(en el heap) con números aleatorios
    num indica el tamaño del arreglo
    min indica el mínimo número aleatorio permitido en el arreglo
    max indica el máximo número aleatorio permitido en el arreglo
*/
int* arreglo_int(size_t num, int min, int max){
	time_t t;
	//Inicializa el generador de numeros aleatorios
    srand((unsigned) time(&t));
    //indice para recorrer
    int ind = 0;
	//Se usa malloc para apartar memoria y se guarda en un apuntador
	int *arrg = malloc(num * sizeof(int));
	//Rellenamos el arreglo de numeros al azar con rand y se generaran con un minimo y un maximo
	for(ind;ind<num;ind++){
		//Se agrega al arreglo
		arrg[ind] = (rand()%(max - min)) + min;
	}
	//Finalmente devolvemos el apuntador al arreglo de numeros aleatorios
	return arrg;
}

/*  Crea un arreglo de doubles(en el heap) con números aleatorios
    num indica el tamaño del arreglo
    min indica el mínimo número aleatorio permitido en el arreglo
    max indica el máximo número aleatorio permitido en el arreglo
*/
double* arreglo_double(size_t num, double min, double max){
	time_t t;
	//inicializa el generador de numeros aleatorios
    srand((unsigned) time(&t));
	
	//Se usa malloc para apartar memoria y se guarda en un apuntador
	double *arrgD = malloc(num * sizeof(double));
	int ind = 0;
	//Rellenamos el arreglo con numeros aleatorios con rand generados con un minimo y un maximo
	for(ind;ind<num;ind++){
		 // hacemos el cast a double y dividimos con RAND_MAX y el resultado lo sumamos y multiplicamo
		double aux = (double)rand() / RAND_MAX;
		arrgD[ind] = min + aux *(max - min);
	}
	return arrgD;
}
