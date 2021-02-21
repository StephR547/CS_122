#include "tree.h"
#include <string.h>

void story(tree *my_tree){
    tree *current = my_tree;
    int user_choice;
    if(current->element == 1){
       FILE *file;
       char string;
       file = fopen("1.txt", "r");
       printf("\n");
       while((string = fgetc(file))!= EOF){
           printf("%c", string);
       }
       scanf("%d", &user_choice);
       if(user_choice == 0){
           current = go_right(current);
       }else if(user_choice == 1){
           current = go_left(current);
       }
    }
     if(current->element == 2){
       FILE *file;
       char string;
       file = fopen("2.txt", "r");
       printf("\n");
       while((string = fgetc(file))!= EOF){
           printf("%c", string);
       }
       scanf("%d", &user_choice);
       if(user_choice == 0){
           current = go_left(current);
       }else if(user_choice == 1){
           current = go_right(current);
       }
    }
     if(current->element == 3){
       FILE *file;
       char string;
       file = fopen("3.txt", "r");
       printf("\n");
       while((string = fgetc(file))!= EOF){
           printf("%c", string);
       }
       scanf("%d", &user_choice);
       if(user_choice == 0){
           current = go_left(current);
       }else if(user_choice == 1){
           current = go_right(current);
       }
    }
     if(current->element == 4){
       FILE *file;
       char string;
       file = fopen("4.txt", "r");
       printf("\n");
       while((string = fgetc(file))!= EOF){
           printf("%c", string);
       }
       scanf("%d", &user_choice);
       if(user_choice == 0){
           current = go_left(current);
       }else if(user_choice == 1){
           current = go_right(current);
       }
    }
     if(current->element == 5){
       FILE *file;
       char string;
       file = fopen("5.txt", "r");
       printf("\n");
       while((string = fgetc(file))!= EOF){
           printf("%c", string);
       }
       scanf("%d", &user_choice);
       if(user_choice == 0){
           current = go_left(current);
       }else if(user_choice == 1){
           current = go_right(current);
       }
    }
     if(current->element == 6){
       FILE *file;
       char string;
       file = fopen("6.txt", "r");
       printf("\n");
       while((string = fgetc(file))!= EOF){
           printf("%c", string);
       }
       scanf("%d", &user_choice);

       if(user_choice == 0){
           current = go_left(current);
       }else if(user_choice == 1){
           current = go_right(current);
       }
    }
    if(current->element == 7){
       FILE *file;
       char string;
       file = fopen("7.txt", "r");
       printf("\n");
       while((string = fgetc(file))!= EOF){
           printf("%c", string);
       }
       scanf("%d", &user_choice);
       if(user_choice == 0){
           current = go_left(current);
       }else if(user_choice == 1){
           current = go_right(current);
       }
    }
    if(user_choice == 4){
        return;
    }
    story(current);
}

int main(){
    tree *story_tree = NULL;
    tree *current = NULL;
    FILE *config = fopen("config.txt","r");
    for(int i = 0; i < 9; i++){
        char command[20];
        int element;
        fscanf(config, "%s", command);
        fscanf(config, "%d", &element);

        if(strcmp(command, "MAKE_ROOT") == 0){
            create_root(&story_tree, element);
            current = story_tree;
        }else if(strcmp(command, "ADD_LEFT") == 0){
            set_left(current, element);
        }else if(strcmp(command, "ADD_RIGHT") == 0){
            set_right(current, element);
        }else if(strcmp(command, "GO_UP") == 0){
            current = go_up(current);
        }else if(strcmp(command, "GO_LEFT") == 0){
            current = go_left(current);
        }else if(strcmp(command, "GO_RIGHT") == 0){
            current = go_right(current);
        }
    }
    fclose(config);
    story(story_tree);
}