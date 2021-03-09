#include "b-profundidade.h"

int main (){
    int i = 0,aux[Y];
    int av[X][2] = {{1,4},{1,12},{6,0},{6,8},{6,3},{7,4},{8,5},{8,10},{8,11},{9,6},{9,10},{10,8},{11,4},{12,5},{12,11}};
    Grafo *grafo = criar_grafo(Y,3);
    while(i < X){    
        inserir(grafo,av[i][0],av[i][1]);
        i++;
    }
    imprimir(grafo);
    percorre_grafo(grafo,aux);
    excluir_grafo(grafo);
    return 0;
}
