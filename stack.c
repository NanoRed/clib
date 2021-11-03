#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

bool InitStack(Stack **stack, size_t itemSize, bool (* free)(void *item))
{
    Stack *newStack;
    if ((newStack = (Stack *)malloc(sizeof(Stack))) == NULL) {
        return false;
    }
    newStack->top = NULL;
    newStack->len = 0;
    newStack->itemSize = itemSize;
    newStack->free = free;
    *stack = newStack;
    return true;
}

bool FreeStack(Stack *stack)
{
    StackNode *current = stack->top;
    while (current != NULL) {
        stack->top = current->next;
        stack->free(current->item);
        FreeStackNode(current);
        current = stack->top;
    }
    free(stack);
    return true;
}

bool ResetStack(Stack *stack)
{
    StackNode *current = stack->top;
    while (current != NULL) {
        stack->top = current->next;
        stack->free(current->item);
        FreeStackNode(current);
        current = stack->top;
    }
    stack->len = 0;
    return true;
}

bool MakeStackNode(StackNode **node, void *item)
{
    StackNode *newNode;
    if ((newNode = (StackNode *)malloc(sizeof(StackNode))) == NULL) {
        return false;
    }
    newNode->item = item;
    newNode->next = NULL;
    *node = newNode;
    return true;
}

bool FreeStackNode(StackNode *node)
{
    free(node);
    return true;
}

bool PushStackItem(Stack *stack, void *item)
{
    StackNode *newNode;
    if (!MakeStackNode(&newNode, item)) {
        return false;
    }
    newNode->next = stack->top;
    stack->top = newNode;
    stack->len++;
    return true;
}

bool PopStackItem(Stack *stack, void * restrict item)
{
    StackNode *top = stack->top;
    if (top == NULL) {
        return false;
    }
    stack->top = top->next;
    memcpy(item, top->item, stack->itemSize);
    stack->free(top->item);
    FreeStackNode(top);
    stack->len--;
    return true;
}

bool TraverseStack(Stack *stack, bool (* invoke)(const void *item))
{
    StackNode *current = stack->top;
    while(current != NULL) {
        if (!invoke(current->item)) {
            return false;
        }
        current = current->next;
    }
    return true;
}