#ifndef GRAFOLISTAADJACENCIA_H
#define GRAFOLISTAADJACENCIA_H

    //Lista que vai conter todas as pessoas que sao seguidas
 struct vertices{
    struct vertices* ant;
    char nomeSeguidos[40];
    struct vertices*  prox;
};

    //Lista que vai conter todos as pessoas que seguem
struct No{
    struct No *ant;
    char nomeSegue[40];
    struct vertices** listaAdjacencia;
    struct No *prox;
};

typedef struct No elem;
typedef struct No* segue;
typedef struct vertices elemSeguidos;
typedef struct vertices* seguidos;



segue* criaGrafo();
seguidos* criaSeguidores();
void insereSegueGrafo(segue* lista, char nomePessoa[40]);
void insereSeguidores(segue* lista, char nomePessoaSeguida[40], char nomePessoaSegue[40]);
void imprimeGrafoListaAdjacencia(segue* lista);


void insereSeguidoresLista(seguidos* lista, char nomePessoaSeguida[40]);
void imprimeAdjacencia(seguidos* lista);

#endif