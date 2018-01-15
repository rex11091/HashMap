#include "build/temp/_test_HashMap.c"
#include "CException.h"
#include "Exception.h"
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

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(34))));};

  data = (Data *)(hashTable.list[7].head->data);

  UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(36), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("David")), (const char*)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(37));

  free(data);

}

void test_HashMap_Given_empty_hash_table_over_table_size_index_is_inserted_expect_exceptions(void){

  ExceptionPtr ex;

  Data *data;

  HashTable hashTable;

  HashMapInit(&hashTable,10);

  data = dataCreate(5,"David");

  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; if (

 _setjmp((

 NewFrame

 ), __builtin_frame_address (0)) 

 == 0) { if (1){

  _HashMapAdd(&hashTable,5,(void *)data, 1000,(Compare)IntegerKeyCompare);

  }

  else { } CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; } else { ex = CExceptionFrames[MY_ID].Exception; (void)ex; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != ((ExceptionPtr)0x5A5A5A5A)){

    dumpException(ex);

    freeException1(ex);

  }

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

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(84))));};

  data = (Data *)(hashTable.list[7].head->data);

  UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(86), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("David")), (const char*)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(87));



  if ((((hashTable.list[7].head->next)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(89))));};

  data = (Data *)(hashTable.list[7].head->next->data);

  UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(91), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("Ali")), (const char*)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(92));



  free(David);

  free(Ali);

}

void test_HashMap_Given_empty_hash_table_and_David_and_duplicated_key_data_IS_Ali_expect_return_ALI_with_key5(void){

  Data *data,*David,*Ali;

  HashTable hashTable;

  HashMapInit(&hashTable,10);



  David = dataCreate(5,"David");

  _HashMapAdd(&hashTable,5,(void *)David, 7,(Compare)IntegerKeyCompare);

  Ali = dataCreate(5,"Ali");

  _HashMapAdd(&hashTable,5,(void *)Ali, 7,(Compare)IntegerKeyCompare);



  if ((((hashTable.list[7].head)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(116))));};

  data = (Data *)(hashTable.list[7].head->data);

  UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(118), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("Ali")), (const char*)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(119));



  if ((((hashTable.list[7].head->next)) == 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(121))));};



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

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(145))));};

  UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(146), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("Ali")), (const char*)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(147));

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

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(172))));};

  data = (Data*)_HashMapRemove(&hashTable,3,7,(Compare)IntegerKeyCompare);

  data = (Data *)(hashTable.list[7].head->next);

  if ((((data)) == 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(175))));};

  free(david);

  free(ali);

}

void test_hashMapRemove_given_over_size_limit_expected_exceptions(void){

  ExceptionPtr ex;

  Data *data,*david,*ali;

  HashTable hashTable;

  HashMapInit(&hashTable,10);

  david = dataCreate(5,"David");

  _HashMapAdd(&hashTable,5,(void *)david, 7,(Compare)IntegerKeyCompare);

  ali = dataCreate(3,"Ali");

  _HashMapAdd(&hashTable,3,(void *)ali, 7,(Compare)IntegerKeyCompare);



    { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; if (

   _setjmp((

   NewFrame

   ), __builtin_frame_address (0)) 

   == 0) { if (1){

  data = (Data*)_HashMapRemove(&hashTable,3,11,(Compare)IntegerKeyCompare);

  }

  else { } CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; } else { ex = CExceptionFrames[MY_ID].Exception; (void)ex; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != ((ExceptionPtr)0x5A5A5A5A)){

    dumpException(ex);

    freeException1(ex);

  }

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

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(226))));};

  data = (Data *)(hashTable.list[5].head->data);

  UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(228), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("David")), (const char*)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(229));

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

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(254))));};

  data = (Data *)(hashTable.list[5].head->data);

  UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(256), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("David")), (const char*)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(257));



  if ((((hashTable.list[5].head->next)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(259))));};

  data = (Data *)(hashTable.list[5].head->next->data);

  UnityAssertEqualNumber((UNITY_INT)((15)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(261), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("Ali")), (const char*)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(262));



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

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(289))));};

  data = (Data *)(hashTable.list[5].head->data);

  UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(291), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("Ali")), (const char*)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(292));



  if ((((hashTable.list[5].head->next)) == 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(294))));};





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

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(320))));};

  UnityAssertEqualNumber((UNITY_INT)((15)), (UNITY_INT)((Search->key)), (

 ((void *)0)

 ), (UNITY_UINT)(321), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("Ali")), (const char*)((Search->name)), (

 ((void *)0)

 ), (UNITY_UINT)(322));

  free(david);

  free(ali);



}

void test_hashMapRemoveString_given_David_5_Ali_15_then_remove_David_expected_Ali_only_in_table(void){

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

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(350))));};



  HashMapRemoveString(&hashTable,15);

  data = (Data *)(hashTable.list[5].head->next);

  if ((((data)) == 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(354))));};

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

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(376))));};

  data = (Data *)(hashTable.list[1].head->data);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(378), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((8)), (UNITY_INT)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(379), UNITY_DISPLAY_STYLE_INT);



  free(Andy);

}

void test_hashMapaddInteger_add_8_19_expect_8_19(void){

  Data *data,*rex,*rexGoh;

  HashTable hashTable;

  HashMapInit(&hashTable,10);

  rex = dataCreate(1,(int *)8);

  HashMapAddInteger(&hashTable,(void *)rex,1);

  rexGoh = dataCreate(11,(int *)19);

  HashMapAddInteger(&hashTable,(void *)rexGoh,11);



  if ((((hashTable.list[1].head)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(402))));};

  data = (Data *)(hashTable.list[1].head->data);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(404), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((8)), (UNITY_INT)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(405), UNITY_DISPLAY_STYLE_INT);



  if ((((hashTable.list[1].head->next)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(407))));};

  data = (Data *)(hashTable.list[1].head->next->data);

  UnityAssertEqualNumber((UNITY_INT)((11)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(409), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((19)), (UNITY_INT)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(410), UNITY_DISPLAY_STYLE_INT);



  free(rex);

  free(rexGoh);

}

void test_hashMapaddInteger_added_duplicated_expect_19(void){

  Data *data,*rex,*rexGoh;

  HashTable hashTable;

  HashMapInit(&hashTable,10);

  rex = dataCreate(1,(int *)8);

  HashMapAddInteger(&hashTable,(void *)rex,1);

  rexGoh = dataCreate(1,(int *)19);

  HashMapAddInteger(&hashTable,(void *)rexGoh,1);



  if ((((hashTable.list[1].head)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(435))));};

  data = (Data *)(hashTable.list[1].head->data);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(437), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((19)), (UNITY_INT)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(438), UNITY_DISPLAY_STYLE_INT);



  if ((((hashTable.list[1].head->next)) == 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(440))));};





  free(rex);

  free(rexGoh);

}

void test_hashMapSearch_search_8_expect_8(void){

  Data *data,*rex,*rexGoh;

  HashTable hashTable;

  HashMapInit(&hashTable,10);

  rex = dataCreate(1,(int *)8);

  HashMapAddInteger(&hashTable,(void *)rex,1);

  rexGoh = dataCreate(11,(int *)19);

  HashMapAddInteger(&hashTable,(void *)rexGoh,11);





  Data *Search=HashMapSearchInteger(&hashTable,1);

  if ((((Search)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(467))));};

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((Search->key)), (

 ((void *)0)

 ), (UNITY_UINT)(468), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((8)), (UNITY_INT)((Search->name)), (

 ((void *)0)

 ), (UNITY_UINT)(469), UNITY_DISPLAY_STYLE_INT);



  free(rex);

  free(rexGoh);

}

void test_hashMapRemoveinteger_remove_19_expect_8_only_in_list_1(void){

  Data *remove,*rex,*rexGoh;

  HashTable hashTable;

  HashMapInit(&hashTable,10);

  rex = dataCreate(1,(int *)8);

  HashMapAddInteger(&hashTable,(void *)rex,1);

  rexGoh = dataCreate(11,(int *)19);

  HashMapAddInteger(&hashTable,(void *)rexGoh,11);





  remove = (Data *)(hashTable.list[1].head->next);

  if ((((remove)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(495))));};



  HashMapRemoveInteger(&hashTable,11);

  remove = (Data *)(hashTable.list[1].head->next);



  if ((((remove)) == 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(500))));};



  free(rex);

  free(rexGoh);

}
