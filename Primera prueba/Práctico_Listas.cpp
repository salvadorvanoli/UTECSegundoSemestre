#include <iostream>
using namespace std;

struct nodo{
    int info;
    nodo* sig;
};

typedef nodo* Lista; //Alias: es como establecer un nodo*, pero podemos simplemente establecer "Lista nombre-variable"

// Imprime una lista

void imprimir_recursivo (Lista L){
    if(L==NULL){
        cout << "#";
    } else {
        cout << "| " << L->info << " | -";
        imprimir_recursivo(L->sig);
    }
}

// Crear una lista con punteros

nodo* crearNProfe2(int n){
    nodo* res = NULL;
    nodo* aux;
    int i = 1;
    while(i<=n){
        aux = new nodo;
        aux->info = i++;
        aux->sig = res;
        res = aux;
    }
    return res;
}

nodo* crearNOrdenado(int n){
    nodo* L = new nodo;
    nodo* aux = L;
    L->info = 1;
    for(int i=2; i<=n; i++){
        L->sig = new nodo;
        L = L->sig;
        L->info = i;
    }
    L->sig=NULL;
    return aux;
}

// ultimo debe devolver el último valor de una lista

int ultimo (Lista L){
    while(L->sig != NULL){
        L = L->sig;
    }
    return L->info;
}

// promedio: dada una lista no vacía, retorna el promedio de sus elementos
// precondición: no introducir una lista vacía, sino explota (0/0)

float promedio(Lista L){
    float total = 0;
    int cant = 0;
    while(L != NULL){
        total += L->info;
        cant++;
        L = L->sig;
    }
    return total/cant;
}

// insOrden: dados un entero x y una lista L ordenada: inserta x en L ordenadamente. Comparar con la solución recursiva.

void insOrden(Lista & L, int x){
    Lista A = L;
    Lista B = L;
    while(A->info > x && A != NULL){
        if(A->info == x){
            return;
        }
        B = A;
        A = A->sig;
    }
    nodo * nuevo = new nodo;
    B->sig = nuevo;
    nuevo->info = x;
    nuevo->sig = A;
    imprimir_recursivo(L);
    cout << "Valor actual de L: " << L->info << endl;
}

void insOrdenProfe(Lista & L, int x){
    Lista nuevo = new nodo;
    nuevo->info = x;
    if(L==NULL || x>L->info){
        nuevo->sig=L;
        L=nuevo;
    } else {
        Lista aux = L;
        while(aux->sig != NULL && aux->sig->info > x){
            aux = aux->sig;
        }
        nuevo->sig = aux->sig;
        aux->sig = nuevo;
    }
    imprimir_recursivo(L);
}

void insOrdenProfe2(Lista & L, int x){
    Lista nuevo = new nodo;
    nuevo->info = x;
    if(L==NULL || x>L->info){
        nuevo->sig=L;
        L=nuevo;
    } else {
        Lista aux = L;
        while(aux->sig != NULL && aux->sig->info > x){
            aux = aux->sig;
        }
        nuevo->sig = aux->sig;
        aux->sig = nuevo;
    }
    imprimir_recursivo(L);
}

void insOrdenRecursivoProfe(Lista & L, int x){
    if(L == NULL || L->info < x){
        Lista nuevo = new nodo;
        nuevo->info = x;
        nuevo->sig = L;
        L = nuevo;
    } else {
        insOrdenRecursivoProfe(L->sig, x);
    }
}

// dados un entero x y una lista L, inserta x al final de L

void insFinal (Lista & L, int x){
    Lista A = L;
    while(A->sig != NULL){
        A = A->sig;
    }
    nodo * nuevo = new nodo;
    nuevo->info = x;
    nuevo->sig = NULL;
    A->sig = nuevo;
}

// removerTodos: dados un entero x y una lista L, remueve a x de L

void removerTodos(Lista & L, int x){
    Lista copia = L;
    while(copia->sig != NULL && copia->sig->info != x){
        copia=copia->sig;
    }
    Lista aux = copia->sig;
    copia->sig=copia->sig->sig;
    delete aux;
}

void removerTodos2(Lista & L, int x){
    Lista copia = L;
    while(copia->sig != NULL){
        if(copia->sig->info == x){
            Lista aux = copia->sig; 
            copia->sig=copia->sig->sig;
            delete aux;
        }
        copia=copia->sig;
    }
}

void removerTodosProfe(Lista & L, int x){
    Lista borrar;
    while(L != NULL && L->info == x){
        borrar = L;
        L = L->sig;
        delete borrar;
    }
    Lista aux = L;
    while(aux != NULL && aux->sig != NULL){
        if(aux->sig->info == x){
            borrar = aux->sig;
            aux->sig = borrar->sig;
            delete borrar;
        } else {
            aux = aux->sig;
        }
    }
}

void removerTodosRecursivo(Lista & L, int x){
    if(L != NULL){
        if(L->info == x){
            Lista borrar = L;
            L = L->sig;
            delete borrar;
            removerTodosRecursivo(L, x);
        } else {
            removerTodosRecursivo(L->sig, x);
        }
    }
}

// esSubLista: dadas dos listas l y p, verifica si l esta incluida en p. Una lista l1 está incluida en l2 si
// y sólo sí existen dos listas, l3 y l4, tal que cumplen que l2 = l3 l1 l4. Tenga en cuenta que las listas
// pueden ser vacías

bool esSubLista(Lista L, Lista P){
    Lista grande = L;
    Lista chica = P;
    if (chica == NULL || grande == NULL){
        cout << "Una de las listas introducidas es nula" << endl;
        return false;
    }
    while(grande->info != chica->info && grande->sig != NULL){
        grande = grande->sig;
    }
    while(grande->info == chica->info && grande->sig != NULL){
        grande = grande->sig;
        chica = chica->sig;
    }
    if(chica->sig == NULL){
        return true;
    } else {
        return false;
    }
}

bool esSubListaProfe(Lista L1, Lista L2){
    Lista aux1 = L1;
    Lista aux2 = L2;
    while(L2 != NULL && L1 != NULL){
        if(L1->info == L2->info){
            L1 = L1->sig;
            L2 = L2->sig;
        } else {
            aux1 = L1 = aux1->sig;
            if(L2 != aux2){
                L2 = aux2;
            }
        }
    }
    return (L2 == NULL);
}

bool esSubListaProfeRecursivo(Lista L1, Lista L2){
    if(L2 == NULL){
        return true;
    }
    if(L1 == NULL){
        return false;
    }
    if(L1->info != L2->info){
        return esSubListaProfeRecursivo(L1->sig, L2);
    } else {
        return esSubListaProfeRecursivo(L1->sig, L2->sig) || esSubListaProfeRecursivo(L1->sig, L2);
    }
}

// Operación parcial: tiene precondiciones
// Operación total: no tiene precondiciones

// EJERCICIO 2 EJERCICIO 2 EJERCICIO 2 EJERCICIO 2 EJERCICIO 2 EJERCICIO 2 EJERCICIO 2 EJERCICIO 2 EJERCICIO 2

// primeros: dado un natural i y una lista l, retorna la lista resultado de tomar los primeros i elementos de L

Lista primeros(Lista L, int i){
    if(i==0){
        return NULL;
    }
    Lista ListaNueva = new nodo;
    Lista Leer = ListaNueva;
    ListaNueva->info = L->info;
    L = L->sig;
    while(i>1 && L != NULL){
        nodo * nuevo = new nodo;
        nuevo->info = L->info;
        ListaNueva->sig = nuevo;
        ListaNueva = ListaNueva->sig;
        L = L->sig;
        i--;
    }
    imprimir_recursivo(Leer);
    return Leer;
}

Lista primerosProfe(Lista L, int i){
    Lista res = NULL;
    Lista aux;
    while(L != NULL && i-- > 0){
        if(res == NULL){
            res = new nodo;
            res->info = L->info;
            aux = res;
        } else {
            aux->sig = new nodo;
            aux = aux->sig;
            aux->info = L->info;
        }
        L = L->sig;
    }
    if(res != NULL){
        aux->sig = NULL;
    }
    return res;
}

// sinPrimeros: dado un natural i y una lista l, retorna la lista resultado de eliminar los primeros i elementos de L

Lista sinPrimeros(Lista L, int i){
    Lista ListaNueva = new nodo;
    Lista aux = ListaNueva;
    while(i>0){
        L = L->sig;
        i--;
    }
    while(L != NULL){
        ListaNueva->info = L->info;
        nodo * nuevo = new nodo;
        ListaNueva->sig = nuevo;
        ListaNueva = ListaNueva->sig;
        L = L->sig;
    }
    imprimir_recursivo(aux);
    return aux;
}

Lista sinPrimerosVale(Lista L, int i){
    Lista sinPrimeros = NULL;
    Lista aux = sinPrimeros;
    while(L != NULL && i>0){
        L = L->sig;
        i--;
    }
    while(L != NULL){
        if(sinPrimeros == NULL){
            nodo * temp = new nodo;
            sinPrimeros = temp;
            aux = sinPrimeros;
        }
        sinPrimeros->info = L->info;
        L = L->sig;
        if(L != NULL){
            nodo * temp = new nodo;
            sinPrimeros->sig = temp;
            sinPrimeros = sinPrimeros->sig;
        }
    }
    sinPrimeros->sig = NULL;
    return aux;
}

// intercalado: dadas dos listas ordenadas l y p, genera una lista intercalando ordenadamente ambas listas

Lista intercalado(Lista L, Lista P){
    Lista NuevaLista = new nodo;
    Lista aux = NuevaLista;
    while(L->sig != NULL || P->sig != NULL){
        if(L->sig != NULL && L->info > P->info){
            NuevaLista->info = L->info;
            nodo * nuevo = new nodo;
            NuevaLista->sig = nuevo;
            NuevaLista = NuevaLista->sig;
            L = L->sig;
        }
        if(P->sig != NULL && L->info < P->info){
            NuevaLista->info = P->info;
            nodo * nuevo2 = new nodo;
            NuevaLista->sig = nuevo2;
            NuevaLista = NuevaLista->sig;
            P = P->sig;
        }
    }
    imprimir_recursivo(aux);
    return aux;
}

Lista intercaladoProfe(Lista L1, Lista L2){
    Lista res = new nodo;
    Lista aux = res;
    while((L1 != NULL || L2 != NULL)){
        aux->sig = new nodo;
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

// EJERCICIO 3 EJERCICIO 3 EJERCICIO 3 EJERCICIO 3 EJERCICIO 3 EJERCICIO 3 EJERCICIO 3 EJERCICIO 3 EJERCICIO 3 EJERCICIO 3

struct nodo_doble{
    int info;
    nodo_doble * sig;
    nodo_doble * ant;
};

typedef nodo_doble * ListaDoble;

// listaVacía: retorna una lista vacía

ListaDoble listaVacia(){
    return NULL;
}

// insPrincipio: dados un entero x y una lista L, retorna el resultado de insertar x al principio de L.

ListaDoble insPrincipio(ListaDoble L, int x){
    while(L != NULL && L->ant != NULL){
        L = L->ant;
    }
    ListaDoble nuevo = new nodo_doble;
    nuevo->info = x;
    nuevo->ant = NULL;
    nuevo->sig = L;
    if(L != NULL){
        L->ant = nuevo;
    }
    return nuevo;
}

// esVacia: dada una lista l, verifica si l esta vacía

bool esVaciaDoble(ListaDoble L){
    if(L == NULL && L->sig == NULL && L->ant == NULL){
        return true;
    } else {
        return false;
    }
}

// esElemento: dados un entero x y una lista L, verifica si x pertenece a L

bool esElemento(ListaDoble L, int x){
    ListaDoble aux = L;
    while(aux != NULL){
        if(aux->info == x){
            return true;
        }
        aux = aux->sig;
    }
    aux = L;
    while(aux != NULL){
        if(aux->info == x){
            return true;
        }
        aux = aux->ant;
    }
    return false;
}

// EJERCICIO 4  EJERCICIO 4  EJERCICIO 4  EJERCICIO 4  EJERCICIO 4  EJERCICIO 4  EJERCICIO 4  EJERCICIO 4  EJERCICIO 4  EJERCICIO 4  

// Crea una lista circular ordenada

nodo* crearNCircularOrdenado(int n){
    nodo* res = new nodo;
    nodo* aux = res;
    res->info = 1;
    for(int i=2; i<=n; i++){
        res->sig = new nodo;
        res = res->sig;
        res->info = i;
    }
    res->sig=aux;
    return aux;
}

nodo* crearNCircularRandom(int n){
    srand(time(NULL));
    nodo* res = new nodo;
    nodo* aux = res;
    res->info = 1;
    for(int i=2; i<=n; i++){
        res->sig = new nodo;
        res = res->sig;
        res->info = rand() % 10 + 1;
    }
    res->sig=aux;
    return aux;
}

// Imprime una lista circular

void imprimirCircular (Lista L){
    Lista aux = L->sig;
    cout << "| " << L->info << " | -";
    while(aux != L){
        cout << "| " << aux->info << " | -";
        aux = aux->sig;
    }
    cout << "#";
}

// Verifica si la lista es vacía

bool esVaciaCircular(Lista L){
    if(L == NULL){
        return true;
    }
    return false;
}

// resto: dada una lista l no vacía, retorna la lista sin su primer elemento

Lista restoCircular(Lista & L){
    Lista aux = L;
    Lista borrar = L;
    while(aux->sig != L){
        aux = aux->sig;
    }
    L = L->sig;
    aux->sig = L;
    delete borrar;
    return L;
}

void restoCircularProfe(Lista & L){
    if(L->sig == L){
        delete L;
        L = NULL;
    } else {
        Lista aux = L->sig;
        while(aux->sig != L){
            aux = aux->sig;
        }
        Lista borrar = L;
        aux->sig = borrar->sig;
        L = L->sig;
        delete borrar;
    }
}

// ultimo: dada una lista l no vacía, retorna su último elemento

int ultimoCircular(Lista L){
    Lista aux = L->sig;
    while(aux->sig != L){
        aux = aux->sig;
    }
    return aux->info;
}

// insOrden: dados un entero x y una lista l ordenada, retorna el resultado de insertar x en l ordenadamente

Lista insOrdenCircularYo(Lista L, int x){
    Lista nuevo = new nodo;
    Lista aux = L;
    Lista siguiente = L->sig;
    if(L->info > x){
        while(aux->sig!=L){
            aux = aux->sig;
        }
        aux->sig = nuevo;
        nuevo->sig = L;
        return nuevo;
    }
    while(aux->info < x && aux->sig != L){
        aux = aux->sig;
        siguiente = aux->sig;
    }
    nuevo->sig = siguiente;
    nuevo->info = x;
    aux->sig = nuevo;
    return L;
}

void insOrdenCircularProfe(Lista & L, int x){
    Lista nuevo = new nodo;
    nuevo->info = x;
    if(L == NULL){
        nuevo->sig = nuevo;
        L = nuevo;
        return;
    }
    if(L->info > x){
        nuevo->sig = L->sig;
        L = nuevo;
    }
    Lista aux = L;
    while(aux->sig != L){
        if(aux->sig->info > x){
            nuevo->sig = aux->sig;
            aux->sig = nuevo;
            return;
        }
        aux = aux->sig;
    }
}

// EJERCICIO 5 EJERCICIO 5 EJERCICIO 5 EJERCICIO 5 EJERCICIO 5 EJERCICIO 5 EJERCICIO 5 EJERCICIO 5 EJERCICIO 5 EJERCICIO 5

struct cabezal {
    nodo* primero;
    nodo* actual;
};

typedef cabezal* lista;

lista crearNCabezal(int n){
    if (n == 0){
        return NULL;
    }
    lista L = new cabezal;
    L->primero = new nodo;
    L->primero->info = 1;
    L->actual = L->primero;
    for (int i = 2; i <= n; i++){
        L->actual->sig = new nodo;
        L->actual = L->actual->sig;
        L->actual->info = i;
    }
    L->actual->sig = NULL;
    return L;
}

void imprimirRecursivoCabezal (lista L) {
    if (L->primero == NULL){
        cout << "#" << endl;
    } else {
        cout << "| " << L->primero->info << " | - ";
        imprimir_recursivo (L->primero->sig);
    }
}

// listaVacia: crea una lista vacía.

lista listaVaciaCabezal(){
    lista nuevo = NULL;
    nuevo->primero = NULL;
    nuevo->actual = NULL;
    return nuevo;
}

// inicio: dada una lista l no vacía, coloca la posición actual al inicio de l

void inicioCabezal(lista & L){
    L->actual = L->primero;
}

// siguiente: dada una lista l no vacía, mueve la posición actual al siguiente nodo (elemento). En caso
// de que la posición actual sea el final de la lista, coloca la posición actual al inicio de la lista (tiene un
// comportamiento circular).

void siguienteCabezal(lista L){
    if(L->actual->sig == NULL){
        L->actual = L->primero;
    } else {
        L->actual = L->actual->sig;
    }
}

// insertar: dados un entero x y una lista l, inserta el elemento x luego de la posición actual en la lista.
// La posición actual pasa a ser el elemento (nodo) recién insertado. Si la lista l está vacía, el resultado
// es la lista unitaria que contiene a x, siendo este elemento la posición actual en la lista resultado.

lista insertarCabezal(lista L, int x){
    nodo * nuevo = new nodo;
    nuevo->info = x;
    if(L == NULL){
        L->primero = nuevo;
        L->primero->sig = NULL;
        L->actual = L->primero;
        return L;
    }
    nuevo->sig = L->actual->sig;
    L->actual->sig = nuevo;
    return L;
}

lista insertarCabezalVale (lista L, int x){
    nodo * nuevo = new nodo;
    nuevo->info = x;
    if (L->primero == NULL){
        L->primero = nuevo;
        L->primero->sig = NULL;
        L->actual = L->primero;
        return L;
    }
    if (L->actual->sig == NULL){
        nuevo->sig = NULL;
        L->actual->sig = nuevo;
        return L;
    }
    nuevo->sig = L->actual->sig;
    L->actual->sig = nuevo;
    return L;
}

// elemento: dada una lista l no vacía, retorna el elemento en la posición actual de l.

Lista elementoActual(lista L){
    return L->actual;
}

int main(){
    lista L = crearNCabezal(0);
    imprimirRecursivoCabezal(L);
    cout << endl;
    // Lista M = crearNCircularOrdenado(10);
    // imprimirCircular(M);
    // cout << endl;
    imprimirRecursivoCabezal(insertarCabezal(L, 3));
}