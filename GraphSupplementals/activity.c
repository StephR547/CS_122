#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct matrix{
    int number_of_vert;
    int **element;
}matrix;

void init_matrix(matrix *graph, int number_of_vert){
    graph->number_of_vert = number_of_vert;
    graph->element = malloc(sizeof(int *) * number_of_vert);
    for(int i = 0; i < number_of_vert; i++) {
        graph->element[i] = calloc(sizeof(int) * number_of_vert, sizeof(int));
    }
}

void display_matrix(matrix graph){
    printf("Displaying a graph:\n");
     for (int i = 0; i < graph.number_of_vert; i++){        
        printf("  %2d", i);    
    }    
    printf("\n");    
    for (int i = 0; i < graph.number_of_vert; i++){        
        printf("%2d ", i);        
        for (int j = 0; j < graph.number_of_vert; j++){            
            printf("%2d ", graph.element[i][j]);        
        }        
    printf("\n");  
    }
    printf("DONE\n");  
}

void add_directed_edge_matrix(matrix graph, int from, int to){
    if (from < 0 || from >= graph.number_of_vert     || to < 0 || to >= graph.number_of_vert) {
        printf("Invalid index, edge not added\n");
    }else if(graph.element[from][to] != 0){
        printf("Edge already exists\n");
    }else{
        graph.element[from][to] = 1;
    }
}

void remove_directed_edge_matrix(matrix graph, int from, int to){
    if (from < 0 || from >= graph.number_of_vert     || to < 0 || to >= graph.number_of_vert){
     printf("Invalid index, edge not added\n");
    }else if(graph.element[from][to] == 0){ 
        printf("Edge does not exist\n"); 
    }else{
        graph.element[from][to] = 0;
    }
}

int main(){
struct matrix graph;
init_matrix(&graph, 3);
char command[100];
do{
    printf("Please Enter Command:");
    scanf("%s", command);
    if(strcmp(command, "DISPLAY") == 0){
        display_matrix(graph);
    }else if(strcmp(command, "REMOVE_EDGE") == 0){
        int from, to;
        scanf("%d %d", &from, &to);
        remove_directed_edge_matrix(graph, from, to);
    }else if(strcmp(command, "ADD_EDGE") == 0){
        int from, to;
        scanf("%d %d", &from, &to);
        add_directed_edge_matrix(graph, from, to);
    }
}while(strcmp(command, "EXIT") != 0);
   
}