#include <stdio.h>
#include <stdlib.h>

#include "grafoListaAdjacencia.h"
#include <string.h>

int main(){

    segue* lista = criaGrafo();
    insereSegueGrafo(lista, "vanessa\0");
    insereSeguidores(lista, "alexandre\0", "vanessa\0");
    insereSegueGrafo(lista, "Paulo\0");
    insereSeguidores(lista, "poldaslda\0", "Paulo\0");
    insereSeguidores(lista, "maraca\0", "Paulo\0");
    imprimeGrafoListaAdjacencia(lista);
    return 0;
}