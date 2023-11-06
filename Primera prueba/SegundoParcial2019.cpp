#include <iostream>
using namespace std;

struct nodoABB{
    int info;
    nodoABB * izq;
    nodoABB * der;
};

typedef nodoABB* ABB; 

struct nodoLista{
    int info;
    nodoLista * sig;
};

typedef nodoLista * Lista;

struct nodoAG {
    int info;
    nodoAG * pH;
    nodoAG * sH;
};

typedef nodoAG * AG; 

int maximo(ABB A){
    ABB aux = A;
    if(A->der != NULL){
        A = A->der;
    }
    return A->info;
}

void insertarComienzo(Lista & L, int dato){
    Lista nodo = new nodoLista;
    nodo->info = dato;
    nodo->sig = L;
    L = nodo;
}

void insertarOrdenadamente(ABB A, int k, Lista & L){
    if(A != NULL){
        if(A->info < k){
            insertarOrdenadamente(A->der, k, L);
            insertarComienzo(L, k);
        }
        insertarOrdenadamente(A->izq, k, L);
    }
}

Lista listaOrdenada(ABB A, int k){
    Lista resultado = NULL;
    if(A != NULL){
        insertarOrdenadamente(A, k, resultado);
    }
    return resultado;
}

int cantHijos(AG A){
    int cont = 0;
    while(A->sH != NULL){
        cont++;
        A = A->sH;
    }
    return cont;
}

bool hijosAcotados (AG A, unsigned int k){
    if(A == NULL){
        return true;
    }
    return (cantHijos(A->pH) <= k) && hijosAcotados(A->sH, k) && hijosAcotados(A->pH, k);
}

int main(){
    ABB A = new nodoABB;
    
    A->info = 15;
    A->izq = new nodoABB;
    A->der = new nodoABB;
    
    A->izq->info = 13;
    A->izq->izq = new nodoABB;
    A->izq->der = new nodoABB;
    
    A->izq->izq->info = 7;
    A->izq->izq->izq = NULL;
    A->izq->izq->der = NULL;
    
    A->izq->der->info = 14;
    A->izq->der->izq = NULL;
    A->izq->der->der = NULL;
    
    A->der->info = 19;
    A->der->izq = NULL;
    A->der->der = NULL;

    maximo(A);
}