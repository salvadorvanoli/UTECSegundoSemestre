#include "TADDeque.hpp"
#include <iostream>
#include <cassert>
using namespace std;

typedef int T;

struct nodoCola{
    T dato;
    nodoCola->sig;
    nodoCola->ant;
};

typedef nodoCola * C;

struct Deque{
    C inicio;
    C fin;
}

typedef Deque * Di;

Di crearDeque(){
    C nuevaCola = new nodoCola;
    nuevaCola->dato = NULL;
    nuevaCola->sig = NULL;
    nuevaCola->ant = NULL;
    Di nuevoDeque = new Deque;
    nuevoDeque->inicio = nuevaCola;
    nuevoDeque->fin = nuevaCola;
    return D;
}

void insertarNodoAlFinal(Di & D, T elem){
    C nuevo = new nodoCola;
    nuevo->dato = elem;
    nuevo->sig = NULL;
    nuevo->ant = D->fin;
    D->fin->sig = nuevo;
    D->fin = D->fin->sig;
}

void insertarNodoAlInicio(Di & D, T elem){
    C nuevo = new nodoCola;
    nuevo->dato = elem;
    nuevo->ant = D->inicio;
    if(D->inicio->sig == NULL){
        nuevo->sig = NULL;
        D->inicio->sig = nuevo;
        return;
    } else {
        nuevo->sig = D->inicio->sig;
        nuevo->sig->ant = nuevo;
        D->inicio->sig = nuevo;
        return;
    }
}

void quitarNodoFinal(Di & D){
    C borrar = D->fin;
    D->fin = D->fin->ant;
    D->fin->sig = NULL;
    delete borrar;
}

void quitarNodoInicio(Di & D){
    C borrar = D->inicio->sig;
    if(D->inicio->sig == NULL){
        D->inicio->sig = NULL;
    } else {
        D->inicio->sig = borrar->sig;
        D->inicio->sig->ant = D->inicio;
    }
    delete borrar;
}

Di obtenerInicio(Di & D){
    return D->inicio->sig;
}

Di obtenerFinal(Di & D){
    return D->fin;
}

bool esDequeVacio(Di & D){
    return D->inicio->sig == NULL;
}