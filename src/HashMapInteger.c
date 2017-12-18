#include "HashMapInteger.h"
void HashMapAddInteger(HashTable *table,int* data,uint32_t key){
  // compute hash value
  // hashValue = hash(..........)
  uint32_t hashValue = HashusingModulo(key,table->size);
  // _hashMapAdd(table,data,hashValue)
  _HashMapAdd(table,key, data, hashValue,(Compare)IntegerKeyCompare);
}


void *HashMapSearchInteger(HashTable *table,uint32_t key){

  // compute hash value
  // hashValue = hash(..........)
  uint32_t hashValue = HashusingModulo(key,table->size);
  // _hashMapAdd(table,data,hashValue)
  _HashMapSearch(table,key, hashValue,(Compare)IntegerKeyCompare);
}


void HashMapRemoveInteger(HashTable *table,uint32_t key){
  // compute hash value
  // hashValue = hash(..........)
  uint32_t hashValue = HashusingModulo(key,table->size);
  // _hashMapAdd(table,data,hashValue)
  _HashMapRemove(table,key, hashValue,(Compare)IntegerKeyCompare);
}
