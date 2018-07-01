#include "Puzzle8.h"

using namespace std;


Puzzle8::Puzzle8(){
    char num[9];
    profundidad=0;
    srand(time(NULL));
    for(int i=0; i<9; i++){
        char numero=abs(rand()%10);
        while(strchr(num, numero)==NULL) numero=abs(rand()%10);
        num[i]=numero;
    }
    int n=0;
    for(int j=0; j<3; j++){
        for(int k=0; k<3; k++){
            if(num[n]==9) puzzle[j][k]=0;
            else puzzle[j][k]=num[n];
            n++;
        }
    }
}

Puzzle8::Puzzle8(int num[9]){
    int n=0;
    for(int j=0; j<3; j++){
        for(int k=0; k<3; k++){
            puzzle[j][k]=num[n];
            n++;
        }
    }
}

Puzzle8 ::Puzzle8(Puzzle8 *ppadre){
    padre=ppadre;
    profundidad=padre->profundidad+1;
    for(int j=0; j<3; j++){
        for(int k=0; k<3; k++){
            puzzle[j][k]=padre->puzzle[j][k];
        }
    }

}

void Puzzle8::hueco(int &x, int &y){
    bool encontrado=false;
    int i=0, j=0;
    while(!encontrado && !(i==2 && j==2)){
        if(posicion(i, j)==0){
                x=i;
                y=j;
                encontrado=true;
        }
        else{
            if(j<3) j++;
            else{
                j=0;
                i++;
            }
        }//fin else
    }//fin while
}

int Puzzle8::posicion(int x, int y){
    return puzzle[x][y];
}

void Puzzle8::mostrar_puzzle(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<puzzle[i][j]<<"\t|\t";
        }
        cout<<"\n-----------------------------------------\n";
    }
}

Puzzle8* Puzzle8::mover_izq(){
    Puzzle8 *hijo=new Puzzle8(this);
    int x, y;//coordenadas del hueco
    hueco(x, y);//paso por referencia
    if(x-1>0){
        hijo->puzzle[x][y]=puzzle[x-1][y];
        hijo->puzzle[x-1][y]=0;
    }
    else hijo=NULL;
    return hijo;
}

Puzzle8* Puzzle8::mover_der(){
    Puzzle8 *hijo=new Puzzle8(this);
    int x,y;
    hueco(x,y);
    if(x+1<3){
        hijo->puzzle[x][y]=puzzle[x+1][y];
        hijo->puzzle[x+1][y]=0;
    }
    else hijo=NULL;
    return hijo;
}

Puzzle8* Puzzle8::mover_abajo(){
    Puzzle8 *hijo=new Puzzle8(this);
    int x,y;
    hueco(x,y);
    if(y+1<3){
        hijo->puzzle[x][y]=puzzle[x][y+1];
        hijo->puzzle[x][y+1]=0;
    }
    else hijo=NULL;
    return hijo;
}

Puzzle8* Puzzle8::mover_arriba(){
    int x,y;
    Puzzle8 *hijo=new Puzzle8(this);
    hueco(x,y);
    if(y-1>0){
        hijo->puzzle[x][y]=puzzle[x][y-1];
        hijo->puzzle[x][y-1]=0;
    }
    else hijo=NULL;
    return hijo;
}

Puzzle8* Puzzle8::generaHijos(){
    Puzzle8 *p=new Puzzle8[4];
    padre=this;
    p[0]=mover_abajo();
    p[1]=mover_arriba();
    p[2]=mover_der();
    p[3]=mover_izq();
    return p;
}

void Puzzle8::mostrar_camino(){
    Puzzle8 *n=this;
    while(n!=NULL){
        n->mostrar_puzzle();
        n=padre;
    }
}

bool Puzzle8::final(){
    bool fin=true;
    if(puzzle[2][2]!=0) fin=false;
    else{
        int i=0, j=0;
        while(fin && !(i==2 && j==2)){
            if(puzzle[i][j]!=j+1+3*i) fin=false;
            else{
                if(j<3) j++;
                else{
                    i++;
                    j=0;
                }
            }
        }//fin while
    }//fin else
    return fin;
}

int Puzzle8::getProfundidad(){
    while(padre!=NULL){
        this->padre=this->padre->padre;
        profundidad++;
    }
    return profundidad;
}

bool Puzzle8::operator==(Puzzle8 p){
    int iguales=false;
    int i=0, j=0;
    while(!iguales && !(i==2 && j==2)){
        if(puzzle[i][j]==p.puzzle[i][j]) iguales=true;
        else{
            if(j<3) j++;
            else{
                i++;
                j=0;
            }
        }
    }//fin while
    return iguales;
}
