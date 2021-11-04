#include <stdlib.h>
#include <string.h>
#include "queue.h"

bool InitQueue(Queue **queue, size_t itemSize, bool (* free)(void *item))
{
    QueueNode *emptyNode;
    if (!MakeQueueNode(&emptyNode, NULL)) {
        return false;
    }
    Queue *newQueue;
    if ((newQueue = (Queue *)malloc(sizeof(Queue))) == NULL) {
        FreeQueueNode(emptyNode);
        return false;
    }
    newQueue->front = newQueue->rear = emptyNode;
    newQueue->len = 0;
    newQueue->itemSize = itemSize;
    newQueue->free = free;
    *queue = newQueue;
    return true;
}

bool FreeQueue(Queue *queue)
{
    QueueNode *current = queue->front->next;
    while (current != NULL) {
        queue->front->next = current->next;
        queue->free(current->item);
        FreeQueueNode(current);
        current = queue->front->next;
    }
    FreeQueueNode(queue->front);
    free(queue);
    return true;
}

bool ResetQueue(Queue *queue)
{
    QueueNode *current = queue->front->next;
    while (current != NULL) {
        queue->front->next = current->next;
        queue->free(current->item);
        FreeQueueNode(current);
        current = queue->front->next;
    }
    queue->rear = queue->front;
    return true;
}

bool MakeQueueNode(QueueNode **node, void *item)
{
    QueueNode *newNode;
    if ((newNode = (QueueNode *)malloc(sizeof(QueueNode))) == NULL) {
        return false;
    }
    newNode->item = item;
    newNode->next = NULL;
    *node = newNode;
    return true;
}

bool FreeQueueNode(QueueNode *node)
{
    free(node);
    return true;
}

bool PushQueueItem(Queue *queue, void *item)
{
    QueueNode *newNode;
    MakeQueueNode(&newNode, item);
    queue->rear->next = newNode;
    queue->rear = newNode;
    queue->len++;
    return true;
}

bool PopQueueItem(Queue *queue, void * restrict item)
{
    QueueNode *tmpNode = queue->front->next;
    if (tmpNode == NULL) {
        return false;
    } else if ((queue->front->next = tmpNode->next) == NULL) {
        queue->rear = queue->front;
    }
    memcpy(item, tmpNode->item, queue->itemSize);
    queue->free(tmpNode->item);
    FreeQueueNode(tmpNode);
    queue->len--;
    return true;
}

bool TraverseQueueItem(Queue *queue, bool (* invoke)(const void *item))
{
    QueueNode *current = queue->front->next;
    while (current != NULL) {
        if (!invoke(current->item)) {
            return false;
        }
        current = current->next;
    }
    return true;
}