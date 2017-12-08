#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include "IntegerCompare.h"

typedef struct Item Item;
typedef struct LinkedList LinkedList;

struct Item{
  Item *next;
  void *data;
};

struct LinkedList{
  Item *head;
  Item *tail;
  int len;

};

void ListInit(LinkedList *list);
void ListAdd(LinkedList *list, Item *item);
Item *ListRemoveIDEither1stOrByName(LinkedList *list, char  *name);
Item *ListSearch(LinkedList *list ,void *data, Compare IntegerCompare);
void createItem(Item *item, void *data, Item *next);

#endif // _LINKEDLIST_H
