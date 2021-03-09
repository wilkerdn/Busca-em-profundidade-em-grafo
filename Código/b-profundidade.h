#include <stdio.h>
#include <stdlib.h>

#define X 15
#define Y 13

typedef struct grafo{
    int vertice;
    int max;
    int n_vertice;
    int *x;
    int *grau;
    int **arestas;
    struct grafo *prox;   
}Grafo;

Grafo *criar_grafo(int vertice, int max);
void excluir_grafo(Grafo *grafo);
int inserir(Grafo *grafo, int origem, int destino);
void imprimir(Grafo *grafo);
void percorre_grafo (Grafo *grafo, int *aux);
void percorre(Grafo *grafo, int i, int *aux);

