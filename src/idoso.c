#include "idoso.h"

struct idoso {
    char* nome;
    Lista* amigos;
    Lista* cuidadores;
    Lista* sensores;

    int febresBaixas;
};

Idoso* criaIdoso(char* nome){
    Idoso* idoso = malloc(sizeof(Idoso));
    idoso->nome = strdup(nome);
    idoso->amigos = criaLista();
    idoso->cuidadores = criaLista();
    idoso->sensores = criaLista();
    idoso->febresBaixas = 0;
}

void registraFebreBaixa(Idoso* idoso) {
    idoso->febresBaixas+=1;
}

void resetaFebreBaixa(Idoso* idoso){
    idoso->febresBaixas = 0;
}

int getFebreBaixa(Idoso* idoso){
    return idoso->febresBaixas;
}

Lista* getAmigos(Idoso* idoso){
    return idoso->amigos;
}

char* getNome(Idoso* idoso){
    return idoso->nome;
}

Lista* getCuidadores(Idoso* idoso){
    return idoso->cuidadores;
}

Lista* getSensores(Idoso* idoso){
    return idoso->sensores;
}

void adicionaAmigo(Idoso* idoso1, Idoso* idoso2){
    insereElemento(idoso1->amigos, idoso2);
    insereElemento(idoso2->amigos, idoso1);
}

void removeAmigo(Idoso* idoso1, Idoso* idoso2){
    retira(idoso1->amigos, idoso2);
    retira(idoso2->amigos, idoso1);
}

void adicionaCuidador(Idoso* idoso, Cuidador* cuidador){
    insereElemento(idoso->cuidadores, cuidador);
}

void adicionaSensorIdoso(Idoso* idoso, Sensor* sensor){
    insereElemento(idoso->sensores, sensor);
}

void registraFalecimento(Idoso* idoso){
    listaCallbackBase(idoso->amigos, idoso, removeAmigo);

    liberaIdoso(idoso);
}

Idoso* getAmigoProximo(Idoso* idoso, int leitura){
    Sensor* sensorIdoso = buscaCallback(getSensores(idoso), verificaLeitura, leitura);
    Idoso* proximo = comparaCallback(getAmigos(idoso), comparaDistanciaAmigos, sensorIdoso, leitura);
    return proximo;
}

Cuidador* getCuidadorProximo(Idoso* idoso, int leitura){
    Sensor* sensorIdoso = buscaCallback(getSensores(idoso), verificaLeitura, leitura);
    Cuidador* proximo = comparaCallback(getCuidadores(idoso), comparaDistanciaCuidador, sensorIdoso, leitura);
    return proximo;
}

Idoso* comparaDistanciaAmigos(Sensor* base, Idoso* amigo, Idoso* amigoMaisProximo, int leitura) {
    Sensor* sensorAmigo = buscaCallback(getSensores(amigo), verificaLeitura, leitura);
    if (sensorAmigo == NULL) {
        return 0;
    }
    if (isMorto(sensorAmigo)){
        return 0;
    }
    if (amigoMaisProximo == NULL){
        return 1;
    }
    if (distancia(base, sensorAmigo) < distancia(base, buscaCallback(getSensores(amigoMaisProximo), verificaLeitura, leitura))) {
        return 1;
    }
    return 0;
}

void extraiSensorIdoso(Idoso* idoso){
    char aux[1024];
    int leitura = 0;
    int falecimento = 0;
    float temperatura_aux = 0.0f;
    float latitude_aux = 0.0f;
    float longitude_aux = 0.0f;
    int queda_aux = 0.0f;
    
    strcat(strcpy(aux, idoso->nome), ".txt");
    FILE *file = fopen(aux,"r");

    if (file == NULL) {
        return;
    }
    while (fscanf (file, "%[^\r]%*[\r]", aux)) {
        if (strcmp(aux, " ") == 0 || strcmp(aux, "\n") == 0) {
            break;
        }
        if (strcmp(aux,"\nfalecimento") == 0 || strcmp(aux,"falecimento") == 0){
            falecimento = 1;
        } else {
            sscanf(aux, "%f;%f;%f;%d", &temperatura_aux, &latitude_aux, &longitude_aux, &queda_aux);
        }
        Sensor* sensor = criaSensor(leitura,temperatura_aux,latitude_aux,longitude_aux,queda_aux,falecimento);
        adicionaSensorIdoso(idoso, sensor);
        leitura += 1;
    }
  fclose(file);
}

int analisaSensorIdoso(Idoso* idoso, int sensor) {
    char* aux[1024];
    strcat(strcpy(aux, getNome(idoso)), "-saida.txt");
    FILE *file = fopen(aux,"a");

    Sensor* s = buscaCallback(getSensores(idoso), verificaLeitura, sensor);
    if (s == NULL){
        fflush (file);
        fclose(file);
        return 1;
    }
    if (isMorto(s)) {
        fprintf(file, "falecimento\n");
        fflush (file);
        fclose(file);
        return 1;
    }
    if (getQueda(s)) {
        Cuidador* c = getCuidadorProximo(idoso, sensor);
        if (c == NULL){
            fprintf(file, "Queda mas, infelizmente, o idoso está sem cuidadores na rede\n");
        } else{
            fprintf(file, "queda, acionou %s\n", getNomeCuidador(c));
        }
    }else if (getTemperatura(s) >= 38){
        Cuidador* c = getCuidadorProximo(idoso, sensor);
        resetaFebreBaixa(idoso);
        if (c == NULL){
            fprintf(file, "Febre alta mas, infelizmente, o idoso está sem cuidadores na rede\n");
        } else{
            fprintf(file, "febre alta, acionou %s\n", getNomeCuidador(c));
        }
    }else if (getTemperatura(s) > 37) {
        registraFebreBaixa(idoso);
        if (getFebreBaixa(idoso) >= 4) {
            Cuidador* c = getCuidadorProximo(idoso, sensor);
            if (c == NULL){
                fprintf(file, "Febre baixa pela quarta vez mas, infelizmente, o idoso está sem cuidadores na rede\n");
            } else{
                fprintf(file, "febre baixa pela quarta vez, acionou %s\n", getNomeCuidador(c));
                resetaFebreBaixa(idoso);
            }
        } else {
            Idoso* amigo = getAmigoProximo(idoso, sensor);
            if (amigo == NULL){
                fprintf(file, "Febre baixa mas, infelizmente, o idoso está sem amigos na rede\n");
            } else {
                fprintf(file, "febre baixa, acionou amigo %s\n", getNome(amigo));
            }
        }
    } else {
        fprintf(file, "tudo ok\n");
    }
    fflush (file);
    fclose(file);
    return 0;
}

int verificaNomeIdoso(Idoso* idoso, char* nome) {
    if (strcmp(idoso->nome,nome) == 0){
        return 1;
    }
    return 0;
}

void liberaIdoso(Idoso* idoso) {
    free(idoso->nome);
    liberaLista(idoso->amigos);
    liberaLista(idoso->cuidadores);
    listaCallback(idoso->sensores, liberaSensor);
    liberaLista(idoso->sensores);
    free(idoso);
}