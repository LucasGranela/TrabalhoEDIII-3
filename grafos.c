#include "grafos.h"
#include <stdio.h>
#include <stdlib.h>


Lista* criaListas() {
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL)
        (*li) = NULL;
    return li;
}

grafo cria_Grafo(int quantV) {
    grafo graph = (grafo)malloc(sizeof(struct grafos));

    graph->quantVertices = quantV;
    graph->quantArestas = 0;
    graph->listaAdjacentes = malloc(quantV * sizeof(Lista));
    
    int i;

    for(i = 0; i < quantV; i++)
        graph->listaAdjacentes[i] = criaListas();

    return graph;
}

void insere_Aresta_Grafo(grafo* graph, int verticeInic, int verticeFim){
    Lista* lista;
    lista = (*graph)->listaAdjacentes[verticeInic];

    Elem* no = (Elem*)malloc(sizeof(Elem));

    no->prox = NULL;
    no->numSeguido = verticeFim;

    if((*lista) == NULL){
        *lista = no;
    } else {
        Elem* aux;
        aux = *lista;
        
        while(aux->prox != NULL){
            aux = aux->prox;
        }

        aux->prox = no;
    }
}


void liberaGrafo(grafo* graph){
    int i;
    for (i = 0; i < (*graph)->quantVertices; i++) {
        Lista* l = (*graph)->listaAdjacentes[i]; 
        while ( *l != NULL) {
        Elem *r = *l;
        *l = (*l)->prox;
        free(r);
        }
    }
    free((*graph)->listaAdjacentes);
}

void imprimeGrafo(grafo* graph){
    int i;
    Lista* lista;
    for(i = 0; i < (*graph)->quantVertices; i++){
        lista = (*graph)->listaAdjacentes[i];
        if(*lista != NULL){
            Elem* no;
            no = *lista;

            while (no != NULL) {
                printf("%d, ", no->numSeguido);
                no = no->prox;
            }   
            
            printf("\n");
        }
    }
}


