#include <stdio.h>
#include "int_linked.h"
#include "doubly_circular.h"
#define CCYN  "\x1B[36m"
#define CRED  "\x1B[31m"
#define CNRM  "\x1B[0m"
//Count Down Function
int count_down(int number){
    if (number == 0){
        printf("%d\n", number);
        return number;
    }
    else {
        printf("%d\n", number);
        count_down(number - 1);
    }
    return number;
}
//GCD Function
int gcd(int num_1, int num_2) {
    if(num_2 != 0){
        return gcd(num_2, (num_1 % num_2));
    }else{
        return num_1;
    }
}
//Sum Till Zero Function
void sum_till_zero(int sum){
    int input;
    printf("Please Enter A Number:"); 
    scanf("%d", &input);
    if(input != 0){
        sum = sum + input;
        sum_till_zero(sum);
    }else if(input == 0){
        printf("The Sum is: %d\n", sum);
        return;
    }
}
void sum_tail(){
   int input;
    printf("Please Enter A Number:"); 
    scanf("%d", &input);
    sum_till_zero(input);
}
//Fibonacci Sequence
void fibonnacci(int user_pick, int current_n, int n1_place, int n2_place, int nth_term){
    if(current_n == 0){
        n1_place = 0;
        n2_place = 0;
    }
    if(current_n == 1){
        n1_place = 1;
        n2_place = 0;
    } 
    if(current_n == user_pick){
        printf("%d\n", nth_term);
        return;
    }
    nth_term = n1_place + n2_place;
    n2_place = n1_place;
    n1_place = nth_term;
    current_n++;
    fibonnacci(user_pick, current_n, n1_place, n2_place, nth_term);
   
}
void fibonnacci_tail(){
    int choice;
    printf("Please Enter The Term You Would Like To See: ");
    scanf("%d", &choice);
    fibonnacci(choice, 0, 0, 0, 0);
}
//Star Triangle
void star_triangle(int width){ 
    if(width == 0){
            return;
        }  
        for(int i = 0; i < width; i++){
            printf("*");
        }
        printf("\n");
        star_triangle(width-1);
       
} 
void star_tail(){
    int width_choice;
    printf("Please Enter a Size:");
    scanf("%d", &width_choice);
    star_triangle(width_choice);
}
//Largest and Smallest
void max_min_num(node *head, int max, int min){
    if(max < head->data){
        max = head->data;
    }
    if(min > head->data){
        min = head->data;
    }
    head = head->next;

    if(head == NULL){
        printf("Max Number: %d\n", max);
        printf("Min Number: %d\n", min);
        return;
    }
    max_min_num(head, max, min);
}
void max_min_tail(node *list){
    node *head = list;
    display_list(list);
    max_min_num(head, 0, 100);

}
//List Copy
void list_copy(doubly_circular *copy_list, doubly_circular *orginal_list, doubly_circular *ptr_list){
    double_circ_add_to_end(&copy_list, ptr_list->element);
    ptr_list = ptr_list->next;
    if(orginal_list == ptr_list){
        printf("COPY: ");
        double_circ_display(copy_list);
        return;
    }
    list_copy(copy_list, orginal_list, ptr_list);
}
void copy_tail(doubly_circular **orginal_list){
    doubly_circular *head_ptr = *orginal_list;
    doubly_circular *copy_list = NULL;
    printf("ORGINAL: ");
    double_circ_display(*orginal_list);
    printf("\n");
    list_copy(copy_list, *orginal_list, head_ptr);
}
    
int main(){
    int user_choice;
   
    while(user_choice != 0){
        printf("What Operation Would You Like To Do\n");
        printf("\t1: Count Down\n\t2: Greatest Common Divsor\n\t3: Sum Till Zero\n\t4: Fibonacci Sequence\n\t5: Star Triangle\n\t6: Largest and Smallest\n\t7: List Copy\n");
        printf("Enter A Number:");
        scanf("%d", &user_choice);
        if(user_choice == 1){
            printf("\t%sSTARTING COUNT DOWN OPERATION\n", CCYN);
            printf("%s", CNRM);
            int cd_number_input;
            printf("Enter Starting Number: ");
            scanf("%d", &cd_number_input);
            count_down(cd_number_input);
        }else if(user_choice == 2){
            printf("\t%sSTARTING GCD OPERATION\n", CCYN);
            printf("%s", CNRM);
            int gcd_num1_input;
            int gcd_num2_input;
            printf("Please Enter Two Numbers:\n");
            scanf("%d", &gcd_num1_input);
            scanf("%d", &gcd_num2_input);
            int gcd_results = gcd(gcd_num1_input, gcd_num2_input);
            printf("The GCD of %d and %d is: %d\n",gcd_num1_input, gcd_num2_input, gcd_results);
        }else if(user_choice == 3){
            printf("\t%sSTARTING SUM TILL ZERO OPERATION\n", CCYN);
            printf("%s", CNRM);
            sum_tail();
        }else if(user_choice == 4){
            printf("\t%sSTARTING FIBONACCI SEQUENCE OPERATION\n", CCYN);
            printf("%s", CNRM);
            fibonnacci_tail();
        }else if(user_choice == 5){
            printf("\t%sSTARTING STAR TRIANGLE OPERATION\n", CCYN);
            printf("%s", CNRM);
            star_tail();
        }else if(user_choice == 6){
            printf("\t%sSTARTING LARGEST AND SMALLEST OPERATION\n", CCYN);
            printf("%s", CNRM);
            node *my_list = NULL;
            add_to_start_of_list(&my_list, 3);
            add_to_start_of_list(&my_list, 5);
            add_to_start_of_list(&my_list, 1);
            add_to_start_of_list(&my_list, 7);
            add_to_start_of_list(&my_list, 8);
            add_to_start_of_list(&my_list, 12);
            add_to_start_of_list(&my_list, 5);
            add_to_start_of_list(&my_list, 6);
            max_min_tail(my_list);
        }else if(user_choice == 7){
            printf("\t%sSTARTING LIST COPY OPERATION\n", CCYN);
            printf("%s", CNRM);
            doubly_circular *list = NULL;
            double_circ_add_to_end(&list, 3);
            double_circ_add_to_end(&list, 6);
            double_circ_add_to_end(&list, 9);
            double_circ_add_to_end(&list, 10);
            double_circ_add_to_end(&list, 12);
            double_circ_add_to_end(&list, 2);
            copy_tail(&list);
        }
        printf("%sEnter 0 If You Would Like To Exist\n", CRED);
        printf("%s", CNRM);
    }
    printf("EXITING...\n");
} 