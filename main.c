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

        char status;
        int numPessoa = 0;
        char nomePessoa[40];
        int idPessoa;

        fseek(arqPessoa, 64, SEEK_SET);
        while(fread(&status, 1, 1, arqPessoa) == 1){
            if(status == '0'){
                fseek(arqPessoa, 63, SEEK_CUR); // pula para o proximo registro
                continue;
            }

            fread(&idPessoa, 4,1,arqPessoa);
            fread(nomePessoa, 1, 40, arqPessoa);
            insereListaNomes(nomes, numPessoa, nomePessoa, idPessoa);
            insereGrafo(grafo, nomePessoa, "\0");
            fseek(arqPessoa, 19, SEEK_CUR);
            numPessoa++;
        }

        int idSegue;
        int idSeguido;
        char nomeSegue[40];
        char nomeSeguido[40];

        fseek(arqSegue, 32, SEEK_SET);

        while(fread(&status, 1, 1, arqSegue) == 1){
            if(status == '0'){
                fseek(arqPessoa, 31, SEEK_CUR); // pula para o proximo registro
                continue;
            }
            fread(&idSegue, 4,1,arqSegue);
            fread(&idSeguido, 4,1,arqSegue);
            getNome(nomes, idSegue, nomeSegue);
            getNome(nomes, idSeguido, nomeSeguido);
            insereGrafo(grafo, nomeSegue, nomeSeguido);
            fseek(arqSegue, 23, SEEK_CUR);
        }
        imprimeGrafoListaAdjacencia(grafo);

        limpaGrafo(grafo);

        fclose(arqSegue);
        fclose(arqPessoa);
        fclose(arqIndexa);
    }
    
    return 0;
}