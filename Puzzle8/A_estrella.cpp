#include "A_estrella.h"

using namespace std;

int A_estrella::costo(Puzzle8 e)
{
    int pos_x, pos_y, desp=0;
    int n=0;
    int ideal[3][3];

    for(int i=0; i<3; i++) //generacion de una matriz ideal
    {
        for(int j=0; j<3; j++)
        {
            if(n<9) ideal[i][j] = n;
            else ideal[i][j]=0;
            n++;
        }
    }

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(e.posicion(i, j)!=ideal[i][j] && e.posicion(i,j)!=0 && ideal[i][j]!=0)
            {
                if(e.posicion(i,j)<3) pos_x=0;
                else if(e.posicion(i,j)>3 && e.posicion(i,j)<7) pos_x=1;
                else pos_x=2;

                if(pos_x<2) pos_y=e.posicion(i,j)/3;
                else pos_x=(e.posicion(i,j)/3)-1;
                desp+=abs(pos_x-i)+(pos_y-j);
            }
        }//fin for j
    }//fin for i
    return desp;
}

Puzzle8 A_estrella::seleccionar_mejor()
{
    queue <Puzzle8> copia_abiertos=abiertos;
    Puzzle8 elemento = copia_abiertos.front();
    Puzzle8 mejor = elemento;

    while(!copia_abiertos.empty())
    {
        elemento=copia_abiertos.front();
        if(costo(mejor)>costo(elemento)) mejor=elemento;
        copia_abiertos.pop();
    }
    return mejor;
}


void A_estrella::tratar_repetidos(Puzzle8* hijos[])
{
    list<Puzzle8> copia_cerrados;
    queue<Puzzle8> copia_abiertos;
    Puzzle8 elemento;
    copia_abiertos=abiertos;
    bool repetido=false;

    for(int i=0; i<4; i++)
    {

        while(!copia_cerrados.empty() && !repetido)
        {
            elemento=copia_cerrados.front();
            if(elemento==hijos[i])
            {
                repetido=true;
                if(costo(elemento)>costo(hijos[i])) abiertos.push(hijos[i]);
            }
        }//fin while

        while(!abiertos.empty()) abiertos.pop();

        while(!copia_abiertos.empty())
        {
            elemento=copia_abiertos.front();
            if(elemento==hijos[i])
            {
                if(costo(hijos[i])<costo(copia_abiertos.front()))
                    abiertos.push(hijos[i]);
            }
            else abiertos.push(elemento);
            copia_abiertos.pop();
        }//fin while
    }//fin for
}

Puzzle8* A_estrella::busqueda(Puzzle8* p)
{
    Puzzle8 *actual = p;
    abiertos.push(actual);
    *actual = seleccionar_mejor();
    Puzzle8 *hijos = new Puzzle8[4];

    while(actual != NULL && !actual->final() && !abiertos.empty())
    {
        abiertos.pop();
        cerrados.push_back(actual);
        hijos = actual->generaHijos();
        tratar_repetidos(&hijos);

        for(int i=0; i<4; i++)
        {
            if(typeid(hijos[i]).name()==typeid(Puzzle8).name())
                abiertos.push(hijos[i]);
        }
        *actual=abiertos.front();
    }


    return actual;
}
