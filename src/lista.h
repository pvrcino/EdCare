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

/*Tipo que define a Celula*/
typedef struct celula Celula;

/*Tipo que define a Lista*/
typedef struct lista Lista;

/*Cria uma lista vazia
* inputs: nenhum
* output: lista alocada e vazia
* pre-condicao: nao tem
* pos-condicao: lista alocada e vazia */
Lista *criaLista();

/*Insere um item na lista na ultima posicao.
* inputs: lista, item a ser inserido
* output: nenhum
* pre-condicao: item alocado dinamicamente, lista ja criada
* pos-condicao: item na ultima posição da lista*/
void insereElemento(Lista* lista, void*item);


/*Executa um callback para todos os items da lista.
* inputs: lista, funcao callback
* output: nenhum
* pre-condicao: lista ja criada, callback recebe os items da lista como parametro
* pos-condicao: callback realizado*/
void listaCallback(Lista* lista, void (*callback)(void *));

/*Retira um item da lista.
* inputs: a lista e o item
* output: 1 para caso tenha encontrado, 0 caso contrario
* pre-condicao: lista nao nula
* pos-condicao: lista sem o item */
int retira(Lista* lista, void* item);

/*Libera toda a memoria utilizada pela lista (exceto os items).
* inputs: a lista
* output: nenhum
* pre-condicao: lista alocada
* pos-condicao: toda memoria da lista liberada (exceto os items) */
void liberaLista(Lista* lista);

/*Executa um callback para buscar um item da lista.
* inputs: lista, funcao callback, chave para a busca
* output: item procurado pelo callback
* pre-condicao: lista ja criada, callback recebe os items da lista como parametro e uma chave
* pos-condicao: nenhuma*/
void* buscaCallback(Lista* lista, int (*callback)(void *, void*), void* chave);

/*Executa um callback para comparar items da lista.
* inputs: lista, funcao callback, chave de base e uma referencia do item a ser comparado
* output: item que seja requisitado na comparacao (maior, menor, igual...)
* pre-condicao: lista ja criada, callback recebe os items da lista como parametro, uma chave, uma base e a referencia
* pos-condicao: nenhuma*/
void* comparaCallback(Lista* lista, int (*callback)(void*, void *, void*, int), void* base, int referencia);

/*Retira da lista items que atendam o requisito de um callback.
* inputs: lista, uma referencia para a analise se deve ou nao ser retirado, funcao callback
* output: lista de items procurados pelo callback
* pre-condicao: lista ja criada, callback recebe os items da lista como parametro e uma referencia
* pos-condicao: items retirados da lista*/
Lista* retiraCallback(Lista* lista, int retirada, int (*callback)(void *, int));

/*Executa um callback para os items que atendam o requisito de um callback a uma base.
* inputs: lista, uma base, funcao callback
* output: lista de items procurados pelo callback
* pre-condicao: lista ja criada, callback recebe os items da lista como parametro e uma referencia
* pos-condicao: nenhuma*/
void listaCallbackBase(Lista* lista, void* base, void (*callback)(void * ,void *));

/*Retira todos os elemtos de uma lista em outra.
* inputs: lista base, lista de elementos a serem retirados
* output: nenhum
* pre-condicao: listas ja criadas
* pos-condicao: todos elementos da lista2 retirados da lista1*/
void retiraOutraLista(Lista* lista1, Lista* lista2);

#endif