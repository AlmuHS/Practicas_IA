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

#include "Restar_Cuadrados.h"
#include "Maquina.h"

using namespace std;

Restar_Cuadrados::Restar_Cuadrados(int val, int accion, int prof, bool smax)
{
    valor=val;
	eleccion=accion;
	profundidad=prof;
	heuristica=0;
	esMax=smax;
}

bool Restar_Cuadrados::sMax(){
    return esMax;
}

void Restar_Cuadrados::jugar(int num, int limite){
    Maquina mac;
    int resp;
    valor=num;
    cout<<"El valor inicial es "<<valor<<endl;

    while(valor>0){
        esMax=false;
        cout<<"Elige valor: ";
        cin>>resp;
        if(resp>sqrt(valor) || resp<=0)
            while(resp>sqrt(valor) || resp<=0){
                cout<<"Elige valor: ";
                cin>>resp;
            }
        cout<<"Has elegido el valor "<<resp<<endl
            <<"Quedan "<<valor-pow(resp,2)<<endl;
        valor-=pow(resp,2);

        if(valor>0){
            esMax=true;
            Restar_Cuadrados nodo(valor, resp, 0, true);
            mac.Busqueda(nodo, limite);
            cout<<"La maquina elige el valor "<<nodo.eleccion<<endl
                <<"Quedan "<<valor-pow(nodo.eleccion, 2)<<endl;
            valor-=pow(nodo.eleccion,2);
        }
    }
    if(esMax==true) cout<<"Gana la maquina";
    else cout<<"Gana el jugador";
}

int Restar_Cuadrados::Heuristica(bool esMax){
    if(valor == pow((int) sqrt(valor), 2)){
        if(esMax==true) heuristica=-900;
        else heuristica=900;
    }
    else if(valor == pow((int)sqrt(eleccion), 2)+1){// cuadrado +1
        if(esMax==true) heuristica=500;
        else heuristica=-500;
    }
    else heuristica=0;
    return heuristica;
}


int Restar_Cuadrados::get_valor(){
    return valor;
}

int Restar_Cuadrados::get_profundidad(){
    return profundidad;
}

int Restar_Cuadrados::get_eleccion(){
    return eleccion;
}

int Restar_Cuadrados::get_heuristica(){
    return heuristica;
}

void Restar_Cuadrados::set_eleccion(int num){
    eleccion=num;
}

void Restar_Cuadrados::set_heuristica(int num){
    heuristica=num;
}

void Restar_Cuadrados::set_Max(bool max){
    esMax=max;
}

