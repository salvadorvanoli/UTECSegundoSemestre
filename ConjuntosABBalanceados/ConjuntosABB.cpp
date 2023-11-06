#include <iostream>
using namespace std;

struct ABB{

};


void insertar(ABB & A, ABB B){
    if(A->dato < B->dato){
        insertar(A->izq, B);
    }
    if(A->dato > B->dato){
        insertar()
    }
}

ABB unionABB(ABB A, ABB B){
    if(B == NULL){
        return NULL;
    }
    insertar(A, B);
    A = unionABB(A, B->izq);
    A = unionABB(A, B->der);
    return A;
}

ABB interseccionABB(ABB A, ABB B){

}
