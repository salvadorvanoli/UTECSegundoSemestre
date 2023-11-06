#ifndef TADDeque
#define TADDeque

typedef struct nodoCola * C;
typedef struct Deque * Di;
typedef int T;

// --- CONSTRUCTORAS

// Crea un deque vacío
// Precondiciones: no tiene

Di crearDeque();

// Inserta un elemento en el deque
// Precondiciones: que el deque exista y el elemento introducido no sea nulo

// Inserta el nodo al final
void insertarNodoAlFinal(Di &, T elem);

// Inserta el nodo al inicio
void insertarNodoAlInicio(Di &, T elem);

// --- SELECTORAS

// Quita un elemento en el deque
// Precondiciones: que el deque exista y el elemento a quitar también


// Quita el último nodo
void quitarNodoFinal(Di &);


// Quita el primer nodo
void quitarNodoInicio(Di &);

// Devuelve el primer elemento del deque
// Precondiciones: que el deque exista

Di obtenerInicio(Di &);

// Devuelve el último elemento del deque
// Precondiciones: que el deque exista

Di obtenerFinal(Di &);

// --- PREDICADO

// Devuelve true si el deque está vacío
// Precondiciones: no tiene

bool esDequeVacio(Di &);

#endif;