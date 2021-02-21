#include "linked_stack.h"

void linked_initialize(linked_stack *stack) {
    stack->head = NULL;
}

void linked_display(linked_stack stack) {
    i_display_list(stack.head);
}

void linked_push(linked_stack *stack, int element) {
    i_add_to_start_of_list(&(stack->head), element);
}

int linked_peek(linked_stack stack, int *top_value) {
    if (stack.head == NULL) {
        return 0;
    } else {
        *top_value = stack.head->data;
        return 1;
    }
}

int linked_pop(linked_stack *stack) {
    if (stack->head == NULL) {
        return 0;
    } else {
        i_remove_from_start_of_list(&(stack->head));
        return 1;
    }
}