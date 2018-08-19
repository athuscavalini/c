#ifndef ITEM_H
#define ITEM_H

/*
item Item (tipo opaco). Contém campos:
	- letra(unsigned char);
	- binario(char*);
*/
typedef struct item Item;

/*
- Cria uma Struct de Item
* inputs: Uma letra, um vetor(correspondente ao binário) e um inteiro
* output: Item criado
* pre-condicao: Não há
* pos-condicao: Item criado e preenchido
*/
Item* cria_item(unsigned char,char*,int);

/*
- Libera a mémoria do item
* inputs: Item
* output: Nada
* pre-condicao: Item não nulo
* pos-condicao: Libera o Item e todos os seus campos alocados
*/
void libera_item(void*);

/*
- Imprime o item
* inputs: Item
* output: Nada
* pre-condicao: Item não nulo
* pos-condicao: Item impresso
*/
void imprime_item(void*);

/*
- Retorna o binário de um item
* inputs: Item e um vetor de vetores
* output: Nada
* pre-condicao: Não há
* pos-condicao: Campo binario do Item é retornado
*/
void retorna_binario(void*, char**);

#endif
