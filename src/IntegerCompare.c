#include "IntegerCompare.h"
#include "Data.h"

int IntegerKeyCompare(uint32_t key,Data *data)
{
  return key = data->key;
}


int IntegerCompare(void *data, void *refData)
{

  if (data == refData)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}
