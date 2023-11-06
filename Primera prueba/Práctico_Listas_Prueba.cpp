#include <iostream>
using namespace std;

struct nodoLista{
    int info;
    nodoLista* sig;
};

typedef nodoLista* Lista;

Lista ultimo(Lista L){
    while(L->sig != NULL){
        L = L->sig;
    }
    return L;
}

void imprimir_recursivo (Lista L){
    if(L==NULL){
        cout << "#";
    } else {
        cout << "| " << L->info << " | -";
        imprimir_recursivo(L->sig);
    }
}

nodoLista* crearNOrdenado(int n){
    nodoLista* L = new nodoLista;
    nodoLista* aux = L;
    L->info = 1;
    for(int i=2; i<=n; i++){
        L->sig = new nodoLista;
        L = L->sig;
        L->info = i;
    }
    L->sig=NULL;
    return aux;
}

int promedio(Lista L){
    int total = 0;
    int cantElem = 0;
    while(L->sig != NULL){
        total += L->info;
        cantElem++;
        L = L->sig;
    }
    return total/cantElem;
}

void insOrden(Lista & L, int x){
    if(L == NULL){
        return;
    }
    Lista insertar = new nodoLista;
    insertar->info = x;
    Lista aux = L;
    while(aux->sig != NULL && aux->sig->info < x){
        aux = aux->sig;
    }
    insertar->sig = aux->sig->sig;
    aux->sig = insertar;
}

void insFinal(Lista & L, int x){
    if(L == NULL){
        L = new nodoLista;
        L->info = x;
        L->sig = NULL;
    }
    Lista aux = L;
    while(aux->sig != NULL){
        aux = aux->sig;
    }
    aux->sig = new nodoLista;
    aux->sig->info = x;
    aux->sig->sig = NULL;
}

void removerTodos(Lista L, int x){
    if(L == NULL || L->info == x){
        L = NULL;
        return;
    }
    Lista aux = L;
    while(aux->sig != NULL && aux->sig->info != x){
        aux = aux->sig;
    }
    Lista borrar = aux->sig;
    aux->sig = borrar->sig;
    delete borrar;
}

bool esSubLista(Lista L, Lista P){
    if(L == NULL){
        return true;
    }
    if(P == NULL){
        return false;
    }
    Lista auxL = L;
    Lista auxP = P;
    while(auxP != NULL && auxP->info != auxL->info){
        auxP = auxP->sig;
    }
    while(auxL != NULL){
        if(auxL->info != auxP->info || (auxP == NULL && auxL != NULL)){
            return false;
        }
        auxL = auxL->sig;
    }
    return true;
}

// Ejercicio 2

Lista primeros(Lista L, int x){
    if(L == NULL){
        return NULL;
    }
    if(x == 0){
        return NULL;
    }
    Lista aux = L;
    Lista nueva = new nodoLista;
    Lista auxN = nueva;
    while(aux != NULL && x>0){
        x--;
        nueva->info = aux->info;
        if(x != 0 && aux->sig != NULL){
            nueva->sig = new nodoLista;
            nueva = nueva->sig;
        }
        aux = aux->sig;
    }
    nueva->sig = NULL;
    return auxN;
}

Lista sinPrimeros(Lista L, int x){
    if(L == NULL){
        return NULL;
    }
    Lista nueva = new nodoLista;
    Lista aux = L;
    Lista auxN = nueva;
    while(x>0 && aux->sig != NULL){
        x--;
        aux = aux->sig;
    }
    if(aux->sig == NULL && x>0){
        return NULL;
    }
    while(aux != NULL){
        nueva->info = aux->info;
        if(aux->sig != NULL){
            nueva->sig = new nodoLista;
            nueva = nueva->sig;
        }
        aux = aux->sig;
    }
    nueva->sig = NULL;
    return auxN;
}

Lista intercalado(Lista L1, Lista L2){
    Lista res = new nodoLista;
    Lista aux = res;
    while((L1 != NULL || L2 != NULL)){
        aux->sig = new nodoLista;
        aux = aux->sig;
        if((L1 == NULL) || (L2 != NULL && L1->info > L2->info)){
            aux->info = L2->info;
            L2 = L2->sig;
        } else {
            aux->info = L1->info;
            L1 = L1->sig;
        }
    }
    aux->sig = NULL;
    Lista borrar = res;
    res = res->sig;
    delete borrar;
    return res;
}

Lista concatenacion(Lista L, Lista P){
    Lista nueva = new nodoLista;
    Lista auxN = nueva;
    while(L != NULL){
        nueva->info = L->info;
        if(L->sig != NULL || P != NULL){
            nueva->sig = new nodoLista;
            nueva = nueva->sig;
        }
        L = L->sig;
    }
    while(P != NULL){
        nueva->info = P->info;
        if(P->sig != NULL){
            nueva->sig = new nodoLista;
            nueva = nueva->sig;
        }
        P = P->sig;
    }
    nueva = NULL;
    return auxN;
}

int main(){
    Lista L = crearNOrdenado(4);
    imprimir_recursivo(L);
    Lista M = crearNOrdenado(4);
    cout << endl;
    Lista P = intercalado(L, M);
    imprimir_recursivo(P);
}