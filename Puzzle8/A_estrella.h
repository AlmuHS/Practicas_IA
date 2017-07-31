#ifndef A_ESTRELLA_H
#define A_ESTRELLA_H

#include <queue>
#include <list>
#include "Puzzle8.h"
#include <typeinfo>
#include <algorithm>

using namespace std;

class A_estrella
{
    queue <Puzzle8> abiertos;
    list <Puzzle8> cerrados;
    public:
        Puzzle8* busqueda(Puzzle8 *p);
        int costo(Puzzle8 e);
        void tratar_repetidos(Puzzle8* hijos[]);
        Puzzle8 seleccionar_mejor();
};

#endif // A_ESTRELLA_H
