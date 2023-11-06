#include <iostream>
using namespace std;

typedef string T;

struct nodoLista{
    string info;
    nodoLista * sig;
};

typedef nodoLista * ListaString;

struct nodoDelivery{
    ListaString inicio;
    ListaString fin;
    unsigned cantUrgentes;
};

typedef nodoDelivery * TD;

TD crearTD(){
    TD nuevo = new nodoDelivery;
    nuevo->inicio = nuevo->fin = new nodoLista;
    nuevo->cantUrgentes=0;
    nuevo->inicio->info = "";
    nuevo->inicio->sig = NULL;
    nuevo->fin = nuevo->inicio;
    return nuevo;
}

void insertarUrgente(TD & TAD, T elemento){
    ListaString nuevo = new nodoLista;
    nuevo->info = elemento;
    nuevo->sig = TAD->inicio->sig;

    TAD->inicio->sig = nuevo;
    TAD->cantUrgentes++;
}

void insertarNormal(TD & TAD, T elemento){
    ListaString nuevo = new nodoLista;
    nuevo->info = elemento;
    nuevo->sig = NULL;

    TAD->fin->sig = nuevo;
    TAD->fin = TAD->fin->sig;
}

bool esTadVacio(TD TAD){
    return TAD->inicio->sig == NULL;
}

int cantUrgentes(TD TAD){
    return TAD->cantUrgentes;
}

string atenderCliente(TD & TAD){
    ListaString borrar = TAD->inicio->sig;
    string devolver = borrar->info;

    TAD->inicio->sig = TAD->inicio->sig->sig;

    delete borrar;
    return devolver;
}

string atenderClienteProfe(TD & TAD){
    ListaString proximo = TAD->inicio->sig;
    string res = proximo->info;
    TAD->inicio->sig = proximo->sig;
    delete proximo;
    if(TAD->cantUrgentes > 0){
        TAD->cantUrgentes--;
    }
    if(TAD->inicio->sig == NULL){
        TAD->fin = TAD->inicio;
    }
    return res;
}