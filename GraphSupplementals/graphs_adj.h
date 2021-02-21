#include <stdio.h>
#include "int_linked.h"

typedef struct adj_list{    
    int id;    
    i_node *connections;    
    struct adj_list *next;
} adj_list;

void display_adj(adj_list *list);
int search_adj(adj_list *graph, int element);
void add_new_vertex_adj(adj_list **list, int element);
void add_edge_directed_adj(adj_list *graph, int from, int to);
void add_edge_undirected_adj(adj_list *graph, int first, int second);
void remove_edge_directed_adj(adj_list *graph, int from, int to);
void remove_edge_undirected_adj(adj_list *graph, int first, int second);
void remove_vertex_adj(adj_list **graph, int vertex);
void remove_from_start_of_list_adj(adj_list **head_ptr);
void remove_from_list_at_index_adj(adj_list **head_ptr, int index_to_remove_from);
