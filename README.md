INTRODUÇÃO

Desde o advento da revolução industrial em 1760, há um aumento exponencial da qualidade de vida da população global. Com isso, a expectativa de vida mundial tornou-se um bem de valor inimaginável que cresceu e trouxe consigo algumas problemáticas.
É de conhecimento público que idosos sofrem com incapacidades diárias, sejam elas físicas ou até mesmo sociais, já que estes geralmente têm filhos, que crescem e seguem sua própria vida. Devido a isso, é necessário que seja utilizado a própria tecnologia que foi capaz de abrir a possibilidade de viver-se mais tempo para que isso seja feito com maior qualidade e segurança.
Com isso, surge o EDCARE. Um sistema que visa monitorar idosos através de sensores para detectar seus problemas físicos, além disso, integrá-los em um sistema de apoio entre cuidadores e amigos deles mesmos! O sistema possui sensores capazes de monitorar a temperatura do idoso, sua posição geográfica e até mesmo se houve uma queda em algum momento da leitura. Além disso notifica amigos ou cuidadores em determinadas circunstâncias sejam elas:
Em caso de queda e/ou febre alta (igual ou acima de 38) o sistema aciona o cuidador, equipado com sensores de geolocalização, mais próximo do idoso.
Em caso de febre baixa, o sistema chama o amigo mais próximo ao idoso.
Em caso de 4 episódios de febre baixa sequenciais, o sistema chama o cuidador mais próximo ao idoso.


IMPLEMENTAÇÃO

O sistema foi feito de modo a fazer uso de estrutura de dados de listas encadeadas, utilizando sempre um uso consciente de memória. O GCC utilizado para compilar e testar o programa foi a versão gcc (Debian 11.3.0-3) 11.3.0. Já o valgrind utilizado para testar possíveis vazamentos de memória foi o valgrind-3.18.1. E por fim o makefile utilizado para construir o arquivo de execução do projeto foi o GNU Make 4.3.
Estrutura de Dados
As TADs de idosos, cuidadores e sensores foram implementadas seguindo o diagrama abaixo, onde os idosos carregam consigo uma lista de amigos, outra lista de cuidadores e outra de sensores, de modo que um ponteiro de idoso carrega consigo todos dados necessários referentes a este idoso. A escolha foi realizada para facilitar a manipulação destes dados, além de estruturar bem o sistema em si.


A estrutura da lista encadeada escolhida foi uma lista genérica com sentinela, utilizada para armazenar todo tipo de dado necessário no sistema. A tipagem dentro da TAD da célula da lista, definindo o item como do tipo void* fez com que isso fosse possível, de modo a deixar o sistema mais maleável e com um tipo único de estrutura de dados. Além disso, foi utilizada a sentinela de modo a dar proteção na manipulação dos dados desta, além de simplificar o tipo de inserção utilizado (inserção ao final).

Principais funções
	As funções utilizadas para manipular essas listas utilizam CALLBACKs. Callbacks são funções que são passadas como parâmetro para outras funções. No EdCare, alguns exemplos de funções que recebem callbacks são as documentadas no arquivo lista.h:

	void listaCallback(Lista* lista, void (*callback)(void *))
	/*Executa um callback para todos os items da lista.
	* inputs: lista, funcao callback
	* output: nenhum
	* pre-condicao: lista ja criada, callback recebe os items da lista como parametro
	* pos-condicao: callback realizado*/


	void* buscaCallback(Lista* lista, int (*callback)(void *, void*), void* chave);
	/*Executa um callback para buscar um item da lista.
	* inputs: lista, funcao callback, chave para a busca
	* output: item procurado pelo callback
	* pre-condicao: lista ja criada, callback recebe os items da lista como parametro e uma chave
	* pos-condicao: nenhuma*/

	void* comparaCallback(Lista* lista, int (*callback)(void*, void *, void*, int), void* base, int referencia);
	/*Executa um callback para comparar items da lista.
	* inputs: lista, funcao callback, chave de base e uma referencia do item a ser comparado
	* output: item que seja requisitado na comparacao (maior, menor, igual...)
	* pre-condicao: lista ja criada, callback recebe os items da lista como parametro, uma chave, uma base e a referencia
	* pos-condicao: nenhuma*/

	Lista* retiraCallback(Lista* lista, int retirada, int (*callback)(void *, int));
	/*Executa um callback para os items que atendam o requisito de um callback a uma base.
	* inputs: lista, uma base, funcao callback
	* output: lista de items procurados pelo callback
	* pre-condicao: lista ja criada, callback recebe os items da lista como parametro e uma referencia
	* pos-condicao: nenhuma*/
	
Com isso, podemos manter a lista de forma a suportar qualquer tipo de variável a ser armazenada em suas células, já que a manipulação destas é feita via callback. Um exemplo disso, é o “listaCallback”, usado no arquivo “edcare.c” nas linhas 106 e 107 para chamar a função de extração de sensores, ou nas linhas 120 e 121 para fazer a liberação de memória de todos os idosos presentes na lista.

CONCLUSÃO

Por fim, é mister salientar que o processo de criação do EdCare fez com que diversas habilidades dentro do aspecto da programação fossem desenvolvidas, como o uso consciente de memória, criação de algoritmos, callbacks e estruturas de dados. Em sua programação houveram algumas dificuldades devido a escolha do tipo da lista, já que esta é de um tipo mais maleável, o que traz algumas consequências como maior atenção no tratamento dos dados. Porém, no geral essa escolha foi proveitosa.
BIBLIOGRAFIA
https://www.geeksforgeeks.org/callbacks-in-c/, Geeks for Geeks, 2019
https://aticleworld.com/generic-linked-list-in-c/#:~:text=In%20C%20language%2C%20we%20can,address%20of%20any%20data%20type., Florin Curelaru, 2020
https://gcc.gnu.org/onlinedocs/gcc-11.3.0/gcc/, Free Software Foundation, Inc.
https://valgrind.org/docs/
https://www.gnu.org/software/make/manual/make.html
