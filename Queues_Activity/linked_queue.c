#include "linked_queue.h"

void linked_queue_init(lab_queue *queue){
    queue->list = NULL;
}

int linked_queue_dequeue(lab_queue *queue){
    if (is_queue_empty(*queue)) {        
        return 0;    
    } else{        
        double_circ_remove_from_start(&(queue->list));        
        return 1;    
    }
}
void linked_queue_enqueue(lab_queue *queue, person element){
    double_circ_add_to_end(&(queue->list), element);
}
int is_queue_empty(lab_queue queue){
    if(queue.list == NULL){
        return 1;
    }else{
        return 0;
    }
}
void linked_queue_display(lab_queue queue){
    if(is_queue_empty(queue) == 1){
        printf("EMPTY\n");
    }else if(queue.list == queue.list->next){
        printf("USER(id: %d time: %d)\n", queue.list->element.id, queue.list->element.time_in_server); 
    }else{        
        printf("FRONT USER(id: %d time: %d) ", queue.list->element.id, queue.list->element.time_in_server);        
        doubly_circular *current = queue.list;        
        current = current->next;        
        while (current != queue.list->prev)  {            
            printf(" <- (id: %d time: %d) ", current->element.id, current->element.time_in_server);            
            current = current->next;        
        }        
        printf(" <- BACK(id: %d time: %d)\n", current->element.id, current->element.time_in_server);    
    }
}
int linked_queue_peek(lab_queue queue, person *peeked_value){
     if (is_queue_empty(queue) == 1) {          
        return 0;    
    } else {        
        *peeked_value = queue.list->element.id;        
        return 1;    
    }
    
}