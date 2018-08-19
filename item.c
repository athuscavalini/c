#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "item.h"

struct item{
    unsigned char letra;
    char* binario;
};

Item* cria_item(unsigned char c,char* binario,int tam){
    Item* n = (Item*)malloc(sizeof(Item));
    n->letra = c;
    n->binario = (char*)malloc(tam*sizeof(char));
    strcpy(n->binario,binario);
    return n;
}

void libera_item(void* a){
    Item* aux = (Item*)a;
    free(aux->binario);
    free(aux);
}

void imprime_item(void* a){
    Item* aux = (Item*)a;
    printf("%c = %s\n",aux->letra,aux->binario);
}

void retorna_binario(void* a, char** vetor){
    Item* aux = (Item*)a;
    vetor[aux->letra] = (char*)malloc(strlen(aux->binario)+1);
    strcpy(vetor[aux->letra],aux->binario);
}
