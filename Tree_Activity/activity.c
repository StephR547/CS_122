#include "tree.h"
#include <string.h>

int main(){
    struct tree *my_tree = NULL;
    struct tree *current = NULL;
    char command[20];
    do{
        printf("Please Enter Command:");
        scanf("%s",command);
        if(strcmp("MAKE", command) == 0){
            int element;
            scanf("%d", &element);
            create_root(&my_tree, element);
            current = my_tree;
        }else if(strcmp(command, "PREORDER") ==0 ){
            preorder(my_tree);
        }else if(strcmp(command, "INORDER") ==0 ){
            inorder(my_tree);
        }else if (strcmp(command, "POSTORDER") ==0 ){
            postorder(my_tree);
        }else if(strcmp(command, "ADD") ==0 ){
            scanf("%s", command);
            int element;
            scanf("%d", &element);
            if(strcmp(command, "LEFT") ==0 ){
                set_left(current, element);
            }else if(strcmp(command, "RIGHT") ==0 ){
                set_right(current, element);
            }
        }else if(strcmp(command, "GO") ==0 ){
            scanf("%s",command);
            if(strcmp(command, "UP") ==0 ){
                current = go_up(current);
            }else if(strcmp(command, "LEFT") ==0 ){
                current = go_left(current);
            }else if(strcmp(command, "RIGHT") ==0 ){
                current = go_right(current);
            }
        }else if(strcmp(command, "PRINT") ==0 ){
            if(current != NULL){
                printf("%d\n", current->element);
            }
        }
    }while(strcmp(command, "EXIT") != 0);
    
    // DELETE
    
}