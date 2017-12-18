#include "build/temp/_test_HashMap.c"
#include "HashMapInteger.h"
#include "HashMapString.h"
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





void test_HashMap_Given_empty_hash_table_and_David_is_added_expect_David_inserted(void){

  Data *data;

  HashTable hashTable;

  HashMapInit(&hashTable,10);

  data = dataCreate(5,"David");

  _HashMapAdd(&hashTable,5,(void *)data, 7,(Compare)IntegerKeyCompare);



  if ((((hashTable.list[7].head)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(25))));};

  data = (Data *)(hashTable.list[7].head->data);

  UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(27), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("David")), (const char*)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(28));

  free(data);

}

void test_HashMap_Given_empty_hash_table_and_David_and_ALI_is_added_expect_DAvid_and_Ali_inserted(void){

  Data *data,*David,*Ali;

  HashTable hashTable;

  HashMapInit(&hashTable,10);



  David = dataCreate(5,"David");

  _HashMapAdd(&hashTable,5,(void *)David, 7,(Compare)IntegerKeyCompare);

  Ali = dataCreate(3,"Ali");

  _HashMapAdd(&hashTable,3,(void *)Ali, 7,(Compare)IntegerKeyCompare);



  if ((((hashTable.list[7].head)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(51))));};

  data = (Data *)(hashTable.list[7].head->data);

  UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(53), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("David")), (const char*)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(54));



  if ((((hashTable.list[7].head->next)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(56))));};

  data = (Data *)(hashTable.list[7].head->next->data);

  UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(58), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("Ali")), (const char*)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(59));



  free(David);

  free(Ali);

}



void test_hashMapSearch_given_David_Ali_then_search_Ali_expected_Ali_return(void){

  Data *data,*david,*ali;

  HashTable hashTable;

  HashMapInit(&hashTable,10);

  david = dataCreate(5,"David");

  _HashMapAdd(&hashTable,5,(void *)david, 7,(Compare)IntegerKeyCompare);

  ali = dataCreate(3,"Ali");

  _HashMapAdd(&hashTable,3,(void *)ali, 7,(Compare)IntegerKeyCompare);





  data = (Data*)_HashMapSearch(&hashTable,3,7,(Compare)IntegerKeyCompare);

  if ((((data)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(76))));};

  UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(77), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("Ali")), (const char*)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(78));

  free(david);

  free(ali);



}



void test_hashMapRemove_given_David_Ali_then_remove_Ali_expected_Ali_return(void){

  Data *data,*david,*ali;

  HashTable hashTable;

  HashMapInit(&hashTable,10);

  david = dataCreate(5,"David");

  _HashMapAdd(&hashTable,5,(void *)david, 7,(Compare)IntegerKeyCompare);

  ali = dataCreate(3,"Ali");

  _HashMapAdd(&hashTable,3,(void *)ali, 7,(Compare)IntegerKeyCompare);





  data = (Data *)(hashTable.list[7].head->next);

  if ((((data)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(95))));};

  data = (Data*)_HashMapRemove(&hashTable,3,7,(Compare)IntegerKeyCompare);



  data = (Data *)(hashTable.list[7].head->next);

  if ((((data)) == 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(99))));};

  free(david);

  free(ali);



}

void test_HashMapAddString_Given_empty_hash_table_and_David_is_added_expect_David_inserted(void){

  Data *data;

  HashTable hashTable;

  HashMapInit(&hashTable,10);

  data = dataCreate(5,"David");

  HashMapAddString(&hashTable,(void *)data,5);



  if ((((hashTable.list[5].head)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(123))));};

  data = (Data *)(hashTable.list[5].head->data);

  UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(125), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("David")), (const char*)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(126));

  free(data);

}

void test_HashMapAddString_Given_empty_hash_table_and_David_and_Ali_is_added_expect_David_and_Ali(void){

  Data *data,*David,*Ali;

  HashTable hashTable;

  HashMapInit(&hashTable,10);



  David = dataCreate(5,"David");

  HashMapAddString(&hashTable,(void *)David,5);



  Ali = dataCreate(15,"Ali");

  HashMapAddString(&hashTable,(void *)Ali,15);



  if ((((hashTable.list[5].head)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(151))));};

  data = (Data *)(hashTable.list[5].head->data);

  UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(153), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("David")), (const char*)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(154));



  if ((((hashTable.list[5].head->next)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(156))));};

  data = (Data *)(hashTable.list[5].head->next->data);

  UnityAssertEqualNumber((UNITY_INT)((15)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(158), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("Ali")), (const char*)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(159));



  free(David);

  free(Ali);

}

void test_HashMapAddString_Given_empty_hash_table_adding_duplicated_(void){

  Data *data,*David,*Ali;

  HashTable hashTable;

  HashMapInit(&hashTable,10);



  David = dataCreate(5,"David");

  HashMapAddString(&hashTable,(void *)David,5);



  Ali = dataCreate(5,"Ali");

  HashMapAddString(&hashTable,(void *)Ali,5);



  if ((((hashTable.list[5].head)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(186))));};

  data = (Data *)(hashTable.list[5].head->data);

  UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(188), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("Ali")), (const char*)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(189));



  if ((((hashTable.list[5].head->next)) == 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(191))));};





  free(David);

  free(Ali);

}

void test_hashMapSearchString_given_David_Ali_then_search_Ali_expected_Ali_return(void){

  Data *david,*ali;

  HashTable hashTable;

  HashMapInit(&hashTable,10);

  david = dataCreate(5,"David");

  HashMapAddString(&hashTable,(void *)david,5);

  ali = dataCreate(15,"Ali");

  HashMapAddString(&hashTable,(void *)ali,15);



  Data *Search=HashMapSearchString(&hashTable,15);

  if ((((Search)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(217))));};

  UnityAssertEqualNumber((UNITY_INT)((15)), (UNITY_INT)((Search->key)), (

 ((void *)0)

 ), (UNITY_UINT)(218), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("Ali")), (const char*)((Search->name)), (

 ((void *)0)

 ), (UNITY_UINT)(219));

  free(david);

  free(ali);



}





void test_hashMapRemoveString_given_David_15_then_remove_David_expected_Ali_only_in_table(void){

  Data *data,*david,*ali;

  HashTable hashTable;

  HashMapInit(&hashTable,10);



  david = dataCreate(5,"David");

  HashMapAddString(&hashTable,(void *)david,5);

  ali = dataCreate(15,"Ali");

  HashMapAddString(&hashTable,(void *)ali,15);





  data = (Data *)(hashTable.list[5].head->next);

  if ((((data)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(238))));};



  HashMapRemoveString(&hashTable,15);



  data = (Data *)(hashTable.list[5].head->next);

  if ((((data)) == 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(243))));};

  free(david);

  free(ali);



}



void test_hashMapaddInteger_add_8_expect_8(void){

  Data *data,*Andy;

  HashTable hashTable;

  HashMapInit(&hashTable,10);

  Andy = dataCreate(1,(int *)8);

  HashMapAddInteger(&hashTable,(void *)Andy,1);



  if ((((hashTable.list[1].head)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(256))));};

  data = (Data *)(hashTable.list[1].head->data);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(258), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((8)), (UNITY_INT)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(259), UNITY_DISPLAY_STYLE_INT);



  free(Andy);

}



void test_hashMapaddInteger_add_8_16_expect_8_16(void){

  Data *data,*rex,*rexGoh;

  HashTable hashTable;

  HashMapInit(&hashTable,10);

  rex = dataCreate(1,(int *)8);

  HashMapAddInteger(&hashTable,(void *)rex,1);

  rexGoh = dataCreate(11,(int *)19);

  HashMapAddInteger(&hashTable,(void *)rexGoh,11);



  if ((((hashTable.list[1].head)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(273))));};

  data = (Data *)(hashTable.list[1].head->data);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(275), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((8)), (UNITY_INT)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(276), UNITY_DISPLAY_STYLE_INT);



  if ((((hashTable.list[1].head->next)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(278))));};

  data = (Data *)(hashTable.list[1].head->next->data);

  UnityAssertEqualNumber((UNITY_INT)((11)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(280), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((19)), (UNITY_INT)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(281), UNITY_DISPLAY_STYLE_INT);



  free(rex);

  free(rexGoh);

}
