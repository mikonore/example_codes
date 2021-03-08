#include "hashfunc.h"
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
 
int main(){ // main testar att lägga till två noder i hashtabellen och sedan leta efter värdet för nyckeln key2
	Nod ** myhashvek = malloc(sizeof(Nod *) * HASHVEKSIZE); // skapar en hashtabell
	init(myhashvek);
	put(myhashvek, "key", "value");
	put(myhashvek, "key2", "value2");
	char * val = get(myhashvek, "key2");
	printf("%s\n", val);
}


void insertnod(Nod ** padr, Nod * tobeadded){	// lägger till noden tobeadded i listan padr
	while((*padr)->next != NULL | (*padr)->next != 0){
		padr = &(*padr)->next;
	}
	(*padr)->next = tobeadded;
    tobeadded->prev = (*padr); 
}

Nod * search(Nod * p, char key[512]){		//letar efter key i listan p och returnerar noden
	int ret;
	char str1[512];
	char str2[512];
	while(p != NULL | p != 0){
		strcpy(str1, p->key);
		strcpy(str2, key);
		ret = strcmp(str1, str2);
		if(ret==0){
			return p;
		}
		p = p->next;
	}
	if(ret==0){
		return p;
	}
	else{
		return NULL;
	}
}

uint32_t tilpro_hash(const char * s) {		// hashar värdet s
  uint32_t hash = 0;
  size_t i = 0;
  while (s[i] != '\0') {
    hash += s[i++];
    hash += hash << 10;
    hash ^= hash >> 6;
  }
  hash += hash << 3;
  hash ^= hash >> 11;
  hash += hash << 13;

  hash = hash & ( HASHVEKSIZE - 1 );
  return hash;
}

// put tar hashtabellen och två strängar key och value som parametrar. 
// put räknar ut hashindex för key med tilpro_hash och söker där i den dubbellänkade listan efter key. 
// Om ingen sådan Nod påträffas läggs en ny Nod med key och value in i listan. om däremot en Nod med key påträffas ska value ändras (använd strcpy)
void put(Nod ** hashtable, char * key, char * value) {
    int hashindex;
    hashindex = tilpro_hash(key);
    Nod * p = hashtable[hashindex];
    if (p==NULL){ // om ingen nod hittas läggs en ny nod till
        Nod * node =  malloc(sizeof(Nod));
        strcpy(node->key, key);
        strcpy(node->value, value);
        node->next = NULL;
        node->prev = NULL;
        p = node;
        hashtable[hashindex] = p;
    }
    else{ // om noden redan finns
    	char newkey[512];
    	strcpy(newkey, key);
    	Nod * searchnode = search(p, newkey); 
    	if (searchnode==NULL){ // om det inte finns en nod med samma key
    		Nod * node = malloc(sizeof(Nod));
        	strcpy(node->key, key);
        	strcpy(node->value, value);
        	node->next = NULL;
        	node->prev = NULL;
    		insertnod(&p, node); // lägg till noden i listan
    	}
    	else{ // om det finns en nod med samma key
    		strcpy(searchnode->value, value); // ändra value i den noden
    	}
    }
}

// get tar hashtabellen och en sträng key som parametrar och returnerar NULL om key inte finns annars returneras värdet associerat med key. 
// get räknar ut hashindex för key med tilpro_hash och söker där i den dubbellänkade listan efter key.
char * get(Nod ** hashtable, char * key) {
	int hashindex;
	char newkey[512];
	hashindex = tilpro_hash(key);
	Nod * p = hashtable[hashindex];
	strcpy(newkey, key);
	Nod * node = search(p, newkey);
	if (node==NULL){
		return NULL;
	}
	else{
		return node->value;
	}
}

// init itererar genom hashtabellen och sätter alla index till NULL. 
// Det går att lösa med en for-loop som går från 0 till HASHVEKSIZE men det finns även en funktion memset som kan användas.
void init(Nod ** vek) {
	int a;
	for( a = 0 ; a < HASHVEKSIZE ; a = a + 1){
		vek[a] = NULL;
	}
}