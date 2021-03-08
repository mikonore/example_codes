#ifndef tproHASHFUNC_H
#define tproHASHFUNC_H

#include <stdint.h>
#include "key.h"    // en headerfil för en modifierad dubbellänkad lista p3

uint32_t tilpro_hash(const char * s) ; // hashar värdet s

void put(Nod ** hashtable, char * key, char * value); // put lägger till key och value i hashtabellen

char * get(Nod ** hashtable, char * key); // get letar upp key i hashtabellen

void init(Nod ** vek); // init itererar genom hashtabellen och sätter alla index till NULL

#define HASHVEKSIZE 1048576

#endif