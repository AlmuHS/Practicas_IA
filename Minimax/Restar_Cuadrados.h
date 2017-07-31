#ifndef RESTAR_CUADRADOS_H
#define RESTAR_CUADRADOS_H

#include <iostream>
#include <cmath>

using namespace std;

class Restar_Cuadrados
{
    int valor, eleccion, profundidad, heuristica;
    bool esMax;
    public:
        Restar_Cuadrados(int val=60, int accion=0, int prof=0, bool smax=false);
        int Heuristica(bool esMax);
        void jugar(int val, int limite);
        int get_valor();
        int get_profundidad();
        int get_eleccion();
        int get_heuristica();
        void set_heuristica(int num);
        void set_eleccion(int num);
        bool sMax();
        void set_Max(bool max);
};

#endif // RESTAR_CUADRADOS_H
