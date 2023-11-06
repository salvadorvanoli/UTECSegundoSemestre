#ifndef ColaDinamicaNoAcotada
#define ColaDinamicaNoAcotada

typedef int T;
typedef struct cola * Cola;
typedef struct cabezal * Cabezal;

// CONSTRUCTORAS

// Crea una nueva cola vacía
// Precondiciones: no tiene

Cabezal crearCola();

// Inserta un nuevo elemento al final de la cola
// Precondiciones: el dato no puede ser nulo

void insertar(Cabezal &, T);

// SELECTORAS

// Devuelve el elemento al inicio de la cola
// Precondiciones: la cola no puede estar vacía

T principio(Cabezal);

// Elimina el primer elemento de la cola
// Precondiciones: la cola no puede estar vacía

void quitarElemento(Cabezal &);

// PREDICADOS

// Retorna true si la cola está vacía
// Precondiciones: no tiene

bool colaVacia(Cabezal);

// DESTRUCTORAS

// Elimina la cola y todos sus espacios de memoria
// Precondiciones: no tiene

void eliminarCola(Cabezal);

#endif;