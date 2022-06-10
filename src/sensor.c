#include "sensor.h"

struct sensor {
    float temperatura;
    float latitude;
    float longitude;
    int queda;
    int faleceu;
};

Sensor* criaSensor(float temp, float latitude, float longitude, int queda){
    Sensor* sensor = malloc(sizeof(Sensor));
    sensor->temperatura = temp;
    sensor->latitude = latitude;
    sensor->longitude = longitude;
    sensor->queda = queda;
    return sensor;
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