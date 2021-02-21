#include "linked_queue.h"

void linked_queue_initialize(linked_queue *queue) {
    queue->list = NULL;
}

void linked_queue_enqueue(linked_queue *queue, int element) {
    add_to_end(&(queue->list), element);
}

void linked_queue_display(linked_queue queue) {
    if (is_linked_queue_empty(queue) == 1) {
        printf("Empty Queue\n");
    } else if (queue.list == queue.list->next) {
        printf("FRONT AND BACK(%d)\n", queue.list->element);
    } else {
        printf("FRONT(%d)", queue.list->element);
        doubly_circular *current = queue.list;
        // We have already printed the first element so we skip it
        current = current->next;
        // While current is not the last element in the list
        while (current != queue.list->prev)  {
            printf(" <- (%d) ", current->element);
            current = current->next;
        }
        printf(" <- BACK(%d)\n", current->element);
}
}

int is_linked_queue_empty(linked_queue queue) {
    if (queue.list == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int linked_queue_peek(linked_queue queue, int *peeked_value) {
    if (is_linked_queue_empty(queue) == 1) {
        // Nothing to peek, operation prevented
        return 0;
    } else {
        *peeked_value = queue.list->element;
        return 1;
    }
}

int linked_queue_dequeue(linked_queue *queue) {
    if (is_linked_queue_empty(*queue)) {
        // Operation not performed returning error code
        return 1;
    } else {
        remove_from_start(&(queue->list));
        return 0;
    }
}