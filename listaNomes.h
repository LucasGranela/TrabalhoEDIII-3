#ifndef LISTANOMES_H
#define LISTANOMES_H

struct nomes{
    char nome[40];
    int idNome;
};

typedef struct nomes* ListaNomes;

ListaNomes* criaListaNomes(int quantV);
void insereListaNomes(ListaNomes* li, int num, char nome[40], int id);
void getNome(ListaNomes* li, int id, char nome[40]);

#endif
