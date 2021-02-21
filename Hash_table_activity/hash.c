#include "hash.h"

int hash(hash_table table, int key){    
    return key % table.size;
}
void initialize(hash_table *table_ptr, int size){    
    table_ptr->size = size;    
    table_ptr->elements = malloc(sizeof(element_node) * size);    
    for (int i = 0; i < size; i++){        
        table_ptr->elements[i] = NULL;    
    }
}
void display(hash_table table){    
    for (int i = 0; i < table.size; i++){        
        printf("Index %d: ", i);        
        if (table.elements[i] == NULL){            
            printf("\n\tEmpty\n");        
        }else{            
            printf("\n");            
            element_node *current = table.elements[i];            
            while (current != NULL){                
                printf("\tKey: %d Value %d\n", current->key, current->value);                
                current = current->next;            
            }        
        }    
    }
}
void put(hash_table table, int key, int value){    
    int hash_index = hash(table, key);    
    element_node *current = table.elements[hash_index];    
    while(current != NULL && current->key != key){        
        current = current->next;
    }    
    if (current == NULL){        
        element_node *new = malloc(sizeof(element_node));        
        new->key = key;        
        new->value = value;        
        new->next = table.elements[hash_index];        
        table.elements[hash_index] = new;
    }else{        
        current->value = value;    
    }
}
int get(hash_table table, int key, int *value){     
    int hash_index = hash(table, key);    
    element_node *current = table.elements[hash_index];    
    while(current != NULL && current->key != key){        
        current = current->next;    
    }    
    if (current == NULL){        
        printf("Table does not contain this element\n");        
        printf("Setting value to NULL");        
        *value = NULL;        
        return 0;    
    }else{        
        *value = current->value;        
        return 1;    
    }
}
void display_keys_and_values(hash_table table){    
    for (int i = 0; i < table.size; i++){        
        if (table.elements[i] != NULL){            
            element_node *current = table.elements[i];            
            while (current != NULL){                
                printf("Key: %d Value %d\n", current->key, current->value);                
                current = current->next;            
            }        
        }    
    }
}
void remove_from_start_of_list(element_node **head_ptr){    
    if (*head_ptr == NULL){        
        printf("Nothing to remove\n");    
    }else{        
        element_node *removed_node_ptr = (*head_ptr);        
        *head_ptr = (*head_ptr)->next;        
        free(removed_node_ptr);    
    }
}
void remove_from_list_at_index(element_node **head_ptr, int index_to_remove_from){    
    if (index_to_remove_from == 0){        
        remove_from_start_of_list(head_ptr);    
    }else{           
        int current_index = 0;           
        element_node *current_node_ptr = *head_ptr;           
        while (current_index < (index_to_remove_from - 1)){          
            if (current_node_ptr != NULL){                
                current_node_ptr = current_node_ptr->next;           
            }else{                
                printf("Index is invalid, removal not performed\n");                
                return;              
            }            
            current_index++;         
        }        
        element_node *removed_node_ptr = current_node_ptr->next;        
        current_node_ptr->next = removed_node_ptr->next;        
        free(removed_node_ptr);    
    }
}
void remove_element(hash_table table, int key){    
    int hash_index = hash(table, key);    
    element_node *current = table.elements[hash_index];    
    int count = 0;    
    while(current != NULL && current->key != key){        
        current = current->next;        
        count++;    
    }    
    if (current == NULL){
        printf("Key is not in hash table.\n");    
    }else{        
        remove_from_list_at_index(&(table.elements[hash_index]), count);    
    }
}