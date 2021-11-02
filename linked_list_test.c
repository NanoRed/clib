#include "linked_list_test.h"
#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

bool TestList(void)
{
    LinkedList *list;
    InitList(&list, FreeListItem, MatchListItem);

    Item *prevItem = NULL;
    Item *newItem;
    double number;
    for (register int i = 1; i < 10; i++) {
        number = rand()/100.0;
        MakeListItem(&newItem, i, number);
        InsertListItem(list, newItem, prevItem);
        prevItem = newItem;
        printf("insert item: %d %f\n", i, number);
    }

    Item tmpItem;
    tmpItem.id = 4;
    DeleteListItem(list, &tmpItem);
    tmpItem.id = 5;
    DeleteListItem(list, &tmpItem);
    tmpItem.id = 6;
    DeleteListItem(list, &tmpItem);

    TraverseListItem(list, Display);
    FreeList(list);

    return true;
}


bool MakeListItem(Item **item, int id, double number)
{
    Item *newItem;
    newItem = (Item *)malloc(sizeof(Item));
    newItem->id = id;
    newItem->number = number;
    *item = newItem;
    return true;
}

bool FreeListItem(void *item)
{
    free(item);
    return true;
}

bool MatchListItem(const void *itemInList, const void *item)
{
    if (item == NULL) {
        return itemInList == item;
    } else if (itemInList == NULL) {
        return false;
    }
    return ((Item *)itemInList)->id == ((Item *)item)->id;
}

bool Display(const void *item)
{
    printf("show item: %d %f\n", ((Item *)item)->id, ((Item *)item)->number);
    return true;
}