#include <iostream>
using namespace std;

struct nodoLista{
    int dato;
    nodoLista * sig;
    nodoLista * fin;
};

typedef nodoLista * LEnt;

// CONSTRUCTORAS

// Crea una nueva lista

LEnt null(){
    LEnt L = new nodoLista;
    L->dato = NULL;
    L->sig = NULL;
    L->fin = L;
    return L;
}

// Inserta el entero x al inicio de la lista

void insertar(int x, LEnt & L){
    if(L == NULL){
        return;
    }
    LEnt nuevo = new nodoLista;
    nuevo->dato = x;
    nuevo->sig = L->sig;
    L->sig = nuevo;
}

// PARTE B

// Añadiría un puntero al final de la lista, para poder realizar inserciones en O(1)

// Inserta el elemento x al final de la lista.

void insFinal (int x, LEnt & L){
    LEnt nuevo = new nodoLista;
    nuevo->dato = x;
    nuevo->sig = NULL;
    L->fin->sig = nuevo;
    L->fin = L->fin->sig;
}

// PREDICADO

// Verifica si la lista está vacía

bool esVacia(LEnt L){
    return L->sig == NULL;
}

// SELECTORAS

// Devuelve el primer elemento de una lista .

int primero (LEnt L){
    return L->sig->dato;
}

// Devuelve la lista L sin su primer elemento

void resto ( LEnt & L){
    LEnt borrar = L->sig;
    L->sig = borrar->sig;
    delete borrar;
}

// PARTE C

// 