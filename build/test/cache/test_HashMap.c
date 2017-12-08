#include "build/temp/_test_HashMap.c"
#include "IntegerCompare.h"
#include "LinkedList.h"
#include "HashMap.h"
#include "Data.h"
#include "unity.h"


void setUp(void)

{

}



void tearDown(void)

{

}





void test_HashMap_Given_empty_hash_table_and_value_5_is_added_expect_5_inserted(void){

  Data *data;

  HashTable hashTable;

  HashMapInit(&hashTable,10);

  data = dataCreate(5,"David");

  _HashMapAdd(&hashTable,(void*)data,7);



  if ((((hashTable.list[7].head)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(23))));};

  data = (Data *)(hashTable.list[7].head->data);

  UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(25), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("David")), (const char*)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(26));

  free(data);

}

void test_HashMap_Given_empty_hash_table_and_value_5_and_3_is_added_expect_5_and_3_inserted(void){

  Data *data,*David,*Ali;

  HashTable hashTable;

  HashMapInit(&hashTable,10);



  David = dataCreate(5,"David");

  _HashMapAdd(&hashTable,(void*)David,7);

  Ali = dataCreate(3,"Ali");

  _HashMapAdd(&hashTable,(void*)Ali,7);



  if ((((hashTable.list[7].head)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(49))));};

  data = (Data *)(hashTable.list[7].head->data);

  UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(51), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("David")), (const char*)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(52));



  if ((((hashTable.list[7].head->next)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(54))));};

  data = (Data *)(hashTable.list[7].head->next->data);

  UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(56), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("Ali")), (const char*)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(57));



  free(data);

}
