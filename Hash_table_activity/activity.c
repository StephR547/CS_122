#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long int hash(char *str, int size_of_table){
    unsigned long int hash = 5381;
    int c = str[0];
    int index = 0;
    while(c != 0){
        hash = ((hash << 5) + hash) + c;
        index++; 
        c = str[index];
    }
    return hash % size_of_table;
}
typedef struct element_node{    
    int key;    
    int value;    
    struct element_node *next;
}element_node;

typedef struct hash_table{    
    element_node **elements;    
    int size;
}hash_table;

void initialize(hash_table *table_ptr, int size){    
    table_ptr->size = size;    
    table_ptr->elements = malloc(sizeof(element_node) * size);    
    for (int i = 0; i < size; i++){        
        table_ptr->elements[i] = NULL;    
    }
}
void display_keys_and_values(hash_table table){ 
    int diff_word_count = 0;   
    for (int i = 0; i < table.size; i++){        
        if (table.elements[i] != NULL){            
            element_node *current = table.elements[i];            
            while (current != NULL){                
                printf("%s has occured %d times\n", current->key, current->value);                
                current = current->next;   
                diff_word_count++;         
            }        
        }    
    }
    printf("There are %d different words\n", diff_word_count);
}

void increment(hash_table table, char*string){
    int hash_index = hash(string, table.size);
    element_node *current = table.elements[hash_index];
    while(current != NULL && strcasecmp(string, current->key) != 0){
        current = current->next;
    }
    if(current == NULL){
        element_node *new = malloc(sizeof(element_node));
        int size_of_string = strlen(string) + 1;
        new->key = malloc(sizeof(size_of_string));
        strcpy(new->key, string);
        new->value = 1;
        new->next = table.elements[hash_index];
    }else{
        current->value = current->value + 1;
    }   
}

int main(){
    hash_table wuthering_heights;
    initialize(&wuthering_heights, 750000);
    FILE *book = fopen("book.txt", "r");
    while(!feof(book)){
        char word[100];
        fscanf(book, "%s", word);
        increment(wuthering_heights, word);
    }
    display_keys_and_values(wuthering_heights);
}