#ifndef _DATA_H
#define _DATA_H

#include "stdint.h"

typedef struct Data Data;
struct Data{
  uint32_t key;
  void *name;
};

Data *dataCreate(uint32_t key, void *name);

#endif // _DATA_H
