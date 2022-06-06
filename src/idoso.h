#ifndef IDOSO_H_
#define IDOSO_H_

#include <stdio.h>
#include "LHSES.h"

typedef struct idoso Idoso;

Idoso* criaIdoso(char* nome, Lista* amigos, Lista* cuidadores, Lista* sensores);

int registraFebreBaixa(Idoso* idoso);
int registraFebreAlta(Idoso* idoso);

void adicionaAmigo(Idoso* idoso1, Idoso* idoso2);
void buscaAmigoPorNome(Idoso* idoso, Idoso* amigo);

void registraFalecimento(Idoso* idoso);

void liberaIdoso(Idoso* idoso);

#endif