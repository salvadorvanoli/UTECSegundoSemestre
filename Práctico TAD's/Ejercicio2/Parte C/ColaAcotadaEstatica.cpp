#include "ColaAcotadaEstatica.hpp"
#include <iostream>
#include <cassert>
#define MAX_ARRAY 100
using namespace std;

typedef int T;

struct colaEstatica{
    int array[MAX_ARRAY];
    int cota;
    int cantActual;
};

typedef colaEstatica * Cola;

Cola crearCola(int cota){
    Cola nuevo = new colaEstatica;
    nuevo->cota = cota;
    nuevo->cantActual = 0;
    return nuevo;
}

void insertar(Cola & C, T dato){
    if(C->cota <= C->cantActual){
        return;
    }
    C->array[C->cantActual+1] = dato;
    C->cantActual++;
}

T principio(Cola & C){
    return C->array[0];
}

void quitarElemento(Cola & C){
    C->cantActual--;
}

bool colaVacia(Cola & C){
    return C->array[C->cantActual] == NULL;
}

void eliminarCola(Cola & C){
    delete C;
}