#include "lista.h"

struct celula{
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

void listaCallbackBase(Lista* lista, void* base, void (*callback)(void * ,void *)){
    Celula* celula = lista->primeiro;
    while (celula != NULL) {
        Celula* prox = celula->prox;
        callback(base, celula->item);
        celula = prox;
    }
}

Lista* retiraCallback(Lista* lista, int retirada, int (*callback)(void *, int)){
    Lista* saida = criaLista();
    Celula* celula = lista->primeiro;
    while (celula != NULL) {
        Celula* prox = celula->prox;
        if (callback(celula->item, retirada) == 1) {
            insereElemento(saida, celula->item);
            retira(lista, celula->item);
        }
        celula = prox;
    }
    return saida;
}


void* buscaCallback(Lista* lista, int (*callback)(void *, void*), void* chave) {
    Celula* celula = lista->primeiro;
    while (celula != NULL) {
        Celula* prox = celula->prox;
        if (callback(celula->item, chave)) {
            return celula->item;
        }
        celula = prox;
    }
    return NULL;
}

void* comparaCallback(Lista* lista, int (*callback)(void*, void *, void*, int), void* base, int referencia) {
    void* retorno = NULL;

    Celula* celula = lista->primeiro;
    while (celula != NULL) {
        Celula* prox = celula->prox;
        if (callback(base, celula->item, retorno, referencia)) {
            retorno = celula->item;
        }
        celula = prox;
    }
    return retorno;
}


void insereElemento(Lista* lista, void*item) {
    Celula* celula = malloc(sizeof(Celula));
    celula->item = item;

	if (lista->ultimo){
		lista->ultimo->prox = celula;
	}
	celula->prox = NULL;
	
    lista->ultimo = celula;

    if (!lista->primeiro) {
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

void retiraOutraLista(Lista* lista1, Lista* lista2){
    Celula* celula = lista2->primeiro;
    while (celula != NULL) {
        Celula* prox = celula->prox;
        retira(lista1, celula->item);
        celula = prox;
    }
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
