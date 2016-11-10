#include "b_sort.h"

/*  bsort: ordena un arreglo usando el algoritmo bubble sort
    base: es un apuntador a un arreglo a ordenar
    num: es el número de elementos en el arreglo
    size: es el tamaño en bytes de cada elemento en el arreglo
    compar: es el apuntador a una función comparadora, que regresa:
           número negativo si el primer elemento es menor
           0 si ambos elementos son iguales
           número positivo si el primer elemento es mayor
*/
void bsort(void* base, size_t num, size_t size, int (*compar)(const void*, const void*)){
	//Vamos a tener indices para el recorrido del arreglo
	int ind, jind;
	//Convertimos la bese generica  a su tipo ya sea int o double
	double *baseDouble = base;
	int *baseInt = base;

	if(size == 8){//El caso en el que el arreglo sea de doubles
		//Se recorre el arreglo 
		for(ind = 0; ind<num; ind++){
			//Recorremos el arreglo menos veces que el ind
			for(jind = 0; jind < num-ind; jind++){
				//Llamamos a la funcion para omparar
			    //Si el valor del arreglo en la posicion de ind es mayor 
				if((*compar)(baseDouble + jind,baseDouble + jind + 1)>0){
					//Guardamos el valor de jind
					double aux = *(baseDouble +  jind);
					//modificamos el arreglo en la posicion delante del indice
					*(baseDouble + jind) = *(baseDouble + jind + 1);
					//Al de atras lo igualamos al de adelante
					*(baseDouble + jind + 1) = aux;
				}
			}
		}
	} 
	if(size <= 4){ //Entonces es un arreglo tipo int
		for(ind = 0; ind<num; ind++){
			
			//Recorremos el arreglo menos veces que el indice
			for(jind = 0; jind < num-ind; jind++){
				if((*compar)(baseInt + jind, baseInt + jind + 1)==1){
					//Guardamos el valor de jind
					int aux = *(baseInt + jind); 
					//modificamos el arreglo en la posicion delante de ind
					*(baseInt + jind) = *(baseInt + jind + 1);
					//Al de atras lo igualamos al de adelante
					*(baseInt + jind + 1) = aux;
				}
			}
		}
	}
}