#include "linked.h"

void display(circular *head){
    if (head != NULL) {
        circular *current_node_ptr = head;
        do{
            printf("\t{ %s } \n", current_node_ptr->name);
            current_node_ptr = current_node_ptr->next;
        }while (strcmp(current_node_ptr->name, head->name)!= 0);
    } else {
        printf("Empty list\n");  
    }
}

void insert_to_empty_list(circular **head_ptr, char *element){
     circular *new_node_ptr = malloc(sizeof(circular));
     new_node_ptr->name = malloc((strlen(element)+1) * sizeof(char));
     strcpy(new_node_ptr->name, element);
     new_node_ptr->next = new_node_ptr;
     *head_ptr = new_node_ptr;

}

void insert_at_start(circular **head_ptr, char *name){
	if(*head_ptr == NULL){
        insert_to_empty_list(head_ptr, name);
    }else{
        circular *new_node_ptr = malloc(sizeof(circular));
        new_node_ptr->name = malloc((strlen(name)+1)*sizeof(char));
        strcpy(new_node_ptr->name, name);
	    new_node_ptr->next = *head_ptr;
        circular *current = *head_ptr;
        while(current->next != (*head_ptr)){
            current = current->next;
        }
        current->next = new_node_ptr;
        *head_ptr = new_node_ptr;
    }
}

void insert_at_end(circular **head_ptr, char *name){
    if (*head_ptr == NULL) {
        insert_at_start(head_ptr, name);
    } 
    else { 
        circular *current_node_ptr = *head_ptr;
        while(current_node_ptr-> next != (*head_ptr)) {
        current_node_ptr = current_node_ptr->next;
        }
        circular *new_node_ptr = malloc(sizeof(circular));
        new_node_ptr->name = malloc((strlen(name)+1) * sizeof(char));
        strcpy(new_node_ptr->name, name);
        new_node_ptr->next = current_node_ptr->next;
        current_node_ptr->next = new_node_ptr; 
    }

}

void remove_from_start(circular **head_ptr){
    if (*head_ptr == NULL) {
        printf("Nothing to remove\n");
    } else if(*head_ptr == (*head_ptr)->next){
    	circular *removed_node_ptr = (*head_ptr);
    	*head_ptr = NULL;
    	free(removed_node_ptr);
    }else{
        circular *current = *head_ptr;
        while (current->next != *head_ptr){
            current = current->next;
        }
        current->next = (*head_ptr)->next;
        circular *removed = *head_ptr;
        *head_ptr = removed->next;
        free(removed);
    }
}

void delete_by_name(circular **head_ptr, char *element_to_remove){
    circular *current = *head_ptr;
    circular *removed_node = NULL;

    while(strcmp(current->name , element_to_remove) != 0){
        current = current->next;
    }
    removed_node = current;

    if(strcmp(current->name , element_to_remove) == 0){
        remove_from_start(&removed_node);
    }

}