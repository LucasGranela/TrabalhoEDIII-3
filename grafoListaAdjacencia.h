#ifndef GRAFOLISTAADJACENCIA_H
#define GRAFOLISTAADJACENCIA_H

    //Lista que vai conter todas as pessoas que sao seguidas
typedef struct vertices{
    struct seguidos* ant;
    char nomeSeguidos[40];
    struct seguidos*  prox;
} seguidos;

    //Lista que vai conter todos as pessoas que seguem
struct No{
    struct elem *ant;
    char nomeSegue[40];
    struct vertices **listaAdjacencia;
    struct elem *pos;
};

typedef struct no elem;

typedef struct no* segue;



void criaGrafo(segue* lista);




#endif