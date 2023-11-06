#include <iostream>
using namespace std;

struct nodoAG{
    int info;
    nodoAG* pH;
    nodoAG* sH;
};

typedef nodoAG * AG;

struct nodoLista{
 int info;
 nodoLista* sig;
};

typedef nodoLista* Lista;

bool esCamino (AG A, Lista L){
    if(A == NULL){
        return false;
    }
    if(A->info == L->info){
        if(L->sig == NULL){
            if(A->pH == NULL){
                return true;
            } else {
                return false;
            }
        } else {
            return esCamino(A->pH, L->sig);
        }
    }
    return esCamino(A->sH, L);
}


int main(){
    Lista L = new nodoLista;
    L->info = 1;
    L->sig = new nodoLista;

    L->sig->info = 3;
    L->sig->sig = NULL;

    AG A = new nodoAG;
    A->info = 1;
    A->sH = NULL;
    A->pH = new nodoAG;

    A->pH->info = 9;
    A->pH->sH = new nodoAG;

    A->pH->sH->info = 3;
    A->pH->sH->pH = NULL;
    A->pH->sH->sH = NULL;

    cout << esCamino(A, L) << endl;
}