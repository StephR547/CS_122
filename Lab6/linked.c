#include "linked.h"

void add_to_start_of_list(node **head_ptr, int data_to_add) {
	node *new_node_ptr = malloc(sizeof(node));
	new_node_ptr->data = data_to_add;
	new_node_ptr->next = *head_ptr;
	*head_ptr = new_node_ptr;
}

void remove_from_start_of_list(node **head_ptr) {
    if (*head_ptr == NULL) {
        printf("Nothing to remove\n");
    } else {
    	node *removed_node_ptr = (*head_ptr);
    	*head_ptr = (*head_ptr)->next;
    	free(removed_node_ptr);
    }
}

void display_list(node *head) {
    if (head == NULL) {
        printf("Empty\n");
    } else {
        node *current_node_ptr = head;
        while (current_node_ptr != NULL) {
            printf(" { %d } -> ", current_node_ptr->data);
            current_node_ptr = current_node_ptr->next;
        }
        printf("X\n");
    }
}