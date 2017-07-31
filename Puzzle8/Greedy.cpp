#include "Greedy.h"

using namespace std;

void Greedy::tratar_repetidos(Puzzle8* hijos[]){
    list<Puzzle8> copia_cerrados;
    queue<Puzzle8> copia_abiertos;
    Puzzle8 elemento;
    copia_abiertos=abiertos;
    bool repetido=false;

    for(int i=0; i<4; i++){

        while(!copia_cerrados.empty() && !repetido){
            elemento=copia_cerrados.front();
            if(elemento==hijos[i]){
                repetido=true;
                hijos[i]=NULL;
            }
        }//fin while

        repetido=false;

        while(!copia_abiertos.empty() && !repetido){
            elemento=copia_abiertos.front();
            if(elemento==hijos[i]){
                repetido=true;
                hijos[i]=NULL;
            }
            copia_abiertos.pop();
        }//fin while
    }//fin fo
}

int Greedy::costo(Puzzle8 e){
    int desp=0;
    int n=0;
    int ideal[3][3];
    for(int i=0; i<3; i++){//generacion de una matriz ideal
        for(int j=0; j<3; j++){
            if(n<9) ideal[i][j]=n;
            else ideal[i][j]=0;
            n++;
        }
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(e.posicion(i, j)!=ideal[i][j] && e.posicion(i,j)!=0 && ideal[i][j]!=0)
                desp++;
        }//fin for j
    }//fin for i
    return desp;
}

Puzzle8 Greedy::seleccionar_mejor(){
    queue <Puzzle8> copia_abiertos=abiertos;
    Puzzle8 elemento=copia_abiertos.front();
    Puzzle8 mejor=elemento;
    while(!copia_abiertos.empty()){
        elemento=copia_abiertos.front();
        if(costo(mejor)>costo(elemento)) mejor=elemento;
        copia_abiertos.pop();
    }
    return mejor;
}



Puzzle8* Greedy::busqueda(Puzzle8 *p){
    Puzzle8 *actual=p;
    abiertos.push(actual);
    *actual=seleccionar_mejor();
    Puzzle8 *hijos=new Puzzle8[4];
    while(!actual->final() && !abiertos.empty()){
        abiertos.pop();
        cerrados.push_back(actual);
        hijos=actual->generaHijos();
        tratar_repetidos(&hijos);
        for(int i=0; i<4; i++)
            if(typeid(hijos[i]).name()==typeid(Puzzle8).name())
                abiertos.push(hijos[i]);
        *actual=abiertos.front();
    }
    return actual;
}
