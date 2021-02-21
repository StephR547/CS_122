#include "priority_queue.h"

int main(){
    priority queue;
    priority_init(&queue);
    priority_enqueue(&queue, 17);
    double_circ_display(queue.head);
    priority_enqueue(&queue, 84);
    double_circ_display(queue.head);
    priority_enqueue(&queue, 34);
    double_circ_display(queue.head);
    priority_enqueue(&queue, 100);
    double_circ_display(queue.head);
    
}