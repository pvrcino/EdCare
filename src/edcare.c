#include "edcare.h"

void imprimeNomes(void* teste);

int main(){
    Lista* idosos = criaLista();

    Idoso* idoso1 = criaIdoso("Joaquim");
    Idoso* idoso2 = criaIdoso("Joao");
    Idoso* idoso3 = criaIdoso("Maria");

    insereElemento(idosos, idoso1, IDOSO);
    insereElemento(idosos, idoso2, IDOSO);
    insereElemento(idosos, idoso3, IDOSO);

    listaCallback(idosos, imprimeNomes);
    listaCallback(idosos, liberaIdoso);
    liberaLista(idosos);
    return 0;
}

void imprimeNomes(void* teste){
    Idoso* idoso = teste;
    imprimeNome(idoso);
}
