#include "list_test.h"
#include "list.h"
#include <stdlib.h>
#include <stdio.h>

bool TestList(void)
{
    List *list;
    if (!InitList(&list)) {
        return false;
    }

    Item *item;
    double number;
    register int i = 1;
    for (; i < 10; i++) {
        number = rand()/100.0;
        if (!CreateItem(&item, i, number)) {
            return false;
        }
        if (!InsertListItem(list, item, FindFirstNode)) {
            return false;
        }
        printf("insert item: %d %f\n", i, number);
    }

    void *dummy;
    if (!DeleteListItem(list, dummy, FindDeleteNode, FreeListItem)) {
        return false;
    }
    if (!DeleteListItem(list, dummy, FindDeleteNode, FreeListItem)) {
        return false;
    }
    if (!DeleteListItem(list, dummy, FindDeleteNode, FreeListItem)) {
        return false;
    }

    if (!Traverse(list, Display)) {
        return false;
    }
    if (!FreeList(list, FreeListItem)) {
        return false;
    }

    return true;
}

bool FindDeleteNode(const void *item)
{
    if (((Item *)item)->id%3 == 0) {
        return true;
    }
    return false;
}

bool CreateItem(Item **item, int id, double number)
{
    Item *newItem;
    newItem = (Item *)malloc(sizeof(Item));
    newItem->id = id;
    newItem->number = number;
    *item = newItem;
    return true;
}

bool FindFirstNode(const void *item)
{
    if (item == NULL) {
        return true;
    }
    return false;
}

bool FreeListItem(void *item)
{
    free(item);
    return true;
}

bool Display(const void *item)
{
    printf("show item: %d %f\n", ((Item *)item)->id, ((Item *)item)->number);
    return true;
}