#include "doubly_circular.h"
#include "linked.h"
#include <time.h>
#include <string.h>

int main(){
    srand(time(NULL)); 
    int user_pick;
    int num_of_players;
    int num_of_players_killed;
    char name_input[14];
    circular *my_players = NULL;
//Player Set Up:
    printf("Please Enter The Number Of Players: ");
    scanf("%d",&num_of_players);
    
    for(int i = 1; i < (num_of_players+1); i++){
        printf("Please Enter The Name Of Player %d: ", i);
        scanf("%s", name_input);
        insert_at_end(&my_players, name_input);
    }
    printf("\tThe Players Are:\n");
    display(my_players);

    circular *current_player = NULL;
    current_player = my_players; 
    
//Game
     while(num_of_players != 1){
        num_of_players_killed = 0;
        int spots = (num_of_players * 3);  
        doubly_circular *game_list = NULL;
        int baguette = (rand()%(spots - 1 + 1) + 1);
        for(int i = 0; i < spots; i++){
            if(i == baguette){
                double_circ_add_to_start(&game_list, 1);
            }else{
                double_circ_add_to_start(&game_list, 0);
            }
        }
        printf("LET THE GAMES BEGIN!!\n");
        printf("The current player is %s\n", current_player->name);
        doubly_circular *posion_list_front = NULL;
        doubly_circular *posion_list_back = NULL;
        posion_list_front = game_list;
        posion_list_back = game_list;
        posion_list_back = posion_list_back->prev;
        char name_arr[10];

         do{
            printf("Please Enter One Of The Following Options:\n");
            printf("\t0: Bite off the FRONT\n");
            printf("\t1: Bite off the BACK\n");
            printf("Enter Your Choice As A Number: ");
            scanf("%d",&user_pick);
            fflush(stdin);

            if(user_pick == 0){
                printf("\t%s Took A BITE From The FRONT\n", current_player->name);
                if(posion_list_front->element == 1){
                (strcpy(name_arr, current_player->name));
                current_player = current_player->next;
                printf("%s...IS POSIONED\n", name_arr);
                delete_by_name(&my_players, name_arr);
                num_of_players--; 
                num_of_players_killed++;   
            }else{
                printf("%s...IS SAFE\n", current_player->name);
                printf("\t%s Is Passing The Baguette to %s \n", current_player->name, current_player->next->name);
                current_player = current_player->next;
                printf("The current player is %s\n", current_player->name);
            }
                double_circ_remove_from_start(&game_list);
                posion_list_front = game_list;                
            }else if(user_pick == 1){
                printf("\t%s Took A BITE From The BACK\n", current_player->name);
                if(posion_list_back->element == 1){
                (strcpy(name_arr, current_player->name));
                current_player = current_player->next;
                printf("%s...IS POSIONED\n", name_arr);
                delete_by_name(&my_players, name_arr);
                num_of_players--; 
                num_of_players_killed++;   
            }else{
                printf("%s...IS SAFE\n", current_player->name);
                printf("\t%s Is Passing The Baguette to %s \n", current_player->name, current_player->next->name);
                current_player = current_player->next;
                printf("The current player is %s\n", current_player->name);
            }
                double_circ_remove_from_end(&game_list);
                posion_list_back = game_list;
                posion_list_back = posion_list_back->prev;
            }else{
                printf("INVALD OPTION\n");
            }  
        }while(num_of_players_killed == 0);
     }
     printf("And The WINNER is...%s!\nLuck Was On Your Side Today.\n", current_player->name);
}