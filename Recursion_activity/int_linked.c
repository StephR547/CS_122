#include "int_linked.h"

int list_contains(node *head, int element) {
    node *current = head;
    while (current != NULL) {
        if (element == current->data) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void add_to_start_of_list(node **head_ptr, int data_to_add) {
	// create a node pointer and set it to a space for a node
	node *new_node_ptr = malloc(sizeof(node));
	// put the data we want to insert into the new node
	new_node_ptr->data = data_to_add;
	new_node_ptr->next = *head_ptr;
	*head_ptr = new_node_ptr;
}

void add_to_end_of_list(node **head_ptr, int data_to_add) {
  
    if (*head_ptr == NULL) {
        add_to_start_of_list(head_ptr, data_to_add);
    } 
    else {
        
        node *current_node_ptr = *head_ptr;
        while(current_node_ptr-> next != NULL) {
        current_node_ptr = current_node_ptr-> next;
        }
        node *new_node_ptr = malloc(sizeof(node));
		// put the data we want to insert into the new node
	    new_node_ptr->data = data_to_add;
        new_node_ptr->next = NULL;
        current_node_ptr->next = new_node_ptr; 
    }
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

void remove_from_end_of_list(node **head_ptr) {
    if (*head_ptr == NULL) {
		printf("List is empty, removal not performed\n");
	} else if ((*head_ptr)->next == NULL) {
        remove_from_start_of_list(head_ptr);
    }
    else {
    node *current_ptr = *head_ptr;
    node *behind_ptr = *head_ptr;
    current_ptr = current_ptr->next;    
    while(current_ptr->next!=NULL) {
	    current_ptr = current_ptr->next;
	    behind_ptr = behind_ptr->next;
    }
    free(current_ptr);
    behind_ptr->next = NULL;
    }
}


void remove_from_list_at_index(node **head_ptr, int index_to_remove_from) {
	if (index_to_remove_from == 0) {
		remove_from_start_of_list(head_ptr);
	} else {
		   int current_index = 0;
           node *current_node_ptr = *head_ptr;
           while (current_index < (index_to_remove_from - 1)) {
	       if (current_node_ptr != NULL) {
		        current_node_ptr = current_node_ptr->next;
	       } else {
		        printf("Index is invalid, removal not performed\n");
		        return;  
	        }
	        current_index++; 
        }
        node *removed_node_ptr = current_node_ptr->next;
        current_node_ptr->next = removed_node_ptr->next;
        free(removed_node_ptr);
	}
}

void add_to_list_at_index(node **head_ptr, int data_to_add, int index_to_add_at) {

    if (index_to_add_at == 0) {
        add_to_start_of_list(head_ptr, data_to_add);
    }
    else {
        int current_index = 0;
        node *current_node_ptr = *head_ptr;
        while (current_index < (index_to_add_at - 1)) {
	        if (current_node_ptr != NULL) {
		        current_node_ptr = current_node_ptr->next;
	        } else {
		        printf("Index is invalid, insertion not performed\n");
		        return;  
	        }
	        current_index++;
        }
        node *new_node_ptr = malloc(sizeof(node));
        new_node_ptr->data = data_to_add;
        new_node_ptr->next = NULL;
        new_node_ptr->next = current_node_ptr->next;
        current_node_ptr->next = new_node_ptr;
    }
}

void display_list(node *head) {
    if (head == NULL) {
        printf("Empty list\n");
    } else {
        node *current_node_ptr = head;
        while (current_node_ptr != NULL) {
            printf(" { %d } -> ", current_node_ptr->data);
            current_node_ptr = current_node_ptr->next;
        }
        printf("X\n");
    }
}
