#include "grafoListaAdjacencia.h"

#include <stdio.h>
#include <stdlib.h>

void criaGrafo(segue* lista){
    segue* no;

    no = (segue*) malloc (sizeof(segue));

    if(no != NULL){
        *no = NULL;
        lista = no;
    }

}
