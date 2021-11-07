#include "linked_list.h"
#include <stdlib.h>

bool InitList(LinkedList **list, bool (* free)(void *item), bool (* match)(const void *itemInList, const void *item))
{
    LinkedListNode *head;
    if (!MakeListNode(&head, NULL)) {
        return false;
    }
    LinkedList *newList;
    if ((newList = (LinkedList *)malloc(sizeof(LinkedList))) == NULL) {
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

bool FreeList(LinkedList *list)
{
    LinkedListNode *current = list->head->next;
    while (current != NULL) {
        list->head->next = current->next;
        list->free(current->item);
        FreeListNode(current);
        current = list->head->next;
    }
    if (list->head) {
        FreeListNode(list->head);
    }
    free(list);
    return true;
}

bool ResetList(LinkedList *list)
{
    LinkedListNode *current = list->head->next;
    while (current != NULL) {
        list->head->next = current->next;
        list->free(current->item);
        FreeListNode(current);
        current = list->head->next;
    }
    list->len = 0;
    return true;
}

bool MakeListNode(LinkedListNode **node, void *item)
{
    if ((*node = (LinkedListNode *)malloc(sizeof(LinkedListNode))) == NULL) {
        return false;
    }
    (*node)->item = item;
    (*node)->next = NULL;
    return true;
}

bool FreeListNode(LinkedListNode *node)
{
    free(node);
    return true;
}

bool FindListItem(const LinkedList *list, void **item, const void *findItem)
{
    LinkedListNode *current = list->head->next;
    while (current != NULL) {
        if (list->match(current->item, findItem)) {
            *item = current->item;
            return true;
        }
        current = current->next;
    }
    return false;
}

bool InsertListItem(LinkedList *list, void *item, const void *afterThisItem)
{
    LinkedListNode *previous = list->head;
    while (previous != NULL) {
        if (list->match(previous->item, afterThisItem)) {
            LinkedListNode *newNode;
            if (!MakeListNode(&newNode, item)) {
                return false;
            }
            newNode->next = previous->next;
            previous->next = newNode;
            list->len++;
            return true;
        }
        previous = previous->next;
    }
    return false;
}

bool DeleteListItem(LinkedList *list, void *findItem)
{
    LinkedListNode *previous = list->head, *current = list->head->next;
    while (current != NULL) {
        if (list->match(current->item, findItem)) {
            previous->next = current->next;
            list->free(current->item);
            FreeListNode(current);
            list->len--;
            return true;
        }
        previous = current;
        current = current->next;
    }
    return false;
}

bool TraverseList(LinkedList *list, bool (* invoke)(const void *item))
{
    LinkedListNode *current = list->head->next;
    while (current != NULL) {
        if (!invoke(current->item)) {
            return false;
        }
        current = current->next;
    }
    return true;
}