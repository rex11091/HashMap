#include "LinkedList.h"
#include <stdio.h>

void ListInit(LinkedList *list){
  list->head = NULL;
  list->tail = NULL;
  list->len = 0;
}

void ListAdd(LinkedList *list, Item *item)
{
  if(list->len==0){
    list->head = item;
    list->tail = item;
  }
  else{
    list->tail=item;
  }
    list->len += 1;
    item->next = NULL;
}
int Compare(LinkedList list, char name){
  return int result=strcmp(name,(Student *)list->head->Student.name);
}
int ListFind(LinkedList list, char name)
{
  //Item temp;
  //ListInit (*temp);
  int result,n=1;

  while(list->head !=NULL){
  result=Compare(list,name);
  if(result!=0){
    list->head=item;
    n++;
  }
  else
    return n;
  return n;
}
void ListRemove(LinkedList *list, char name)
{
  LinkedList temp1,temp2;
  //ListInit(*temp);
  temp1=list;
  temp2=list;

  int x;
  x=ListFind(list,name);
  if(x==1){
    list->head=item;
  }
  else{
  for(int y=0;y<x+2;y++){
    temp1->head=item;
  }
  for(int i=0;i<x-2;i++)
  {
    list->head=item;
  }
    list->head=temp1->head->item;
}
