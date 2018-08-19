#ifndef LISTA_H_
#define LISTA_H_

/*
celula Celula (tipo opaco). Contém campos:
	- info(void*);
	- prox(Celula*);
*/
typedef struct celula Celula;

/*
lista Lista (tipo opaco). Contém campos:
	- prim(Celula*)
	- ult(Celula*)
*/
typedef struct lista Lista;

/*
- Cria uma Struct de Lista
* inputs: Nada
* output: A lista criada (vazia)
* pre-condicao: Não há
* pos-condicao: Lista criada e sem elementos
*/
Lista* cria_lista();

/*
- Informa se uma lista está vazia ou não.
* inputs: Lista
* output: Um inteiro informando se é vazia ou não
* pre-condicao: Não há
* pos-condicao: Valor 1 para vazia e 0 para não vazia
*/
int vazia_lista(Lista*);

/*
- Insere elementos na ordem crescente em uma lista
* inputs: Lista e o elemnto a ser inserido
* output: Nada
* pre-condicao: Lista não nula
* pos-condicao: Elemento na ordem crescente
*/
void insere_crescente_lista(Lista*, void*,int (*) (void*));

/*
- Insere elementos na última posição de uma lista
* inputs: Lista e o elemnto a ser inserido
* output: Nada
* pre-condicao: Lista não nula
* pos-condicao: Elemento inserido no final da lista
*/
void insere_lista(Lista*,void*);

/*
- Retira o primeiro elemento da lista
* inputs: Lista
* output: Retorna a célula retirada, caso não tenha retorna NULL
* pre-condicao: Lista não nula
* pos-condicao: Lista sem o elemento
*/
void* retira_lista(Lista*);

/*
- Libera a mémoria de uma lista
* inputs: Lista
* output: Nada
* pre-condicao: Lista não nula
* pos-condicao: Libera a lista e as células e o conteúdo das células
*/
void libera_lista(Lista*,void (*) (void*));

/*
- Retorna a info (void*) de uma celula
* inputs: Celula
* output: Info da celula (void*)
* pre-condicao: Celula não nula
* pos-condicao: Campo info da Celula é retornado
*/
void* retorna_info(Celula*);

/*
- Retorna a primeira célula de uma Lista
* inputs: Lista
* output: Primeira célula de uma lista
* pre-condicao: Não há
* pos-condicao: Campo prim da Lista é retornado
*/
Celula* retorna_primeiro(Lista*);

/*
- Retorna a última célula de uma Lista
* inputs: Lista
* output: Última célula de uma lista
* pre-condicao: Não há
* pos-condicao: Campo ult da Lista é retornado
*/
Celula* retorna_ultimo(Lista*);

/*
- Retorna o próximo elemento de uma celula
* inputs: Celula
* output: Proximo elemento (celula) de uma célula
* pre-condicao: Não há
* pos-condicao: Campo prox da Celula é retornado
*/
Celula* retorna_proximo(Celula*);

/*
- Passa as informações da lista para um vetor de vetores
* inputs: Lista, função, vetor
* output: Nada
* pre-condicao: Lista não nula
* pos-condicao: Vetor preenchido com os binários
*/
void preenche_vetor(Lista*,void (*) (void*, char**), char**);

/*
- Imprime a lista
* inputs: Lista e função de imprimir o elemento da célula
* output: Nada
* pre-condicao: Lista não nula
* pos-condicao: Lista impressa
*/
void imprime_lista(Lista*,void (*) (void*));

#endif
