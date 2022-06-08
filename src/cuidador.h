#ifndef CUIDADOR_H_
#define CUIDADOR_H_

#include <stdio.h>
#include "sensor.h"

typedef struct cuidador Cuidador;

Cuidador* criaCuidador(char* nome);

void adicionaSensorCuidador(Cuidador* cuidador, Sensor* sensor);

#endif