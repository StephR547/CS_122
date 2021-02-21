#include <stdio.h>
void looping_and_recursion(){
    int input;
    do{
        printf("Please Enter A Value Between 0 And 10\n"); 
        scanf("%d", &input);
    }while(input < 0 || input > 10);
    printf("You Entered: %d\n", input);
    if(input != 0){
        printf("Enter 0 To Stop\n");
        looping_and_recursion();
    }else{
        return;
    }
}

int sum_array_no_tail(int array[], int size, int current){
    if(current == size){
        return 0;
    }
    return array[current] + sum_array_no_tail(array, size, current + 1);

}

int sum_array_tail(int array[], int size, int current, int result){
    if(current == size){
        return result;
    }else{
        return sum_array_tail(array, size, current + 1, result + array[current]);
    }
}
int main(){
    const int size = 5;
    int array[size] = {3, 10, 20, 4, 5};
    int result = sum_array_no_tail(array, size, 0);
    printf("The Result: %d\n", result);
    int result2 = sum_array_tail(array, size, 0, 0);
    printf("New Result: %d\n", result2);
}