#include "doubly_circular.h"

typedef struct linked_queue {
    doubly_circular *list;
} linked_queue;

void linked_queue_initialize(linked_queue *queue);
void linked_queue_enqueue(linked_queue *queue, int element);
void linked_queue_display(linked_queue queue);
int is_linked_queue_empty(linked_queue queue);
int linked_queue_peek(linked_queue queue, int *peeked_value);
int linked_queue_dequeue(linked_queue *queue);