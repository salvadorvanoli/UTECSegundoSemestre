#include <iostream>
using namespace std;

typedef int T;

struct nodoGenerico{
    T dato;
    nodoGenerico * sig;
}

typedef nodoGenerico * nodo;

struct pila{
    nodo cima;
}

typedef pila * Pila;

struct cola{
    
}

typedef cola * Cola;

bool mismosElementos(Pila & p, Cola & c){
    Pila aux = crearPila();
    Pila auxP = p;
    Cola auxC = c;
    while(!esPilaVacia(auxP)){
        apilar(cima(auxP), aux);
        desapilar(auxP);
    };
    while(!esPilaVacia(aux) && !esColaVacia(auxC)){
        if(cima(aux) == frente(auxC)){
            desapilar(aux);
            desencolar(auxC);
        } else {
            destruirCola(c);
            destruirPila(p);
            destruirPila(aux);
            return false;
        }
    }
    if(cima(aux) != frente(auxC)){
        destruirCola(c);
        destruirPila(p);
        destruirPila(aux);
        return false;
    }
    destruirCola(c);
    destruirPila(p);
    destruirPila(aux);
    return true;
}