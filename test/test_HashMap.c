#include "unity.h"
#include "Data.h"
#include "HashMap.h"
#include "LinkedList.h"
#include "IntegerCompare.h"
#include "HashMapString.h"
#include "HashMapInteger.h"
#include "Exception.h"
#include "CException.h"

void setUp(void)
{
}

void tearDown(void)
{
}
/*
*     index  ------
*            |    |
*            |    |
*       7    |  * | -->david
*            |    |
*            |    |
*/

void test_HashMap_Given_empty_hash_table_and_David_is_added_expect_David_inserted(void){
  Data *data;
  HashTable hashTable;
  HashMapInit(&hashTable,10);
  data = dataCreate(5,"David");
  _HashMapAdd(&hashTable,5,(void *)data, 7,(Compare)IntegerKeyCompare);

  TEST_ASSERT_NOT_NULL(hashTable.list[7].head);
  data = (Data *)(hashTable.list[7].head->data);
  TEST_ASSERT_EQUAL(5,data->key);
  TEST_ASSERT_EQUAL_STRING("David",data->name);
  free(data);
}
/*
*     index  ------
*            |    |
*            |    |
*       7    |  * | -->david(size put 1000 which over size limit)
*            |    |
*            |    |
*/

void test_HashMap_Given_empty_hash_table_over_table_size_index_is_inserted_expect_exceptions(void){
  CEXCEPTION_T ex;
  Data *data;
  HashTable hashTable;
  HashMapInit(&hashTable,10);
  data = dataCreate(5,"David");
  Try{
  _HashMapAdd(&hashTable,5,(void *)data, 1000,(Compare)IntegerKeyCompare);
  }
  Catch(ex){
    dumpException(ex);
    freeException1(ex);
  }
    free(data);
}

/*
*     index  ------
*            |    |
*            |    |
*       7    |  * | -->david->ali
*            |    |
*            |    |
*/

void test_HashMap_Given_empty_hash_table_and_David_and_ALI_is_added_expect_DAvid_and_Ali_inserted(void){
  Data *data,*David,*Ali;
  HashTable hashTable;
  HashMapInit(&hashTable,10);

  David = dataCreate(5,"David");
  _HashMapAdd(&hashTable,5,(void *)David, 7,(Compare)IntegerKeyCompare);
  Ali = dataCreate(3,"Ali");
  _HashMapAdd(&hashTable,3,(void *)Ali, 7,(Compare)IntegerKeyCompare);

  TEST_ASSERT_NOT_NULL(hashTable.list[7].head);
  data = (Data *)(hashTable.list[7].head->data);
  TEST_ASSERT_EQUAL(5,data->key);
  TEST_ASSERT_EQUAL_STRING("David",data->name);

  TEST_ASSERT_NOT_NULL(hashTable.list[7].head->next);
  data = (Data *)(hashTable.list[7].head->next->data);
  TEST_ASSERT_EQUAL(3,data->key);
  TEST_ASSERT_EQUAL_STRING("Ali",data->name);

  free(David);
  free(Ali);
}
/*
*     index  ------                                                 index     --------
*            |    |                                                           |       |
*            |    |                     added duplicated key                  |       |
*       7    |  * | -->david->ali       ----------->                    7     |   *   |  -->ali
*            |    |                                                           |       |
*            |    |                                                           |       |
*/

void test_HashMap_Given_empty_hash_table_and_David_and_duplicated_key_data_IS_Ali_expect_return_ALI_with_key5(void){
  Data *data,*David,*Ali;
  HashTable hashTable;
  HashMapInit(&hashTable,10);

  David = dataCreate(5,"David");
  _HashMapAdd(&hashTable,5,(void *)David, 7,(Compare)IntegerKeyCompare);
  Ali = dataCreate(5,"Ali");
  _HashMapAdd(&hashTable,5,(void *)Ali, 7,(Compare)IntegerKeyCompare);

  TEST_ASSERT_NOT_NULL(hashTable.list[7].head);
  data = (Data *)(hashTable.list[7].head->data);
  TEST_ASSERT_EQUAL(5,data->key);
  TEST_ASSERT_EQUAL_STRING("Ali",data->name);

  TEST_ASSERT_NULL(hashTable.list[7].head->next);

  free(David);
  free(Ali);
}
/*
*     index  ------
*            |    |
*            |    |                  search 3
*       7    |  * | -->david->ali       ----------->      data = ali
*            |    |
*            |    |
*/
void test_hashMapSearch_given_David_Ali_then_search_Ali_expected_Ali_return(void){
  Data *data,*david,*ali;
  HashTable hashTable;
  HashMapInit(&hashTable,10);
  david = dataCreate(5,"David");
  _HashMapAdd(&hashTable,5,(void *)david, 7,(Compare)IntegerKeyCompare);
  ali = dataCreate(3,"Ali");
  _HashMapAdd(&hashTable,3,(void *)ali, 7,(Compare)IntegerKeyCompare);


  data = (Data*)_HashMapSearch(&hashTable,3,7,(Compare)IntegerKeyCompare);
  TEST_ASSERT_NOT_NULL(data);
  TEST_ASSERT_EQUAL(3,data->key);
  TEST_ASSERT_EQUAL_STRING("Ali",data->name);
  free(david);
  free(ali);

}

/*
*     index  ------                                       index     --------
*            |    |                                                 |       |
*            |    |                     remove ali                  |       |
*       7    |  * | -->david->ali       ----------->                |   *   |  -->david
*            |    |                                                 |       |
*            |    |                                                 |       |
*/
void test_hashMapRemove_given_David_Ali_then_remove_Ali_expected_Ali_return(void){
  Data *data,*david,*ali;
  HashTable hashTable;
  HashMapInit(&hashTable,10);
  david = dataCreate(5,"David");
  _HashMapAdd(&hashTable,5,(void *)david, 7,(Compare)IntegerKeyCompare);
  ali = dataCreate(3,"Ali");
  _HashMapAdd(&hashTable,3,(void *)ali, 7,(Compare)IntegerKeyCompare);


  data =  (Data *)(hashTable.list[7].head->next);
  TEST_ASSERT_NOT_NULL(data);
  data = (Data*)_HashMapRemove(&hashTable,3,7,(Compare)IntegerKeyCompare);
  data =  (Data *)(hashTable.list[7].head->next);
  TEST_ASSERT_NULL(data);
  free(david);
  free(ali);
}
/*
*     index  ------
*            |    |
*            |    |                   remove
*       7    |  * | -->david->ali-----------> over size limit expect exceptions
*            |    |
*            |    |
*/
void test_hashMapRemove_given_over_size_limit_expected_exceptions(void){
  CEXCEPTION_T ex;
  Data *data,*david,*ali;
  HashTable hashTable;
  HashMapInit(&hashTable,10);
  david = dataCreate(5,"David");
  _HashMapAdd(&hashTable,5,(void *)david, 7,(Compare)IntegerKeyCompare);
  ali = dataCreate(3,"Ali");
  _HashMapAdd(&hashTable,3,(void *)ali, 7,(Compare)IntegerKeyCompare);

    Try{
  data = (Data*)_HashMapRemove(&hashTable,3,11,(Compare)IntegerKeyCompare);
  }
  Catch(ex){
    dumpException(ex);
    freeException1(ex);
  }
  free(david);
  free(ali);
}


/*-------------------------------------------- Test HaspMapString---------------------------------------------*/
/*
*     index  ------
*            |    |
*            |    |
*       5    |  * | -->5(David)
*            |    |
*            |    |
*
*/
void test_HashMapAddString_Given_empty_hash_table_and_David_is_added_expect_David_inserted(void){
  Data *data;
  HashTable hashTable;
  HashMapInit(&hashTable,10);
  data = dataCreate(5,"David");
  HashMapAddString(&hashTable,(void *)data,5);

  TEST_ASSERT_NOT_NULL(hashTable.list[5].head);
  data = (Data *)(hashTable.list[5].head->data);
  TEST_ASSERT_EQUAL(5,data->key);
  TEST_ASSERT_EQUAL_STRING("David",data->name);
  free(data);
}

/*
*     index  ------
*            |    |
*            |    |
*       5    |  * | -->5(david)->15(ali)
*            |    |
*            |    |
*
*/

void test_HashMapAddString_Given_empty_hash_table_and_David_and_Ali_is_added_expect_David_and_Ali(void){
  Data *data,*David,*Ali;
  HashTable hashTable;
  HashMapInit(&hashTable,10);

  David = dataCreate(5,"David");
  HashMapAddString(&hashTable,(void *)David,5);

  Ali = dataCreate(15,"Ali");
  HashMapAddString(&hashTable,(void *)Ali,15);

  TEST_ASSERT_NOT_NULL(hashTable.list[5].head);
  data = (Data *)(hashTable.list[5].head->data);
  TEST_ASSERT_EQUAL(5,data->key);
  TEST_ASSERT_EQUAL_STRING("David",data->name);

  TEST_ASSERT_NOT_NULL(hashTable.list[5].head->next);
  data = (Data *)(hashTable.list[5].head->next->data);
  TEST_ASSERT_EQUAL(15,data->key);
  TEST_ASSERT_EQUAL_STRING("Ali",data->name);

  free(David);
  free(Ali);
}
/*
*     index  ------                        index  ------
*            |    |                               |    |
*            |    |  added duplicated key         |    |
*       5    |  * | -->5(David)  -------->  5     |    |-----> 5(Ali)
*            |    |                               |    |
*            |    |                               |    |
*
*/


void test_HashMapAddString_Given_empty_hash_table_adding_duplicated_(void){
  Data *data,*David,*Ali;
  HashTable hashTable;
  HashMapInit(&hashTable,10);

  David = dataCreate(5,"David");
  HashMapAddString(&hashTable,(void *)David,5);

  Ali = dataCreate(5,"Ali");
  HashMapAddString(&hashTable,(void *)Ali,5);

  TEST_ASSERT_NOT_NULL(hashTable.list[5].head);
  data = (Data *)(hashTable.list[5].head->data);
  TEST_ASSERT_EQUAL(5,data->key);
  TEST_ASSERT_EQUAL_STRING("Ali",data->name);

  TEST_ASSERT_NULL(hashTable.list[5].head->next);


  free(David);
  free(Ali);
}

/*
*     index  ------
*            |    |
*            |    |
*       5    |  * | -->5(David)->15(ali)      search (ali)
*            |    |
*            |    |
*
*/
void test_hashMapSearchString_given_David_Ali_then_search_Ali_expected_Ali_return(void){
  Data *david,*ali;
  HashTable hashTable;
  HashMapInit(&hashTable,10);
  david = dataCreate(5,"David");
  HashMapAddString(&hashTable,(void *)david,5);
  ali = dataCreate(15,"Ali");
  HashMapAddString(&hashTable,(void *)ali,15);

  Data *Search=HashMapSearchString(&hashTable,15);
  TEST_ASSERT_NOT_NULL(Search);
  TEST_ASSERT_EQUAL(15,Search->key);
  TEST_ASSERT_EQUAL_STRING("Ali",Search->name);
  free(david);
  free(ali);

}

/*
*     index  ------                                     index  ------
*            |    |                                            |    |
*            |    |                          remove david      |    |
*       5    |  * | -->5(David)->15(ali)  ----------------->   |    |-----> 15(Ali)
*            |    |                                            |    |
*            |    |                                            |    |
*
*/

void test_hashMapRemoveString_given_David_5_Ali_15_then_remove_David_expected_Ali_only_in_table(void){
  Data *data,*david,*ali;
  HashTable hashTable;
  HashMapInit(&hashTable,10);

  david = dataCreate(5,"David");
  HashMapAddString(&hashTable,(void *)david,5);
  ali = dataCreate(15,"Ali");
  HashMapAddString(&hashTable,(void *)ali,15);


  data =  (Data *)(hashTable.list[5].head->next);
  TEST_ASSERT_NOT_NULL(data);

  HashMapRemoveString(&hashTable,15);
  data =  (Data *)(hashTable.list[5].head->next);
  TEST_ASSERT_NULL(data);
  free(david);
  free(ali);

}
/*-------------------------------------------- Test HaspMapinteger---------------------------------------------*/
/*
*     index  ------
*            |    |
*            |    |
*       1    |  * | --> 8
*            |    |
*            |    |
*
*/
void test_hashMapaddInteger_add_8_expect_8(void){
  Data *data,*Andy;
  HashTable hashTable;
  HashMapInit(&hashTable,10);
  Andy = dataCreate(1,(int *)8);
  HashMapAddInteger(&hashTable,(void *)Andy,1);

  TEST_ASSERT_NOT_NULL(hashTable.list[1].head);
  data = (Data *)(hashTable.list[1].head->data);
  TEST_ASSERT_EQUAL(1,data->key);
  TEST_ASSERT_EQUAL(8,data->name);

  free(Andy);
}

/*
*     index  ------
*            |    |
*            |    |
*       1    |  * | --> 8 -> 19
*            |    |
*            |    |
*
*/
void test_hashMapaddInteger_add_8_19_expect_8_19(void){
  Data *data,*rex,*rexGoh;
  HashTable hashTable;
  HashMapInit(&hashTable,10);
  rex = dataCreate(1,(int *)8);
  HashMapAddInteger(&hashTable,(void *)rex,1);
  rexGoh = dataCreate(11,(int *)19);
  HashMapAddInteger(&hashTable,(void *)rexGoh,11);

  TEST_ASSERT_NOT_NULL(hashTable.list[1].head);
  data = (Data *)(hashTable.list[1].head->data);
  TEST_ASSERT_EQUAL(1,data->key);
  TEST_ASSERT_EQUAL(8,data->name);

  TEST_ASSERT_NOT_NULL(hashTable.list[1].head->next);
  data = (Data *)(hashTable.list[1].head->next->data);
  TEST_ASSERT_EQUAL(11,data->key);
  TEST_ASSERT_EQUAL(19,data->name);

  free(rex);
  free(rexGoh);
}


/*
*     index  ------                                             index  ------
*            |    |                                                   |    |
*            |    |         added 19 same key                         |    |
*       1    |  * | -->8  ----------------->                      1   |  * |-----> 19
*            |    |                                                   |    |
*            |    |                                                   |    |
*
*/
void test_hashMapaddInteger_added_duplicated_expect_19(void){
  Data *data,*rex,*rexGoh;
  HashTable hashTable;
  HashMapInit(&hashTable,10);
  rex = dataCreate(1,(int *)8);
  HashMapAddInteger(&hashTable,(void *)rex,1);
  rexGoh = dataCreate(1,(int *)19);
  HashMapAddInteger(&hashTable,(void *)rexGoh,1);

  TEST_ASSERT_NOT_NULL(hashTable.list[1].head);
  data = (Data *)(hashTable.list[1].head->data);
  TEST_ASSERT_EQUAL(1,data->key);
  TEST_ASSERT_EQUAL(19,data->name);

  TEST_ASSERT_NULL(hashTable.list[1].head->next);


  free(rex);
  free(rexGoh);
}

/*
*     index  ------
*            |    |
*            |    |               search 8
*       1    |  * | -->8->19  ----------------->         search(8)
*            |    |
*            |    |
*
*/
void test_hashMapSearch_search_8_expect_8(void){
  Data *data,*rex,*rexGoh;
  HashTable hashTable;
  HashMapInit(&hashTable,10);
  rex = dataCreate(1,(int *)8);
  HashMapAddInteger(&hashTable,(void *)rex,1);
  rexGoh = dataCreate(11,(int *)19);
  HashMapAddInteger(&hashTable,(void *)rexGoh,11);


  Data *Search=HashMapSearchInteger(&hashTable,1);
  TEST_ASSERT_NOT_NULL(Search);
  TEST_ASSERT_EQUAL(1,Search->key);
  TEST_ASSERT_EQUAL(8,Search->name);

  free(rex);
  free(rexGoh);
}

/*
*     index  ------                                     index  ------
*            |    |                                            |    |
*            |    |                     remove 19              |    |
*      1     |  * | -->8---->19   ----------------->     1     | *  |-----> 8
*            |    |                                            |    |
*            |    |                                            |    |
*
*/
void test_hashMapRemoveinteger_remove_19_expect_8_only_in_list_1(void){
  Data *remove,*rex,*rexGoh;
  HashTable hashTable;
  HashMapInit(&hashTable,10);
  rex = dataCreate(1,(int *)8);
  HashMapAddInteger(&hashTable,(void *)rex,1);
  rexGoh = dataCreate(11,(int *)19);
  HashMapAddInteger(&hashTable,(void *)rexGoh,11);


  remove =  (Data *)(hashTable.list[1].head->next);
  TEST_ASSERT_NOT_NULL(remove);

  HashMapRemoveInteger(&hashTable,11);
  remove =  (Data *)(hashTable.list[1].head->next);

  TEST_ASSERT_NULL(remove);

  free(rex);
  free(rexGoh);
}
