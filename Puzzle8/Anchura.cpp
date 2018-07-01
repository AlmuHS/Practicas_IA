#include "Anchura.h"

Anchura::Anchura()
{
    //ctor
    //Inicializar estructuras abiertos y cerrados
}

Puzzle8* Anchura::busqueda(Puzzle8 *p){
    Puzzle8 *actual = p;
    abiertos.push(actual);
    Puzzle8 *hijos = new Puzzle8[4];

    while(actual != NULL && !actual->final() && !abiertos.empty()){
        abiertos.pop();//eliminar primero
        cerrados.push_back(actual);
        hijos = actual->generaHijos();

        for(int i = 0; i < 4; i++){
            if(typeid(hijos[i]).name() == typeid(Puzzle8).name())
                abiertos.push(hijos[i]);
        }

        *actual = abiertos.front();
        delete hijos;
    }
    return actual;
}
