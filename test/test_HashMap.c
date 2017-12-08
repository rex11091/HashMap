#include "unity.h"
#include "Data.h"
#include "HashMap.h"
#include "LinkedList.h"
#include "IntegerCompare.h"

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

void test_HashMap_Given_empty_hash_table_and_value_5_and_3_is_added_expect_5_and_3_inserted(void){
  Data *data,*David,*Ali;
  HashTable hashTable;
  HashMapInit(&hashTable,10);

  David = dataCreate(5,"David");
  _HashMapAdd(&hashTable,(void*)David,7);
  Ali = dataCreate(3,"Ali");
  _HashMapAdd(&hashTable,(void*)Ali,7);

  TEST_ASSERT_NOT_NULL(hashTable.list[7].head);
  data = (Data *)(hashTable.list[7].head->data);
  TEST_ASSERT_EQUAL(5,data->key);
  TEST_ASSERT_EQUAL_STRING("David",data->name);

  TEST_ASSERT_NOT_NULL(hashTable.list[7].head->next);
  data = (Data *)(hashTable.list[7].head->next->data);
  TEST_ASSERT_EQUAL(3,data->key);
  TEST_ASSERT_EQUAL_STRING("Ali",data->name);

  free(data);
}
