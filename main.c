#include <stdio.h>
#include <stdlib.h>

#include "grafoListaAdjacencia.h"
#include <string.h>

int main(){

    segue* lista = criaGrafo();
    
    //insereSegueGrafo(lista, "vanessa");
    insereGrafo(lista, "vanessa\0", "alberto\0");
    
    //insereSegueGrafo(lista, "vanessa");
    insereGrafo(lista, "vanessa", "\0");
    insereGrafo(lista, "Alexandre", "\0");
    insereGrafo(lista, "Alexandre", "Paulo");
    insereGrafo(lista, "vanessa", "Macarena");

    imprimeGrafoListaAdjacencia(lista);

    limpaGrafo(lista);
    return 0;
}