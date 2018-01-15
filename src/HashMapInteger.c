#include "HashMapInteger.h"
#include "Exception.h"
#include "CException.h"

void HashMapAddInteger(HashTable *table,int* data,uint32_t key){
  CEXCEPTION_T ex;
  Try{
  uint32_t hashValue = HashusingModulo(key,table->size);
  _HashMapAdd(table,key, data, hashValue,(Compare)IntegerKeyCompare);
  }
  Catch(ex){
    Throw(ex);
  }
}


void *HashMapSearchInteger(HashTable *table,uint32_t key){

  uint32_t hashValue = HashusingModulo(key,table->size);
  _HashMapSearch(table,key, hashValue,(Compare)IntegerKeyCompare);
}


void HashMapRemoveInteger(HashTable *table,uint32_t key){
  CEXCEPTION_T ex;
  Try{
  uint32_t hashValue = HashusingModulo(key,table->size);
  _HashMapRemove(table,key, hashValue,(Compare)IntegerKeyCompare);
  }
  Catch(ex){
  Throw(ex);
  }
}
