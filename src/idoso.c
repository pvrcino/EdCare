#include "idoso.h"

struct idoso {
    char* nome;
    Lista* amigos;
    Lista* cuidadores;
    Lista* sensores;
};

Idoso* criaIdoso(char* nome){
    Idoso* idoso = malloc(sizeof(Idoso));
    idoso->nome = strdup(nome);
    idoso->amigos = criaLista();
    idoso->cuidadores = criaLista();
    idoso->sensores = criaLista();
}

void adicionaAmigo(Idoso* idoso1, Idoso* idoso2){
    insereElemento(idoso1->amigos, idoso2, IDOSO);
    insereElemento(idoso2->amigos, idoso1, IDOSO);
}

void adicionaCuidador(Idoso* idoso, Cuidador* cuidador){
    insereElemento(idoso->cuidadores, cuidador, CUIDADOR);
}

void adicionaSensorIdoso(Idoso* idoso, Sensor* sensor){
    insereElemento(idoso->sensores, sensor, SENSOR);
}

void liberaIdoso(Idoso* idoso) {
    free(idoso->nome);
    liberaLista(idoso->amigos);
    liberaLista(idoso->cuidadores);
    listaCallback(idoso->sensores, liberaSensor);
    liberaLista(idoso->sensores);
}