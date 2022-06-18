#include "idoso.h"

struct idoso {
    char* nome;
    Lista* amigos;
    Lista* cuidadores;
    Lista* sensores;
};

Idoso* criaIdoso(char* nome){
    Idoso* idoso = malloc(sizeof(Idoso));
    idoso->nome = strdup(nome);
    idoso->amigos = criaLista();
    idoso->cuidadores = criaLista();
    idoso->sensores = criaLista();
}

Lista* getAmigos(Idoso* idoso){
    return idoso->amigos;
}


int verificaNomeIdoso(Idoso* idoso, char* nome) {
    if (strcmp(idoso->nome,nome) == 0){
        return 1;
    }
    return 0;
}

char* getNome(Idoso* idoso){
    return idoso->nome;
}

Lista* getCuidadores(Idoso* idoso){
    return idoso->cuidadores;
}

void imprimeIdoso(Idoso* idoso){
    printf("%s\n", idoso->nome);
}

void adicionaAmigo(Idoso* idoso1, Idoso* idoso2){
    insereElemento(idoso1->amigos, idoso2, IDOSO);
    insereElemento(idoso2->amigos, idoso1, IDOSO);
}

void adicionaCuidador(Idoso* idoso, Cuidador* cuidador){
    insereElemento(idoso->cuidadores, cuidador, CUIDADOR);
}

void adicionaSensorIdoso(Idoso* idoso, Sensor* sensor){
    insereElemento(idoso->sensores, sensor, SENSOR);
}

void registraFalecimento(Idoso* idoso){
    // liberaIdoso(idoso);
}

void extraiSensorIdoso(Idoso* idoso){
    char aux[1024];
    float temperatura_aux = 0.0f;
    float latitude_aux = 0.0f;
    float longitude_aux = 0.0f;
    int queda_aux = 0.0f;

    strcat(strcpy(aux, idoso->nome), ".txt");
    FILE *file = fopen(aux,"r");

    if (file == NULL) {
        return;
    }
    while (fscanf (file, "%[^\n]\n", aux) != EOF){
        if (strcmp(aux,"falecimento") == 0){
            registraFalecimento(idoso);
            break;
        }
        sscanf(aux, "%f;%f;%f;%d", &temperatura_aux, &latitude_aux, &longitude_aux, &queda_aux);
        Sensor* sensor = criaSensor(temperatura_aux,latitude_aux,longitude_aux,queda_aux);
        adicionaSensorIdoso(idoso, sensor);
    }
  fclose(file);
}

void liberaIdoso(Idoso* idoso) {
    free(idoso->nome);
    liberaLista(idoso->amigos);
    liberaLista(idoso->cuidadores);
    listaCallback(idoso->sensores, liberaSensor);
    liberaLista(idoso->sensores);
    free(idoso);
}