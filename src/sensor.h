#ifndef SENSOR_H_
#define SENSOR_H_

#include <stdio.h>
#include <math.h>
#include "LHSES.h"

typedef struct sensor Sensor;


Sensor* criaSensor(int leitura, float temp, float latitude, float longitude, int queda, int faleceu);
void liberaSensor(Sensor *sensor);
int verificaLeitura(Sensor* sensor, int leitura);
float getTemperatura(Sensor* sensor);
float getLatitude(Sensor* sensor);
float getLongitude(Sensor* sensor);
float getQueda(Sensor* sensor);
int isMorto(Sensor* sensor);
void liberaSensor(Sensor * sensor);
float distancia(Sensor* sensor1, Sensor* sensor2);

#endif