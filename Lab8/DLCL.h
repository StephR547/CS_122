#include <stdio.h> 
#include <stdlib.h>

typedef struct doubly_circular {    
    int id;
    int arrival_time;
    int server_time;   
    struct doubly_circular *next;    
    struct doubly_circular *prev;
} doubly_circular;

void display(doubly_circular *head);
void add_to_empty_list(doubly_circular **head_ptr, int id);
void add_to_start(doubly_circular **head_ptr, int id);
void add_at_index(doubly_circular **head_ptr, int id, int index);
void add_to_end(doubly_circular **head_ptr, int id);
void remove_from_start(doubly_circular **head_ptr);
void remove_from_index(doubly_circular **head_ptr, int index);
void remove_from_end(doubly_circular **head_ptr);