#ifndef SENSOR_H_
#define SENSOR_H_

#include <stdio.h>
#include <math.h>
#include "lista.h"

/*Tipo que define o Sensor*/
typedef struct sensor Sensor;

/*Cria e aloca o Sensor
* inputs: numero de leitura do sensor, temperatura, latitude, longitude, se caiu, se houve falecimento
* output: sensor alocado
* pre-condicao: nao tem
* pos-condicao: sensor alocado */
Sensor* criaSensor(int leitura, float temp, float latitude, float longitude, int queda, int faleceu);

/*Libera a memoria alocada para o Sensor
* inputs: sensor
* output: nenhum
* pre-condicao: sensor alocado
* pos-condicao: memoria liberada */
void liberaSensor(Sensor *sensor);

/*Verifica se o sensor refere-se a uma certa leitura
* inputs: sensor, numero da leitura
* output: 1 para sim, 0 para nao
* pre-condicao: sensor alocado
* pos-condicao: nenhum */
int verificaLeitura(Sensor* sensor, int leitura);

/*Retorna a temperatura no sensor
* inputs: sensor
* output: temperatura no sensor
* pre-condicao: sensor alocado
* pos-condicao: nenhuma */
float getTemperatura(Sensor* sensor);

/*Retorna a latitude no sensor
* inputs: sensor
* output: latitude no sensor
* pre-condicao: sensor alocado
* pos-condicao: nenhuma */
float getLatitude(Sensor* sensor);

/*Retorna a longitude no sensor
* inputs: sensor
* output: longitude no sensor
* pre-condicao: sensor alocado
* pos-condicao: nenhuma */
float getLongitude(Sensor* sensor);

/*Retorna se houve queda
* inputs: sensor
* output: 1 para sim, 0 para nao
* pre-condicao: sensor alocado
* pos-condicao: nenhuma */
int getQueda(Sensor* sensor);

/*Retorna se houve falecimento
* inputs: sensor
* output: 1 para sim, 0 para nao
* pre-condicao: sensor alocado
* pos-condicao: nenhuma */
int isMorto(Sensor* sensor);

/*Libera toda a memoria alocada para o sensor
* inputs: sensor
* output: nenhum
* pre-condicao: sensor alocado
* pos-condicao: memoria liberada */
void liberaSensor(Sensor * sensor);

/*Calcula a distancia entre dois sensores
* inputs: sensor
* output: distancia entre os sensores
* pre-condicao: sensor alocado
* pos-condicao: nenhuma */
float distancia(Sensor* sensor1, Sensor* sensor2);

#endif