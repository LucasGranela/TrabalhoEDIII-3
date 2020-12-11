#ifndef GRAFOS_H
#define GRAFOS_H

struct arestas{
    int numSeguido; //numero equivalente ao nome da pessoa no struct nomes
    struct arestas*  prox;
};

struct nomes{
    char nome[40];
    int idNome;
};

typedef struct nomes* ListaNomes;
typedef struct arestas* Lista;
typedef struct arestas Elem;

struct grafos {
    Lista** listaAdjacentes;
    int quantVertices;
    int quantArestas;
};

typedef struct grafos* grafo;

Lista* criaListas();
grafo cria_Grafo(int quantV);
ListaNomes* criaListaNomes(int quantV);
void insereListaNomes(ListaNomes* li, int num, char nome[40], int id);
void insere_Aresta_Grafo(grafo* graph, int verticeInic, int verticeFim);
void imprimeGrafo(grafo* graph);
void liberaGrafo(grafo* graph);




#endif