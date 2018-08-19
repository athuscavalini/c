#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include "bit.h"

unsigned char decod(Arvore* lida, char* buf, int* pos, FILE* arq,unsigned char* c){
	//funcao auxiliar que faz a decodificacao do arquivo na pratica.
	//recebe a arvore de codificacao, o buffer e a posição nele, o arquivo e um ponteiro para char.
	Arvore* aux = lida;
	while((esquerda(aux)!=NULL)&&(direita(aux)!=NULL)){
		// percorre-se a arvore de acordo com o representado do arquivo.
		if (*c=='0') aux = esquerda(aux);
		if (*c=='1') aux = direita(aux);
		*c = pega_1(arq,buf,pos);
	}
	return letra(aux); //ao encontrar um nó folha, retorna o caractere armazenado nele.
}

int main(int parametros, char* arquivo[])
{
	//Abre o arquivo a ser compactado, caso não consiga, encerra o programa
	FILE* arq = fopen(arquivo[1], "rb");
	if(arq == NULL){
		printf("Arquivo não encontrado\n");
		return 0;
	}
	fseek(arq, 0, SEEK_END);
	long int nbits = ftell(arq)*8;
	fseek(arq, 0, SEEK_SET);

	char buf[8] = {'0','0','0','0','0','0','0','0'}; //buffer para ler o arquivo bit a bit.
	int pos = 0; //posicao na leitura do buffer.

	unsigned char a;
  	fread(&a,1,1,arq); //lê um byte do arquivo.
  	dec_to_bin(a,buf); //converte-o e insere no buffer.

	Arvore* lida = arv_criavazia();
	lida = le_arvore(arq,buf,&pos);
	unsigned char tam;
	fread(&tam,1,1,arq); //lê o byte que servirá de parada para a descompactação.

	Lista* tabela = cria_lista();
	char* binario = (char*)malloc(altura(lida)+1);
	cria_tabela(tabela,lida,lida,altura(lida)+1,binario);
	free(binario);
	char* chave[256];
	for(int i=0;i<256;i++){
		chave[i] = NULL;
	}
	preenche_vetor(tabela,retorna_binario,chave);

	long int bits_percorridos = ftell(arq)*8; //cria o contador para calcular a parada da descompactação.

	//descodificando os binarios:
	fread(&a,1,1,arq); //reenchendo o mesmo buffer com o proximo byte
	dec_to_bin(a,buf);
	pos = 0;
	arquivo[1][strlen(arquivo[1])-5] = '\0';
	int marcador = 0;
	for(int i=strlen(arquivo[1]);marcador==0;i--){
		if(arquivo[1][i] == '_'){
			arquivo[1][i] = '.';
			break;
		}
	}
	FILE* arq2 = fopen(arquivo[1],"w");
	unsigned char v = pega_1(arq,buf,&pos);
	unsigned char c;
	while (!feof(arq)){
		c = decod(lida,buf,&pos,arq,&v); //funcao que decodifica o proximo caractere do arquivo.
		fputc(c,arq2); //imprime o caractere no arquivo de saida.
		bits_percorridos = bits_percorridos + strlen(chave[c]);
		if (bits_percorridos >= (nbits - tam)) break; //condicao de parada atendida. termina a descompactação.
	}
	//encerrada a decodificacao, faz-se a liberacao da memoria alocada durante a execucao do programa.
	libera_lista(tabela,libera_item);
	for(int i=0;i<256;i++){
		if(chave[i]!=NULL){
			free(chave[i]);
		}
	}
	arv_libera(lida);
	fclose(arq);
	fclose(arq2);
	return 0;
}
