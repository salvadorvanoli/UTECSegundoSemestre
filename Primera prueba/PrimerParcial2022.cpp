#include <iostream>
using namespace std;

struct nodoLista{
 int info;
 nodoLista * sig;
};

typedef nodoLista * Lista;

struct nodoABB {
 int info;
 nodoABB * izq;
 nodoABB * der;
};

typedef nodoABB * ABB;

void juntarRepetidos(Lista L) {
    Lista aux = L, pivot;
    while (aux->sig != NULL) {
        if (aux->sig->info == L->info) {
            L = L->sig;
            aux = L;
        }
        else {
            pivot = aux->sig;
            while (pivot->sig != NULL) {
                if (pivot->sig->info != L->info)
                    pivot = pivot->sig;
                else {
                    aux = pivot->sig;
                    pivot->sig = aux->sig;
                    aux->sig = L->sig;
                    L->sig = aux;
                }
            }
            L = aux->sig;
            aux = L;
        }
    }
}

bool estaEnNivel (ABB A, int elem, int h){
    if(A == NULL){
        return false;
    }
    if(h == 1 && A->info != elem){
        return false;
    }
    if(h == 1 && A->info == elem){
        return true;
    }
    if(A->info > elem){
        return estaEnNivel(A->izq, elem, (h-1));
    } else {
        return estaEnNivel(A->der, elem, (h-1));
    }
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
    
    cout << estaEnNivel(A, 14, 2) << endl;

    // Lista L = new nodoLista;
    // Lista aux = L;
    
    // aux->info = 3;
    // aux->sig = new nodoLista;
    // aux = aux->sig;
    
    // aux->info = 1;
    // aux->sig = new nodoLista;
    // aux = aux->sig;
    
    // aux->info = 3;
    // aux->sig = new nodoLista;
    // aux = aux->sig;
    
    // aux->info = 3;
    // aux->sig = new nodoLista;
    // aux = aux->sig;
    
    // aux->info = 6;
    // aux->sig = new nodoLista;
    // aux = aux->sig;
    
    // aux->info = 1;
    // aux->sig = new nodoLista;
    // aux = aux->sig;
    
    // aux->info = 2;
    // aux->sig = new nodoLista;
    // aux = aux->sig;
    
    // aux->info = 2;
    // aux->sig = NULL;
    
    // juntarRepetidos(L);
    
    // for(int i=0; i<10; i++){
    //     cout << " | " << L->info << endl;
    //     L = L->sig;
    // }
}