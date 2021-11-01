#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdbool.h>

typedef struct listNode {
    void *item;
    struct listNode *next;
} ListNode;

typedef struct list {
    ListNode *head;
    unsigned int len;
    bool (* free)(void *item);
    bool (* match)(const void *itemInList, const void *item);
} List;

bool InitList(List **list, bool (* free)(void *item), bool (* match)(const void *itemInList, const void *item));
bool FreeList(List *list);
bool ResetList(List *list);
bool MakeListNode(ListNode **node, void *item);
bool FreeListNode(ListNode *node);
bool FindListItem(const List *list, void **item, const void *findItem);
bool InsertListItem(List *list, void *item, const void *afterThisItem);
bool DeleteListItem(List *list, void *findItem);
bool Traverse(List *list, bool (* invoke)(const void *item));

#endif