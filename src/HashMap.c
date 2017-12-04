#include "HashMap.h"
#include <malloc.h>
#include <stdint.h>
#include <stdio.h>


void initHashMap(HashTable *table,int size){
  table->list = (LinkedList **)calloc(size *SIZE_FACTOR, sizeof(LinkedList **));
  table->size = size;
}

uint32_t HashusingModulo(uint32_t data,uint32_t size){
 return (data % size);
}

void _HashMapAdd(HashTable *table,void *data,int index){
    while(table->list[index] !=NULL){

    }


}

void _HashMapSearch(HashTable *table,void *data,compare compareFunc){

}

void _HashMapRemove(HashTable *table,void *data,compare compareFunc){

}


void initHashMapAddInteger(HashTable *table,int data){
  // compute hash value
  // hashValue = hash(..........)
  uint32_t hashValue = HashusingModulo(data,table->size);
  // _hashMapAdd(table,data,hashValue)
  _HashMapAdd(table,data,hashValue);
}


void initHashMapSearchInteger(HashTable *table,int data){

  // compute hash value
  // hashValue = hash(..........)
  // _hashMapSearch(table,data,hashValue)
}
void initHashMapRemoveInteger(HashTable *table,int data){
  // compute hash value
  // hashValue = hash(..........)
  // _hashMapRemove(table,data,hashValue)
}
