#ifndef _HASHMAP_H
#define _HASHMAP_H
#include  "LinkedList.h"
#include "IntegerCompare.h"
#include <malloc.h>
#include <stdint.h>
#include <stdio.h>

#define SIZE_FACTOR       3

typedef int(*compare)(void *data,void **refdata);
typedef struct HashTable HashTable;

struct HashTable{
  LinkedList  **list;
  int size;  // tell us how big is the List

};

uint32_t HashusingModulo(uint32_t data,uint32_t size);
void initHashMap(HashTable *table,int size);
void initHashMapSearch(HashTable *table,void *data,compare compareFunc);

void _HashMapAdd(HashTable *table,void *data,int hashValue);
void _HashMapSearch(HashTable *table,void *data,compare compareFunc);
void _HashMapRemove(HashTable *table,void *data,compare compareFunc);


#endif // _HASHMAP_H
