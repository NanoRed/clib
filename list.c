#include "list.h"
#include <stdlib.h>

bool InitList(List **list)
{
    ListNode *head;
    if (!MakeListNode(&head, NULL)) {
        return false;
    }
    List *newList;
    if ((newList = (List *)malloc(sizeof(List))) == NULL) {
        void *dummy;
        FreeListNode(head, &dummy);
        return false;
    }
    head->item = head->next = NULL;
    newList->head = head;
    newList->len = 0;
    *list = newList;
    return true;
}

bool FreeList(List *list, bool (* freeListItem)(void *item))
{
    bool result = true;
    ListNode *current = list->head->next;
    void *item;
    while (current != NULL) {
        list->head->next = current->next;
        FreeListNode(current, &item);
        result = freeListItem(item);
        current = list->head->next;
    }
    if (!list->head) {
        FreeListNode(list->head, &item);
    }
    free(list);
    return result;
}

bool ResetList(List *list, bool (* freeListItem)(void *item))
{
    bool result = true;
    ListNode *current = list->head->next;
    while (current != NULL) {
        list->head->next = current->next;
        result = freeListItem(current->item);
        free(current);
        current = list->head->next;
    }
    return result;
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

bool FreeListNode(ListNode *node, void **item)
{
    *item = node->item;
    free(node);
    return true;
}

bool FindListNode(const List *list, ListNode **node, bool (* locateListItem)(const void *item))
{
    ListNode *current = list->head->next;
    while (current != NULL) {
        if (locateListItem(current->item)) {
            *node = current;
            return true;
        }
        current = current->next;
    }
    return false;
}

bool InsertListNode(List *list, ListNode *node, bool (* locateListItem)(const void *item))
{
    ListNode *previous = list->head;
    while (previous != NULL) {
        if (locateListItem(previous->item)) {
            node->next = previous->next;
            previous->next = node;
            return true;
        }
        previous = previous->next;
    }
    return false;
}

bool DeleteListNode(List *list, ListNode *node, bool (* locateListItem)(const void *item))
{
    ListNode *previous = list->head, *current = list->head->next;
    void *dummy;
    while (current != NULL) {
        if (locateListItem(current->item)) {
            *node = *current;
            previous->next = current->next;
            FreeListNode(current, &dummy);
            return true;
        }
        previous = current;
        current = current->next;
    }
    return false;
}

bool FindListItem(const List *list, void **item, bool (* locateListItem)(const void *item))
{
    ListNode *node;
    if (!FindListNode(list, &node, locateListItem)) {
        return false;
    }
    *item = node->item;
    return true;
}

bool InsertListItem(List *list, void *item, bool (* locateListItem)(const void *item))
{
    ListNode *newNode;
    if (!MakeListNode(&newNode, item)) {
        return false;
    }
    return InsertListNode(list, newNode, locateListItem);
}

bool DeleteListItem(List *list, void *item, bool (* locateListItem)(const void *item), bool (* freeListItem)(void *item))
{
    ListNode node;
    if (!DeleteListNode(list, &node, locateListItem)) {
        return false;
    }
    return freeListItem(node.item);
}

bool Traverse(List *list, bool (* handle)(const void *item))
{
    ListNode *current = list->head->next;
    while (current != NULL) {
        if (!handle(current->item)) {
            return false;
        }
        current = current->next;
    }
    return true;
}