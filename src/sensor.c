#include "sensor.h"

struct sensor {
    int leitura;
    float temperatura;
    float latitude;
    float longitude;
    int queda;
    int faleceu;
};

Sensor* criaSensor(int leitura, float temp, float latitude, float longitude, int queda, int faleceu){
    Sensor* sensor = malloc(sizeof(Sensor));
    sensor->leitura = leitura;
    sensor->temperatura = temp;
    sensor->latitude = latitude;
    sensor->longitude = longitude;
    sensor->queda = queda;
    sensor->faleceu = faleceu;
    return sensor;
}

int verificaLeitura(Sensor* sensor, int leitura) {
    if (sensor->leitura == leitura) {
        return 1;
    }
    return 0;
}

float distancia(Sensor* sensor1, Sensor* sensor2) {
    float soma = pow((sensor1->latitude-sensor2->latitude), 2) + pow((sensor1->longitude-sensor2->longitude), 2);
    return sqrt(soma);
}

float getTemperatura(Sensor* sensor){
    return sensor->temperatura;
}
float getLatitude(Sensor* sensor){
    return sensor->latitude;
}
float getLongitude(Sensor* sensor){
    return sensor->longitude;
}
float getQueda(Sensor* sensor){
    return sensor->queda;
}
int isMorto(Sensor* sensor){
    return sensor->faleceu;
}
void liberaSensor(Sensor * sensor){
    free(sensor);
}