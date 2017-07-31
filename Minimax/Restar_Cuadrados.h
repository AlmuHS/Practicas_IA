/* Copyright 2014 Almudena García Jurado-Centurión
    This file is part of Minimax

    Minimax is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Minimax is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Minimax.  If not, see <http://www.gnu.org/licenses/>.
*/

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
