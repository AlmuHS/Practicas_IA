#include "Anchura.h"

Anchura::Anchura()
{
    //ctor
    //Inicializar estructuras abiertos y cerrados
}

Puzzle8* Anchura::busqueda(Puzzle8 *p){
    Puzzle8 *actual=p;
    abiertos.anadir();
    Puzzle8 *hijos;
    while(!actual->final() && !abiertos.vacio()){
        abiertos.borrarprimero();
        cerrados.anadir(actual);
        hijos=actual->generaHijos();
        for(int i=0; i<4; i++){
            if(hijos[i]!=NULL) abiertos.anadir(hijos[i]);
        }
        actual=abiertos.primero();
        delete hijos;
    }
    return actual;
}
