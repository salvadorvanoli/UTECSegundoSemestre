#include <iostream>
using namespace std;

struct nodo {
    int info ;
    nodo * sig ;
};

typedef nodo * Lista ; // Alias: es como establecer un nodo *, pero podemos simplemente establecer "Lista nombre-variable"

void imprimir_recursivo (Lista L) {
    if (L == NULL){
        cout << "#" << endl;
    } else {
        cout << "| " << L->info << " | - ";
        imprimir_recursivo (L->sig);
    }
}

nodo * crearN (int n){
    nodo * res = new nodo;
    nodo * aux = res;
    res->info = n;
    for (n=n-1; n >= 1; n--){
        res->sig = new nodo;
        res = res->sig;
        res->info = n;
    }
    res->sig = NULL;
    return aux;
}

nodo * crearNOrdenado (int n){
    nodo * res = new nodo;
    nodo * aux = res;
    res->info = 1;
    for (int i=2; i <= n; i++){
        res->sig = new nodo;
        res = res->sig;
        res->info = i;
    }
    res->sig = NULL;
    return aux;
}

// Ejercicio 1:

// Mostrar el ultimo elemento de la lista:

int ultimo(Lista L){
    while((L->sig) != NULL){
        L = L->sig;
    }
    cout << "Valor del ultimo elemento: " << L->info << endl;
    return L->info;
}

// Hacer un promedio de la lista:

float promedio(Lista L){
    float suma=0;
    int divisor=0;
    while(L != NULL){
        suma += L->info;
        L = L->sig;
        divisor++;
    }
    cout << "El promedio es de: " << suma/divisor << endl;
    return suma/divisor;
}

// Insertar x en una lista y ordenarla:

void insOrden (Lista & L, int x){
    Lista A = L;
    Lista B = L;
    if (L->info <= x){
        Lista primero = new nodo;
        L->sig = primero;
        primero->info = x;
        primero->sig = A;
        return;
    }
    while (A != NULL && A->info > x){
        B = A;
        A = A->sig;
    }
    Lista nuevo = new nodo;
    B->sig = nuevo;
    nuevo->info = x;
    nuevo->sig = A;
}

// Solucion del profe:

void insOrdenProfe (Lista & L, int x){
    Lista nuevo = new nodo;
    nuevo->info = x;
    if (L == NULL || x > L->info){
        nuevo->sig = L;
        L = nuevo;
    } else {
        Lista aux = L;
        while (aux->sig != NULL && aux->sig->info > x){
            aux = aux->sig;
        }
        nuevo->sig = aux->sig;
        aux->sig = nuevo;
    }
}

void insOrdenRecursivo (Lista & L, int x){
    if (L == NULL || L->info < x){
        Lista nuevo = new nodo;
        nuevo->info = x;
        nuevo->sig = L;
        L = nuevo;
    } else {
        insOrdenRecursivo(L->sig, x);
    }
}

// Insertar x al final de una lista:

void insFinal (Lista & L, int x){
    Lista copia = L;
    while (copia->sig != NULL){
        copia = copia->sig;
    }
    nodo * nuevo = new nodo;
    nuevo->info = x;
    copia->sig = nuevo;
    nuevo->sig = NULL;
}

// Remover x de L:

void removerTodos1 (Lista & L, int x){
    Lista copia = L;
    while (copia->sig != NULL || copia->sig->info != x){
        copia = copia->sig;
    }
    Lista aux = copia->sig;
    copia->sig = copia->sig->sig;
    delete aux;
}

void removerTodos2 (Lista & L, int x){
    Lista copia = L;
    while (copia->sig != NULL){
        if (copia->sig->info == x){
            Lista aux = copia->sig;
            copia->sig = copia->sig->sig;
            delete aux;
        }
        copia = copia->sig;
    }
}

// Solución del profe:

void removerTodosProfe (Lista & L, int x){
    Lista borrar;
    while (L != NULL && L->info == x){
        borrar = L;
        L = L->sig;
        delete borrar;
    }
    Lista aux = L;
    while (aux != NULL && aux->sig != NULL){
        if (aux->sig->info == x){
            borrar = aux->sig;
            aux->sig = borrar->sig;
            delete borrar;
        } else {
            aux = aux->sig;
        }
    }
}

void removerTodosRecursivo (Lista & L, int x){
    if (L != NULL){
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

// Verifica si una lista esta incluida en otra:

bool esSubLista (Lista Grande, Lista Chica){
    Lista aux1 = Grande;
    Lista aux2 = Chica;
    while (aux1 != NULL && aux2 != NULL){
        aux1 = aux1->sig;
        aux2 = aux2->sig;
        
        if (aux1->info != aux2->info){
            cout << "NO ESTA CONTENIDA!!!" << endl;
            return false;
        }
    }
    return (aux2 == NULL);
}

bool esSubListaProfe (Lista L1, Lista L2){
    Lista aux1 = L1;
    Lista aux2 = L2;
    while (L2 != NULL && L1 != NULL){
        if (L1->info == L2->info){
            L1 = L1->sig;
            L2 = L2->sig;
        } else {
            aux1 = L1 = aux1->sig;
            if (L2 != aux2){
                L2 = aux2;
            }
        }
    }
    return (L2 == NULL);
}

bool esSubListaRecursivo (Lista L1, Lista L2){
    if (L2 == NULL){
        return true;
    }
    if (L1 == NULL){
        return false;
    }
    if (L1->info != L2->info){
        return esSubListaRecursivo (L1->sig, L2);
    } else {
        return esSubListaRecursivo (L1->sig, L2->sig) || esSubListaRecursivo (L1->sig, L2);
    }
}


// Ejercicio 2: 

// Parte a: obtener lista con i primeros elementos de lista original



Lista primeros (int n, Lista L){
    Lista primeros = NULL;
    Lista final = primeros;
    if (n==0){
        return final;
    }
    for (n=n; n>0; n--){
        if (primeros == NULL){
            primeros = new nodo;
            final = primeros;
        }
        primeros->info = L->info;
        if (n != 1){
            nodo * temp = new nodo;
            primeros->sig = temp;
            primeros = primeros->sig;
            L = L->sig;
        }
    }
    return final;
}



// Parte b: sinPrimeros

Lista sinPrimeros(int i, Lista L){
    Lista sinPrimeros = NULL;
    Lista aux = sinPrimeros;
    while (L != NULL && i > 0){
        L = L->sig;
        i--;
    }
    while (L != NULL){
        if (sinPrimeros == NULL){
            nodo * temp = new nodo;
            sinPrimeros = temp;
            aux = sinPrimeros;
        }
        sinPrimeros->info = L->info;
        L = L->sig;
        if (L != NULL){
            nodo * temp = new nodo;
            sinPrimeros->sig = temp;
            sinPrimeros = sinPrimeros->sig;
        }
    }
    sinPrimeros->sig = NULL;
    return aux;
}

// Parte c: listas intercaladas

Lista intercalado (Lista A, Lista B){
    Lista nueva = NULL;
    Lista aux = nueva;
    while (A != NULL || B != NULL){
        if (nueva == NULL){
            nodo * temp = new nodo;
            nueva->sig = temp;
            nueva = nueva->sig;
            aux = nueva;
        }
        if (A != NULL){
            nueva->info = A->info;
            A = A->sig;
            nodo * temp = new nodo;
            nueva->sig = temp;
            nueva = nueva->sig;
        }
        if (B != NULL){
            nueva->info = B->info;
            B = B->sig;
            nodo * temp = new nodo;
            nueva->sig = temp;
            nueva = nueva->sig;
        }
    }
    nueva = NULL;
    return aux;
}

// Solucion del profe:

/*
Lista intercaladoProfe (Lista L1, Lista L2){
    Lista res = new nodo;
    Lista aux = res;
    while (L1 != NULL || L2 != NULL){
        aux->sig = new nodo;
        aux = aux->sig;
        if ((L1 == NULL) || (L2 != NULL && L1->info > L2->info)){
            aux->info = L2->info;
            L2 = L2->sig;
        }
    }
}
*/

// Ejercicio 3: Listas dobles

struct nodo_doble {
    int info;
    nodo_doble * sig;
    nodo_doble * ant;
};
typedef nodo_doble * ListaDoble;

// listaVacia: retorna una lista vacía.

ListaDoble listaVacia(){
    return NULL;
}

// insPrincipio: dados un entero x y una lista l, retorna el resultado de insertar x al principio de l.

ListaDoble insPrincipio(int x, ListaDoble L){
    while (L != NULL && L->ant != NULL){
        L = L->ant;
    }
    ListaDoble nuevo = new nodo_doble;
    nuevo->info = x;
    nuevo->ant = NULL;
    nuevo->sig = L;
    if (L != NULL){
       L->ant = nuevo; 
    }
    return nuevo;
}

// esVacia: dada una lista l, verifica si l esta vacía

bool esVacia (ListaDoble L){
    if (L == NULL){
        return true;
    } else {
        return false;
    }
}

// esElemento: dados un entero x y una lista l, verifica si x pertenece a l

bool esElemento(ListaDoble L, int x){
    ListaDoble aux = L;
    while (aux != NULL){
        if (aux->info == x){
            return true;
        } else {
            aux = aux->sig;
        }
    }
    aux = L;
    while (aux != NULL){
        if (aux->info == x){
            return true;
        } else {
            aux = aux->ant;
        }
    }
    return false;
}

// EJERCICIO 4:

nodo * crearNCircular (int n){
    nodo * res = new nodo;
    nodo * aux = res;
    res->info = 1;
    for (int i=2; i <= n; i++){
        res->sig = new nodo;
        res = res->sig;
        res->info = i;
    }
    res->sig = aux;
    return aux;
}

void imprimirCircular (Lista L) {
    Lista aux = L->sig;
    cout << "| " << L->info << " |";
    while (aux != L){
        cout << " " << aux->info << " |";
        aux = aux->sig;
    }
    cout << " #" << endl;
}

bool esVaciaCircular (Lista L){
    if (L == NULL){
        return true;
    } else {
        return false;
    }
}

// resto: dada una lista l no vacía, retorna la lista sin su primer elemento

Lista resto (Lista & L){
    Lista aux = L->sig;
    Lista borrar = L;
    while (aux->sig != L){
        aux = aux->sig;
    }
    L = L->sig;
    delete borrar;
    aux->sig = L;
    return L;
}

// resto circular profe:

void restoCircularProfe (Lista & L){
    if (L->sig == L){
        delete L;
        L = NULL;
    } else {
        Lista aux = L->sig;
        while (aux->sig != L){
            aux = aux->sig;
        }
        Lista borrar = L;
        aux->sig = borrar->sig;
        L = L->sig;
        delete borrar;
    }
}

// ultimo: dada una lista l no vacía, retorna su último elemento.

int ultimoCircular (Lista L){
    Lista aux = L->sig;
    while (aux->sig != L){
        aux = aux->sig;
    }
    cout << "El ultimo valor es: " << aux->info << endl;
    return aux->info;
}

// insOrden: dados un entero x y una lista l ordenada, retorna el resultado de insertar x en l ordenadamente.
// Tiene errores

Lista insOrdenCircular (Lista L, int x){
    Lista aux = L->sig;
    Lista post = L;
    Lista ant = L;
    if (L == NULL){
        L = new nodo;
        L->info = x;
        L->sig = L;
    }
    if (L->info > x){
        while (aux->sig != L){
            aux = aux->sig;
        }
        L = new nodo;
        L->info = x;
        L->sig = post;
        aux->sig = L;
        return L;
    }
    while (aux->sig->info < x){
        aux = aux->sig;
    }
    post = aux->sig;
    ant = aux;
    aux = new nodo;
    aux->info = x;
    ant->sig = aux;
    aux->sig = post;
    return L;
}

Lista insOrdenadoCirc (Lista & L, int x){
    Lista nuevo = new nodo;
    nuevo->info = x;
    Lista aux = L;
    if (L == NULL){
        nuevo->sig = nuevo;
        L = nuevo;
        return L;
    }
    if (L->info > x){
        while (aux->sig != L){
            aux = aux->sig;
        }
        aux->sig = nuevo;
        nuevo->sig = L;
        return nuevo;
    }
    do {
        if (aux->sig->info > x){
            nuevo->sig = aux->sig;
            aux->sig = nuevo;
            return L;
        }
        aux = aux->sig;
    } while (aux->sig != L);
    nuevo->sig = L;
    aux->sig = nuevo;
    return L;
}

// Solución del profe:

void insOrdCircularProfe (Lista & L, int x){
    Lista nuevo = new nodo;
    nuevo->info = x;
    if (L == NULL){
        nuevo->sig = nuevo;
        L = nuevo;
        return;
    }
    if (L->info > x){
        nuevo->sig = L->sig;
        L = nuevo;
    }
    Lista aux = L;
    while (aux->sig != L){
        if (aux->sig->info > x){
            nuevo->sig = aux->sig;
            aux->sig = nuevo;
            return;
        }
        aux = aux->sig;
    }
}

// EJERCICIO 5:
/*
struct nodo {
    int elem ;
    nodo * sig ;
};
*/

struct cabezal {
    nodo * primero ;
    nodo * actual ;
};

typedef cabezal * lista ;

lista crearNLista(int n){
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

void imprimirRecursivoLista (lista L) {
    if (L->primero == NULL){
        cout << "#" << endl;
    } else {
        cout << "| " << L->primero->info << " | - ";
        imprimir_recursivo (L->primero->sig);
    }
}

// listaVacia: crea una lista vacía.

lista listaVaciaCabezal (){
    lista L = NULL;
    L->primero = NULL;
    L->actual = NULL;
    return L;
}

// inicio: dada una lista l no vacía, coloca la posición actual al inicio de l

void inicioCabezal (lista & L){
    L->actual = L->primero;
}

// siguiente: dada una lista l no vacía, mueve la posición actual al siguiente nodo (elemento). En caso
// de que la posición actual sea el final de la lista, coloca la posición actual al inicio de la lista (tiene un
// comportamiento circular).

void siguienteCabezal (lista & L){
    if (L->actual->sig != NULL){
        L->actual = L->actual->sig;
    } else {
        L->actual = L->primero;
    }
}

// insertar: dados un entero x y una lista l, inserta el elemento x luego de la posición actual en la lista.
// La posición actual pasa a ser el elemento (nodo) recién insertado. Si la lista l está vacía, el resultado
// es la lista unitaria que contiene a x, siendo este elemento la posición actual en la lista resultado.

lista insertarCabezal (lista L, int x){
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

// elemento: dada una lista l no vacía, retorna el elemento en la posición actual de l

Lista elemento (lista L){
    if (L == NULL){
        return NULL;
    }
    return L->actual;
}

int main(){
    lista L = crearNLista(15);
    cout << "Sin agregar el cabezal: " << endl;
    inicioCabezal(L);
    imprimirRecursivoLista(L);
    cout << "Con el cabezal agregado: " << endl;
    imprimirRecursivoLista(insertarCabezal(L, 9));
}