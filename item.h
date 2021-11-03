#ifndef ITEM_H_
#define ITEM_H_

#include <stdbool.h>

typedef struct item {
    int id;
    double number;
} Item;

bool MakeItem(Item **item, int id, double number);
bool FreeItem(void *item);
bool MatchItem(const void *item1, const void *item2);
bool DisplayItem(const void *item);

#endif