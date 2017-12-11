#include "HashMap.h"
#include "LinkedList.h"
#include <malloc.h>
#include <stdint.h>
#include <stdio.h>



void HashMapInit(HashTable *table,int size){
  table->list = (LinkedList *)calloc(size *SIZE_FACTOR, sizeof(LinkedList));
  table->size = size;
  table->size_factor = SIZE_FACTOR;
  int i;
    for (i = 0; i < size; i++) {
        ListInit(&table->list[i]);
    }
}


uint32_t HashusingModulo(uint32_t value,uint32_t range){
 return (value % range);
}


void _HashMapAdd(HashTable *table,uint32_t key,void *data,int index,Compare compareFunc){
    Data *temp;
    Item *newItem = (Item *)malloc(sizeof(Item));
    createItem(newItem,data,NULL);
    if(index < table->size){
        ListAdd(&table->list[index],newItem);
    }
}

void *_HashMapSearch(HashTable *table,uint32_t key,int index,Compare compareFunc){
  if(&table->list->head!=NULL)
      return ListSearch(&table->list[index],key,(Compare)compareFunc);
}

void *_HashMapRemove(HashTable *table,uint32_t key,int index,Compare compareFunc){
  //return compareFunc(key,daya)
  //.........
}

/*
void initHashMapAddInteger(HashTable *table,int data){
  // compute hash value
  // hashValue = hash(..........)
  uint32_t hashValue = HashusingModulo(data,table->size);
  // _hashMapAdd(table,data,hashValue)
  _HashMapAdd(table,(void *)data,hashValue);
}


void initHashMapSearchInteger(HashTable *table,uint32_t key){

  // compute hash value
  // hashValue = hash(..........)
  uint32_t hashValue = HashusingModulo(data,table->size);
  // _hashMapSearch(table,data,hashValue)
}
void initHashMapRemoveInteger(HashTable *table,uint32_t key){
  // compute hash value
  // hashValue = hash(..........)
  uint32_t hashValue = HashusingModulo(data,table->size);
  // _hashMapRemove(table,data,hashValue)
}
*/
