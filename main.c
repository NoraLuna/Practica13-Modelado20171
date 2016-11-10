/*Incluye las funciones de b_sort.c y arreglos_random.c*/
#include "b_sort.h"
#include "arreglos_random.h"
#include "arreglos_random.c"
#include "b_sort.c"

//Para imprimir en consola
#include <stdio.h>

/*Declara las funciones que vamos a ocupar*/
// función que compara dos enteros
int cmp_int(const void *a, const void *b);
// función que compara dos doubles
int cmp_double(const void *a, const void *b);
// función que imprime una lista de enteros de tamaño num
void imprime_int(int *arreglo, size_t num);
// función que imprime una lista de doubles de tamaño num
void imprime_double(double *arreglo, size_t num);


int main()
{
    // Se inicializan 2 arreglos, uno de ints y otro de doubles
    int *arr1 = arreglo_int(20, 0, 10);
    double *arr2 = arreglo_double(20, 0, 10);

    // Se imprime ordena e imprime el primer arreglo
    imprime_int(arr1, 20);
    bsort(arr1, 20, sizeof(int), &cmp_int);
    imprime_int(arr1, 20);

    // Se imprime ordena e imprime el segundo arreglo
    imprime_double(arr2, 20);
    bsort(arr2, 20, sizeof(double), &cmp_double);
    imprime_double(arr2, 20);

    // Se libera la memoria que ocupan los arreglos ordenados
    free(arr1);
    free(arr2);

    return 0;//regresamos 0
}

//Funcion que recibe dos apuntadores, como es void, implica que no tiene ningun tipo de valor asociado
//Los parametros const void, apuntan a un espacio de memoria que no será modificado
//Si los enteros son iguales regresa 0, 1 si el primero es mayor y -1 en otro caso 
int cmp_int(const void *a, const void *b){
    //Se obtiene el valor del apuntador en un entero, haciendo un casting al tipo de valor int 
    int v_a = *(int *) a;
    //Lo mismo para b
    int v_b = *(int *) b;
    //Se comparan los numeros
    if(v_a == v_b){
        return 0;
    } else if(v_a > v_b){
        return 1;
    }

    return -1;
}

//Funcion que recibe dos apuntadores sin ningun tipo de valor asociado
//Regresa 0 si son iguales, 1 si el primero es mayor y -1 en otro caso
int cmp_double(const void *a, const void *b){
    //Se convierten en doubleslos apuntadores haciendo un casting al tipo de valor
    double v_a = *(double *) a;
    //Lo mismo para b
    double v_b = *(double *) b;
    //Se comparan los numeros
    if(v_a > v_b){
        return 1;
    } else if(v_a == v_b){
        return 0;
    }

    return -1;
}

//Funcion que imprime el arreglo y no regresa nada
//Recibe un apuntador a un arreglo y su tamaño
void imprime_int(int *arreglo, size_t num){
    int ind = 0;
    for(ind;ind<num;ind++){
        printf("El valor del arregloInt en[ %d ] es: %d\n", ind, arreglo[ind]);
    }

}

//Funcion que imprime el arreglo de doubles
//Recibe un arreglo de doubles y su tamaño
void imprime_double(double *arreglo, size_t num){
    int ind = 0;
    for(ind;ind<num;ind++){
        printf("El valor del arregloDouble en[ %d ] es: %f\n", ind, arreglo[ind]);
    }
}