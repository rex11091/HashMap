#ifndef _INTEGERCOMPARE_H
#define _INTEGERCOMPARE_H

#include "Compare.h"
#include <stdint.h>
#include "Data.h"

int IntegerKeyCompare(uint32_t key,Data *data);


int IntegerCompare(void*data, void *refData);
#endif // _INTEGERCOMPARE_H
