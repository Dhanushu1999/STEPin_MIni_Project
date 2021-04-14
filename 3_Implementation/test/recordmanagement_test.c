
#include "unity.h"
#include "recordmanagement.h"

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}
FILE *fp;
  

void test_addrecord(void) {
  struct employee emp = {"Addedrecord",11.0,10,10};
  TEST_ASSERT_EQUAL(0, addrecord(fp,&emp));
}

void test_displayrecord(void) 
{ 
  TEST_ASSERT_EQUAL(0, displayrecord(fp,1));
}
void test_deleterecord(void) 
{ 
  TEST_ASSERT_EQUAL(0, deleterecord(fp,1));
}
void test_modifyrecord(void) 
{ 
  TEST_ASSERT_EQUAL(0, modifyrecord(fp,1));
}

int main()
{
  fp = fopen("data.txt", "rb+");

	// showing error if file is
	// unable to open.
	if (fp == NULL) 
	{
		fp = fopen("data.txt", "wb+");
	}
  
  UNITY_BEGIN();

  RUN_TEST(test_addrecord);
  RUN_TEST(test_displayrecord);
  RUN_TEST(test_deleterecord);
  RUN_TEST(test_modifyrecord);

  return UNITY_END();
}
