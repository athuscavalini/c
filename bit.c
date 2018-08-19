#include <stdlib.h>
#include <stdio.h>
#include "bit.h"

void dec_to_bin(int num, char* bin){
   int aux;

   for (aux = 7; aux >= 0; aux--)
   {
      if (num % 2 == 0)
         bin[aux] = '0';
      else
         bin[aux] = '1';
      num = num / 2;
   }

}

char pega_1(FILE* file, char* buf, int* pos){
  char c;
  c = buf[*pos];
  *pos = *pos + 1;
  if (*pos>7){
      unsigned char a = 0;
      fread(&a,1,1,file);
      dec_to_bin(a,buf);
      *pos = 0;
  }
  return c;
}

unsigned char pega_8(FILE* file, char* buf, int* pos){
  char aux[8];
  for (int i = 0;i<8;i++){
    aux[i]=pega_1(file,buf,pos);
  }
  return binstr_to_ascii(aux);
}

double elev(int num, int exp){
  double resp=1;
  for(int i=0;i<exp;i++){
    resp*=num;
  }
  return resp;
}

unsigned char binstr_to_ascii(char* buf){
  int s = 8;
  unsigned char dec = 0;
  int i = 0;
  while (s--){
    dec = dec + elev(2,i++)*(buf[s]-'0');
  }
  return dec;
}
