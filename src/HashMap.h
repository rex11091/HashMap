#ifndef _HASHMAP_H
#define _HASHMAP_H

#include "LinkedList.h"
#include "IntegerCompare.h"
#include "data.h"
#include <malloc.h>
#include <stdint.h>
#include <stdio.h>

#define SIZE_FACTOR       1
#define OUT_OF_HASH_SIZE_LIMIT   91

typedef int(*compare)(void *data,void **refdata);
typedef struct HashTable HashTable;

struct HashTable{
  LinkedList *list;
  int size;  // tell us how big is the List
  int size_factor;

};

uint32_t HashusingModulo(uint32_t value,uint32_t range);
void HashMapInit(HashTable *table,int size);

void _HashMapAdd(HashTable *table,uint32_t key,void *data,int index,Compare compareFunc);


void *_HashMapSearch(HashTable *table,uint32_t key,int index,Compare compareFunc);


void *_HashMapRemove(HashTable *table,uint32_t key,int index,Compare compareFunc);


#endif // _HASHMAP_H
