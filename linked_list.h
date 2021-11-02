#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdbool.h>

typedef struct linkedListNode {
    void *item;
    struct linkedListNode *next;
} LinkedListNode;

typedef struct linkedList {
    LinkedListNode *head;
    unsigned int len;
    bool (* free)(void *item);
    bool (* match)(const void *itemInList, const void *item);
} LinkedList;

bool InitList(LinkedList **list, bool (* free)(void *item), bool (* match)(const void *itemInList, const void *item));
bool FreeList(LinkedList *list);
bool ResetList(LinkedList *list);
bool MakeListNode(LinkedListNode **node, void *item);
bool FreeListNode(LinkedListNode *node);
bool FindListItem(const LinkedList *list, void **item, const void *findItem);
bool InsertListItem(LinkedList *list, void *item, const void *afterThisItem);
bool DeleteListItem(LinkedList *list, void *findItem);
bool TraverseListItem(LinkedList *list, bool (* invoke)(const void *item));

#endif