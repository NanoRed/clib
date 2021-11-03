#include <stdlib.h>
#include <stdio.h>
#include "linked_list_test.h"
#include "linked_list.h"
#include "item.h"

bool TestList(void)
{
    LinkedList *list;
    InitList(&list, FreeItem, MatchItem);

    Item *prevItem = NULL;
    Item *newItem;
    double number;
    for (register int i = 1; i < 10; i++) {
        number = rand()/100.0;
        MakeItem(&newItem, i, number);
        InsertListItem(list, newItem, prevItem);
        prevItem = newItem;
        printf("insert item into list: %d %f\n", i, number);
    }

    Item tmpItem;
    tmpItem.id = 4;
    DeleteListItem(list, &tmpItem);
    printf("delete item from list: %d %f\n", tmpItem.id, tmpItem.number);
    tmpItem.id = 5;
    DeleteListItem(list, &tmpItem);
    printf("delete item from list: %d %f\n", tmpItem.id, tmpItem.number);
    tmpItem.id = 6;
    DeleteListItem(list, &tmpItem);
    printf("delete item from list: %d %f\n", tmpItem.id, tmpItem.number);

    TraverseList(list, DisplayItem);
    FreeList(list);

    return true;
}
