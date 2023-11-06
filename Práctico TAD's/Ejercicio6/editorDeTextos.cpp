#include <iostream>
using namespace std;

typedef char T;

struct nodoGenerico{
    T dato;
    nodoGenerico * sig;
}

typedef nodoGenerico * nodo;

struct pila{
    nodo cima;
}

typedef pila * Pila;

void mensaje(Lista l){
    Pila p = crearPila();
    while(!esListaVacia(l)){
        apilar(l->dato, p);
        l = l->sig;
    }

    string res;
    int cont = 0;

    while(!esPilaVacia(p)){
        while(p->dato == '#'){
            desapilar(p);
            cont++;
        }
        while(cont>0){
            if(p->dato == '#'){
                cont++;
            }
            if(p->dato == '@'){
                break;
            }
            desapilar(p);
            cont--;
        }
        if(p->dato == '@'){
            while(!esPilaVacia(p)){
                desapilar(p);
            }
        }
        if(!esPilaVacia(p)){
            res += p->dato;
        }
    }
    cout << res << endl;
    return;
}