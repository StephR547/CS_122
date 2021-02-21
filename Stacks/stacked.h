#include <stdio.h>
#include <stdlib.h>

//Singly Struct
typedef struct node {    
    int data;    
    struct node *next;
}node;

void singly_add_to_start_of_list(node **head_ptr, int data_to_add);
void singly_remove_from_start_of_list(node **head_ptr);
void singly_display_list(node *head);

//Stack Struct
typedef struct linked_stack {    
    node *head;
}linked_stack;

void stack_linked_initialize(linked_stack *stack);
void stack_linked_display(linked_stack stack);
void stack_linked_push(linked_stack *stack, int element);
int stack_linked_peek(linked_stack stack, int *top_value);
int stack_linked_pop(linked_stack *stack);


