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
    Item *newItem = (Item *)malloc(sizeof(Item));
    createItem(newItem,data,NULL);
    if(index < table->size){
      //search
     ListAddOrReplace(&table->list[index],newItem,key,compareFunc);
      //  ListAdd(&table->list[index],newItem);
    }
}

void *_HashMapSearch(HashTable *table,uint32_t key,int index,Compare compareFunc){
  if(&table->list->head!=NULL)
      return ListSearch(&table->list[index],key,(Compare)compareFunc);
}

void *_HashMapRemove(HashTable *table,uint32_t key,int index,Compare compareFunc){
  if(&table->list->head!=NULL)
    return Listremove(&table->list[index],key,(Compare) compareFunc);
}
