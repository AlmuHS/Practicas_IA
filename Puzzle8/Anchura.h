#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include "Puzzle8.h"
#include <list>
#include <queue>
#include <typeinfo>

using namespace std;

class Anchura
{

    queue <Puzzle8> abiertos;
    list <Puzzle8> cerrados;
    public:
        Anchura();
        Puzzle8* busqueda(Puzzle8 *p);
};

#endif // ANCHURA_H
