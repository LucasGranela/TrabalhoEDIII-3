#include <stdio.h>
#include <stdlib.h>

#include "grafos.h"
#include "utilizadas.h"
#include <string.h>

int main(){

    int caso;
    char nomeArquivoPessoa[50];
    char nomeArquivoIndexaPessoa[50];
    char nomeArquivoSegueOrdenado[50];

    scanf("%d%*c%[^ ]%*c%[^ ]%*c%s", &caso, nomeArquivoPessoa, nomeArquivoIndexaPessoa, nomeArquivoSegueOrdenado);

    if(caso == 9){
        FILE *arqPessoa, *arqIndexa, *arqSegue;

        if(!abreArquivo(&arqPessoa, nomeArquivoPessoa, "rb\0", 1) || !abreArquivo(&arqIndexa, nomeArquivoIndexaPessoa, "rb\0", 2) || !abreArquivo(&arqSegue, nomeArquivoSegueOrdenado, "rb\0", 3));
            return 0;

        

        grafo grafo_Twitter = cria_Grafo(4);

        insere_Aresta_Grafo(&grafo_Twitter, 1,2);
        insere_Aresta_Grafo(&grafo_Twitter, 1,3);
        insere_Aresta_Grafo(&grafo_Twitter, 1,1);
        insere_Aresta_Grafo(&grafo_Twitter, 0,3);

        imprimeGrafo(&grafo_Twitter);

        liberaGrafo(&grafo_Twitter);
        free(grafo_Twitter);

        fclose(arqSegue);
        fclose(arqPessoa);
        fclose(arqIndexa);
    }
    
    return 0;
}