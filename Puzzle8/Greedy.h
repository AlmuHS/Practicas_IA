#ifndef GREEDY_H
#define GREEDY_H

#include <queue>
#include <list>
#include "Puzzle8.h"
#include <typeinfo>

using namespace std;

class Greedy
{
    queue <Puzzle8> abiertos;
    list <Puzzle8> cerrados;
    public:
        int costo(Puzzle8 e);
        Puzzle8 seleccionar_mejor();
        Puzzle8* busqueda(Puzzle8 *p);
        void tratar_repetidos(Puzzle8* hijos[]);
};

#endif // GREEDY_H
