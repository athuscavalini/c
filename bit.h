#ifndef BIT_H_
#define BIT_H_

/*
- Converte um inteiro que representa uma posição na tebela ascii para seu binario correspondente.
* inputs: inteiro e ponteiro pra string de tamanho 8.
* output: nenhum.
* pre-condicao: inteiro indica posição existente na tabela ascii.
* pos-condicao: string contém os bits que representam o byte do inteiro inserido.
*/
void dec_to_bin(int,char*);

/*
- Pega o próximo bit do arquivo.
* inputs: arquivo, ponteiro de tamanho 8 que serve como buffer, ponteiro para inteiro que representa a posição do buffer.
* output: próximo bit do arquivo no formato char (1 ou 0).
* pre-condicao: nenhuma.
* pos-condicao: nenhuma.
*/
char pega_1(FILE*, char*, int*);

/*
- Pega o próximo byte do arquivo.
* inputs: arquivo, ponteiro de tamanho 8 que serve como buffer, ponteiro para inteiro que representa a posição do buffer.
* output: próximo byte do arquivo no formato unsigned char.
* pre-condicao: nenhuma.
* pos-condicao: nenhuma.
*/
unsigned char pega_8(FILE*, char*, int*);

/*
- Função para realizar o cálculo de potência.
* inputs: inteiro da basa e inteiro do expoente.
* output: valor após o cálculo.
* pre-condicao: nenhuma.
* pos-condicao: nenhuma.
*/
double elev(int, int);

/*
- Função que transforma um byte no formato de string para seu correspondente inteiro na tabela ascii.
* inputs: string que representa o byte.
* output: posição do byte na tabela ascii.
* pre-condicao: nenhuma.
* pos-condicao: nenhuma.
*/
unsigned char binstr_to_ascii(char*);

#endif
