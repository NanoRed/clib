#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "item.h"

bool MakeItem(Item **item, int id, double number)
{
    Item *newItem;
    newItem = (Item *)malloc(sizeof(Item));
    newItem->id = id;
    newItem->number = number;
    *item = newItem;
    return true;
}

bool FreeItem(void *item)
{
    free(item);
    return true;
}

bool MatchItem(const void *item1, const void *item2)
{
    if (item1 == NULL || item2 == NULL) {
        return item1 == item2;
    }
    return ((Item *)item1)->id == ((Item *)item2)->id;
}

bool DisplayItem(const void *item)
{
    printf("show item: %d %f\n", ((Item *)item)->id, ((Item *)item)->number);
    return true;
}