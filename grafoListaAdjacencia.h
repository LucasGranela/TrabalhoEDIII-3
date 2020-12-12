#ifndef GRAFOLISTAADJACENCIA_H
#define GRAFOLISTAADJACENCIA_H

#include "stack.h"
#include "listaNomes.h"

    //Lista que vai conter todas as pessoas que sao seguidas
 struct arestas{
    struct arestas* ant;
    char nomeSeguidos[40];
    struct arestas*  prox;
};

    //Lista que vai conter todos as pessoas que seguem
struct vertices{
    struct vertices *ant;
    char nomeSegue[40];
    struct arestas** listaAdjacencia;
    struct vertices *prox;
};

typedef struct vertices elem;
typedef struct vertices* segue;
typedef struct arestas elemSeguidos;
typedef struct arestas* seguidos;

segue* criaGrafo();
seguidos* criaSeguidores();
void insereGrafo(segue* lista, char nomePessoaSegue[40], char nomePessoaSeguida[40]);
void insereSeguidores(segue* lista, char nomePessoaSeguida[40], char nomePessoaSegue[40]);
void imprimeGrafoListaAdjacencia(segue* lista);
void limpaGrafo(segue* lista);
void buscaEmProfundidade(segue* li_segue, ListaNomes* li_Nomes, char nomeVerticeInic[40]);

void insereSeguidoresLista(seguidos* lista, char nomePessoaSeguida[40]);
void transpoeGrafo(segue* grafo,segue* grafoT);

#endif