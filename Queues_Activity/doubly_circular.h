#include <stdio.h>
#include <stdlib.h>

typedef struct person{
	int id;
	int arrival_time;
	int time_in_server;
}person;
typedef struct doubly_circular {
	person element;
	struct doubly_circular *next;
	struct doubly_circular *prev;
}doubly_circular;

void double_circ_display(doubly_circular *head);

void double_circ_add_to_empty_list(doubly_circular **head_ptr, person element);
void double_circ_add_to_start(doubly_circular **head_ptr, person element);
void double_circ_add_at_index(doubly_circular **head_ptr, person element, int index);
void double_circ_add_to_end(doubly_circular **head_ptr, person element);

void double_circ_remove_from_start(doubly_circular **head_ptr);
void double_circ_remove_from_index(doubly_circular **head_ptr, int index);
void double_circ_remove_from_end(doubly_circular **head_ptr);

int list_length(doubly_circular *head_ptr);