#ifndef PUZZLE8_H
#define PUZZLE8_H

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

    class Puzzle8{
        int puzzle[3][3];
        Puzzle8 *padre;
        int profundidad;
        public:
            Puzzle8();//genera un puzzle aleatorio
            Puzzle8(int num[9]);
            Puzzle8(Puzzle8 *padre);
            Puzzle8* mover_izq();//mueve el hueco a la izquierda (si se puede)
            Puzzle8* mover_der();//mueve el hueco a la derecha si es posible
            Puzzle8* mover_arriba();//mueve el hueco hacia arriba si es posible
            Puzzle8* mover_abajo();//mueve el hueco hacia abajo si es posible
            void mostrar_puzzle();//imprime en pantalla el estado del puzzle
            int posicion(int x, int y);//devuelve el valor correspondiente a una determinadada posicion
            void hueco(int &x, int &y);//devuelve la posicion del hueco
            bool final();//comprueba si el estado actual es el final
            void mostrar_camino();
            Puzzle8* generaHijos();
            int getProfundidad();
            bool operator==(Puzzle8 p);
    };

#endif
