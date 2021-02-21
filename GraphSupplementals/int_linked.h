#if !defined(FERRE)
#define FERRE





#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct i_node {
  int data;
  struct i_node *next;
} i_node;

int i_list_contains(i_node *head, int element);

void i_add_to_start_of_list(i_node **head_ptr, int data_to_add);
void i_add_to_list_at_index(i_node **head_ptr, int data_to_add, int index_to_add_at);
void i_add_to_end_of_list(i_node **head_ptr, int data_to_add);

void i_remove_from_start_of_list(i_node **head_ptr);
void i_remove_from_list_at_index(i_node **head_ptr, int index_to_remove_from);
void i_remove_from_end_of_list(i_node **head_ptr);

void i_display_list(i_node *head);

#endif // MACRO