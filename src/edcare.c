#include "edcare.h"

void imprimeNomes(void* teste);

int main(int argc, char *argv[]){

    int NUMBER_OF_SENSORS = 0;
    if (argc < 2) {
        printf("Insira o numero de sensores: ");
        scanf("%d",&NUMBER_OF_SENSORS);
    } else{
        NUMBER_OF_SENSORS = atoi(argv[1]);
    }

    FILE *apoio = fopen("apoio.txt","r");

    if (apoio == NULL) {
        printf("ARQUIVO DE APOIO NAO ENCONTRADO!");
        return;
    }




    // Lista* idosos = criaLista();

    // Idoso* idoso1 = criaIdoso("Joaquim");
    // Idoso* idoso2 = criaIdoso("Joao");
    // Idoso* idoso3 = criaIdoso("Maria");

    // insereElemento(idosos, idoso1, IDOSO);
    // insereElemento(idosos, idoso2, IDOSO);
    // insereElemento(idosos, idoso3, IDOSO);

    // listaCallback(idosos, liberaIdoso);

    // liberaLista(idosos);

    return 0;
}
