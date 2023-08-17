#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ejercicio 1: Encuentra el Elemento Mayor
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y devuelva el valor más grande del arreglo.
*/
//int findMax(int arr[], int size) { return 0; }
int findMax(int arr[], int size) {
    int maximo = arr[0];
    int cont = 1;
    while (cont < size) {
        if (arr[cont] > maximo) {
            maximo = arr[cont];
        }
        cont++;
    }
    return maximo;
}

/*
Ejercicio 2: Invertir un Arreglo
Descripción: Escribe una función que tome un arreglo y su tamaño, y luego
invierta el orden de sus elementos.
*/
//void reverseArray(int arr[], int size) {}
void reverseArray(int arr[], int size) {
    int cont = 0;
    while (cont < size / 2) {
        int aux = arr[cont];
        arr[cont] = arr[size - 1 - cont];
        arr[size - 1 - cont] = aux;
        cont++;
    }
}

/*
Ejercicio 3: Filtrar Números Pares
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y luego devuelva un nuevo arreglo que contenga solo
los números pares del arreglo original.
*/
//int *filterEvenNumbers(int arr[], int size, int *newSize) { return NULL; }
int *filterEvenNumbers(int arr[], int size, int *newSize) {
    int contPares = 0;
    int cont = 0;
    while (cont < size) {
        if (arr[cont] % 2 == 0) {
            contPares++;
        }
        cont++;
    }
    
    int *arrPares = (int *)malloc(contPares * sizeof(int));
    int indice = 0;
    cont = 0;
    while (cont < size) {
        if (arr[cont] % 2 == 0) {
            arrPares[indice] = arr[cont];
            indice++;
        }
        cont++;
    }
    
    *newSize = contPares;
    return arrPares;
}

/*
Ejercicio 4: Fusión de dos Arreglos Ordenados
Descripción: Escribe una función que tome dos arreglos
ordenados y sus tamaños, y luego fusione estos dos
arreglos en un tercer arreglo también ordenado.
*/
//void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2,
//                       int result[]) {}
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int indiceArr1 = 0;
    int indiceArr2 = 0;
    int indiceResult = 0;

    while (indiceArr1 < size1 || indiceArr2 < size2) {
        if (indiceArr1 < size1 && (indiceArr2 >= size2 ||     
             arr1[indiceArr1] <= arr2[indiceArr2])) {
            result[indiceResult] = arr1[indiceArr1];
            indiceArr1++;
        } else {
            result[indiceResult] = arr2[indiceArr2];
            indiceArr2++;
        }
        indiceResult++;
    }
}

/*
Ejercicio 5: Comprobación de Ordenación
Descripción: Escribe una función que tome un arreglo y su tamaño,
y luego devuelva 1 si el arreglo está ordenado en orden ascendente,
  0 si no está ordenado, y -1 si está ordenado en orden descendente.
*/
//int checkSorted(int arr[], int size) { return -2; }
int checkSorted(int arr[], int size) {
    int ordenAscendente = 1;
    int ordenDescendente = 1;
    
    int cont = 1;
    while (cont < size) {
        if (arr[cont] < arr[cont - 1]) {
            ordenAscendente = 0;
        }
        if (arr[cont] > arr[cont - 1]) {
            ordenDescendente = 0;
        }
        cont++;
    }
    
    if (ordenAscendente) {
        return 1;
    } else if (ordenDescendente) {
        return -1;
    } else {
        return 0;
    }
}

/*
Ejercicio 6: Información de una Biblioteca
Descripción: Vamos a representar la información de una biblioteca. En la
biblioteca, hay libros, y cada libro tiene un autor. Queremos organizar esta
información utilizando estructuras anidadas en C. Escribe la función para
inicializar la información de un libro.
*/
typedef struct {
  char nombre[50];
  int anioNacimiento;
} Autor;

typedef struct {
  char titulo[100];
  Autor autor;
  int anioPublicacion;
} Libro;
/*
void inicializarLibro(Libro *libro, const char *titulo, const char *nombreAutor,
                      int anioNacimiento, int anioPublicacion) {}
*/
void inicializarLibro(Libro *libro, const char *titulo, const char *nombreAutor, int anioNacimiento, int anioPublicacion) {
    strcpy(libro->titulo, titulo);
    strcpy(libro->autor.nombre, nombreAutor);
    libro->autor.anioNacimiento = anioNacimiento;
    libro->anioPublicacion = anioPublicacion;
}

/*
Ejercicio 7: Lista enlazada de números
Descripción: Escribe una función que tome un arreglo de enteros y su tamaño, y
luego cree una lista enlazada usando la estructura Nodo. Cada nodo de la lista
debe contener un número del arreglo, y los nodos deben estar enlazados en el
mismo orden que los números aparecen en el arreglo. El último nodo de la lista
debe apuntar a NULL. La función debe devolver un puntero al primer nodo de la
lista enlazada.
Recuerda reservar memoria dinámica para cada nodo usando malloc.
  */

typedef struct nodo {
  int numero;
  struct nodo *siguiente; // puntero al siguiente nodo
} Nodo;

//Nodo *crearListaEnlazada(int arr[], int size) { return NULL; }
Nodo *crearListaEnlazada(int arr[], int size) {
    Nodo *inicio = NULL;
    Nodo *actual = NULL;
    
    int cont = 0;
    while (cont < size) {
        Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
        nuevoNodo->numero = arr[cont];
        nuevoNodo->siguiente = NULL;
        
        if (inicio == NULL) {
            inicio = nuevoNodo;
            actual = nuevoNodo;
        } else {
            actual->siguiente = nuevoNodo;
            actual = nuevoNodo;
        }
        
        cont++;
    }
    
    return inicio;
}