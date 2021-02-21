#include "Queue.h"
#include <time.h>

int main(){
 /*srand(time(NULL));
 int time = 0;
 time++;
 linked_queue input;
 linked_queue_initialize(&input);
 for(int i = 0; i < 8; i++){
    linked_queue_enqueue(&input, i);
    input.list->server_time = time;
 }
 linked_queue_display(input);*/
 int time =0;
 doubly_circular *wait_list = NULL;
 linked_queue server;
 linked_queue_initialize(&server);
 doubly_circular *server_head = NULL;
 doubly_circular *wait_list_head;
 for(int i = 0; i < 10; i++){
     add_to_end(&wait_list, i);
 }
 do{
    wait_list_head = wait_list;
    server_head = server.list;
    if(server_head == NULL){
        for(int i = 0; i < 3; i++){
            linked_queue_enqueue(&server,wait_list_head->id);
            printf(" User id: %d has arrived \n", wait_list_head->id);
            remove_from_start(&wait_list);
            wait_list_head = wait_list;
            server.list->arrival_time = time;
            server.list->server_time = time - server.list->arrival_time;
            server_head = server.list;
        }
    } 
    server.list->server_time = time - server.list->arrival_time;
    server.list->next->server_time = time - server.list->next->arrival_time;
    server.list->prev->server_time = time - server.list->prev->arrival_time;
     if(server.list->server_time == 3){
        printf("Id: %d, time: %d looks like times up, Move it or loose it! \n", server.list->id, server.list->server_time);
        linked_queue_dequeue(&server);
        if(wait_list_head != NULL){
            linked_queue_enqueue(&server,wait_list_head->id);
            printf(" User id: %d has arrived \n", wait_list_head->id);
            remove_from_start(&wait_list);
            wait_list_head = wait_list;
            
        }
        server.list->arrival_time = time;
        //server.list->server_time = time - server.list->arrival_time;
        //server_head = server.list;
     }
     //printf("kjsdb\n");
     time++;
    //display(wait_list); 
    //linked_queue_display(server);
     //if(server.list == NULL){
        //printf("The end\n");
     //}
     
 }while(server_head != NULL);
}