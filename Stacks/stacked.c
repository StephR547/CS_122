#include "stacked.h"

//Singly Functions
void singly_add_to_start_of_list(node **head_ptr, int data_to_add) {
	node *new_node_ptr = malloc(sizeof(node));
	new_node_ptr->data = data_to_add;
	new_node_ptr->next = *head_ptr;
	*head_ptr = new_node_ptr;
}

void singly_remove_from_start_of_list(node **head_ptr) {
    if (*head_ptr == NULL) {
        printf("Nothing to remove\n");
    } else {
    	node *removed_node_ptr = (*head_ptr);
    	*head_ptr = (*head_ptr)->next;
    	free(removed_node_ptr);
    }
}

void singly_display_list(node *head) {
    if (head == NULL) {
        printf("Empty list\n");
    } else {
        node *current_node_ptr = head;
        printf("[ ");
        while (current_node_ptr != NULL) {
            printf("%d ", current_node_ptr->data);
            current_node_ptr = current_node_ptr->next;
        }
        printf("]\n");
    }
}

//Stack Functions
void stack_linked_initialize(linked_stack *stack){    
    stack->head = NULL;
}

void stack_linked_display(linked_stack stack) { 
    singly_display_list(stack.head);
}

void stack_linked_push(linked_stack *stack, int element){
    singly_add_to_start_of_list(&(stack->head), element);
}

int stack_linked_peek(linked_stack stack, int *top_value){
    if (stack.head == NULL) {        
        return 0;    
    }else{        
        *top_value = stack.head->data;        
        return 1;   
    }
}

int stack_linked_pop(linked_stack *stack){
    if (stack->head == NULL) {        
        return 0;    
        }else{        
            singly_remove_from_start_of_list(&(stack->head));        
            return 1;    
        }       
}



