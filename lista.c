#include "lista.h"

// main testar att lägga till 4 noder i en lista och sedan ta bort nod p2
int main(){ 
    Nod* p1=  malloc(sizeof(Nod));
    Nod* p2=  malloc(sizeof(Nod));
    Nod* p3= malloc(sizeof(Nod));
    Nod* p4= malloc(sizeof(Nod));
    makenod(p1, 123, "p1");
    makenod(p2, 456, "p2");
    makenod(p3, 789, "p3");
    makenod(p4, 333, "p4");
    insertnod(&p1, p2);
    insertnod(&p1, p3);
    insertnod(&p1, p4);
    removenod(&p1, p2);
    printlist(p1);
    Nod * p = search(p1, 789);
    printf("%s\n", p->name);
}

void makenod(Nod*p, int tel, char name[30]){	// skapar en nod
    p -> next = NULL;
    p -> prev = NULL;
    p -> tel = tel;
    strcpy(p->name, name);
}

void insertnod(Nod ** padr, Nod * tobeadded){	// lägger till noden tobeadded i listan padr
	while((*padr)->next != NULL){
		padr = &(*padr)->next;
	}
	(*padr)->next = tobeadded;
    tobeadded->prev = (*padr); 
}

void removenod(Nod ** padr, Nod * toberemoved){		// tar bort noden toberemoved ur listan padr och frigör minnet
	while((*padr)->next != NULL){
		if (*padr==toberemoved){
			(*padr) -> prev -> next = (*padr) -> next;
			(*padr) -> next -> prev = (*padr) -> prev;
		}
		padr = &(*padr)->next;
	}
	if (*padr==toberemoved){
		(*padr) -> prev -> next = NULL;
	}
	free(toberemoved);
}

void printnod(Nod * p){ 	// skriver ut en nod
	printf("%s 		%i\n", p -> name, p -> tel);
}

void printlist(Nod * p){	// skriver ut alla noder i listan
	while(p->next != NULL){
		printf("%s 		%i\n", p -> name, p -> tel);
		p = p->next;
	}
	printf("%s 		%i\n", p -> name, p -> tel);
}

Nod * search(Nod * p, int tel){		// letar efter tel i listan p och returnerar noden
	while(p->next != NULL){
		if(p->tel==tel){
			return p;
		}
		p = p->next;
	}
	if(p->tel==tel){
		return p;
	}
	else{
		return NULL;
	}
}