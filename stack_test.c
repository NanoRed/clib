#include <stdio.h>
#include "stack_test.h"
#include "stack.h"
#include "item.h"

bool TestStack(void)
{
    Stack *stack;
    InitStack(&stack, sizeof(Item), FreeItem);

    for (register int i = 1; i < 10; i++) {
        double number = rand()/100.0;
        Item *newItem;
        MakeItem(&newItem, i, number);
        PushStackItem(stack, newItem);
        printf("push item to stack: %d %f\n", i, number);
    }

    Item tmpItem;
    PopStackItem(stack, &tmpItem);
    printf("pop item from stack: %d %f\n", tmpItem.id, tmpItem.number);
    PopStackItem(stack, &tmpItem);
    printf("pop item from stack: %d %f\n", tmpItem.id, tmpItem.number);
    PopStackItem(stack, &tmpItem);
    printf("pop item from stack: %d %f\n", tmpItem.id, tmpItem.number);

    TraverseStack(stack, DisplayItem);
    FreeStack(stack);

    return true;
}