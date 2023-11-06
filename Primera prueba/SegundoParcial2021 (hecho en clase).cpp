<include iostream>
using namespace std;

struct nodoAB{
    int info;
    nodoAB* izq;
    nodoAB* der;
}

typedef nodoAB* AB;

// Parte A Parte A Parte A Parte A Parte A Parte A Parte A  

AB cortarArbol(AB & A, int x){
    if(A == NULL){
        return NULL;
    }
    if(A->info == x){
        AB aux = A;
        A = NULL;
        return aux;
    }
    if(A->izq->info == x){
        AB aux = A->izq;
        A->izq = NULL;
        return aux;
    }
    if(A->der->info == x){
        AB aux = A->der;
        A->der = NULL;
        return aux;
    }
    cortarArbol(A->izq, x);
    cortarArbol(A->der, x);
}

AB cortarArbolProfe(AB & A, int x){
    if(A==NULL){
        return NULL;
    }
    AB res;
    if(A->info == x){
        res = a;
        a = NULL;
    } else {
        res = cortarArbol(A->izq, x);
        if(res == NULL){
            res = cortarArbol(A->der, x);
        }
    }
    return res;
}

// Parte B Parte B Parte B Parte B Parte B Parte B Parte B Parte B 

int maxAlturaPerfecto(AB A){
    if(A == NULL){
        return 0;
    }
    if(A->izq == NULL && A->der == NULL){
        return 1;
    }
    if(A->izq != NULL && A->der != NULL){
        return 1 + max(maxAlturaPerfecto(A->izq), maxAlturaPerfecto(A->der));
    } else {
        return 0;
    }
    return min(maxAlturaPerfecto(A->izq), maxAlturaPerfecto(A->der));
}

// LO QUE DEVUELVE ES EL PUNTO HASTA EL QUE ES PERFECTO

int maxAlturaPerfectoProfe(AB A){
    if(A == NULL){
        return 0;
    }
    if(A->izq == NULL || A->der == NULL){
        return 1;
    } else {
        return 1 + min(maxAlturaPerfecto(A->izq), maxAlturaPerfecto(A->der));
    }
}

// EJERCICIO 2 EJERCICIO 2 EJERCICIO 2 EJERCICIO 2 EJERCICIO 2 EJERCICIO 2 EJERCICIO 2 

struct nodoAG{
    int info;
    nodoAG* pH;
    nodoAG* sH;
};

typedef nodoAG* AG;

int menor(AG A, int k){
    if(A == NULL){
        return 0;
    }
    if(k != 0){
        return max(menor(A->pH, k-1), menor(A->sH,k-1));
    } else {
        return 0;
    }
}