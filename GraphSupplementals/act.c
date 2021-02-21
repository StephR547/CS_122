#include "int_linked.h"
#include "graphs_adj.h"
#include <string.h>
#include <stdlib.h>

int main(){
    adj_list *list = NULL;
    char command[100];
    do{
        printf("Please Enter Command:");
        scanf("%s", command);
        if(strcmp(command, "ADD_VERTEX") == 0){
            int id;
            scanf("%d", &id);
            add_new_vertex_adj(&list, id);
        }else if(strcmp(command, "DISPLAY") == 0){
            display_adj(list);
        }else if(strcmp(command, "ADD_EDGE") == 0){
            int from, to;
            scanf("%d %d", &from, &to);
            add_edge_directed_adj(list, from, to);
        }else if(strcmp(command, "REMOVE_EDGE") == 0){
            int from, to;
            scanf("%d %d", &from, &to);
            remove_edge_directed_adj(list, from, to);
        }
    
    }while(strcmp(command, "EXIT") != 0);
}