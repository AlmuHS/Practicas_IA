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

#include <iostream>
#include "Restar_Cuadrados.h"

using namespace std;

int main()
{
    int val_inicio, limite;
    cout<<"Introduce valor inicial: ";
    cin>>val_inicio;
    cout<<"Introduce limite: ";
    cin>>limite;
    Restar_Cuadrados juego;
    juego.jugar(val_inicio,limite);
    return 0;
}
