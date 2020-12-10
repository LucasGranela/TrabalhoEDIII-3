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

//ele recebe o nome de uma pessoa que segue (nomePessoaSegue) e um nome de uma pessoa que é seguida (nomePessoaSeguida)
//se (nomePessoaSeguida) == null entao ele so adiciona um vertice ao grafo sem aresta nenhuma
//se (nomePessoaSeguida) != null entao ele verifica se existe um vertice igual ao (nomePessoaSegue)
//se existir ele acrescenta uma aresta ao vertice do (nomePessoaSegue)
//se nao existir nenhum vertice com o (nomePessoaSegue) ele cria esse vertice e ja adiciona uma aresta com (nomePessoaSeguida)
//
//Sempre precisa existir um (nomePessoaSegue) != null, se nao ele nao faz nada
//Para adicionar a lista de pessoas seguidas é utilizado a funcao (insereSeguidoresLista)
void insereGrafo(segue* lista, char nomePessoaSegue[40], char nomePessoaSeguida[40]){
    if(lista == NULL) //sai se tiver um erro na lista
        return;
    
    if(strcmp(nomePessoaSegue, "\0") == 0) //retorna tambem se nao tiver vertice na entrada
        return;

    elem* no;
    no = (elem*) malloc(sizeof(elem));
    seguidos *seguidores = criaSeguidores(); 

    strcpy(no->nomeSegue, nomePessoaSegue);
    no->listaAdjacencia = seguidores;
    no->prox = NULL;

    if ((*lista) == NULL) {   //lista vazia: insere in�cio
        no->ant = NULL;

        insereSeguidoresLista(no->listaAdjacencia, nomePessoaSeguida);

        *lista = no;
    } else {
        elem *aux;
        aux = *lista;
        
        while (aux->prox != NULL){
            if(strcmp(nomePessoaSegue, aux->nomeSegue) == 0)
                break;

            aux = aux->prox;
        }
            insereSeguidoresLista(aux->listaAdjacencia, nomePessoaSeguida);
        if(strcmp(nomePessoaSegue, aux->nomeSegue) == 0)
            free(no);
        else {
            aux->prox = no;
            no->ant = aux;
        }
    }
    
}

//aqui ele pega essa lista que segue ja existente e cria uma lista de seguidos
void insereSeguidoresLista(seguidos* lista, char nomePessoaSeguida[40]){
    
    if(strcmp(nomePessoaSeguida, "\0") == 0)
        return;

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

//da free no grafo todo
void limpaGrafo(segue* li){
    if (li != NULL) {
        elem* no;
        seguidos* li_seguidos;
        elemSeguidos* no_seguidos;
        while ((*li) != NULL) {
            no = *li;
            li_seguidos = no->listaAdjacencia;
            while ((*li_seguidos) != NULL) {
                no_seguidos = *li_seguidos;
                *li_seguidos = (*li_seguidos)->prox;
                free(no_seguidos);
            }
            free(li_seguidos);
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}


//ele imprime o grafo seguindo a ordem:
//  Primeiro imprime o nome de alguem que segue e dps todos os seguidos pela pessoa
void imprimeGrafoListaAdjacencia(segue* lista){
    elem* no = *lista;
    seguidos* lista_seguido;
    lista_seguido = no->listaAdjacencia;
    elemSeguidos* no_seguido= *lista_seguido;

    if (lista == NULL)
        return;

    while (no != NULL) {
        printf("%s,",no->nomeSegue);
        while (no_seguido != NULL) {
            if(no_seguido->prox == NULL)
                printf(" %s\n", no_seguido->nomeSeguidos);
            else
                printf(" %s,", no_seguido->nomeSeguidos);
        
            no_seguido = no_seguido->prox;
        }
        no = no->prox;
        if(no == NULL)
            break;
        lista_seguido = no->listaAdjacencia;
        no_seguido = *lista_seguido;
    }
    printf("\n-------------- FIM LISTA -----------------\n");
}