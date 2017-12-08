/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Test Runner Used To Run Each Test Below=====*/
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
      setUp(); \
      TestFunc(); \
  } \
  if (TEST_PROTECT()) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

/*=======Automagically Detected Files To Include=====*/
#include "unity.h"
#include <setjmp.h>
#include <stdio.h>

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_HashMap_Given_empty_hash_table_and_value_5_is_added_expect_5_inserted(void);
extern void test_HashMap_Given_empty_hash_table_and_value_5_and_3_is_added_expect_5_and_3_inserted(void);


/*=======Test Reset Option=====*/
void resetTest(void);
void resetTest(void)
{
  tearDown();
  setUp();
}


/*=======MAIN=====*/
int main(void)
{
  UnityBegin("test_HashMap.c");
  RUN_TEST(test_HashMap_Given_empty_hash_table_and_value_5_is_added_expect_5_inserted, 16);
  RUN_TEST(test_HashMap_Given_empty_hash_table_and_value_5_and_3_is_added_expect_5_and_3_inserted, 39);

  return (UnityEnd());
}