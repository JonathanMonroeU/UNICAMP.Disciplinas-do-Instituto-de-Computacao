//RA 220407 Lindon Jonathan S S P Monroe
//11
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data {
    int id;
    unsigned char keyword[251];
};
typedef struct data data;

unsigned long djb2(unsigned char *str);
int inserir(data *tab, unsigned char *word, int *id);
int buscar(data *tab, unsigned char *word);
int remover(data *tab, unsigned char *word);


