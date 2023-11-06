#include <iostream>
using namespace std;

struct nodo_lista{
    int info;
    nodo_lista * sig;
};

typedef nodo_lista* Lista;

struct nodo_ocurrencias{
    int info;
    unsigned cant;
    nodo_ocurrencias* sig;
};

typedef nodo_ocurrencias* ListaOcurrencias;

ListaOcurrencias auxA = NULL;

ListaOcurrencias crear_lista_ocurrencias (Lista L){
    ListaOcurrencias nueva = NULL;
    if(L != NULL){
        nueva = new nodo_ocurrencias;
        nueva->info = L->info;
        auxA = nueva;
        while(L != NULL){
            if(L->info == nueva->info){
                nueva->cant++;
            } else {
                nueva->sig = new nodo_ocurrencias;
                nueva = nueva->sig;
                nueva->info = L->info;
                nueva->cant = 1;
            }
            L = L->sig;
        }
    }
    return auxA;
}

void eliminar_ocurrencias (ListaOcurrencias L, int elem, unsigned cant) {
    while(L->sig->info != elem && L->sig != NULL){
        L = L->sig;
    }
    if(L->sig->cant > cant){
        L->sig->cant = (L->sig->cant - cant);
    } else {
        ListaOcurrencias borrar = L->sig;
        L->sig = borrar->sig;
        delete borrar;
    }
}

bool separados(Lista L){
    if(L == NULL || L->sig == NULL){
        return true;
    }
    if((L->sig->info - L->info) < 2){
        return false;
    }
    return separados(L->sig);
}

int main(){
    Lista L = new nodo_lista;
    Lista aux = L;
    Lista aux2 = L;
    aux->info = 1;
    aux->sig = new nodo_lista;
    aux = aux->sig;

    aux->info = 1;
    aux->sig = new nodo_lista;
    aux = aux->sig;
    
    aux->info = 1;
    aux->sig = new nodo_lista;
    aux = aux->sig;

    aux->info = 2;
    aux->sig = new nodo_lista;
    aux = aux->sig;

    aux->info = 3;
    aux->sig = new nodo_lista;
    aux = aux->sig;

    aux->info = 3;
    aux->sig = new nodo_lista;
    aux = aux->sig;

    aux->info = 4;
    aux->sig = new nodo_lista;
    aux = aux->sig;

    aux->info = 4;
    aux->sig = new nodo_lista;
    aux = aux->sig;

    aux->info = 5;
    aux->sig = NULL;

    cout << separados(L);
    // ListaOcurrencias M = crear_lista_ocurrencias(L);
    // eliminar_ocurrencias(M, 0, 0);
    // cout << "Número: " << auxA->info << endl << "Ocurrencias: " << auxA->cant << endl << endl;
    // while(auxA->sig != NULL){
    //     auxA = auxA->sig;
    //     cout << "Número: " << auxA->info << endl << "Ocurrencias: " << auxA->cant << endl << endl;
    // }
}