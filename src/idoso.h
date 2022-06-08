#ifndef IDOSO_H_
#define IDOSO_H_

#include <stdio.h>
#include <string.h>
#include "cuidador.h"

typedef struct idoso Idoso;

Idoso* criaIdoso(char* nome);

int registraFebreBaixa(Idoso* idoso);
int registraFebreAlta(Idoso* idoso);

void adicionaAmigo(Idoso* idoso1, Idoso* idoso2);
void adicionaCuidador(Idoso* idoso, Cuidador* cuidador);
void adicionaSensorIdoso(Idoso* idoso, Sensor* sensor);

void registraFalecimento(Idoso* idoso);

void liberaIdoso(Idoso* idoso);

#endif