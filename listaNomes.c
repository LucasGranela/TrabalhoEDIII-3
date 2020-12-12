#include "listaNomes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ListaNomes* criaListaNomes(int quantV){
    ListaNomes* nome = (ListaNomes*)malloc(quantV * sizeof(ListaNomes));

    return nome;
}

void insereListaNomes(ListaNomes* li, int num, char nomeP[40], int id){
    ListaNomes no;
    no = (ListaNomes)malloc(sizeof(struct nomes));

    strcpy(no->nome, nomeP);
    no->idNome = id;
    no->status = 0;

    li[num] = no;
}

void getNome(ListaNomes* li, int id, char nome[40]){
    int i = 0;

    while (li[i]->idNome != id) {
        i++;
    }
        
    strcpy(nome, li[i]->nome);

}

void mudaStatusPeloNome(ListaNomes* li, char nome[40], int status){
    int i = 0;

    //isso aqui pode dar erro se nao existir o nome na lista
    while (strcmp(li[i]->nome, nome) == 0) {
        i++;
    }

    li[i]->status = status;
}

int getStatusPeloNome(ListaNomes* li, char nome[40]){
    int i = 0;

    //isso aqui pode dar erro se nao existir o nome na lista
    while (strcmp(li[i]->nome, nome) == 0) {
        i++;
    }

    return li[i]->status;
}