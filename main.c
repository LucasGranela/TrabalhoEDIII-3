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

        if(!abreArquivo(&arqPessoa, nomeArquivoPessoa, "rb\0", 1))
            return 0;
        if(!abreArquivo(&arqIndexa, nomeArquivoIndexaPessoa, "rb\0", 1))
            return 0;
        if(!abreArquivo(&arqSegue, nomeArquivoSegueOrdenado, "rb\0", 1))
            return 0;

        int quantPessoas = retornaQuantidade(arqPessoa);

        grafo grafo_Twitter = cria_Grafo(quantPessoas);

        fseek(arqPessoa, 64, SEEK_SET);

        char status;
        int numPessoa = 0;
        char nomePessoa[40];
        int idPessoa;

        ListaNomes* listNom = criaListaNomes(quantPessoas);


        while(fread(&status, 1, 1, arqPessoa) == 1){
            if(status == '0'){
                fseek(arqPessoa, 63, SEEK_CUR); // pula para o proximo registro
                continue;
            }

            fread(&idPessoa, 4,1,arqPessoa);
            fread(nomePessoa, 1, 40, arqPessoa);
            insere_Aresta_Grafo(&grafo_Twitter, numPessoa, numPessoa); //o primeiro numero de toda lista é a pessoa que segue, as outras sao as pessoas seguidas
            insereListaNomes(listNom, numPessoa, nomePessoa, idPessoa);
            fseek(arqPessoa, 19, SEEK_CUR);
            numPessoa++;
        }

        imprimeGrafo(&grafo_Twitter);

        liberaGrafo(&grafo_Twitter);
        free(grafo_Twitter);

        fclose(arqSegue);
        fclose(arqPessoa);
        fclose(arqIndexa);
    }
    
    return 0;
}