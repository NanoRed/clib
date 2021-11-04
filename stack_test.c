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
        printf("push item to stack: %d %f %d\n", i, number, stack->len);
    }

    Item tmpItem;
    PopStackItem(stack, &tmpItem);
    printf("pop item from stack: %d %f %d\n", tmpItem.id, tmpItem.number, stack->len);
    PopStackItem(stack, &tmpItem);
    printf("pop item from stack: %d %f %d\n", tmpItem.id, tmpItem.number, stack->len);
    PopStackItem(stack, &tmpItem);
    printf("pop item from stack: %d %f %d\n", tmpItem.id, tmpItem.number, stack->len);

    TraverseStack(stack, DisplayItem);
    FreeStack(stack);

    return true;
}