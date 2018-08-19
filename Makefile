### Makefile ###

# Nome do compilador
CC = gcc

# Opções de compilação
CFLAGS = -Wall -g

FONTES = item lista arvore bit
all: $(FONTES) compacta descompacta clean $(info TrabED: Athus e Leonardo)
item:
	@ $(CC) $(CFLAGS) -c item.c

lista:
	@ $(CC) $(CFLAGS) -c lista.c

arvore:
	@ $(CC) $(CFLAGS) -c arvore.c

bit:
	@ $(CC) $(CFLAGS) -c bit.c

compacta:
	@ $(CC) -o Compacta Compacta.c item.o lista.o arvore.o bit.o

descompacta:
	@ $(CC) -o Descompacta Descompacta.c item.o lista.o arvore.o bit.o

%.o: %.c
	$(CC) -c $(CFLAGS) $^

clean:
	@ rm -rf *.o

rmproper: clean
	rm -rf $(EXECUTAVEL)
