#include "list.h"
#include <stdlib.h>

bool InitList(List **list, bool (* free)(void *item), bool (* match)(const void *itemInList, const void *item))
{
    ListNode *head;
    if (!MakeListNode(&head, NULL)) {
        return false;
    }
    List *newList;
    if ((newList = (List *)malloc(sizeof(List))) == NULL) {
        FreeListNode(head);
        return false;
    }
    head->item = head->next = NULL;
    newList->head = head;
    newList->len = 0;
    newList->free = free;
    newList->match = match;
    *list = newList;
    return true;
}

bool FreeList(List *list)
{
    ListNode *current = list->head->next;
    while (current != NULL) {
        list->head->next = current->next;
        list->free(current->item);
        FreeListNode(current);
        current = list->head->next;
    }
    if (!list->head) {
        FreeListNode(list->head);
    }
    free(list);
    return true;
}

bool ResetList(List *list)
{
    ListNode *current = list->head->next;
    while (current != NULL) {
        list->head->next = current->next;
        list->free(current->item);
        FreeListNode(current);
        current = list->head->next;
    }
    return true;
}

bool MakeListNode(ListNode **node, void *item)
{
    if ((*node = (ListNode *)malloc(sizeof(ListNode))) == NULL) {
        return false;
    }
    (*node)->item = item;
    (*node)->next = NULL;
    return true;
}

bool FreeListNode(ListNode *node)
{
    free(node);
    return true;
}

bool FindListItem(const List *list, void **item, const void *findItem)
{
    ListNode *current = list->head->next;
    while (current != NULL) {
        if (list->match(current->item, findItem)) {
            *item = current->item;
            return true;
        }
        current = current->next;
    }
    return false;
}

bool InsertListItem(List *list, void *item, const void *afterThisItem)
{
    ListNode *previous = list->head;
    while (previous != NULL) {
        if (list->match(previous->item, afterThisItem)) {
            ListNode *newNode;
            MakeListNode(&newNode, item);
            newNode->next = previous->next;
            previous->next = newNode;
            return true;
        }
        previous = previous->next;
    }
    return false;
}

bool DeleteListItem(List *list, void *findItem)
{
    ListNode *previous = list->head, *current = list->head->next;
    while (current != NULL) {
        if (list->match(current->item, findItem)) {
            previous->next = current->next;
            list->free(current->item);
            FreeListNode(current);
            return true;
        }
        previous = current;
        current = current->next;
    }
    return false;
}

bool Traverse(List *list, bool (* invoke)(const void *item))
{
    ListNode *current = list->head->next;
    while (current != NULL) {
        if (!invoke(current->item)) {
            return false;
        }
        current = current->next;
    }
    return true;
}