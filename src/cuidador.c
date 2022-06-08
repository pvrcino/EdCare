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

void adicionaSensorCuidador(Cuidador* cuidador, Sensor* sensor){
    insereElemento(cuidador->sensores, sensor, CUIDADOR);
}