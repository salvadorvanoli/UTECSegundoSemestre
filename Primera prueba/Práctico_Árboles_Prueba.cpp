#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>
using namespace std;

typedef unsigned int uint;

struct nodoAB{
    uint elem ;
    nodoAB* izq;
    nodoAB* der;
};

typedef nodoAB* AB;

AB consArbol(AB izq, AB der, int x){
    AB A = new nodoAB;
    A->elem = x;
    A->izq = izq;
    A->der = der;
    return A;
}

int contarElems(AB A){
    if(A == NULL){
        return 0;
    }
    return 1 + contarElems(A->izq) + contarElems(A->der);
}

int contarHojas(AB A){
    if(A == NULL){
        return 0;
    }
    if(A->izq == NULL && A->der == NULL){
        return 1;
    }
    return contarHojas(A->izq) + contarHojas(A->der);
}

int altura(AB A){
    if(A == NULL){
        return 0;
    }
    return 1 + max(altura(A->izq), altura(A->der));
}

AB copiar(AB A){
    if(A == NULL){
        return;
    }
    AB nuevo = new nodoAB;
    nuevo->elem = A->elem;
    nuevo->izq = copiar(A->izq);
    nuevo->der = copiar(A->der);
    return nuevo;
}

void liberarArbol(AB A){
    if(A == NULL){
        return;
    }
    liberarArbol(A->izq);
    liberarArbol(A->der);
    delete A;
    A = NULL;
}

// EJERCICIO 2

struct nodoLista {
    uint elem;
    nodoLista* sig ;
};

typedef nodoLista* Lista ;

// TERCERA PARTE: AG

struct nodoAG{
    int dato;
    nodoAG* pH;
    nodoAG* sH;
};

typedef nodoAG* AG;

AG arbolHoja(int x){
    AG nuevo = new nodoAG;
    nuevo->dato = x;
    nuevo->pH = NULL;
    nuevo->sH = NULL;
    return nuevo;
}

bool esArbolHoja(AG A){
    return A->pH == NULL;
}

bool pertenece(AG A, int x){
    if(A == NULL){
        return false;
    }
    if(A->dato == x){
        return true;
    }
    return (pertenece(A->sH, x) || pertenece(A->pH, x));
}

void insertar(AG A, int h, int p){
    if(A->dato != h){
        if(A == NULL){
            return;
        }
        if(A->dato == p){
            AG temp = A->pH;
            A->pH = new nodoAG;
            A->pH->dato = h;
            A->pH->sH = temp;
            A->pH->pH = NULL;
        }
        insertar(A->sH, h, p);
        insertar(A->pH, h, p);
    }
}