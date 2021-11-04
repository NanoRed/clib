#include <stdlib.h>
#include <stdio.h>
#include "queue_test.h"
#include "queue.h"
#include "item.h"

bool TestQueue(void)
{
    Queue *queue;
    InitQueue(&queue, sizeof(Item), FreeItem);

    double number;
    Item *newitem;
    for (register int i = 1; i < 10; i++) {
        number = rand()/100.0;
        MakeItem(&newitem, i, number);
        PushQueueItem(queue, newitem);
        printf("push queue item: %d %f %d\n", newitem->id, newitem->number, queue->len);
    }

    Item tmpItem;
    PopQueueItem(queue, &tmpItem);
    printf("pop queue item: %d %f %d\n", tmpItem.id, tmpItem.number, queue->len);
    PopQueueItem(queue, &tmpItem);
    printf("pop queue item: %d %f %d\n", tmpItem.id, tmpItem.number, queue->len);
    PopQueueItem(queue, &tmpItem);
    printf("pop queue item: %d %f %d\n", tmpItem.id, tmpItem.number, queue->len);

    TraverseQueueItem(queue, DisplayItem);
    FreeQueue(queue);
    
    return true;
}