#ifndef LIST_TEST_H_
#define LIST_TEST_H_

#include <stdbool.h>

typedef struct item {
    int id;
    double number;
} Item;

bool TestList(void);

bool CreateItem(Item **item, int id, double number);
bool FindDeleteNode(const void *item);
bool FindFirstNode(const void *item);
bool FreeListItem(void *item);
bool Display(const void *item);

#endif