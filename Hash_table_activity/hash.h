#include <stdio.h>
#include <stdlib.h>

typedef struct element_node{    
    int key;    
    int value;    
    struct element_node *next;
}element_node;

typedef struct hash_table{    
    element_node **elements;    
    int size;
}hash_table;

int hash(hash_table table, int key);
void initialize(hash_table *table_ptr, int size);
void display(hash_table table);
void put(hash_table table, int key, int value);
int get(hash_table table, int key, int *value);
void display_keys_and_values(hash_table table);
void remove_from_start_of_list(element_node **head_ptr);
void remove_from_list_at_index(element_node **head_ptr, int index_to_remove_from);
void remove_element(hash_table table, int key);