#include "unity.h"
#include "Data.h"
#include "HashMap.h"
#include "LinkedList.h"
#include "IntegerCompare.h"
#include "HashMapString.h"
#include "HashMapInteger.h"

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
*       7    |  * | -->5->3
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
  //TEST_ASSERT_EQUAL(3,data->key)
  data =  (Data *)(hashTable.list[7].head->next);
  TEST_ASSERT_NULL(data);
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


void test_hashMapRemoveString_given_David_15_then_remove_David_expected_Ali_only_in_table(void){
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
//  TEST_ASSERT_EQUAL(3,data->key)
  data =  (Data *)(hashTable.list[5].head->next);
  TEST_ASSERT_NULL(data);
  free(david);
  free(ali);

}
/*-------------------------------------------- Test HaspMapinteger---------------------------------------------*/
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

void test_hashMapaddInteger_add_8_16_expect_8_16(void){
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
