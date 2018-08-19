#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"

struct celula
{
	void* info;
	Celula* prox;
};

struct lista
{
	struct celula *prim;
	struct celula *ult;
};

Lista *cria_lista(){
	Lista *n = (Lista *)malloc(sizeof(Lista));
	n->prim = n->ult = NULL;
	return n;
}

int vazia_lista(Lista* l){
	if(l->prim == NULL){
		return 1;
	}
	return 0;
}

//Insere na ordem crescente
void insere_crescente_lista(Lista *l,void* info,int (*cb) (void*)){
	Celula* n = (Celula *)malloc(sizeof(Celula));
	n->info = info;
	n->prox = NULL;

	Celula* aux = l->prim;
	Celula* ant = NULL;

	while(aux!=NULL && cb(info)>cb(aux->info)){
		ant = aux;
		aux = aux->prox;
	}
	if(l->prim == NULL){//Insere no início(Lista ainda não possuia elementos)
		l->prim = l->ult = n;
		return;
	}
	if(aux == NULL){//Insere na última posição
        ant->prox = n;
		l->ult = n;
		return;
    }
    if(l->prim == aux){//Insere no início
		n->prox = l->prim;
		l->prim = n;
	}else{//No meio da Lista
		ant->prox = n;
		n->prox = aux;
	}
}

void insere_lista(Lista* l,void* info){
	Celula* n = (Celula *)malloc(sizeof(Celula));
	n->info = info;
	n->prox = NULL;
	if(vazia_lista(l)){
		l->prim = l->ult = n;
		return;
	}
	l->ult->prox = n;
	l->ult = n;
}

//Retira sempre a primeira
void* retira_lista(Lista* l){
	if(vazia_lista(l)){
		return NULL;
	}
	Celula* aux = l->prim;
	l->prim = l->prim->prox;
	void* aux2 = aux->info;
	free(aux);
	return aux2;
}

void libera_lista(Lista* l,void (*cb) (void*)){
	Celula* ant = NULL;
	Celula* aux = l->prim;
	while (aux != NULL) {
		ant = aux;
		aux = aux->prox;
		cb(ant->info);
		free (ant);
	}
	free (l);
}

void* retorna_info(Celula* aux){
	if(aux!=NULL){
		return aux->info;
	}
	return NULL;
}

Celula* retorna_primeiro(Lista* l){
	if(l!=NULL){
		return l->prim;
	}
	return NULL;
}

Celula* retorna_ultimo(Lista* l){
	if(l!=NULL){
		return l->ult;
	}
	return NULL;
}

Celula* retorna_proximo(Celula* aux){
	if(aux!=NULL){
		return aux->prox;
	}
	return NULL;
}

void preenche_vetor(Lista* l,void (*cb) (void*, char**), char** vetor){
	Celula* aux = l->prim;
	while (aux!=NULL){
		cb(aux->info,vetor);
		aux = aux->prox;
	}
}

void imprime_lista(Lista* l,void (*cb) (void*)){
	Celula* aux = l->prim;
	while (aux!=NULL){
		cb(aux->info);
		aux = aux->prox;
	}
}
