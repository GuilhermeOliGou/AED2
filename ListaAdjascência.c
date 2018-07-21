#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxVertices 100
#define VerticeNulo NULL
#define ArestaNula NULL

typedef int TipoPeso;

typedef struct S{
    int peso;
    int vertice;
    struct S* prox;
}Aresta;

typedef Aresta* TipoApontador;

typedef struct{
    int NumArestas;
    int NumVertices;
    TipoApontador* lista;
}TipoGrafo;

bool InicializaGrafo (TipoGrafo* g, int nv){
    if (nv <= 0){
        printf("N�mero de v�rtices muito baixo!\n");
        return false;
    }
    if (nv > MaxVertices){
        printf("N�mero de v�rtices acima do m�ximo de %d vertices permitidos!\n", MaxVertices);
        return false;
    }
    TipoApontador* novo = (TipoApontador*) calloc(nv+1, sizeof(TipoApontador));
    if(!novo){
        printf("Espa�o de mem�ria insuficiente!");
        return false;
    }
    free(g->lista);
    g->lista = novo;
    int i;
    for (i = 0; i <= nv; i++){
        g->lista[i] = ArestaNula;
    }
    return true;
}

bool TestaAresta (int i, int j, TipoGrafo*g){
    TipoApontador atual = g->lista[i];
    while (atual){
        if (atual->vertice == j)
            return true;
    }
    return false;
}

bool ListaAdjacenteVazia (int v1, TipoGrafo*g){
    TipoApontador atual = g->lista[v1];
    return atual->prox;
}

int main()
{
    TipoGrafo g;
    InicializaGrafo(&g, 10);
    return 1;
}
