#include "Maquina.h"
using namespace std;

int Maquina::Busqueda(Restar_Cuadrados &A, int limite){

    vector<Restar_Cuadrados> lista;
    A.set_heuristica(0);

    if(A.get_valor()==0){
        if(A.sMax()==true) A.set_heuristica(1000);
        else A.set_heuristica(-1000);
    }

   else if(A.get_profundidad() < limite){
        if( A.sMax()==true ) A.set_heuristica(-10000);
        else A.set_heuristica(10000);


        for(int i=1; i<=sqrt(A.get_valor()); i++){
            if(A.sMax()==true){
                lista.push_back( Restar_Cuadrados(A.get_valor()-pow(i,2), i, A.get_profundidad()+1, false ) );
            }
            else {
                lista.push_back(Restar_Cuadrados(A.get_valor()-pow(i,2), i, A.get_profundidad()+1, true));
            }
        }
        for(int i=0; i<lista.size(); i++){
            int aux=Busqueda(lista[i], limite);
            cout<<"Eleccion: "<<lista[i].get_eleccion()<<"\tValor: "<<lista[i].get_valor()<<"\tHeuristica: "<<lista[i].get_heuristica()<<"\n";
            if(A.sMax()==true){
                if(aux>=A.get_heuristica()){
                    A.set_heuristica(aux);
                    if(A.get_profundidad()==1) A.set_eleccion(lista[i].get_eleccion());
                }//fin if aux
            }//fin if smax
        }//fin for it
        cout<<endl;
    }//fin else if
    else A.Heuristica(A.sMax());
    return A.get_heuristica();
}


