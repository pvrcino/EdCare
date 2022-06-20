#ifndef LISTA_HETEROGENEA_SIMPLESMENTE_ENCADEADA_SENTINELA_H_
#define LISTA_HETEROGENEA_SIMPLESMENTE_ENCADEADA_SENTINELA_H_

#include <stdio.h>
#include <stdlib.h>

/*
TIPOS:
 0 - IDOSO
 1 - CUIDADOR
 2 - SENSOR
*/
#define IDOSO 0
#define CUIDADOR 0
#define SENSOR 0

typedef struct celula Celula;
typedef struct lista Lista;

Lista *criaLista();
void insereElemento(Lista* lista, void*item, int tipo);
void listaCallback(Lista* lista, void (*callback)(void *));
int retiraElemento(Lista* lista, void* item);
void liberaLista(Lista* lista);
void* buscaCallback(Lista* lista, int (*callback)(void *, void*), void* chave);
void* comparaCallback(Lista* lista, int (*callback)(void*, void *, void*, int), void* base, int referencia);

#endif