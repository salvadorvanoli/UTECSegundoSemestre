#include "ColaDinámicaNoAcotada.hpp"
#include <iostream>
#include <cassert>
using namespace std;

typedef int T;

struct cola{
    T dato;
    cola * sig;
};

typedef cola * Cola;

struct cabezal{
    Cola inicio;
    Cola fin;
};

typedef cabezal * Cabezal;

Cabezal crearCola(){
    Cola nuevo = new cola;
    nuevo->dato = NULL;
    nuevo->sig = NULL;

    Cabezal C = new cabezal;
    C->inicio = nuevo;
    C->fin = nuevo;
    return C;
}

void insertar(Cabezal & C, T dato){
    Cola nuevo = new cola;
    nuevo->dato = dato;
    nuevo->sig = NULL;
    C->fin->sig = nuevo;
    C->fin = C->fin->sig;
}

T principio(Cabezal C){
    return C->inicio->sig->dato;
}

bool colaVacia(Cabezal C){
    return C->inicio->sig == NULL;
}

void eliminarCola(Cabezal & C){
    Cola aux = C->inicio;
    while(aux != NULL){
        Cola borrar = aux;
        aux = aux->sig;
        delete borrar;
    }
    delete C;
}