#include "edcare.h"

int NUMBER_OF_SENSORS = 0;

int main(int argc, char *argv[]){

    if (argc < 2) {
        printf("Insira o numero de sensores: ");
        scanf("%d",&NUMBER_OF_SENSORS);
    } else{
        NUMBER_OF_SENSORS = atoi(argv[1]);
    }

    Lista* idosos = constroiListaApoio();
    Lista* cuidadores = constroiListaCuidadores(idosos);
    listaCallback(idosos,extraiSensorIdoso);
    listaCallback(cuidadores, extraiSensorCuidador);

    listaCallback(idosos, analisaSensores);

    listaCallback(idosos, liberaIdoso);
    listaCallback(cuidadores, liberaCuidador);

    liberaLista(cuidadores);

    liberaLista(idosos);

    return EXIT_SUCCESS;
}

Lista* constroiListaApoio() {
    FILE *apoio = fopen("apoio.txt","r");
    Lista* idosos = criaLista();

    if (apoio == NULL) {
        printf("ARQUIVO DE APOIO NAO ENCONTRADO!");
        liberaLista(idosos);
        return NULL;
    } else {
        char aux[1024];
        fscanf (apoio, "%[^\n]\n", aux);
        char *ptr = strtok(aux, "; ");

        while (ptr != NULL){
            Idoso* idoso = criaIdoso(ptr);
            insereElemento(idosos, idoso, IDOSO);
            ptr = strtok(NULL, "; ");
        }

        while (fscanf (apoio, "%[^\n]\n", aux)) {
            if (strcmp(aux, " ") == 0) {
                break;
            }
            char *ptr = strtok(aux, "; ");
            Idoso* idoso1 = buscaCallback(idosos,verificaNomeIdoso,ptr);

            ptr = strtok(NULL, "; ");
            Idoso* idoso2 = buscaCallback(idosos,verificaNomeIdoso,ptr);

            if (idoso1 == NULL || idoso2 == NULL){
                printf("%s - IDOSO NAO ENCONTRADO!\n", aux);
            }

            adicionaAmigo(idoso1, idoso2);
            strcpy(aux, " ");
        }
    }
    fclose(apoio);
    return idosos;
}


Lista* constroiListaCuidadores(Lista* idosos){
    FILE *apoio = fopen("cuidadores.txt","r");
    Lista* cuidadores = criaLista();

    if (apoio == NULL) {
        printf("ARQUIVO DE CUIDADORES NAO ENCONTRADO!");
        liberaLista(cuidadores);
        liberaLista(idosos);
        return NULL;
    } else {
        char aux[1024];
        fscanf (apoio, "%[^\n]\n", aux);
        char *ptr = strtok(aux, "; ");

        while (ptr != NULL){
            Cuidador* cuidador = criaCuidador(ptr);
            insereElemento(cuidadores, cuidador, CUIDADOR);
            ptr = strtok(NULL, "; ");
        }

        while (fscanf (apoio, "%[^\n]\n", aux)) {
            if (strcmp(aux, " ") == 0) {
                break;
            }
            char *ptr = strtok(aux, "; ");
            Idoso* idoso = buscaCallback(idosos,verificaNomeIdoso,ptr);
            ptr = strtok(NULL, "; ");

            while (ptr != NULL){
                Cuidador* cuidador = buscaCallback(cuidadores,verificaNomeCuidador,ptr);
                if (cuidador == NULL){
                    printf("Cuidador %s nao encontrado!", ptr);
                    break;
                }
                adicionaCuidador(idoso, cuidador);
                ptr = strtok(NULL, ";");
            }
            strcpy(aux, " ");
        }
    }
    fclose(apoio);
    return cuidadores;
}

int analisaSensores(Idoso* idoso) {
    int febresBaixas = 0;
    char* aux[1024];
    strcat(strcpy(aux, getNome(idoso)), "-saida.txt");
    FILE *file = fopen(aux,"a");
    for (int i = 0; i < NUMBER_OF_SENSORS; i++) {
        Sensor* s = buscaCallback(getSensores(idoso), verificaLeitura, i);
        if (s == NULL){
            break;
        }
        if (isMorto(s)) {
            fprintf(file, "falecimento\n");
            fclose(file);
            return 1;
        }
        if (getQueda(s)) {
            Cuidador* c = getCuidadorProximo(idoso, i);
            if (c == NULL){
                fprintf(file, "Queda mas, infelizmente, o idoso está sem cuidadores na rede\n");
            } else{
                fprintf(file, "queda, acionou %s\n", getNomeCuidador(c));
            }
        }else if (getTemperatura(s) >= 38){
            Cuidador* c = getCuidadorProximo(idoso, i);
            febresBaixas = 0;
            if (c == NULL){
                fprintf(file, "Febre alta mas, infelizmente, o idoso está sem cuidadores na rede\n");
            } else{
                fprintf(file, "febre alta, acionou %s\n", getNomeCuidador(c));
            }
        }else if (getTemperatura(s) > 37) {
            febresBaixas += 1;
            if (febresBaixas >= 4) {
                Cuidador* c = getCuidadorProximo(idoso, i);
                if (c == NULL){
                    fprintf(file, "Febre baixa pela quarta vez mas, infelizmente, o idoso está sem cuidadores na rede\n");
                } else{
                    fprintf(file, "febre baixa pela quarta vez, acionou %s\n", getNomeCuidador(c));
                }
            } else {
                Idoso* amigo = getAmigoProximo(idoso, i);
                if (amigo == NULL){
                    fprintf(file, "Febre baixa mas, infelizmente, o idoso está sem amigos na rede\n");
                } else{
                    fprintf(file, "febre baixa, acionou amigo %s\n", getNome(amigo));
                }
            }
        } else {
            fprintf(file, "tudo ok\n");
        }
    }
    fclose(file);
}