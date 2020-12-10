#include "grafoListaAdjacencia.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

segue* criaGrafo() {
    segue* li = (segue*) malloc(sizeof(segue));

    if (li != NULL)
        *li = NULL;

    return li;
}

seguidos* criaSeguidores() {
    seguidos* li = (seguidos*) malloc(sizeof(seguidos));

    if ((li) != NULL)
        (*li) = NULL;

    return li;
}

//grafo é feito de duas linhas, uma lista de pessoas (segue) e uma lista de vertices (seguidos) 
//aqui ele cria essa lista que segue e aponta ela para um campo null de seguidos 
void insereSegueGrafo(segue* lista, char nomePessoa[40]){
    elem* no;
    no = (elem*) malloc(sizeof(elem));
    seguidos *seguidores = criaSeguidores(); 

    strcpy(no->nomeSegue, nomePessoa);
    no->listaAdjacencia = seguidores;
    no->prox = NULL;

    if ((*lista) == NULL) {   //lista vazia: insere in�cio
        no->ant = NULL;
        *lista = no;
    } else {
        elem *aux;
        aux = *lista;
        
        while (aux->prox != NULL){
            aux = aux->prox;
        }

        aux->prox = no;
        no->ant = aux;
    }

}

//aqui ele pega essa lista que segue ja existente e cria uma lista de seguidos
void insereSeguidoresLista(seguidos* lista, char nomePessoaSeguida[40]){
    elemSeguidos* no; 
    no = (elemSeguidos*) malloc(sizeof(elemSeguidos));

    strcpy(no->nomeSeguidos, nomePessoaSeguida);
    (no)->prox = NULL;
    
    if((*lista) == NULL){
        (no)->ant = NULL;
        *lista = no;
    } else {
        elemSeguidos *aux;
        aux = *lista;
        
        while ((aux)->prox != NULL){
            (aux) = (aux)->prox;
        }

        (aux)->prox = (no);
        (no)->ant = (aux);
    }
}

void insereSeguidores(segue* lista, char nomePessoaSeguida[40], char nomePessoaSegue[40]){
    elem* aux;
    aux = *lista;

    while (aux != NULL) {
        if(strcmp(aux->nomeSegue, nomePessoaSegue) == 0) {
            insereSeguidoresLista(aux->listaAdjacencia, nomePessoaSeguida);
            return;
        }
        else 
            aux = aux->prox;
    }
}

void imprimeGrafoListaAdjacencia(segue* lista){
    elem* no = *lista;

    if (lista == NULL)
        return;

    while (no != NULL) {
        printf("%s,",no->nomeSegue);
        imprimeAdjacencia(no->listaAdjacencia);
        no = no->prox;
    }
    printf("\n-------------- FIM LISTA -----------------\n");
}

void imprimeAdjacencia(seguidos* lista){
    elemSeguidos* no = *lista;
    if (lista == NULL)
        return;

    while (no != NULL) {
        if(no->prox == NULL)
            printf(" %s\n", no->nomeSeguidos);
        else
            printf(" %s,", no->nomeSeguidos);
        
        no = no->prox;
    }
}