#include "utilizadas.h"
#include <string.h>


int imprimeRegistroNaTela(FILE* arquivo){
    //variaveis do arquivo
    char status;
    int idPessoa;
    char nomePessoa[40];
    int idadePessoa;
    char twitterPessoa[15];
    fread(&status, sizeof(char), 1, arquivo);
    if(status == '0') //arquivo logicamente removido
        return 0;// registro logicamente removido = retorna false
    else {
        //leitura dos dados do registro existente
        fread(&idPessoa, sizeof(int), 1, arquivo);
        fread(nomePessoa, sizeof(char), 40, arquivo);
        fread(&idadePessoa, sizeof(int), 1, arquivo);
        fread(twitterPessoa, sizeof(char), 15, arquivo);
        printf("Dados da pessoa de código %d\n", idPessoa);
        if(nomePessoa[0] != '\0')
            printf("Nome: %s\n", nomePessoa);
        else
            printf("Nome: -\n");
        if(idadePessoa != -1)
            printf("Idade: %d anos\n", idadePessoa);
        else
            printf("Idade: -\n");
        printf("Twitter: %s\n", twitterPessoa);
        printf("\n");
    }
    return 1; //registro ocorreu como esperado = true
}

void escreveCabcArqPessoa(FILE* arquivoPessoa, int quantReg, char status){
    int i;
    fseek(arquivoPessoa, 0, SEEK_SET); //posicionando a escrita para escrever o cabecalho

    //como o fwrite pede um ponteiro foi necessario criar vetores de uma posicao
    char cabStatus1 = status;
    char cablixo1[59];
    for(i = 0; i < 59; i++) //escre o vetor lixo inteiro
        cablixo1[i] = '$';
    int quantRegistros = quantReg;

    //escrevendo o cabecalho
    fwrite(&cabStatus1, sizeof(char), 1, arquivoPessoa);
    fwrite(&quantRegistros, sizeof(int), 1, arquivoPessoa);
    fwrite(cablixo1, sizeof(char), 59, arquivoPessoa);
}

void escreveCabcArqIndexa(FILE* arqIndex, char status){
    int i;

    //criacao do cabecalho
    char cabStatus2 = status;
    char cablixo2[7];

    for(i = 0; i < 7; i++)
        cablixo2[i] = '$';

    fseek(arqIndex, 0, SEEK_SET);
    fwrite(&cabStatus2, 1, 1, arqIndex); //status
    fwrite(cablixo2, 1, 7, arqIndex); //lixo
}

void escreveCabArqSegue(FILE* arquivoSegue, int quantSeg, char status){
    int i;
    fseek(arquivoSegue, 0, SEEK_SET); //posicionando a escrita para escrever o cabecalho

    //como o fwrite pede um ponteiro foi necessario criar vetores de uma posicao
    char cabStatus1 = status;
    char cablixo[27];
    for(i = 0; i < 27; i++) //escre o vetor lixo inteiro
        cablixo[i] = '$';
    int quantSeguidores = quantSeg;

    //escrevendo o cabecalho
    fwrite(&cabStatus1, sizeof(char), 1, arquivoSegue);
    fwrite(&quantSeguidores, sizeof(int), 1, arquivoSegue);
    fwrite(cablixo, sizeof(char), 27, arquivoSegue);
}

//insere no arquivo pessoas
void inserirArqPessoas(int idPessoa, char nomePessoa[60], int idadePessoa, char twitterPessoa[40], FILE* arquivoPessoa){
    int i;
    int strFinal = 0; // quando for o final da string ele fica um
    for(i = 0; i < 60; i++){ //funcao para identificar e settar o lixo
        if(strFinal == 1)
            nomePessoa[i] = '$';
        else if(nomePessoa[i] == '\0')
            strFinal = 1;
        else if(i == 39){ //aqui ele ja prepara a variavel para ser salva no tamanho exato do necessario no arquivo
            nomePessoa[i] = '\0';
            strFinal = 1;
            break;
        }
    }

    strFinal = 0; //setando zero de novo para recomecar a verificacao da outra palavra
    for(i = 0; i < 40; i++){
        if(strFinal == 1)
            twitterPessoa[i] = '$';
        else if(twitterPessoa[i] == '\0')
            strFinal = 1;
        else if(i == 14){ //aqui ele ja prepara a variavel para ser salva no tamanho exato do necessario no arquivo
            twitterPessoa[i] = '\0';
            strFinal = 1;
            break;
        }
    }

    char removido = '1';

    //aqui escreve todos os dados no arquivoPessoa.bin
    fwrite(&removido, sizeof(char), 1, arquivoPessoa);
    fwrite(&idPessoa, 4, 1, arquivoPessoa);
    fwrite(nomePessoa, sizeof(char), 40, arquivoPessoa);
    fwrite(&idadePessoa, 4, 1, arquivoPessoa);
    fwrite(twitterPessoa, sizeof(char), 15, arquivoPessoa);
}

int verificaConsistencia(FILE* arquivo){ //se tiver consistente retorna 1, se nao 0
    //verifica se o arquivo esta consistente para continuar o programa
    char statusArquivo;
    fseek(arquivo, 0, SEEK_SET);
    fread(&statusArquivo, sizeof(char), 1, arquivo);

    //fecha os arquivos antes do encerramento do programa
    if(statusArquivo == '0'){
        printf("Falha na execução da funcionalidade.\n");
        fclose(arquivo);
        return 0;
    }

    return 1;
}

int verificaConsistenciaComAPalavraProcessamento(FILE* arquivo){ //se tiver consistente retorna 1, se nao 0
    //verifica se o arquivo esta consistente para continuar o programa
    char statusArquivo;
    fseek(arquivo, 0, SEEK_SET);
    fread(&statusArquivo, sizeof(char), 1, arquivo);

    //fecha os arquivos antes do encerramento do programa
    if(statusArquivo == '0'){
        printf("Falha no processamento do arquivo.\n");
        fclose(arquivo);
        return 0;
    }

    return 1;
}

int retornaRRN(FILE* arquivo){ //retorna o RRN do id achado
    int valor; //verifica o id requerido para encontrar o campo
    scanf("%d", &valor);

    int RRN;
    int id = 0;

    //posiciona o ponteiro do arquivo no id requerido para buscar o RRN certo
    fseek(arquivo, 4, SEEK_SET); //primeiro id
    //apesar do primeiro id ser com 8 bytes, se somar esse fseek com o do while da os 8 bytes necessarios

    while(id < valor){ //passa por todos os id para verificar se ele nao foi excluido
        fseek(arquivo, 4, SEEK_CUR); //pula proximo id - pula o campo do RRN
        fread(&id, sizeof(int), 1, arquivo); //le id
    }
    if(id == valor){
        //apos verificar a existencia do dado, procura-se o RRN e faz a busca no arquivoPessoa
        fread(&RRN, sizeof(int), 1, arquivo);
        return RRN;
    }

    return -1; //se retornar -1,nao encontrou o id
}

int retornaRRNcomId(FILE* arquivo,int valor){ //retorna o RRN do id achado

    int RRN;
    int id = 0;

    //posiciona o ponteiro do arquivo no id requerido para buscar o RRN certo
    fseek(arquivo, 4, SEEK_SET); //primeiro id
    //apesar do primeiro id ser com 8 bytes, se somar esse fseek com o do while da os 8 bytes necessarios

    while(id < valor){ //passa por todos os id para verificar se ele nao foi excluido
        fseek(arquivo, 4, SEEK_CUR); //pula proximo id - pula o campo do RRN
        fread(&id, sizeof(int), 1, arquivo); //le id
    }
    if(id == valor){
        //apos verificar a existencia do dado, procura-se o RRN e faz a busca no arquivoPessoa
        fread(&RRN, sizeof(int), 1, arquivo);
        return RRN;
    }

    return -1; //se retornar -1,nao encontrou o id
}

int abreArquivo(FILE** arq, char* nome, char* modo, int tipo){
    FILE* arquivo = fopen(nome, modo);

    if(arquivo == NULL){
        printf("Falha na execução da funcionalidade.\n");
        return 0;
    }

    if((strcmp(modo, "wb\0") != 0) && tipo != 4){
        char statusArquivo;
        fseek(arquivo, 0, SEEK_SET);
        fread(&statusArquivo, sizeof(char), 1, arquivo);

        if(statusArquivo == '0'){
        printf("Falha na execução da funcionalidade.\n");
        fclose(arquivo);
        return 0;
        }
    }

    *arq = arquivo;
    return 1;
}

void insereCSVparaSegue(FILE* arqCSV, FILE* arqSegue, int* quantPessoas){
    int idPessoaPrinc;
    int idPessoaSec;
    char grauAmizade[3];
    char dataInicio[10];
    char dataFim[10];

    fseek(arqCSV, 83, SEEK_SET);
    while(fscanf(arqCSV, "%d%*c", &idPessoaPrinc) == 1){
        fscanf(arqCSV, "%d%*c%[^,]%*c%[^,]%*c%s" , &idPessoaSec, grauAmizade, dataInicio, dataFim);
        (*quantPessoas)++;

        inserirArqSegue(idPessoaPrinc, idPessoaSec, grauAmizade, dataInicio, dataFim, arqSegue);
    }

}

void inserirArqSegue(int idPessoaQueSegue, int idPessoaQueESeguida, char graAmizade[3], char dataInicio[10], char dataFim[10],  FILE* arquivoSegue){
    int i;
    int strFinal = 0; // quando for o final da string ele fica um
    for(i = 0; i < 3; i++){ //funcao para identificar e settar o lixo
        if(strFinal == 1)
            graAmizade[i] = '$';
        else if(graAmizade[i] == '\0')
            strFinal = 1;
        else if(i == 2){ //aqui ele ja prepara a variavel para ser salva no tamanho exato do necessario no arquivo
            graAmizade[i] = '\0';
            strFinal = 1;
            break;
        }
    }
    char removido = '1';

    char *dataInicioReal = (dataInicio);
    char *dataFimReal = (dataFim);

    //aqui escreve todos os dados no arquivoSegue.bin
    fwrite(&removido, sizeof(char), 1, arquivoSegue);
    fwrite(&idPessoaQueSegue, 4, 1, arquivoSegue);
    fwrite(&idPessoaQueESeguida, 4, 1, arquivoSegue);
    fwrite(graAmizade, sizeof(char), 3, arquivoSegue);
    fwrite(dataInicioReal, sizeof(char), 10, arquivoSegue);
    fwrite(dataFimReal, sizeof(char), 10, arquivoSegue);
}

char* interpretadorDeGrau(char grauAmizade[4]){
    if(grauAmizade[0] == '0')
        return "segue porque é uma celebridade";
    if(grauAmizade[0] == '1')
        return  "segue porque é amiga de minha amiga";
    if(grauAmizade[0] == '2')
        return "segue porque é minha amiga";
    return "-";
}

int retornaQuantidade(FILE* arquivoPessoa){
    fseek(arquivoPessoa, 1, SEEK_SET);

    int quant;

    fread(&quant, 4, 1, arquivoPessoa);

    return quant;
}

void geraGrafo(FILE* arqPessoa, FILE* arqSegue, segue* grafo, ListaNomes* nomes){
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
}
