#include "doubly_circular.h"

typedef struct lab_queue{
    doubly_circular *list;
}lab_queue;

void linked_queue_init(lab_queue *queue);
void linked_queue_enqueue(lab_queue *queue, person element);
void linked_queue_display(lab_queue queue);
int is_queue_empty(lab_queue queue);
int linked_queue_peek(lab_queue queue, person *peeked_value);
int linked_queue_dequeue(lab_queue *queue);