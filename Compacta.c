#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

//Lembrar de colocar o END OF FILE (-1) na hora de descompactar.

int main(int parametros, char* arquivo[])
{
	//Abre o arquivo a ser compactado, caso não consiga, encerra o programa.
	FILE* arq = fopen(arquivo[1], "r");
	if(arq == NULL){
		printf("Arquivo não encontrado\n");
		return 0;
	}

	//Cria um vetor cujo cada posição representa as ocorrências de um elemento da tabela ascii.
	int ascii[256];
	for(int i = 0; i<256 ;i++){
		ascii[i] = 0;
	}

	//Conta a ocorrência de cada caracter.
	long int tam_entrada = 0;
	unsigned char c = fgetc(arq);
	while (!feof(arq)){
		ascii[c]++;
		c = fgetc(arq);
		tam_entrada++;
	}

	//Coloca as informações dos vetores em uma lista na ordem crescente e conta a quantidade de letras diferentes.
	int letras_existentes = 0;
	Lista* caracteres = cria_lista();
	for(int i = 0; i<256 ;i++){
		if(ascii[i] != 0){
			Arvore* arv = arv_cria(ascii[i],i,arv_criavazia(),arv_criavazia());
			//printf("%c = %d\n",i,peso(arv));
			insere_crescente_lista(caracteres,arv,peso);
			letras_existentes++;
		}
	}

	junta_arvores(caracteres);

	//Calcular quantos algarismos terá o maior número binário (para poder criar o vetor sem alocação excessiva).
	int tamanho_binario = 1;
	int temp = 1;
	while(temp<letras_existentes){
		temp*=2;
		tamanho_binario++;
	}

	Lista* tabela = cria_lista();
	Arvore* arv = retorna_info(retorna_primeiro(caracteres));

	char* binario = (char*)malloc(altura(arv)+1);
	binario[0] = '\0';
	cria_tabela(tabela,arv,arv,altura(arv)+1,binario);
	free(binario);

	int marcador = 0;
	for(int i=strlen(arquivo[1]);marcador==0;i--){
		if(arquivo[1][i] == '.'){
			marcador = i;
			break;
		}
	}
	char* arq_saida = (char*)malloc(strlen(arquivo[1])+6);
	strcpy(arq_saida,arquivo[1]);
	arq_saida[marcador]='_';
	strcat(arq_saida,".comp");
	FILE* arq2 = fopen(arq_saida,"wb");

	fclose(arq);
	arq = fopen(arquivo[1], "r");

	char* chave[256];
	preenche_vetor(tabela,retorna_binario,chave);

	int sobra = 0;
	for (int w = 0;w<256;w++){
		if(ascii[w]!=0){
			sobra = sobra+(ascii[w]*(strlen(chave[w])));
		}
	}
	sobra = 8-(sobra%8);

	char buf[8] = {'0','0','0','0','0','0','0','0'};
 	int pos = 0;
	imprime_trie(arq2,arv,buf,&pos);
	if (pos!=0) imprimir('0',1,arq2,buf,&pos);
	fwrite(&sobra,1,1,arq2);

	comprimir(arq,arq2,chave);

	fseek(arq2, 0, SEEK_END);
        long int tam_saida = ftell(arq2);
	printf("Tamanho reduzido em: %ld%%\n",100-((tam_saida*100)/tam_entrada));

	for(int i =0;i<256;i++){
		if(ascii[i]!=0){
			free(chave[i]);
		}
	}
	free(arq_saida);
	fclose(arq2);
	libera_lista(tabela,libera_item);
	libera_lista(caracteres,arv_libera);
	fclose(arq);
	return 0;
}
