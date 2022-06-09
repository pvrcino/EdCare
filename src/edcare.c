#include "edcare.h"

int main(int argc, char *argv[]){

    int NUMBER_OF_SENSORS = 0;
    if (argc < 2) {
        printf("Insira o numero de sensores: ");
        scanf("%d",&NUMBER_OF_SENSORS);
    } else{
        NUMBER_OF_SENSORS = atoi(argv[1]);
    }

    Lista* idosos = constroiListaApoio();
    Lista* cuidadores = constroiListaCuidadores(idosos);
    listaCallback(idosos,extraiSensorIdoso);

    // Idoso* joao = buscaCallback(idosos,verificaNomeIdoso,"Joao");
    // listaCallback(getCuidadores(joao), imprimeCuidador);
    // listaCallback(cuidadores, imprimeIdoso);

    listaCallback(idosos, liberaIdoso);
    listaCallback(cuidadores, liberaCuidador);

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
        char aux[2048];
        fscanf (apoio, "%[^\n]\n", aux);
        char *ptr = strtok(aux, ";");

        while (ptr != NULL){
            Idoso* idoso = criaIdoso(ptr);
            insereElemento(idosos, idoso, IDOSO);
            ptr = strtok(NULL, ";");
        }

        while (fscanf (apoio, "%[^\n]\n", aux)) {
            if (strcmp(aux, " ") == 0) {
                break;
            }
            char *ptr = strtok(aux, ";");
            Idoso* idoso1 = buscaCallback(idosos,verificaNomeIdoso,ptr);

            ptr = strtok(NULL, ";");
            Idoso* idoso2 = buscaCallback(idosos,verificaNomeIdoso,ptr);

            if (idoso1 == NULL || idoso2 == NULL){
                printf("%s - IDOSO NAO ENCONTRADO!\n", aux);
            }

            adicionaAmigo(idoso1, idoso2);
            strcpy(aux, " ");
        }
    }
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
        char aux[2048];
        fscanf (apoio, "%[^\n]\n", aux);
        char *ptr = strtok(aux, ";");

        while (ptr != NULL){
            Cuidador* cuidador = criaCuidador(ptr);
            insereElemento(cuidadores, cuidador, CUIDADOR);
            ptr = strtok(NULL, ";");
        }

        while (fscanf (apoio, "%[^\n]\n", aux)) {
            if (strcmp(aux, " ") == 0) {
                break;
            }
            char *ptr = strtok(aux, ";");
            Idoso* idoso = buscaCallback(idosos,verificaNomeIdoso,ptr);
            ptr = strtok(NULL, ";");

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
    return cuidadores;
}
