#include <stdio.h>
#include <stdlib.h>

//#include "grafos.h"
#include "grafoListaAdjacencia.h"
#include "utilizadas.h"
#include "listaNomes.h"
#include <string.h>

int main(){

    int caso;
    char nomeArquivoPessoa[50];
    char nomeArquivoIndexaPessoa[50];
    char nomeArquivoSegueOrdenado[50];

    scanf("%d%*c%[^ ]%*c%[^ ]%*c%s", &caso, nomeArquivoPessoa, nomeArquivoIndexaPessoa, nomeArquivoSegueOrdenado);

    if(caso == 9){
        FILE *arqPessoa, *arqIndexa, *arqSegue;

        if(!abreArquivo(&arqPessoa, nomeArquivoPessoa, "rb\0", 1))
            return 0;
        if(!abreArquivo(&arqIndexa, nomeArquivoIndexaPessoa, "rb\0", 1))
            return 0;
        if(!abreArquivo(&arqSegue, nomeArquivoSegueOrdenado, "rb\0", 1))
            return 0;

        int quantPessoas = retornaQuantidade(arqPessoa);

        segue *grafo = criaGrafo();

        ListaNomes* nomes = criaListaNomes(quantPessoas);

        geraGrafo(arqPessoa, arqSegue, grafo, nomes);

        imprimeGrafoListaAdjacencia(grafo);

        limpaGrafo(grafo);

        fclose(arqSegue);
        fclose(arqPessoa);
        fclose(arqIndexa);
    }

    else if(caso == 10){
        FILE *arqPessoa, *arqIndexa, *arqSegue;

        if(!abreArquivo(&arqPessoa, nomeArquivoPessoa, "rb\0", 1))
            return 0;
        if(!abreArquivo(&arqIndexa, nomeArquivoIndexaPessoa, "rb\0", 1))
            return 0;
        if(!abreArquivo(&arqSegue, nomeArquivoSegueOrdenado, "rb\0", 1))
            return 0;

        int quantPessoas = retornaQuantidade(arqPessoa);

        segue *grafo = criaGrafo();

        ListaNomes* nomes = criaListaNomes(quantPessoas);

        geraGrafo(arqPessoa, arqSegue, grafo, nomes);

        segue *grafoT = criaGrafo();
        transpoeGrafo(grafo, grafoT);
        imprimeGrafoListaAdjacencia(grafoT);

        limpaGrafo(grafo);
        limpaGrafo(grafoT);

        fclose(arqSegue);
        fclose(arqPessoa);
        fclose(arqIndexa);
    }


    return 0;
}
