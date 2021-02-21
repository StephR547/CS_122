#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct frequencies{
    char **words;
    int *frequencies;
    int current_size;
}frequencies;

void init(frequencies book, int num_of_words){
    book.words = malloc(sizeof(char*) * num_of_words);
    book.frequencies = malloc(sizeof(int) * num_of_words);
    book.current_size = 0;
}

void display_all(frequencies book){
    for(int i = 0; i < book.current_size; i++){
        printf("%s has occured %d times", book.words[i], book.frequencies[i]);
    }
    printf("There are %d different words in book", book.current_size);
}

void increment(frequencies *book, char *word){
    int index = 0;
    for(int i = 0; i < book->current_size; i++){
        if(strcasecmp(word, book->words[i]) == 0){
            book->frequencies[i] = book->frequencies[i] + 1;
            return;
        }
    }
    int length = strlen(word) + 1;
    book->words[book->current_size] = malloc(length * sizeof(char));
    book->frequencies[book->current_size] = 1;
    book->current_size = book->current_size + 1;
}

int main(){
    frequencies wuthering_heights;
    init(wuthering_heights, 750000);
    FILE *book = fopen("book.txt", "r");
    while(!feof(book)){
        char word[100];
        fscanf(book, "%s", word);
        increment(&wuthering_heights, word);
    }
    display_all(wuthering_heights);
}
