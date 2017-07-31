#ifndef PROFUNDIDAD_H
#define PROFUNDIDAD_H

#include <stack>
#include <list>
#include "Puzzle8.h"
#include <typeinfo>

using namespace std;

class Profundidad
{
    list <Puzzle8> cerrados;
    stack <Puzzle8> abiertos;
    int nivel, limite;
    void tratar_repetidos(Puzzle8* hijos[]);
    public:
        Profundidad(int limit);
        Puzzle8* busqueda(Puzzle8 *p);
};

#endif // PROFUNDIDAD_H
