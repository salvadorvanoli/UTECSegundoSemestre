#include <iostream>
using namespace std;

struct nodoAB{
    int info;
    nodoAB* izq;
    nodoAB* der;
};

typedef nodoAB* AB;

AB cortarArbol (AB & A, int x){
    AB nuevo = NULL;
    if (A == NULL){
        return NULL;
    }
    if(A->izq->info == x){
        AB nuevo = A->izq;
        A->izq = NULL;
        return nuevo;
    }
    if(A->der->info == x){
        AB nuevo = A->der;
        A->der = NULL;
        return nuevo;
    }
    if(A->der != NULL){
        cortarArbol(A->der, x);
    }
    if(A->izq != NULL){
        cortarArbol(A->izq, x);
    }
    return nuevo;
}

struct nodoAG {
    int info;
    nodoAG * pH;
    nodoAG * sH;
};

typedef nodoAG * AG;

int minimo(int x, int y){
    return x;
}

int menor(AG A, int k){
    int res = A->info;
    int min;
    if (A->sH != NULL) {
        min = menor(A->sH, k);
        res = minimo(min, res);
    }
    if (k > 1 && A->pH != NULL) {
        min = menor(A->pH, k-1);
        res = minimo(min, res);
    }
    return res;
}

int main(){
    AB A = new nodoAB;
    
    A->info = 15;
    A->izq = new nodoAB;
    A->der = new nodoAB;
    
    A->izq->info = 13;
    A->izq->izq = new nodoAB;
    A->izq->der = new nodoAB;
    
    A->izq->izq->info = 7;
    A->izq->izq->izq = NULL;
    A->izq->izq->der = NULL;
    
    A->izq->der->info = 14;
    A->izq->der->izq = NULL;
    A->izq->der->der = NULL;
    
    A->der->info = 19;
    A->der->izq = NULL;
    A->der->der = NULL;

    cout << cortarArbol(A, 13) << endl << cortarArbol(A, 13)->izq << endl << cortarArbol(A, 13)->der;
}