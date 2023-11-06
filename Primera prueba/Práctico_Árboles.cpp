#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef unsigned int uint;

struct nodoAB {
    uint elem ;
    nodoAB * izq;
    nodoAB * der;
};

typedef nodoAB * AB;

void mostrarArbol(AB A, string prefix = "", bool isLeft = true) {
    if (A != NULL) {
        cout << prefix;
        cout << (isLeft ? "|-- " : "\\-- ");
        cout << "(" << A->elem << ")" << endl;

        mostrarArbol(A->izq, prefix + (isLeft ? "|   " : "    "), true);
        mostrarArbol(A->der, prefix + (isLeft ? "|   " : "    "), false);
    }
}

AB crearArbolBinario(const vector<uint>& elementos) {
    srand(time(0)); // Inicializar la semilla del generador de números aleatorios
    AB raiz = NULL;

    for (const uint& elem : elementos) {
        AB nuevo = new nodoAB;
        nuevo->elem = elem;
        nuevo->izq = NULL;
        nuevo->der = NULL;

        if (raiz == NULL) {
            raiz = nuevo; // El primer elemento se convierte en la raíz
        } else {
            // Insertar elementos de manera aleatoria en el árbol
            AB actual = raiz;
            AB padre = NULL;
            bool esIzquierdo = true;

            while (actual != NULL) {
                padre = actual;
                esIzquierdo = (rand() % 2 == 0); // Generar 0 o 1 de manera aleatoria

                if (esIzquierdo) {
                    actual = actual->izq;
                } else {
                    actual = actual->der;
                }
            }

            if (esIzquierdo) {
                padre->izq = nuevo;
            } else {
                padre->der = nuevo;
            }
        }
    }

    return raiz;
}

// consArbol: que retorna un árbol no vacío a partir de un natural y otros dos árboles.

AB consArbol(AB izq, AB der, uint x){
    AB nuevo = new nodoAB;
    nuevo->elem = x;
    nuevo->izq = izq;
    nuevo->der = der;
    return nuevo;
}

// contarElems: que recibe un árbol y retorna la cantidad de elementos del mismo

uint contarElems(AB A){
    if(A==NULL){
        return 0;
    } else {
        return 1 + contarElems(A->izq) + contarElems(A->der);
    }
}

// contarHojas: que recibe un árbol y retorna la cantidad de hojas (nodos cuyos ambos subárboles son vacíos) del mismo

uint contarHojas(AB A){
    if(A == NULL){
        return 0;
    } else {
        if(A->izq == NULL && A->der == NULL){
            return 1;
        }
        return contarHojas(A->izq) + contarHojas(A->der);
    }
}

// altura: que recibe un árbol y retorna la altura del mismo. Si el árbol es vacío su altura es 0

uint altura(AB A){
    if(A==NULL){
        return 0;
    } else {
        if(altura(A->izq) > altura(A->der)){
            return 1 + altura(A->izq);
        } else {
            return 1 + altura(A->der);
        }
    }
}

uint alturaMAX(AB A){
    if(A==NULL){
        return 0;
    } else {
        return 1 + max(altura(A->izq), altura(A->der));
    }
}

// copiar: que recibe un árbol y retorna una copia limpia (que no comparte registros de memoria) del mismo.

AB copiarArbol(AB A){
    if(A == NULL){
        return NULL;
    }
    AB nuevo = new nodoAB;
    nuevo->elem = A->elem;
    nuevo->izq = copiarArbol(A->izq);
    nuevo->der = copiarArbol(A->der);
    return nuevo;
}

// liberarArbol: que recibe un árbol y elimina del mismo todos los nodos, liberando la memoria asociada a cada uno de ellos.

void liberarArbol(AB & A){
    if(A != NULL){
        liberarArbol(A->izq);
        liberarArbol(A->der);
        delete A;
        A = NULL;
    }
}

// EJERCICIO 2 EJERCICIO 2 EJERCICIO 2 EJERCICIO 2 EJERCICIO 2 EJERCICIO 2 EJERCICIO 2 EJERCICIO 2 EJERCICIO 2 EJERCICIO 2 EJERCICIO 2 

struct nodoLista {
    uint elem ;
    nodoLista * sig ;
};

typedef nodoLista * Lista ;

nodoLista* crearNOrdenado(int n){
    nodoLista* L = new nodoLista;
    nodoLista* aux = L;
    L->elem = 1;
    for(int i=2; i<=n; i++){
        L->sig = new nodoLista;
        L = L->sig;
        L->elem = i;
    }
    L->sig=NULL;
    return aux;
}


void imprimir_recursivo (Lista L){
    if(L==NULL){
        cout << "#";
    } else {
        cout << "| " << L->elem << " | -";
        imprimir_recursivo(L->sig);
    }
}

Lista insComienzo(uint elem, Lista & L){
    Lista nuevo = new nodoLista;
    nuevo->elem = elem;
    nuevo->sig = L;
    L = nuevo;
    return L;
}

Lista merge(Lista L1, Lista L2){
    if(L1 == NULL){
        return L2;
    }
    Lista aux = L1;
    while(aux->sig != NULL){
        aux = aux->sig;
    }
    aux->sig = L2;
    return L1;
}

// enOrden: que recibe un árbol b y retorna una lista con los elementos de b ordenados según la recorrida en orden de b.

Lista enOrden(AB A){
    if(A == NULL){
        return NULL;
    }
    Lista nueva = new nodoLista;
    if(A->izq != NULL){
        enOrden(A->izq);
    }
    nueva->elem = A->elem;
    nueva->sig = new nodoLista;
    nueva = nueva->sig;
    if(A->der != NULL){
        enOrden(A->der);
    }
    return nueva;
}

Lista enOrdenProfe(AB A){
    if(A == NULL){
        return NULL;
    }
    Lista der = enOrden(A->der);
    Lista L = insComienzo(A->elem, der);
    return merge(enOrden(A->izq), L);
}

// preOrden: que recibe un árbol b y retorna una lista con los elementos de b ordenados según la recorrida en pre orden de b.

// Lista preOrden(AB A){
//     if(A == NULL){
//         return NULL;
//     }

// }

// esCamino: que recibe un árbol b y una lista l, y retorna TRUE si y solo si l es igual a un camino desde la raíz a un hoja de b.

bool esCamino(AB A, Lista L) {
    if (A == NULL && L == NULL) {
        return true;
    }
    if (A == NULL || L == NULL || A->elem != L->elem) {
        return false;
    }
    bool izquierda = esCamino(A->izq, L->sig);
    bool derecha = esCamino(A->der, L->sig);
    return izquierda || derecha;
}


// bool esCamino(AB A, Lista L){
//     if(A->elem != L->elem){
//         return false;
//     }
//     if((A->elem == L->elem) && (A->izq == NULL && A->der == NULL)){
//         return true;
//     }
//     L = L->sig;
//     return esCamino(A->izq, L) || esCamino(A->der, L);
// }

int main(){
    vector<uint> elementos = {1, 2, 3, 1, 1, 2, 3};
    AB A = crearArbolBinario(elementos);

    Lista L = crearNOrdenado(3);
    mostrarArbol(A);
    cout << endl;
    // mostrarArbol(copiarArbol(A));
    // imprimir_recursivo(enOrdenProfe(A));
    imprimir_recursivo(L);
    cout << endl;
    cout << esCamino(A, L);
}