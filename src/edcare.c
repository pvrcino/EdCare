#include "edcare.h"

struct edcare {
    Lista* idosos;
    Lista* cuidadores;
    int numeroSensores;
};

Edcare* inicializaEdcare(int numeroSensores ){
    Edcare* edcare = malloc(sizeof(Edcare));
    edcare->idosos = criaLista();
    edcare->cuidadores = criaLista();
    edcare->numeroSensores = numeroSensores;

    return edcare;
}

void inicializaApoio(Edcare* edcare) {
    FILE *apoio = fopen("apoio.txt","r");
    if (apoio == NULL) {
        printf("ARQUIVO DE APOIO NAO ENCONTRADO!");
        liberaLista(edcare->idosos);
        exit(EXIT_FAILURE);
    } else {
        char aux[1024];
        fscanf (apoio, "%[^\r]%*[\r]", aux);
        char *ptr = strtok(aux, "; ");

        while (ptr != NULL){
            Idoso* idoso = criaIdoso(ptr);
            insereElemento(edcare->idosos, idoso);
            ptr = strtok(NULL, "; ");
        }

        while (fscanf (apoio, "%[^\r]%*[\r]", aux)) {
            if (strcmp(aux, " ") == 0 || strcmp(aux, "\n") == 0) {
                break;
            }
            char *ptr2 = strtok(aux, "; \n");

            Idoso* idoso1 = buscaCallback(edcare->idosos,verificaNomeIdoso,ptr2);

            ptr2 = strtok(NULL, "; ");

            Idoso* idoso2 = buscaCallback(edcare->idosos,verificaNomeIdoso,ptr2);
            adicionaAmigo(idoso1, idoso2);
            strcpy(aux, " ");
        }
    }
    fclose(apoio);
    return;
}


void inicializaCuidadores(Edcare* edcare){
    FILE *apoio = fopen("cuidadores.txt","r");
    Lista* cuidadores = edcare->cuidadores;
    Lista* idosos = edcare->idosos;

    if (apoio == NULL) {
        printf("ARQUIVO DE CUIDADORES NAO ENCONTRADO!");
        liberaLista(cuidadores);
        liberaLista(idosos);
        exit(EXIT_FAILURE);
        return;
    } else {
        char aux[1024];
        fscanf (apoio, "%[^\r]%*[\r]", aux);

        char *ptr = strtok(aux, "; ");
        while (ptr != NULL){
            Cuidador* cuidador = criaCuidador(ptr);
            insereElemento(cuidadores, cuidador);
            ptr = strtok(NULL, "; ");
        }

        while (fscanf (apoio, "%[^\r]%*[\r]", aux)) {
            if (strcmp(aux, " ") == 0 || strcmp(aux, " ") == '\n') {
                break;
            }
            char *ptr = strtok(aux, "; \n");
            if (ptr == NULL) {
                break;
            }

            Idoso* idoso = buscaCallback(idosos,verificaNomeIdoso,ptr);
            ptr = strtok(NULL, "; ");

            while (ptr != NULL){
                Cuidador* cuidador = buscaCallback(cuidadores,verificaNomeCuidador,ptr);
                if (cuidador == NULL){
                    printf("Cuidador %s nao encontrado!", ptr);
                    break;
                }
                adicionaCuidador(idoso, cuidador);
                ptr = strtok(NULL, ";");
            }
            strcpy(aux, " ");
        }
    }
    fclose(apoio);
    return;
}

void extraiSensores(Edcare* edcare){
    listaCallback(edcare->idosos,extraiSensorIdoso);
    listaCallback(edcare->cuidadores, extraiSensorCuidador);
}

void analisaSensores(Edcare* edcare){
    for (int i = 0; i < edcare->numeroSensores; i++) {
        Lista* falecidos = retiraCallback(edcare->idosos, i, analisaSensorIdoso);
        retiraOutraLista(edcare->idosos,falecidos);
        listaCallback(falecidos, registraFalecimento);
        liberaLista(falecidos);
    }
}

void finalizaEdcare(Edcare* edcare){
    listaCallback(edcare->idosos, liberaIdoso);
    listaCallback(edcare->cuidadores, liberaCuidador);

    liberaLista(edcare->cuidadores);

    liberaLista(edcare->idosos);

    free(edcare);
}