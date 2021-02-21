#include "Queue.h"


void linked_queue_initialize(linked_queue *queue) {
        queue->list = NULL;
}

void linked_queue_enqueue(linked_queue *queue, int id) { 
       add_to_end(&(queue->list), id);
}

int is_linked_queue_empty(linked_queue queue) {
    if (queue.list == NULL) {
        return 1;    
    } else {        
        return 0;    
    }
}

void linked_queue_display(linked_queue queue) {    
    if (is_linked_queue_empty(queue) == 1) {        
        printf("Empty Queue\n");    
    } else if (queue.list == queue.list->next) {       
        printf("FRONT AND BACK(id: %d time: %d)\n", queue.list->id, queue.list->server_time);    
    } else {        
        printf("FRONT(id: %d time: %d) ", queue.list->id, queue.list->server_time);        
        doubly_circular *current = queue.list;        
        current = current->next;        
        while (current != queue.list->prev)  {            
            printf(" <- (id: %d time: %d) ", current->id, current->server_time);            
            current = current->next;        
        }        
        printf(" <- BACK(id: %d time: %d)\n", current->id, current->server_time);    
    }
}

int linked_queue_peek(linked_queue queue, int *peeked_value) {    
    if (is_linked_queue_empty(queue) == 1) {          
        return 0;    
    } else {        
        *peeked_value = queue.list->id;        
        return 1;    
    }
}

int linked_queue_dequeue(linked_queue *queue) {    
    if (is_linked_queue_empty(*queue)) {        
        return 0;    
    } else {        
        remove_from_start(&(queue->list));        
        return 1;    
    }
}