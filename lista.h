#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct nod {
    char name[30];
    int tel;
    struct nod * next;
    struct nod * prev;
};
typedef struct nod Nod;

void makenod(Nod*p, int tel, char name[30]); // skapar en nod

void insertnod(Nod ** padr, Nod * tobeadded); // lägger till noden tobeadded i listan padr

void removenod(Nod ** padr, Nod * toberemoved); // tar bort noden toberemoved ur listan padr och frigör minnet

void printnod(Nod * p); // skriver ut en nod

void printlist(Nod * p); // skriver ut alla noder i listan

Nod * search(Nod * p, int tel); // letar efter tel i listan p och returnerar noden

