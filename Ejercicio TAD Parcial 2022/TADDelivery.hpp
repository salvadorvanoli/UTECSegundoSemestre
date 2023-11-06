#include <iostream>
using namespace std;

typedef int T;

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

// Crea la estructura TAD, con ambas representaciones vacías
// Precondiciones: no tiene

TD crearTD();

// Apila un elemento en la representación Pila del Delivery
// Precondiciones: debe existir el TAD y el elemento no puede ser nulo

void insertarUrgente(TD &, T elemento);

// Encola un elemento en la representación Cola del Delivery
// Precondiciones: debe existir el TAD y el elemento no puede ser nulo

void insertarNormal(TD &, T elemento);

// Devuelve true si el TAD está vacío
// Precondiciones: debe existir el TAD

bool esTadVacio(TD);

// Devuelve la cantidad de elementos urgentes del TAD
// Precondiciones: debe existir el TAD

int cantUrgentes(TD);

// Devuelve y elimina el siguiente elemento a ser atendido
// Precondiciones: debe existir el TAD y no debe estar vacío

nodoLista atenderCliente(TD &);