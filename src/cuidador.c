#include "cuidador.h"

struct cuidador {
    char* nome;
    Lista* sensores;
};

Cuidador* criaCuidador(char* nome){
    Cuidador* cuidador = malloc(sizeof(Cuidador));
    cuidador->nome = strdup(nome);
    cuidador->sensores = criaLista();
}

void imprimeCuidador(Cuidador* cuidador){
    printf("%s\n", cuidador->nome);
}

void adicionaSensorCuidador(Cuidador* cuidador, Sensor* sensor){
    insereElemento(cuidador->sensores, sensor, CUIDADOR);
}

int verificaNomeCuidador(Cuidador* cuidador, char* nome) {
    if (strcmp(cuidador->nome,nome) == 0){
        return 1;
    }
    return 0;
}

void liberaCuidador(Cuidador* cuidador) {
    free(cuidador->nome);
    listaCallback(cuidador->sensores, liberaSensor);
    liberaLista(cuidador->sensores);
}