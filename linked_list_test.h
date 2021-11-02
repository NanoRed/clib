#ifndef LIST_TEST_H_
#define LIST_TEST_H_

#include <stdbool.h>

typedef struct item {
    int id;
    double number;
} Item;

bool TestList(void);

bool MakeListItem(Item **item, int id, double number);
bool FreeListItem(void *item);
bool MatchListItem(const void *itemInList, const void *item);
bool Display(const void *item);

#endif