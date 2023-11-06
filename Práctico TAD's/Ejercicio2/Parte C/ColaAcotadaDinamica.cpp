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
    int cota;
    int elemsActuales;
};

typedef cabezal * Cabezal;

Cabezal crearCola(int cota){
    Cola nuevo = new cola;
    nuevo->dato = NULL;
    nuevo->sig = NULL;

    Cabezal C = new cabezal;
    C->inicio = nuevo;
    C->fin = nuevo;
    C->cota = cota;
    C->elemsActuales = 0;

    return C;
}

void insertar(Cabezal & C, T dato){
    if(C->cota = C->elemsActuales){
        return;
    }
    Cola nuevo = new cola;
    nuevo->dato = dato;
    nuevo->sig = NULL;
    C->fin->sig = nuevo;
    C->fin = C->fin->sig;
    C->elemsActuales++;
}

T principio(Cabezal C){
    return C->inicio->sig->dato;
}

void quitarElemento(Cabezal & C){
    Cola borrar = C->inicio->sig;
    if(borrar->sig != NULL){
        C->inicio->sig = borrar->sig;
    } else {
        C->inicio->sig == NULL;
    }
    C->elemsActuales--;
    delete borrar;
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