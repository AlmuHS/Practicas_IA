#include "Algoritmos.h"

using namespace std;

Puzzle8* Algoritmos::busqueda_anchura(Puzzle8 *p){
    Puzzle8 *actual=p;
    abiertos.push_back(actual);
    Puzzle8 *hijos=new Puzzle8[4];
    while(actual->final()==false && !abiertos.empty()){
        abiertos.pop_front();
        cerrados.push_back(actual);
        hijos=actual->generaHijos();
        for(int i=0; i<4; i++){
            if(typeid(hijos[i]).name()==typeid(Puzzle8).name())
                abiertos.push_back(hijos[i]);
        }
        *actual=abiertos.front();
        delete hijos;
    }
    return actual;
}

Puzzle8* Algoritmos::busqueda_a_estrella(Puzzle8 *p){
    Puzzle8 *actual=p;
    abiertos.push_back(actual);
    Puzzle8 *hijos=new Puzzle8[4];
    while(!actual->final() && !abiertos.empty()){
        abiertos.pop_front();
        cerrados.push_back(actual);
        hijos=actual->generaHijos();
        //tratar repetidos
        for(int i=0; i<4; i++){
            if(typeid(hijos[i]).name()==typeid(Puzzle8).name())
                abiertos.push_back(hijos[i]);
        }
        *actual=abiertos.front();
        delete hijos;
    }
}

