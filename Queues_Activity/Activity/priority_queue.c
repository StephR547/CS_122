#include "priority_queue.h"

void linked_queue_init(priority *queue){
    queue->head = NULL;
}

void priority_dequeue(priority *queue){
    double_circ_remove_from_start(&(queue->head));
}
void priority_enqueue(priority *queue, int element){
    //double_circ_add_to_end(&(queue->head), element);
    if(queue->head == NULL){
        double_circ_add_to_start(&(queue->head), element);
    }else{
        doubly_circular *current = queue->head;
        int count = 0;
        while(current->element < current->element && current != queue->head->prev){
            count++;
            current = current->next;
        }
        if(current == queue->head->prev && current->element < element){
            count++;
        }
        double_circ_add_at_index(&(queue->head), element, count);
        }

}

int priority_peek(priority *queue, int *result){
    if(queue->head == NULL){
        return 0;
    }else{
        *result = queue->head->element;
        return 1;
    }
    
}