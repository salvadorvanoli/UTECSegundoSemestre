#ifndef TADListaDigitos
#define TADListaDigitos

typedef unsigned int Digito;
typedef struct listaDigito * LDig;

/* Crea la lista de dígitos vacía */

LDig null();

/* Inserta un elemento al principio de la lista de digitos */

LDig cons(Digito x, LDig L);

/* Verifica si la lista de dígitos no está vacía */

bool empty(LDig L);

/* Retorna el primer elemento de la lista de dígitos */
/* Precondición: la lista no es vacía */

Digito head(LDig L);

/* Retorna la lista de dígitos sin su primer elemento */
/* Precondición: la lista no es vacía */

LDig tail(LDig L);

#endif