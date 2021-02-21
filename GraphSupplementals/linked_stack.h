
#include <stdio.h>
#include <stdlib.h>
#include "int_linked.h"

typedef struct linked_stack {
    i_node *head;
} linked_stack;

void linked_initialize(linked_stack *stack);
void linked_display(linked_stack stack);
void linked_push(linked_stack *stack, int element);
int linked_peek(linked_stack stack, int *top_value);
int linked_pop(linked_stack *stack);