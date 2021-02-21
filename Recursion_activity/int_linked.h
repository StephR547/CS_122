#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int data;
  struct node *next;
}node;

int list_contains(node *head, int element);

void add_to_start_of_list(node **head_ptr, int data_to_add);
void add_to_list_at_index(node **head_ptr, int data_to_add, int index_to_add_at);
void add_to_end_of_list(node **head_ptr, int data_to_add);

void remove_from_start_of_list(node **head_ptr);
void remove_from_list_at_index(node **head_ptr, int index_to_remove_from);
void remove_from_end_of_list(node **head_ptr);

void display_list(node *head);