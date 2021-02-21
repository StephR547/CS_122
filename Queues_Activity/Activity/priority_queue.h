#include "queue_doubly_circular.h"

typedef struct priority_queue{
    doubly_circular *head;
}priority;

void priority_init(priority *queue);
void priority_enqueue(priority *queue, int element);
void priority_dequeue(priority *queue);
int priority_peek(priority *queue, int *result);