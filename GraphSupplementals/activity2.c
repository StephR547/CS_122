#include "int_linked.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct adj_node{    
    int id;       
    i_node *connections;        
    struct adj_node *next;
}adj_node;

void display_adj(adj_node *list){    
    if (list == NULL){        
        printf("Empty graph\n");    
    }else{        
        adj_node *current = list;        
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
int search(adj_node *graph, int element){     
    adj_node *current = graph;    
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
void add_new_vertex(adj_node **list, int element){    
    if (search(*list,element) != -1){        
        printf("Cannot add a duplicate element\n");    
    }else{              
        adj_node *new_node = malloc(sizeof(adj_node));        
        new_node->id = element;        
        new_node->connections = NULL;        
        new_node->next = *list;        
        *list = new_node;    
    }   
}

void add_edge_directed(adj_node *graph, int from, int to){    
    if (search(graph, from) == -1 || search(graph, to) == -1){        
        printf("Invalid vertices, operation not performed\n");    
    }else{        
        adj_node *current = graph;        
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

void remove_edge_directed(adj_node *graph, int from, int to){     
    if (search(graph, from) == -1 || search(graph, to) == -1){        
        printf("Invalid vertices, operation not performed\n");    
    }else{         
        adj_node *current = graph;        
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

int main(){
    adj_node *list = NULL;
    char command[100];
    do{
        printf("Please Enter Command:");
        scanf("%s", command);
        if(strcmp(command, "ADD_VERTEX") == 0){
            int id;
            scanf("%d", &id);
            add_new_vertex(&list, id);
        }else if(strcmp(command, "DISPLAY") == 0){
            display_adj(list);
        }else if(strcmp(command, "ADD_EDGE") == 0){
            int from, to;
            scanf("%d %d", &from, &to);
            add_edge_directed(list, from, to);
        }else if(strcmp(command, "REMOVE_EDGE") == 0){
            int from, to;
            scanf("%d %d", &from, &to);
            remove_edge_directed(list, from, to);
        }
    
    }while(strcmp(command, "EXIT") != 0);
}