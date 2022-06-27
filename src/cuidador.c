#include "cuidador.h"

struct cuidador {
    char* nome;
    Lista* sensores;
};

Cuidador* criaCuidador(char* nome){
    Cuidador* cuidador = malloc(sizeof(Cuidador));
    cuidador->nome = strdup(nome);
    cuidador->sensores = criaLista();
    return cuidador;
}

char* getNomeCuidador(Cuidador* cuidador){
     return cuidador->nome;
}

void adicionaSensorCuidador(Cuidador* cuidador, Sensor* sensor){
    insereElemento(cuidador->sensores, sensor);
}

Lista* getSensoresCuidador(Cuidador* cuidador){
    return cuidador->sensores;
}


Cuidador* comparaDistanciaCuidador(Sensor* base, Cuidador* cuidador, Cuidador* cuidadorMaisProximo, int leitura) {
    Sensor* sensorCuidador = buscaCallback(getSensoresCuidador(cuidador), verificaLeitura, leitura);
    if (sensorCuidador == NULL) {
        return 0;
    }
    if (cuidadorMaisProximo == NULL){
        return 1;
    }
    Sensor* maisProximo = buscaCallback(getSensoresCuidador(cuidadorMaisProximo), verificaLeitura, leitura);
    if (distancia(base, sensorCuidador) < distancia(base, maisProximo)) {
        return 1;
    }
    return 0;
}

int verificaNomeCuidador(Cuidador* cuidador, char* nome) {
    if (strcmp(cuidador->nome,nome) == 0){
        return 1;
    }
    return 0;
}

void extraiSensorCuidador(Cuidador* cuidador){
    char aux[1024];
    int leitura = 0;
    float temperatura_aux = 0.0f;
    float latitude_aux = 0.0f;
    float longitude_aux = 0.0f;
    int queda_aux = 0.0f;

    strcpy(aux, cuidador->nome);
    strcat(aux, ".txt");
    FILE *file = fopen(aux,"r");

    if (file == NULL) {
        return;
    }
    while (fscanf(file, "%f;%f", &latitude_aux, &longitude_aux) != EOF){
        if (strcmp(aux, " ") == 0 || strcmp(aux, "\n") == 0) {
            break;
        }
        Sensor* sensor = criaSensor(leitura,temperatura_aux,latitude_aux,longitude_aux,queda_aux,0);

        adicionaSensorCuidador(cuidador, sensor);
        leitura += 1;
    }
  fclose(file);
}

void liberaCuidador(Cuidador* cuidador) {
    free(cuidador->nome);
    listaCallback(cuidador->sensores, liberaSensor);
    liberaLista(cuidador->sensores);
    free(cuidador);
}

