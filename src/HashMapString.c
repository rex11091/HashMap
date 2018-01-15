#include "HashMapString.h"
#include "Exception.h"
#include "CException.h"


void HashMapAddString(HashTable *table,char* data,uint32_t key){
  CEXCEPTION_T ex;
  Try{
  uint32_t hashValue = HashusingModulo(key,table->size);
  _HashMapAdd(table,key, data, hashValue,(Compare)IntegerKeyCompare);
  }
  Catch(ex)
  {
    Throw(ex);
  }
}


void *HashMapSearchString(HashTable *table,uint32_t key){
  uint32_t hashValue = HashusingModulo(key,table->size);
  _HashMapSearch(table,key, hashValue,(Compare)IntegerKeyCompare);
}


void HashMapRemoveString(HashTable *table,uint32_t key){
  CEXCEPTION_T ex;
  Try{
  uint32_t hashValue = HashusingModulo(key,table->size);
  _HashMapRemove(table,key, hashValue,(Compare)IntegerKeyCompare);
  }
  Catch(ex)
  {
    Throw(ex);
  }
}
