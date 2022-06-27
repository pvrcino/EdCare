#ifndef IDOSO_H_
#define IDOSO_H_

#include <stdio.h>
#include <string.h>
#include "cuidador.h"

/*Tipo que define o Idoso*/
typedef struct idoso Idoso;

/*Cria e aloca o Idoso, alem de suas listas de cuidadores e amizades
* inputs: nome do idoso
* output: idoso alocado
* pre-condicao: nao tem
* pos-condicao: idoso alocado, nome alocado dinamicamente, listas criadas */
Idoso* criaIdoso(char* nome);

/*Retorna as amizades do Idoso
* inputs: idoso
* output: lista de amizades
* pre-condicao: idoso alocado
* pos-condicao: nenhuma */
Lista* getAmigos(Idoso* idoso);

/*Retorna o nome do idoso
* inputs: idoso
* output: nome do idoso
* pre-condicao: idoso alocado
* pos-condicao: nenhuma */
char* getNome(Idoso* idoso);

/*Retorna os cuidadores do Idoso
* inputs: idoso
* output: lista de cuidadores
* pre-condicao: idoso alocado
* pos-condicao: nenhuma */
Lista* getCuidadores(Idoso* idoso);

/*Retorna os sensores do Idoso
* inputs: idoso
* output: lista de sensores
* pre-condicao: idoso alocado
* pos-condicao: nenhuma */
Lista* getSensores(Idoso* idoso);

/*Verifica o nome do cuidador
* inputs: o cuidador e o nome a ser comparado
* output: 1 para igual, 0 para diferente
* pre-condicao: cuidador alocado
* pos-condicao: nenhum */
int verificaNomeIdoso(Idoso* idoso, char* nome);

/*Retorna o cuidador mais proximo do Idoso em determinada leitura de sensor
* inputs: idoso, numero de leitura do sensor
* output: cuidador mais proximo
* pre-condicao: idoso alocado
* pos-condicao: nenhuma */
Cuidador* getCuidadorProximo(Idoso* idoso, int leitura);

/*Adiciona em ambas lista de amizades dos idosos o outro
* inputs: dois idosos
* output: nenhum
* pre-condicao: idosos alocados e ainda nao amigos
* pos-condicao: idosos amigos reciprocamente */
void adicionaAmigo(Idoso* idoso1, Idoso* idoso2);

/*Adiciona um cuidador ao idoso
* inputs: idoso, cuidador
* output: nenhum
* pre-condicao: idoso e cuidador alocados
* pos-condicao: cuidador inserido na lista de cuidadores do idoso */
void adicionaCuidador(Idoso* idoso, Cuidador* cuidador);

/*Adiciona um sensor ao idoso
* inputs: idoso, sensor
* output: nenhum
* pre-condicao: idoso e sensor alocados
* pos-condicao: cuidador inserido na lista de sensor do idoso */
void adicionaSensorIdoso(Idoso* idoso, Sensor* sensor);

/*Retorna o Idoso (amigo) mais proximo do Idoso em determinada leitura de sensor
* inputs: idoso, numero de leitura do sensor
* output: idoso mais proximo
* pre-condicao: idoso alocado
* pos-condicao: nenhuma */
Idoso* getAmigoProximo(Idoso* idoso, int leitura);

/*Retorna o idoso(amigo) mais proximo entre dois de um sensor base
* inputs: o sensor base, os idosos e o numero de leitura do sensor base
* output: idoso mais proximo da base
* pre-condicao: cuidadores criados e sensor base criado
* pos-condicao: nenhum */
Idoso* comparaDistanciaAmigos(Sensor* base, Idoso* amigo, Idoso* amigoMaisProximo, int leitura);

/*Retira o idoso do edcare
* inputs: idoso
* output: nenhum
* pre-condicao: idoso alocado
* pos-condicao: idoso liberado, idoso removido de outras listas de amizades */
void registraFalecimento(Idoso* idoso);

/*Libera a memoria alocada do idoso
* inputs: idoso
* output: nenhum
* pre-condicao: idoso alocado
* pos-condicao: nome e lista de amizades e cuidadores liberada, além do idoso */
void liberaIdoso(Idoso* idoso);

/*Le o arquivo de sensor do idoso e insere a TAD na lista de sensores do idoso
* inputs: idoso
* output: nenhum
* pre-condicao: idoso alocado
* pos-condicao: todos sensores alocados e inserios na lista de sensores */
void extraiSensorIdoso(Idoso* idoso);

/*Registra que o idoso teve uma febre baixa
* inputs: idoso
* output: nenhum
* pre-condicao: idoso alocado
* pos-condicao: adiciona uma febre baixa a sequencia do idoso */
void registraFebreBaixa(Idoso* sensor);

/*Anula a sequencia de febres baixas do idoso
* inputs: idoso
* output: nenhum
* pre-condicao: idoso alocado
* pos-condicao: sequencia de febres baixas igual a 0 */
void resetaFebreBaixa(Idoso* idoso);

/*Retorna a sequencia de febres baixas do idoso
* inputs: idoso
* output: numero da sequencia de febres baixas
* pre-condicao: idoso alocado
* pos-condicao: nenhuma */
int getFebreBaixa(Idoso* idoso);

/*Analisa e adiciona ao arquivo de saida do idoso uma leitura de sensor
* inputs: idoso, numero de leitura do sensor
* output: 1 caso o idoso tenha morrido ou o sensor é invalido, 0 caso contrario
* pre-condicao: idoso alocado
* pos-condicao: arquivo de saida do idoso preenchido com a interpretacao do sistema acerca do sensor */
int analisaSensorIdoso(Idoso* idoso, int sensor);

#endif