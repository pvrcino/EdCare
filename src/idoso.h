#ifndef IDOSO_H_
#define IDOSO_H_

#include <stdio.h>
#include <string.h>
#include "cuidador.h"

typedef struct idoso Idoso;

Idoso* criaIdoso(char* nome);

int registraFebreBaixa(Idoso* idoso);
int registraFebreAlta(Idoso* idoso);

Lista* getAmigos(Idoso* idoso);

char* getNome(Idoso* idoso);
Lista* getCuidadores(Idoso* idoso);
Lista* getSensores(Idoso* idoso);

int verificaNomeIdoso(Idoso* idoso, char* nome);
Cuidador* getCuidadorProximo(Idoso* idoso, int leitura);
Cuidador* comparaDistanciaCuidador(Sensor* base, Cuidador* cuidador, Cuidador* cuidadorMaisProximo, int leitura);

void adicionaAmigo(Idoso* idoso1, Idoso* idoso2);
void adicionaCuidador(Idoso* idoso, Cuidador* cuidador);
void adicionaSensorIdoso(Idoso* idoso, Sensor* sensor);
void imprimeIdoso(Idoso* idoso);

Idoso* getAmigoProximo(Idoso* idoso, int leitura);
Idoso* comparaDistanciaAmigos(Sensor* base, Idoso* amigo, Idoso* amigoMaisProximo, int leitura);

void registraFalecimento(Idoso* idoso);

void liberaIdoso(Idoso* idoso);
Lista* getCuidadores(Idoso* idoso);
void extraiSensorIdoso(Idoso* idoso);
#endif