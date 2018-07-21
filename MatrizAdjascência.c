#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXNUMVERTICES 100
#define VerticeInvalido -1
#define ArestaInvalida false

typedef bool TipoPeso;
typedef int TipoApontador;

typedef struct {
    int Vertices;
    int Arestas;
    TipoPeso matriz[MAXNUMVERTICES+1][MAXNUMVERTICES+1];
}TipoGrafo;

bool IniciaGrafo (TipoGrafo * g, int nv){
    if (nv > MAXNUMVERTICES){
        fprintf(stderr, "ERRO: Valor maior que o número máximo de vértices permitido(%d)\n",MAXNUMVERTICES);
        return false;
    }
    if (nv <= 0){
        fprintf(stderr, "ERRO: Digite apenas números positivos maiores que zero!!\n");
        return false;
    }
    g->Vertices = nv;
    g->Arestas = 0;
    int i;
    int j;
    for (i = 1; i <= nv; i++){
        for (j = 1; j <= nv; j++){
            g->matriz[i][j] = ArestaInvalida;
        }
    }
    return true;
}

bool TestaVertices (int v1, int v2){
    if (v1 <= 0){
        fprintf(stderr, "ERRO: Valor de V1 abaixo do permitido. Digite apenas inteiros positivos maiores que zero!!\n");
        return false;
    }
    if (v2 <= 0){
        fprintf(stderr, "ERRO: Valor de V2 abaixo do permitido. Digite apenas inteiros positivos maiores que zero!!\n");
        return false;
    }
    if (v1 > MAXNUMVERTICES){
        fprintf(stderr, "ERRO: Valor de V1 maior que o número máximo de vértices permitido(%d)\n",MAXNUMVERTICES);
        return false;
    }
    if (v1 > MAXNUMVERTICES){
        fprintf(stderr, "ERRO: Valor de V2 maior que o número máximo de vértices permitido(%d)\n",MAXNUMVERTICES);
        return false;
    }
    return true;
}

bool ExisteAresta (int v1, int v2, TipoGrafo * g){
    if (!TestaVertices(v1,v2))
        return false;
    if (g->matriz[v1][v2] != ArestaInvalida)
        return true;
    return false;
}

bool ListaAdjacenteVazia (int v1, TipoGrafo * g){
    if (v1 <= 0){
        fprintf(stderr, "ERRO: Valor de V1 abaixo do permitido. Digite apenas inteiros positivos maiores que zero!!\n");
        return false;
    }
    if (v1 > MAXNUMVERTICES){
        fprintf(stderr, "ERRO: Valor de V1 maior que o número máximo de vértices permitido(%d)\n",MAXNUMVERTICES);
        return false;
    }
    int i;
    for (i = 1; i <= g->Vertices; i++)
        if (g->matriz[v1][i] != ArestaInvalida)
            return false;
    return true;
}

TipoApontador  PrimeiroAdjascente (int v1, TipoGrafo * g){
    if (v1 <= 0){
        fprintf(stderr, "ERRO: Valor de V1 abaixo do permitido. Digite apenas inteiros positivos maiores que zero!!\n");
        return false;
    }
    if (v1 > MAXNUMVERTICES){
        fprintf(stderr, "ERRO: Valor de V1 maior que o número máximo de vértices permitido(%d)\n",MAXNUMVERTICES);
        return false;
    }
    int i;
    for (i = 1; i <= g->Vertices; i++)
        if (g->matriz[v1][i] != ArestaInvalida)
            return i;
    return VerticeInvalido;
}

TipoApontador ProximoAdjascente (int v1, TipoApontador * a, TipoGrafo * g){
    if (v1 <= 0){
        fprintf(stderr, "ERRO: Valor de V1 abaixo do permitido. Digite apenas inteiros positivos maiores que zero!!\n");
        return false;
    }
    if (v1 > MAXNUMVERTICES){
        fprintf(stderr, "ERRO: Valor de V1 maior que o número máximo de vértices permitido(%d)\n",MAXNUMVERTICES);
        return false;
    }
    int i;
    for (i = *a; i <= g->Vertices; i++)
        if (g->matriz[v1][i] != ArestaInvalida)
            return i;
    return VerticeInvalido;
}

void InsereAresta (int v1, int v2, TipoPeso peso, TipoGrafo * g){
    if (!TestaVertices(v1,v2))
        return;
    g->matriz[v1][v2] = peso;
    g->Arestas = g->Arestas + 1;
}

void RemoveAresta (int v1, int v2, TipoGrafo * g){
    if (!TestaVertices(v1,v2))
        return;
    g->matriz[v1][v2] = ArestaInvalida;
    g->Arestas = g->Arestas - 1;
}

void PrintaGrafo (TipoGrafo * g){
    int i;
    int j;
    for (i = 1; i <= g->Vertices; i++){
        for (j = 1; j <= g->Vertices; j++){
            printf(" %d", g->matriz[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    TipoApontador a = 4;
    TipoGrafo g;
    IniciaGrafo(&g, 10);
    int i;
    int j;
    for (i = 1; i <= 10; i++){
        for (j = 1; j <= 10; j++){
            InsereAresta(i,j,true, &g);
        }
    }
    for (i = 1; i <= 10; i++){
        RemoveAresta(i,i,&g);
        RemoveAresta(5,i,&g);
    }
    PrintaGrafo(&g);
    if (ExisteAresta(10,1,&g))
        printf("EUREKA!!\n");
    if (ExisteAresta(1,1,&g))
        printf("EUREKA!!\n");
    if (ListaAdjacenteVazia(5,&g))
        printf("Batata!!\n");
    if (ListaAdjacenteVazia(1,&g))
        printf("Batata!!\n");
    printf("%d\n", PrimeiroAdjascente(1,&g));
    printf("%d\n", ProximoAdjascente(5,&a,&g));
    return 1;
}
