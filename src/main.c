#include "edcare.h"

int main(int argc, char *argv[]){
    int n_sensor = 0;
    if (argc < 2) {
        printf("Insira o numero de sensores: ");
        scanf("%d",&n_sensor);
    } else{
        n_sensor = atoi(argv[1]);
    }

    Edcare* edcare = inicializaEdcare(n_sensor);
    
    inicializaApoio(edcare);

    inicializaCuidadores(edcare);

    extraiSensores(edcare);

    analisaSensores(edcare);
    
    finalizaEdcare(edcare);

    return EXIT_SUCCESS;
}