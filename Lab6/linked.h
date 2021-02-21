#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

void add_to_start_of_list(node **head_ptr, int data_to_add);
void remove_from_start_of_list(node **head_ptr);
void display_list(node *head);