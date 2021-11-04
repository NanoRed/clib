#ifndef STACK_H_
#define STACK_H_

#include <stdbool.h>
#include <stdlib.h>

typedef struct stackNode {
    void *item;
    struct stackNode *next;
} StackNode;


typedef struct stack {
    StackNode *top;
    unsigned int len;
    size_t itemSize;
    bool (* free)(void *item);
} Stack;

bool InitStack(Stack **stack, size_t itemSize, bool (* free)(void *item));
bool FreeStack(Stack *stack);
bool ResetStack(Stack *stack);
bool MakeStackNode(StackNode **node, void *item);
bool FreeStackNode(StackNode *node);
bool PushStackItem(Stack *stack, void *item);
bool PopStackItem(Stack *stack, void * restrict item);
bool TraverseStack(Stack *stack, bool (* invoke)(const void *item));

#endif