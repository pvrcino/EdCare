#ifndef LISTA_HETEROGENEA_SIMPLESMENTE_ENCADEADA_SENTINELA_H_
#define LISTA_HETEROGENEA_SIMPLESMENTE_ENCADEADA_SENTINELA_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct celula Celula;
typedef struct lista Lista;

Lista *criaLista();
void insereElemento(Lista* lista, void*item, int tipo);
void listaCallback(Lista* lista, void (*callback)(void *));
int retiraElemento(Lista* lista, void* item);
void liberaLista(Lista* lista);

#endif