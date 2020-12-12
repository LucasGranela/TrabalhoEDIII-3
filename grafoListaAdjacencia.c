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
        elem *ante;
        elem *atual;
        atual = *lista;
        
        while (atual != NULL && strcmp(atual->nomeSegue, nomePessoaSegue) < 0 ){
            ante = atual;
            atual = atual->prox;
        }
        if(atual != NULL && strcmp(nomePessoaSegue, atual->nomeSegue) == 0){
            free(no);
            insereSeguidoresLista(atual->listaAdjacencia, nomePessoaSeguida);
        }
        else {
            insereSeguidoresLista(no->listaAdjacencia, nomePessoaSeguida);
            if (atual == *lista){
                no->ant = NULL;
                (*lista)->ant = no;
                no->prox = (*lista);
                *lista = no;
            } else {
                no->prox = ante->prox;
                no->ant = ante;
                ante->prox = no;
                if (atual != NULL)
                    atual->ant = no;    
            } 
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
        elemSeguidos *ante;
        elemSeguidos *atual;
        atual = *lista;

        while (atual != NULL && strcmp(atual->nomeSeguidos, nomePessoaSeguida) < 0 ){
            ante = atual;
            atual = atual->prox;
        }
        if (atual == *lista){
            no->ant = NULL;
            (*lista)->ant = no;
            no->prox = (*lista);
            *lista = no;
        } else {
            no->prox = ante->prox;
            no->ant = ante;
            ante->prox = no;
            if (atual != NULL)
                atual->ant = no;     
        }
    }
}


void buscaEmProfundidade(segue* li_segue, ListaNomes* li_Nomes, char nomeVerticeInic[40]){
    /*
    STACK *p;
    p = S_New(40 * sizeof(char));

    ListaNomes li;
    li = *li_Nomes;

    elem* no_segue;
    no_segue = *li_segue;

    while ( no_segue->prox != NULL || strcmp(no_segue->nomeSegue, nomeVerticeInic) == 0) {
        no_segue = no_segue->prox;
    }

    //se nao tiver o vertice é pra printar erro e retornar pra main
    if(strcmp(no_segue->nomeSegue, nomeVerticeInic) != 0){
        printf("Falha na execução da funcionalidade.\n");
        S_Destroy(p);
        return;
    }

    S_Push(no_segue->nomeSegue, p);

    seguidos* li_seguidos;
    elemSeguidos* no_seguidos;

    while( (S_Size(p) != 1 && strcmp(no_segue->nomeSegue, nomeVerticeInic) != 0) || (S_Size(p) == 0)){
        li_seguidos = no_segue->listaAdjacencia;
        no_seguidos = *li_seguidos;

        while(getStatusPeloNome(li, no_seguidos->nomeSeguidos) != 0 || no_seguidos->prox != NULL){
            no_seguidos = no_seguidos->prox;
        }
        
        elem* aux;
        aux = *li_segue;

        if(getStatusPeloNome(li, no_seguidos->nomeSeguidos) == 0){
            while(strcmp(aux->nomeSegue, no_seguidos->nomeSeguidos) == 0)
                aux = aux->prox;

            mudaStatusPeloNome(li, no_segue->nomeSegue, 1);
            S_Push(aux->nomeSegue, p);
            no_segue = aux;
            continue;
        }

        char nomeASerBuscado[40];
        while(S_Size(p) != 0) {
            S_Pop(nomeASerBuscado, p);

            if(getStatusPeloNome(li, nomeASerBuscado) == 1){
                while(strcmp(aux->nomeSegue, nomeASerBuscado) == 0)
                    aux = aux->prox;
                
                mudaStatusPeloNome(li, aux->nomeSegue, 2);
                no_segue = aux;
            }
        }
    }

    if(S_Size(p) == 0)
        printf("A FOFOCA NAO RETORNOU\n");
    else
        printf("%ld\n", S_Size(p));
    */
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
        printf("%s",no->nomeSegue);
        lista_seguido = no->listaAdjacencia;
        no_seguido = *lista_seguido;
        if(no_seguido == NULL)
            printf("\n");
        while (no_seguido != NULL) {
            if(no_seguido->prox == NULL)
                printf(", %s\n", no_seguido->nomeSeguidos);
            else
                printf(", %s", no_seguido->nomeSeguidos);
        
            no_seguido = no_seguido->prox;
        }
        no = no->prox;
    }
}