#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdbool.h>

typedef struct listNode {
    void *item;
    struct listNode *next;
} ListNode;

typedef struct list {
    ListNode *head;
    int len;
} List;

bool InitList(List **list);
bool FreeList(List *list, bool (* freeListItem)(void *item));
bool ResetList(List *list, bool (* freeListItem)(void *item));
bool MakeListNode(ListNode **node, void *item);
bool FreeListNode(ListNode *node, void **item);
bool FindListNode(const List *list, ListNode **node, bool (* locateListItem)(const void *item));
bool InsertListNode(List *list, ListNode *node, bool (* locateListItem)(const void *item));
bool DeleteListNode(List *list, ListNode *node, bool (* locateListItem)(const void *item));
bool FindListItem(const List *list, void **item, bool (* locateListItem)(const void *item));
bool InsertListItem(List *list, void *item, bool (* locateListItem)(const void *item));
bool DeleteListItem(List *list, void *item, bool (* locateListItem)(const void *item), bool (* freeListItem)(void *item));
bool Traverse(List *list, bool (* handle)(const void *item));

#endif