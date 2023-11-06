#include <iostream>
using namespace std;

/*
Para que se pudiera hacer una cola acotada dinámica, lo único que agregaría es una cota y una cantidad
actual al cabezal, con la que mantendría un límite al hacer las operaciones, de tal manera que quedaría así:
*/

typedef int T;

struct cola{
    T dato;
    cola * sig;
};

typedef cola * Cola;

struct cabezal{
    Cola inicio;
    Cola fin;
    int cota;
    int elemsActuales;
};

typedef cabezal * Cabezal;