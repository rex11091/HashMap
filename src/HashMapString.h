#ifndef _HASHMAPSTRING_H
#define _HASHMAPSTRING_H

#include "HashMap.h"
#include  "LinkedList.h"
#include "IntegerCompare.h"
#include "data.h"
#include <malloc.h>
#include <stdint.h>
#include <stdio.h>




void HashMapAddString(HashTable *table,char* data,uint32_t key);

void *HashMapSearchString(HashTable *table,uint32_t key);

void HashMapRemoveString(HashTable *table,uint32_t key);




#endif // _HASHMAPSTRING_H
