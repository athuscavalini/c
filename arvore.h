#ifndef ARVORE_H
#define ARVORE_H

#include "item.h"
#include "lista.h"
#include "bit.h"

/*
arvore Arvore (tipo opaco). Contém campos:
	- peso(int)
    - letra(unsigned char)
	- dir(Arvore*)
    - esq(Arvore*)
*/
typedef struct arvore Arvore;

/*
- Cria uma Struct de Arvore
* inputs: Nada
* output: A arvore criada (vazia)
* pre-condicao: Não há
* pos-condicao: Arvore criada e vazia
*/
Arvore* arv_criavazia (void);

/*
- Cria uma Struct de Arvore
* inputs: Um inteiro e duas árvores(esquerda e direita)
* output: A arvore criada
* pre-condicao: Não há
* pos-condicao: Arvore criada e preenchida
*/
Arvore* arv_cria (int, unsigned char, Arvore*, Arvore*);

/*
- Libera a mémoria de uma arvore
* inputs: Arvore
* output: Nada
* pre-condicao: Arvore não nula
* pos-condicao: Libera a Arvore, todos os filhos dessa árvore e todos os campos alocados
*/
void arv_libera (void*);

/*
- Junta as duas primeiras árvores de uma lista
* inputs: Lista
* output: Nada
* pre-condicao: Lista não nula
* pos-condicao: Duas primeiras árvores retirada, juntadas e nova árvore inserida na lista na ordem crescente
*/
void junta_arvores(Lista*);

/*
- Imprime a arvore
* inputs: Arvore
* output: Nada
* pre-condicao: Arvore não nulo
* pos-condicao: Arvore impressa
*/
void arv_imprime (Arvore*);

/*
- Cria a tabela de condificação
* inputs: Lista, Arvore, Arvore, tamanho máximo do binário e um vetor
* output: Nada
* pre-condicao: Lista não nula
* pos-condicao: Lista preenchido com os Itens
*/
void cria_tabela (Lista* l,Arvore*,Arvore*,int tam,char*);

/*
- Informa se uma arvore está vazia ou não.
* inputs: Arvore
* output: Um inteiro informando se é vazia ou não
* pre-condicao: Não há
* pos-condicao: Valor 1 para vazia e 0 para não vazia
*/
int arv_vazia (Arvore*);

/*
- Informa o número de folhas de uma árvore.
* inputs: Arvore
* output: Um inteiro informando o número de folhas
* pre-condicao: Não há
* pos-condicao: Valor informando o número de folhas
*/
int folhas (Arvore*);

/*
- Informa a altura de uma árvore.
* inputs: Arvore
* output: Um inteiro a altura da árvore
* pre-condicao: Não há
* pos-condicao: Valor a altura máxima da árvore
*/
int altura (Arvore*);

/*
- Retorna o campo peso de uma Arvore
* inputs: Arvore
* output: Campo peso da Arvore
* pre-condicao: Não há
* pos-condicao: Campo peso da Arvore é retornado
*/
int peso (void*);

/*
- Retorna o campo letra de uma Arvore
* inputs: Arvore
* output: Campo letra da Arvore
* pre-condicao: Não há
* pos-condicao: Campo letra da Arvore é retornado
*/
char letra (Arvore*);

/*
- Retorna o campo esq de uma Arvore
* inputs: Arvore
* output: Campo esq da Arvore
* pre-condicao: Não há
* pos-condicao: Campo esq da Arvore é retornado
*/
Arvore* esquerda(Arvore*);

/*
- Retorna o campo dir de uma Arvore
* inputs: Arvore
* output: Campo dir da Arvore
* pre-condicao: Não há
* pos-condicao: Campo dir da Arvore é retornado
*/
Arvore* direita(Arvore*);

/*
- Escreve a arvore de huffman no arquivo compactado
* inputs: Arquivo, Arvore, um vetor, e um ponteiro para inteiro 
* output: Nada
* pre-condicao: Arquivo aberto, Arvore não nula, vetor criado e ponteiro não nulo
* pos-condicao: Arvore escrita no arquivo compactado
*/
void imprime_trie(FILE*,Arvore*,char*,int*);

/*
- Lê a árvore do cabeçalho do arquivo compactado
* inputs: Arquivo
* output: Arvore criada e preenchida
* pre-condicao: Arquivo aberto, vetor criado e ponteiro não nulo
* pos-condicao: Campo peso da Arvore é retornado
*/
Arvore* le_arvore(FILE*,char*,int*);

/*
- Imprime os binários no arquivo compactado
* inputs: Char, um inteiro, um arquivo, um vetor, e um vetor para inteiro
* output: Nada
* pre-condicao: Arquivo aberto, vetor criado e ponteiro não nulo
* pos-condicao: Binarios impressos no arquivo
*/
void imprimir(char c, int i, FILE* file, char* buf, int* pos);

/*
- Comprime os dados para a escrita no arquivo(traduz para binário)
* inputs: Arquivo de entrada, arquivo de saída e um vetor com os binários
* output: Arvore criada e preenchida
* pre-condicao: Arquivos abertos, vetor criado
* pos-condicao: Binarios impressos no arquivo
*/
int comprimir(FILE* entrada, FILE* saida, char** vet);

#endif
