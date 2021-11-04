#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdbool.h>

typedef struct queueNode {
    void *item;
    struct queueNode *next;
} QueueNode;

typedef struct queue {
    QueueNode *front;
    QueueNode *rear;
    unsigned int len;
    size_t itemSize;
    bool (* free)(void *item);
} Queue;

bool InitQueue(Queue **queue, size_t itemSize, bool (* free)(void *item));
bool FreeQueue(Queue *queue);
bool ResetQueue(Queue *queue);
bool MakeQueueNode(QueueNode **node, void *item);
bool FreeQueueNode(QueueNode *node);
bool PushQueueItem(Queue *queue, void *item);
bool PopQueueItem(Queue *queue, void * restrict item);
bool TraverseQueueItem(Queue *queue, bool (* invoke)(const void *item));

#endif