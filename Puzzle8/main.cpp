#include <iostream>
#include "Puzzle8.h"
#include "Anchura.h"
#include "Profundidad.h"

using namespace std;

int main()
{
    int mat[9]={1, 2, 3, 4, 5, 6, 7, 0, 8};
    Puzzle8 *prueba=new Puzzle8(mat), *resultado;
    prueba->mostrar_puzzle();
    prueba->mostrar_camino();

    Anchura busqueda;
    Profundidad prof(5);

    resultado=prof.busqueda(prueba);
    //resultado=busqueda.busqueda(prueba);
    resultado->mostrar_puzzle();
    return 0;
}
