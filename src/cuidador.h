#ifndef CUIDADOR_H_
#define CUIDADOR_H_

#include <stdio.h>
#include <string.h>
#include "sensor.h"

/*Tipo que define o Cuidador*/
typedef struct cuidador Cuidador;

/*Cria e aloca um Cuidador, além de suas listas de sensores
* inputs: nome do cuidador
* output: cuidador alocado
* pre-condicao: nao tem
* pos-condicao: cuidador alocado e lista interna de sensores criada */
Cuidador* criaCuidador(char* nome);

/*Adiciona uma leitura de sensor a lista de sensores do cuidador
* inputs: o cuidador e o sensor
* output: nenhum
* pre-condicao: o sensor já deve ter sido criado e o cuidador também
* pos-condicao: sensor inserido na ultima posicao da lista */
void adicionaSensorCuidador(Cuidador* cuidador, Sensor* sensor);


/*Extrai os sensores do cuidador de seu arquivo txt
* inputs: o cuidador
* output: nenhum
* pre-condicao: nao tem
* pos-condicao: cuidador alocado e lista interna de sensores criada */
void extraiSensorCuidador(Cuidador* cuidador);


/*Retorna o nome do cuidador
* inputs: o cuidador
* output: nome do cuidador
* pre-condicao: nao tem
* pos-condicao: nenhum */
char* getNomeCuidador(Cuidador* cuidador);


/*Verifica o nome do cuidador
* inputs: o cuidador e o nome a ser comparado
* output: 1 para igual, 0 para diferente
* pre-condicao: cuidador alocado
* pos-condicao: nenhum */
int verificaNomeCuidador(Cuidador* cuidador, char* nome);

/*Retorna uma lista de sensores do cuidador
* inputs: o cuidador
* output: lista de sensores do cuidador
* pre-condicao: cuidador criado
* pos-condicao: nenhum */
Lista* getSensoresCuidador(Cuidador* cuidador);

/*Retorna o cuidador mais proximo entre dois de um sensor base
* inputs: o sensor base, os cuidadores e o numero de leitura do sensor base
* output: cuidador mais proximo da base
* pre-condicao: cuidadores criados e sensor base criado
* pos-condicao: nenhum */
Cuidador* comparaDistanciaCuidador(Sensor* base, Cuidador* cuidador, Cuidador* cuidadorMaisProximo, int leitura);

/*Libera toda a memoria alocada do cuidador".
* inputs: o cuidador
* output: nenhum
* pre-condicao: cuidador nao nulo
* pos-condicao: toda memoria alocada liberada*/
void liberaCuidador(Cuidador* cuidador);


#endif