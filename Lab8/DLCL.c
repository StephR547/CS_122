#include "DLCL.h"

void display(doubly_circular *head) {    
    if (head != NULL) {        
        printf("LAST NODE");        
        doubly_circular *current = head;        
        do {            
            printf(" <- { %d } -> ", 
            current->id);            
            current = current->next;        
        } while (current != head);        
        printf("FIRST NODE\n");    
    } else {        
        printf("Empty List\n");    
    }
}

void add_to_empty_list(doubly_circular **head_ptr, int id) {    
    doubly_circular *new_node = malloc(sizeof(doubly_circular));    
    new_node->id = id;    
    new_node->next = new_node;    
    new_node->prev = new_node;    
    *head_ptr = new_node;
}

void add_to_start(doubly_circular **head_ptr, int id) {    
    if (*head_ptr == NULL) {        
        add_to_empty_list(head_ptr, id);    
        } else {        
            doubly_circular *new_node = malloc(sizeof(doubly_circular));        
            new_node->id = id;        
            (*head_ptr)->prev->next = new_node;        
            new_node->prev = (*head_ptr)->prev;        
            new_node->next = *head_ptr;        
            (*head_ptr)->prev = new_node;        
            *head_ptr = new_node;    
        }
}

void add_at_index(doubly_circular **head_ptr, int id, int index) {    
    if (index == 0 || *head_ptr == NULL) {        
        add_to_start(head_ptr, id);    
    } else {        
        doubly_circular *current = *head_ptr;        
        int count = 0;        
        while (count < (index - 1)) {            
            current = current->next;            
            count++;        
        }        
        if (current == *head_ptr) {            
            add_to_start(head_ptr, id);            
        } else {                
            doubly_circular *new_node = malloc(sizeof(doubly_circular));                
            new_node->id = id;                
            new_node->prev = current;                
            new_node->next = current->next;                
            current->next = new_node;                
            new_node->next->prev = new_node;            
        }    
    }
}

void add_to_end(doubly_circular **head_ptr, int id) {    
    if (*head_ptr == NULL) {        
        add_to_start(head_ptr, id);    
    } else {        
        doubly_circular *new_node = malloc(sizeof(doubly_circular));        
        new_node->id = id;        
        new_node->next = *head_ptr;        
        new_node->prev = (*head_ptr)->prev;        
        (*head_ptr)->prev->next = new_node;        
        (*head_ptr)->prev = new_node;    
    }
}

void remove_from_start(doubly_circular **head_ptr) {    
    if (*head_ptr == NULL) {        
        printf("The list is empty, removal not performed.\n");    
    }   else if (*head_ptr == (*head_ptr)->next) {        
        free(*head_ptr);        
        *head_ptr = NULL;    
    } else {        
        (*head_ptr)->prev->next = (*head_ptr)->next;        
        (*head_ptr)->next->prev = (*head_ptr)->prev;        
        doubly_circular *removed = *head_ptr;        
        *head_ptr = (*head_ptr)->next;        
        free(removed);    
    }
}

void remove_from_index(doubly_circular **head_ptr, int index) {    
    if (*head_ptr == NULL) {        
        printf("List is empty, removal not performed\n");    
    } else if (index == 0 || (*head_ptr)->next == *head_ptr) {        
        remove_from_start(head_ptr);    
    } else {        
        doubly_circular *current = *head_ptr;        
        int count = 0;        
        while(count < (index -1 )) {            
            current = current->next;            
            count++;        
        }        
        if (current == *head_ptr) {            
            remove_from_start(head_ptr);        
        } else {                
            doubly_circular *removed = current->next;                
            current->next = removed->next;                
            removed->next->prev = current;                
            free(removed);        
        }    
    }
}

void remove_from_end(doubly_circular **head_ptr) {
    if (*head_ptr == NULL) {        
        printf("No ids in list, removal not performed\n");    
    } else if ((*head_ptr)->next == *head_ptr) {        
        remove_from_start(head_ptr);    
    } else {        
        doubly_circular *last_node = (*head_ptr)->prev;        
        doubly_circular *current = last_node->prev;        
        current->next = *head_ptr;        
        (*head_ptr)->prev = current;        
        free(last_node);    
    }
}