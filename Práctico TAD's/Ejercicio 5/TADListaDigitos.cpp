#include "TADListaDigitos.hpp"
#include <iostream>
#include <cassert>
using namespace std;

typedef unsigned int Digito;

struct listaDigito{
    Digito dato;
    listaDigito * sig;
};

typedef listaDigito * LDig;

/* Retorna una lista de dígitos resultado de la suma de las pasadas por parámetro */

LDig invertirLista(LDig L){
    if(L == NULL){
        return NULL;
    }

}

LDig suma(LDig L1, LDig L2){
    LDig resultadoInverso = null();
    LDig aux = resultadoInverso;
    if(head(L1) + head(L2) > 9){
        cons(1, resultadoInverso);
        cons(head(L1) + head(L2) - 10, resultadoInverso);
        L1 = tail(L1);
        L2 = tail(L2);
    }
    while(!empty(L1) && !empty(L2)){
        if(head(L1) + head(L2) > 9){
            resultadoInverso->dato++;
            cons(head(L1) + head(L2) - 10, resultadoInverso);
        } else {
            cons(head(L1) + head(L2), resultadoInverso);
        }
        L1 = tail(L1);
        L2 = tail(L2);
    }
    return aux;
}