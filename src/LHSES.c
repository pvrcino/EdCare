#include "LHSES.h"

struct celula{
    int tipo;
    void* item;
    Celula* prox;
};

struct lista{
    Celula* primeiro;
    Celula* ultimo;
};

Lista *criaLista(){
    Lista *lista = malloc(sizeof(Lista));
    lista->primeiro = NULL;
    lista->ultimo = NULL;

    return lista;
}

void listaCallback(Lista* lista, void (*callback)(void *)){
    Celula* celula = lista->primeiro;
    while (celula != NULL) {
        Celula* prox = celula->prox;
        callback(celula->item);
        celula = prox;
    }
}

void insereElemento(Lista* lista, void*item, int tipo) {
    Celula* celula = malloc(sizeof(Celula));
    celula->item = item;
    celula->tipo = tipo;

	if (lista->ultimo){
		lista->ultimo->prox = celula;
	}
	celula->prox = NULL;
	
    lista->ultimo = celula;

    if (lista->primeiro == NULL) {
        lista->primeiro = celula;
    }
}

int retira(Lista* lista, void* item) {
    Celula* busca = lista->primeiro;
    Celula* anterior = NULL;

    while (busca != NULL) {
        if (busca->item == item){

            if (anterior != NULL) {
                anterior->prox = busca->prox;
            }else {
                lista->primeiro = busca->prox;
            }

            if (busca->prox == NULL){
                lista->ultimo = anterior;
            }

            free(busca);
            return 1;
        } else {
            anterior = busca;
            busca = busca->prox;
        }
    }
    return 0;
}

void liberaLista(Lista* lista) {
    Celula* celula = lista->primeiro;
    while (celula != NULL) {
        Celula* prox = celula->prox;
        free(celula);
        celula = prox;
    }
    free(lista);
}
