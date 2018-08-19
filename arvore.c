#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "arvore.h"

struct arvore{
    int peso;
    unsigned char letra;
    Arvore* dir;
    Arvore* esq;
};

Arvore* arv_criavazia (void){
    return NULL;
}

Arvore* arv_cria (int p, unsigned char l, Arvore* e, Arvore* d){
    Arvore* nova = (Arvore*)malloc(sizeof(Arvore));
    nova->peso = p;
    nova->letra = l;
    nova->esq = e;
    nova->dir = d;
    return nova;
}

void arv_libera (void* a){
    if(!arv_vazia(a)){
        Arvore* aux = (Arvore*)a;
        arv_libera(aux->esq);
        arv_libera(aux->dir);
        free(aux);
    }
    return;
}

void junta_arvores(Lista* l){
	while(retorna_primeiro(l)!=retorna_ultimo(l)){
		Arvore* T1 = retira_lista(l);
		Arvore* T2 = retira_lista(l);
		Arvore* TR = arv_cria(peso(T1)+peso(T2),-1,T1,T2);
		insere_crescente_lista(l,TR,peso);
	}
}

void arv_imprime (Arvore* a){
    printf("<");
    if(!arv_vazia(a)){
        printf("%c ",a->letra);
        arv_imprime(a->esq);
        arv_imprime(a->dir);
    }
    printf(">");
}

void cria_tabela (Lista* l,Arvore* raiz,Arvore* a,int tam,char* binario){
    if(arv_vazia(a)){
        return;
    }
    if(a->dir == NULL && a->esq == NULL){
        insere_lista(l,cria_item(a->letra,binario,tam));
        return;
    }
    if(raiz == a){
        cria_tabela(l,raiz,a->esq,tam,strcpy(binario,"0"));
        cria_tabela(l,raiz,a->dir,tam,strcpy(binario,"1"));
    }else{
        char* aux = (char*)malloc(tam*sizeof(char));
        strcpy(aux,binario);
        cria_tabela(l,raiz,a->esq,tam,strcat(binario,"0"));
        cria_tabela(l,raiz,a->dir,tam,strcat(aux,"1"));
        free(aux);
    }
}

int arv_vazia (Arvore* a){
    return a == NULL;
}

int folhas (Arvore* a){
  if (a==NULL) return 0;
  if (arv_vazia(a)) return 1;
  return folhas(a->esq) + folhas(a->dir);
}

int maior(int a, int b){
  if(a>b) return a;
  else return b;
}

int altura (Arvore* a){
  if((a == NULL)||(a->esq == NULL && a->dir == NULL)) return 0;
  else return 1 + maior(altura(a->esq),altura(a->dir));
}

int peso (void* a){
    if(a!=NULL){
      return ((Arvore*)a)->peso;
    }
    return 0;
}

char letra (Arvore* a){
    if(a!=NULL){
      return a->letra;
    }
    return '0';
}

Arvore* esquerda(Arvore* a){
    if(a!=NULL){
      return a->esq;
    }
    return NULL;
}

Arvore* direita(Arvore* a){
    if(a!=NULL){
      return a->dir;
    }
    return NULL;
}

void imprime_trie(FILE* file, Arvore* a,char* buf,int* pos){
  char bin[8];
  if(!arv_vazia(a)){
    if((arv_vazia(a->dir))&&(arv_vazia(a->esq))){
      imprimir('1',0,file,buf,pos);
      dec_to_bin((a->letra),bin);
      for (int i = 0; i<8; i++){
        imprimir(bin[i],0,file,buf,pos);
      }
    }else{
      imprimir('0',0,file,buf,pos);
      imprime_trie(file,a->esq,buf,pos);
      imprime_trie(file,a->dir,buf,pos);
    }
  }
}

Arvore* le_arvore(FILE* file, char* buf, int* pos){
  Arvore* a;
  unsigned char c = pega_1(file,buf,pos);
  if (c == '0'){
    a = arv_cria(0,'0',arv_criavazia(),arv_criavazia());
    a->esq = le_arvore(file,buf,pos);
    a->dir = le_arvore(file,buf,pos);
  }
  if (c == '1'){
    a = arv_cria(1,pega_8(file,buf,pos),arv_criavazia(),arv_criavazia());
  }
  return a;
}

void imprimir(char c, int i, FILE* file, char* buf, int* pos){
  if (i == 0){
    buf[*pos] = c;
    *pos = *pos + 1;
    if (*pos == 8){
      //printf("%s ",buf);
      *pos = 0;
      unsigned char b = binstr_to_ascii(buf);
      fwrite(&b,1,1,file);
      for (int i = 0;i<8;i++){
        buf[i] = '0';
      }
    }
  }else{
    //printf("%s ",buf);
    *pos = 0;
    unsigned char b = binstr_to_ascii(buf);
    fwrite(&b,1,1,file);
    for (int i = 0;i<8;i++){
      buf[i] = '0';
    }
  }
}

int comprimir(FILE* entrada, FILE* saida, char** vet){
  char buf[8] = {'0','0','0','0','0','0','0','0'};
  int pos = 0;
  unsigned char c = fgetc(entrada);
  while(!feof(entrada)){
    for (int i = 0;i<strlen(vet[c]);i++){
      imprimir(vet[c][i],0,saida,buf,&pos);
    }
    c = fgetc(entrada);
  }
  if (pos!=0) imprimir('0',1,saida,buf,&pos);
  return pos;
}
