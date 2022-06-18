#include "cuidador.h"

struct cuidador {
    char* nome;
    Lista* sensores;
};

Cuidador* criaCuidador(char* nome){
    Cuidador* cuidador = malloc(sizeof(Cuidador));
    cuidador->nome = strdup(nome);
    cuidador->sensores = criaLista();
}

void imprimeCuidador(Cuidador* cuidador){
    printf("%s\n", cuidador->nome);
}

void adicionaSensorCuidador(Cuidador* cuidador, Sensor* sensor){
    insereElemento(cuidador->sensores, sensor, CUIDADOR);
}

void extraiSensorCuidador(Cuidador* cuidador){
    char aux[1024];
    float temperatura_aux = 0.0f;
    float latitude_aux = 0.0f;
    float longitude_aux = 0.0f;
    int queda_aux = 0.0f;

    strcat(strcpy(aux, cuidador->nome), ".txt");
    FILE *file = fopen(aux,"r");

    if (file == NULL) {
        return;
    }
    while (fscanf(file, "%f;%f", &latitude_aux, &longitude_aux) != EOF){
        Sensor* sensor = criaSensor(temperatura_aux,latitude_aux,longitude_aux,queda_aux);
        adicionaSensorCuidador(cuidador, sensor);
    }
  fclose(file);
}

int verificaNomeCuidador(Cuidador* cuidador, char* nome) {
    if (strcmp(cuidador->nome,nome) == 0){
        return 1;
    }
    return 0;
}

void liberaCuidador(Cuidador* cuidador) {
    free(cuidador->nome);
    listaCallback(cuidador->sensores, liberaSensor);
    liberaLista(cuidador->sensores);
    free(cuidador);
}