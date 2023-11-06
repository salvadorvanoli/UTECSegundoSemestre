#include <iostream>
using namespace std;

struct nodo_lista{
    int info;
    nodo_lista * sig;
};

struct nodo_ocurrencias{
    int info;
    unsigned cant;
    nodo_ocurrencias * sig;
};

typedef nodo_Lista * Lista;
typedef nodo_ocurrencias * ListaOcurrencias;

// Parte A Parte A Parte A Parte A Parte A Parte A Parte A Parte A 

ListaOcurrencias crear_lista_ocurrencias(Lista L){
    if(L->sig == NULL){
        return NULL;
    }
    ListaOcurrencias L2 = new nodo_ocurrencias;
    L2->info = NULL;
    L2->cant = NULL;
    ListaOcurrencias aux = L2;
    while(L->sig){
        L = L->sig;
        if(L->info == L2->info){
            L->cant++;
        } else {
            L2->sig = new nodo_ocurrencias;
            L2 = L2->sig;
            L2->info = L->info;
            L2->cant = 1;
        }
    }
    return aux;
}

ListaOcurrencias crear_lista_ocurrencias(Lista L){
    ListaOcurrencias res = new nodo_ocurrencias;
    res->sig = NULL;
    if(L->sig = NULL){
        return res;
    }
    ListaOcurrencias aux = res;
    aux->sig = new nodo_ocurrencias;
    aux = aux->sig;
    L = L->sig;
    aux->info = L->info;
    aux->cant = 1;
    while(L->sig != NULL){
        L = L->sig;
        if(L->info != aux->info){
            aux->sig = new nodo_ocurrencias;
            aux = aux->sig;
            aux->info = L->info;
            aux->cant = 1;
        } else {
            aux->cant++;
        }
    }
}

// Parte B Parte B Parte B Parte B Parte B Parte B Parte B Parte B 

void eliminar_ocurrencias(ListaOcurrencias L, int elem, unsigned cant){
    if(L == NULL){
        return NULL;
    }
    while(L->sig->info != elem && L->sig != NULL){
        L = L->sig;
    }
    if(L->sig == NULL){
        return;
    }
    if(L->sig->cant > cant){
        L->sig->cant -= cant;
    } else {
        ListaOcurrencias aux = L->sig->sig;
        delete L->sig;
        L->sig = aux;
    }
}

void eliminar_ocurrenciasProfe(ListaOcurrencias L, int elem, unsigned cant){
    while(L->sig != NULL && L->sig->info < elem){
        L = L->sig;
    }    
    if(L->sig != NULL){
        if(cant >= L->sig->cant){
            ListaOcurrencias borrar = L->sig;
            L->sig = borrar->sig;
            delete borrar;
        } else {
            L->sig->cant = L->sig->cant - cant;
        }
    }
}

// EJERCICIO 2 EJERCICIO 2 EJERCICIO 2 EJERCICIO 2 EJERCICIO 2 EJERCICIO 2 

bool separados(Lista L){
    if(L == NULL){
        return true;
    }
    if((L->sig->info - L->info) >= 2){
        return separados(L->sig);
    } else {
        return false;
    }
}

bool separados(Lista L){
    if(L == NULL){
        return true;
    }
    if((L->sig->info - L->info) < 2){
        return false;
    }
    separados(L->sig);
}