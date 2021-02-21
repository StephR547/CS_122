#include "graphs_adj.h"

void display_adj(adj_list *list){    
    if (list == NULL){        
        printf("Empty graph\n");    
    }else{        
        adj_list *current = list;        
        while (current != NULL){            
            printf("Vertex ID: %d\n", current->id);            
            if (current->connections == NULL){                
                printf("No connections\n");            
            }else{                
                printf("Connections: ");                
                i_node *con_current = current->connections;                
                while (con_current != NULL){                    
                    printf("{ %d } ", con_current->data);                    
                    con_current = con_current->next;                
                    }                
                    printf("\n");            
            }            
                current = current->next;        
        }    
    }
}

int search_adj(adj_list *graph, int element){     
    adj_list *current = graph;    
    int found = -1;    
    int count = 0;    
    while(current != NULL){        
        if (current->id == element){            
            found = count;        
        }        
        current = current->next;        
        count++;    
    }    
    return found;
}

void add_new_vertex_adj(adj_list **list, int element){    
    if (search_adj(*list,element) != -1){        
        printf("Cannot add a duplicate element\n");    
    }else{              
        adj_list *new_node = malloc(sizeof(adj_list));        
        new_node->id = element;        
        new_node->connections = NULL;        
        new_node->next = *list;        
        *list = new_node;    
    }   
}

void add_edge_directed_adj(adj_list *graph, int from, int to){    
    if (search_adj(graph, from) == -1 || search_adj(graph, to) == -1){        
        printf("Invalid vertices, operation not performed\n");    
    }else{        
        adj_list *current = graph;        
        while (current->id != from){            
            current = current->next;        
        }        
        if (i_list_contains(current->connections,to)==1){            
            printf("Edge already exists, operation not performed\n");        
        }else{            
            i_add_to_start_of_list(&(current->connections), to);        
        }    
    }
}

void add_edge_undirected_adj(adj_list *graph, int first, int second){    
    add_edge_directed_adj(graph, first, second);    
    add_edge_directed_adj(graph, second, first);
}

void remove_edge_directed_adj(adj_list *graph, int from, int to){     
    if (search_adj(graph, from) == -1 || search_adj(graph, to) == -1){        
        printf("Invalid vertices, operation not performed\n");    
    }else{         
        adj_list *current = graph;        
        while (current->id != from){            
            current = current->next;        
        }        
        if (i_list_contains(current->connections,to)==0){            
            printf("Edge doesn't exist, operation not performed\n");        
        }else{            
            int count = 0;            
            i_node *inner = current->connections;            
            while (inner->data != to){                
                count++;                
                inner = inner->next;            
            }            
            i_remove_from_list_at_index(&(current->connections), count);        
        }    
    }
}

void remove_edge_undirected_adj(adj_list *graph, int first, int second){    
    remove_edge_directed_adj(graph, first, second);    
    remove_edge_directed_adj(graph, second, first);
}

void remove_vertex_adj(adj_list **graph, int vertex){    
    if (search_adj(*graph, vertex) == -1){        
        printf("Vertex doesn't exist, operation not performed.\n");    
    }else{        
        adj_list *current = *graph;        
        int count = 0;        
        while (current->id != vertex){            
            current = current->next;            
            count++;        
        }        
        while(current->connections != NULL){            
            i_remove_from_start_of_list(&(current->connections));        
        }        
        remove_from_list_at_index_adj(graph, count);        
        current = *graph;        
        while (current != NULL){            
            i_node *con_current = current->connections;            
            count = 0;            
            while (con_current != NULL){                
                if (con_current->data == vertex){                    
                    i_remove_from_list_at_index(&(current->connections), count);                
                }                
                count++;                
                con_current = con_current->next;            
            }            
            current = current->next;        
        }    
    }
}

void remove_from_start_of_list_adj(adj_list **head_ptr){    
    if (*head_ptr == NULL) {
        printf("Nothing to remove\n");    
    }else{        
        adj_list *removed_node_ptr = (*head_ptr);        
        *head_ptr = (*head_ptr)->next;        
        free(removed_node_ptr);    
    }
}

void remove_from_list_at_index_adj(adj_list **head_ptr, int index_to_remove_from){    
    if (index_to_remove_from == 0){        
        remove_from_start_of_list_adj(head_ptr);    
    }else{           
        int current_index = 0;           
        adj_list *current_node_ptr = *head_ptr;           
        while (current_index < (index_to_remove_from - 1)){           
            if (current_node_ptr != NULL){                
                current_node_ptr = current_node_ptr->next;           
            }else{                
                printf("Index is invalid, removal not performed\n");                
                return;              
            }            
            current_index++;         
        }        
        adj_list *removed_node_ptr = current_node_ptr->next;        
        current_node_ptr->next = removed_node_ptr->next;        
        free(removed_node_ptr);    
    }
}