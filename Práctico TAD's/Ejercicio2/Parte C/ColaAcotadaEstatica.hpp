#ifndef ColaAcotadaEstatica
#define ColaAcotadaEstatica

typedef int T;
typedef struct colaEstatica * Cola;

// CONSTRUCTORAS

// Crea una nueva cola vacía
// Precondiciones: no tiene

Cola crearCola();

// Inserta un nuevo elemento al final de la cola
// Precondiciones: el dato no puede ser nulo

void insertar(Cola &, T);

// SELECTORAS

// Devuelve el elemento al inicio de la cola
// Precondiciones: la cola no puede estar vacía

T principio(Cola);

// Elimina el primer elemento de la cola
// Precondiciones: la cola no puede estar vacía

void quitarElemento(Cola &);

// PREDICADOS

// Retorna true si la cola está vacía
// Precondiciones: no tiene

bool colaVacia(Cola);

// DESTRUCTORAS

// Elimina la cola y todos sus espacios de memoria
// Precondiciones: no tiene

void eliminarCola(Cola &);

#endif;