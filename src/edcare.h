#ifndef EDCARE_H_
#define EDCARE_H_

#include <stdlib.h>
#include <stdio.h>

#include "idoso.h"

/*Tipo que define o Edcare*/
typedef struct edcare Edcare;

/*Cria e aloca o Edcare, além das suas listas de apoio e cuidadores
* inputs: numero de sensores
* output: edcare alocado
* pre-condicao: nao tem
* pos-condicao: edcare alocado e suas listas criadas */
Edcare* inicializaEdcare(int numeroSensores);

/*Le o arquivo de apoio, aloca os idosos e da setup na lista de amizades
* inputs: edcare
* output: nenhum
* pre-condicao: edcare alocado
* pos-condicao: idosos alocados e inseridos na lista */
void inicializaApoio(Edcare* edcare);

/*Le o arquivo de cuidadores, aloca os cuidadores e da setup na lista de cuidadores dos idosos
* inputs: edcare
* output: nenhum
* pre-condicao: edcare alocado
* pos-condicao: cuidadores alocados e inseridos na lista */
void inicializaCuidadores(Edcare* edcare);


/*Le o arquivo de cada pessoa do edcare e extrai seus sensores
* inputs: edcare
* output: nenhum
* pre-condicao: edcare alocado, arquivos de cada pessoa existem
* pos-condicao: sensores inseridos em suas respectivas listas */
void extraiSensores(Edcare* edcare);

/*Analisa os sensores de cada idoso e gera seu output
* inputs: edcare
* output: nenhum
* pre-condicao: edcare alocado
* pos-condicao: pessoas falecidas removidas do edcare e arquivos de saida gerados */
void analisaSensores(Edcare* edcare);

/*Finaliza o edcare liberando toda a memoria alocada
* inputs: edcare
* output: nenhum
* pre-condicao: edcare alocado
* pos-condicao: toda memoria do sistema liberada */
void finalizaEdcare(Edcare* edcare);
#endif