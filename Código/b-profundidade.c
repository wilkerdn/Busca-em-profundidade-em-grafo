#include "b-profundidade.h"

int temp = 0;

Grafo *criar_grafo(int vertice, int max){
    Grafo *grafo = (Grafo*)malloc(sizeof(Grafo));
    if (grafo != NULL) {
        int i = 0;
        grafo->n_vertice = vertice;
        grafo->max = max;
        grafo->grau = (int*)calloc(vertice,sizeof(int));
        grafo->x = (int*) calloc (vertice,sizeof(int));
        grafo->arestas = (int**) malloc (vertice * sizeof(int*));
        while (i < vertice) {
            grafo->arestas[i] = (int*)malloc(max * sizeof(int));
            i++;
        }
    }
    return grafo;
}

void excluir_grafo(Grafo* grafo){
    if(grafo != NULL) {
        for(int i = 0; i < grafo->n_vertice; i++) {
            free(grafo->arestas[i]);
        }
        free(grafo->arestas);
        free(grafo->grau);
        free(grafo);
    }
}


int inserir(Grafo *grafo, int origem, int destino){
    if (grafo == NULL){
        return 0;
    }
    if (origem < 0 || origem >= grafo->n_vertice){
        return 0;
    }
    if (destino < 0 || destino >= grafo->n_vertice){
        return 0;
    }
    grafo->arestas[origem][grafo->grau[origem]] = destino;
    grafo->grau[origem]++;
    return 1;
}

void imprimir(Grafo *grafo){
    printf("\nGRAFO\n");
    if(grafo!=NULL){
        int i = 0, j;
        while(i < grafo->n_vertice) {
                printf("%d--> ", i + 1);
            j = 0;
            while (j < grafo->grau[i]){
                printf ("%d ", grafo->arestas[i][j] + 1);
                j++;
            }
            printf ("\n");
            i++;
        }
    }
}

void percorre_grafo(Grafo *grafo, int *aux){
    printf ("\nTEMPO\n");
    int i = 0,temp = 0;
    while(i < grafo->n_vertice){
        aux[i] = 0;
        i++;
    }
    i = 0;
    while(i < grafo->n_vertice){
        if (aux[i] == 0) {
            percorre(grafo, i, aux);
            i++;
        }
    }
    i = 0;
    while(i < grafo->n_vertice){
        if (i < 9) {
            printf ("%d--> ", i + 1);
        }else {
            printf ("%d-->", i + 1);
        }
        printf ("%d\n", grafo->x[i]);    
        i++;
    }
     
}

void percorre(Grafo *grafo, int i, int *aux){
    grafo->x[i] = temp++;
    int j = 0;
    while (j < grafo->grau[i]) {
        aux[j] = 1;
        if (aux[grafo->arestas[i][j]] != 0) {
            percorre(grafo, j, aux);
        }
        j++;
    }  
}
