#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include "Data.h"
#include "IntegerCompare.h"

typedef struct Item Item;
typedef struct LinkedList LinkedList;

struct Item{
  Item *next;
  Data *data;
};

struct LinkedList{
  Item *head;
  Item *tail;
  int len;

};

void ListInit(LinkedList *list);
void ListAdd(LinkedList *list, Item *item);
Item *ListRemoveIDEither1stOrByName(LinkedList *list, char  *name);
void *ListSearch(LinkedList *list ,uint32_t key, Compare compareFunc);
void *Listremove(LinkedList *list, uint32_t key, Compare compareFunc);
void createItem(Item *item, void *data, Item *next);

#endif // _LINKEDLIST_H
