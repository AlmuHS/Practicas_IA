#include "Profundidad.h"

using namespace std;

Profundidad::Profundidad(int limit)
{
    limite=limit;
    nivel=0;
}

void Profundidad::tratar_repetidos(Puzzle8* hijos[]){
    list<Puzzle8> copia_cerrados;
    stack<Puzzle8> copia_abiertos;
    Puzzle8 elemento;
    bool repetido=false;
    for(int i=0; i<4; i++){
        while(!copia_cerrados.empty() && !repetido){
            elemento=copia_cerrados.front();
            if(elemento==hijos[i]){
                repetido=true;
                if(elemento.getProfundidad()>hijos[i]->getProfundidad())
                    cerrados.unique();
            }
            else copia_cerrados.pop_front();
        }//fin while

        repetido=false;
        while(!copia_abiertos.empty() && !repetido){
            elemento=copia_abiertos.top();
            if(elemento==hijos[i]){
                repetido=true;
                delete hijos[i];
            }
            else copia_abiertos.pop();
        }//fin while
    }//fin for
}

Puzzle8* Profundidad::busqueda(Puzzle8* p){
    Puzzle8 *actual=p;
    Puzzle8 *hijos=new Puzzle8[4];
    abiertos.push(actual);
    while(!actual->final() && !abiertos.empty()){
        abiertos.pop();
        cerrados.push_back(actual);
        nivel=actual->getProfundidad();
        cout<<nivel;
        if(nivel<limite){
            hijos=actual->generaHijos();
            tratar_repetidos(&hijos);
            nivel++;
        }//fin if
        for(int i=0; i<4; i++)
            if(typeid(hijos[i]).name()==typeid(Puzzle8).name())
                abiertos.push(hijos[i]);
        *actual=abiertos.top();
    }//fin while
    actual->mostrar_puzzle();
    return actual;
}
