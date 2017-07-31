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
