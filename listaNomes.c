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

    li[num] = no;
}

void getNome(ListaNomes* li, int id, char nome[40]){
    int i = 0;

    while (li[i]->idNome != id) {
        i++;
    }
        
    strcpy(nome, li[i]->nome);

}