#ifndef _HASHMAPINTEGER_H
#define _HASHMAPINTEGER_H

#include  "LinkedList.h"
#include "IntegerCompare.h"
#include "data.h"
#include <malloc.h>
#include <stdint.h>
#include <stdio.h>
#include "HashMap.h"




void HashMapAddInteger(HashTable *table,int* data,uint32_t key);

void *HashMapSearchInteger(HashTable *table,uint32_t key);

void HashMapRemoveInteger(HashTable *table,uint32_t key);
#endif // _HASHMAPINTEGER_H
