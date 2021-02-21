#include "stacked.h"
#include <time.h>

void swap(int array[], int i, int j) {
	int temp_holder = array[i];
	array[i] = array[j];
	array[j] = temp_holder;
}

void shuffle(int array[], int size){
	for (int i = size - 1; i >= 1; i--){
		int j = (rand() % (((i) - 0) + 1) + 0);
		swap(array, i, j);
	}
}

int player_one_turn(linked_stack *player_one_deck, node **p1_discard_pile){
 node *pick = NULL;
 node *player_one_head = player_one_deck->head;
 node *discard = NULL;
 node *card_pointer;
 int discard_pile_count = 0;
 int user_one;
 int card_count = 0;

 printf("Player 1's Turn\n");
 printf("Player 1 drew cards...\n");
 printf("\tPlayer 1's Hand:\n");
 for(int c = 1; ((c < 4) && (player_one_head != NULL)); c++){
    singly_add_to_start_of_list(&pick, player_one_head->data);
    printf("\t%d) %d \n", c, player_one_head->data);
    player_one_head = player_one_head->next;
    card_count++;
    }
 player_one_head = NULL;
 player_one_head = pick;
 card_pointer = pick;
 printf("Player 1 Pick A Card:");
 scanf("%d", &user_one);
 for(int i = card_count; i != user_one; i--){
    player_one_head = player_one_head->next;
 }
 printf("Player 1 Played a # %d \n", player_one_head->data);
 printf("Discarding other cards...\n");
 printf("Discard Pile: ");
 for(int d = 0; d < card_count; d++){
   if(card_pointer->data == player_one_head->data){
      card_pointer = card_pointer->next;
   }else if(pick->data != player_one_head->data){
      singly_add_to_start_of_list(&discard, card_pointer->data);
      card_pointer = card_pointer->next;
      discard_pile_count++;
   } 
 }
 node *discard_ptr = discard;
 for(int a = 0; a < discard_pile_count; a++){
    singly_add_to_start_of_list(p1_discard_pile,discard_ptr->data);
    discard_ptr = discard_ptr->next;
 }
 for(int p =0; p < 3; p++){
    stack_linked_pop(player_one_deck);
 }
 singly_display_list(*p1_discard_pile);
 return player_one_head->data;
}

int player_two_turn(linked_stack *player_two_deck, node **p2_discard_pile){
 node *pick = NULL;
 node *player_two_head = player_two_deck->head;
 node *discard_two = NULL;
 node *card_pointer_two;
 int discard_pile_count = 0;
 int user_two;
 int card_count = 0;

  printf("Player 2's Turn\n");
  printf("Player 2 drew cards...\n");
  printf("\tPlayer 2's Hand:\n");
 for(int c = 1; ((c < 4) && (player_two_head != NULL)); c++){
    singly_add_to_start_of_list(&pick, player_two_head->data);
    printf("\t%d) %d \n", c, player_two_head->data);
    player_two_head=player_two_head->next;
    card_count++;
    }
 player_two_head = NULL;
 player_two_head = pick;
 card_pointer_two = pick;
 printf("Player 2 Pick A Card:");
 scanf("%d", &user_two);
 for(int i = card_count; i != user_two; i--){
    player_two_head = player_two_head->next;
 }
 printf("Player 2 Played a # %d \n", player_two_head->data);
 printf("Discarding other cards...\n");
 printf("Discard Pile: ");
 for(int d = 0; d < card_count; d++){
   if(card_pointer_two->data == player_two_head->data){
      card_pointer_two = card_pointer_two->next;
   }else if(pick->data != player_two_head->data){
      singly_add_to_start_of_list(&discard_two, card_pointer_two->data);
      card_pointer_two = card_pointer_two->next;
      discard_pile_count++;
   } 
 }
 node *discard_ptr = discard_two;
 for(int a = 0; a < discard_pile_count; a++){
    singly_add_to_start_of_list(p2_discard_pile,discard_ptr->data);
    discard_ptr = discard_ptr->next;
 }
 for(int p = 0; p < 3; p++){
    stack_linked_pop(player_two_deck);
 }
 singly_display_list(*p2_discard_pile);
 return player_two_head->data;
}

int main(){
    int card = 0;
    int deck_of_cards[52];
    srand(time(NULL));

    while(card != 52){
        for(int i = 2; i < 15; i++){
            deck_of_cards[card] = i;
            card++;
        } 
    }
    shuffle(deck_of_cards, card);
    printf("Shuffling...\n");
    for(int s = 0; s != 52; s++){
        printf("%d ", deck_of_cards[s]);
    }
    printf("\n");

    linked_stack player_one_deck;
    stack_linked_initialize(&player_one_deck);
    printf("Player 1 Recieving Cards...\n");
    for(int p1 = 0; p1 < 26; p1++){
        stack_linked_push(&player_one_deck, deck_of_cards[p1]);
    }

    linked_stack player_two_deck;
    stack_linked_initialize(&player_two_deck);
    printf("Player 2 Recieving Cards...\n");
    for(int p2 = 26; p2 != 52; p2++){
        stack_linked_push(&player_two_deck, deck_of_cards[p2]);
    }

    node *p1_discard_pile = NULL;
    node *p2_discard_pile = NULL;
    node *player_one_cards = NULL;
    node *player_two_cards = NULL;
    int p1_card_in_play;
    int p2_card_in_play;
    int p1_points = 0;
    int p2_points = 0;

    do{
        printf("ROUND STARTING:\n");
        for(int i = 0; i<1; i++){
        p1_card_in_play = player_one_turn(&player_one_deck, &p1_discard_pile);
        p2_card_in_play = player_two_turn(&player_two_deck, &p2_discard_pile);
        if(p1_card_in_play > p2_card_in_play){
            printf("Player 2 used # %d card on Player 1's # %d card\n",p2_card_in_play, p1_card_in_play);
            printf("Player 1 Wins The Round!\n");
            p1_points= (p1_points + 2);
            printf("\tPlayer 1 Has %d Points \n", p1_points);
            printf("\tPlayer 2 Has %d Points \n", p2_points);
       }else if(p2_card_in_play > p1_card_in_play){
            printf("Player 1 used # %d card on Player 2's # %d card\n",p1_card_in_play, p2_card_in_play);
            printf("Player 2 Wins The Round!\n");
            p2_points= (p2_points + 2);
            printf("\tPlayer 1 Has %d Points \n", p1_points);
            printf("\tPlayer 2 Has %d Points \n", p2_points);
      }else if(p1_card_in_play == p2_card_in_play){
            printf("Both Players Cards Where # %d\n",p1_card_in_play);
            printf("You Guys Tied...\n");
            p1_points++;
            p2_points++;
            printf("\tPlayer 1 Has %d Points \n", p1_points);
            printf("\tPlayer 2 Has %d Points \n", p2_points);
      }
        if(player_two_deck.head == NULL){
        int discard_pile_one = 0;
        node *discard_pile_ptr = NULL;
        discard_pile_ptr = p1_discard_pile;  
        while(discard_pile_ptr != NULL){
            discard_pile_one++;
            discard_pile_ptr = discard_pile_ptr->next;
        }
        int p1_discard_array[discard_pile_one];
        discard_pile_ptr = p1_discard_pile;
        for(int i = 0; i < discard_pile_one; i++){
            p1_discard_array[i] = discard_pile_ptr->data;
            discard_pile_ptr = discard_pile_ptr->next;
        }
        printf("RESHUFFLING P1 DECK\n");
        shuffle(p1_discard_array, discard_pile_one);
        for(int i = 0; i < discard_pile_one; i++){
            singly_add_to_start_of_list(&player_one_cards, p1_discard_array[i]);
        }
        player_one_deck.head = player_one_cards;
        p1_discard_pile = NULL;

        int discard_pile_two = 0;
        node *discard_pile_ptr_two = NULL;
        discard_pile_ptr_two = p2_discard_pile;

        while(discard_pile_ptr_two != NULL){
            discard_pile_ptr_two = discard_pile_ptr_two->next;
            discard_pile_two++;
            
        }
        int p2_discard_array[discard_pile_two];
        discard_pile_ptr_two = p2_discard_pile;
        for(int i =0; i < discard_pile_two; i++){
            p2_discard_array[i] = discard_pile_ptr_two->data;
            discard_pile_ptr_two = discard_pile_ptr_two->next;
        }
        printf("RESHUFFLING P2 DECK...\n");
        shuffle(p2_discard_array, discard_pile_two);
        for(int i = 0; i < discard_pile_two; i++){
            singly_add_to_start_of_list(&player_two_cards, p2_discard_array[i]);
        }
        player_two_deck.head = player_two_cards;
        p2_discard_pile = NULL;
        }
        printf("ROUND ENDING...\n\n");
    }
    for(int t = 0; t < 1; t++){
        printf("ROUND STARTING:\n");
        p2_card_in_play = player_two_turn(&player_two_deck, &p2_discard_pile);
        p1_card_in_play = player_one_turn(&player_one_deck, &p1_discard_pile);
        if(p1_card_in_play > p2_card_in_play){
            printf("Player 1 Wins The Round!\n");
            p1_points= (p1_points + 2);
            printf("Player 1 Has %d Points \n", p1_points);
            printf("Player 2 Has %d Points \n", p2_points);
       }else if(p2_card_in_play > p1_card_in_play){
            printf("Player 2 Wins The Round!\n");
            p2_points= (p2_points + 2);
            printf("Player 1 Has %d Points \n", p1_points);
            printf("Player 2 Has %d Points \n", p2_points);
      }else if(p1_card_in_play == p2_card_in_play){
            printf("You Guys Tied...\n");
            p1_points++;
            p2_points++;
            printf("Player 1 Has %d Points \n", p1_points);
            printf("Player 2 Has %d Points \n", p2_points);
      }
        if(player_two_deck.head == NULL){
        int discard_pile_1 = 0;
        node *discard_pile_ptr_1 = NULL;
        discard_pile_ptr_1 = p1_discard_pile;  
        while(discard_pile_ptr_1 != NULL){
            discard_pile_1++;
            discard_pile_ptr_1 = discard_pile_ptr_1->next;
        }
        int p1_discard_array[discard_pile_1];
        discard_pile_ptr_1 = p1_discard_pile;
        for(int i = 0; i < discard_pile_1; i++){
            p1_discard_array[i] = discard_pile_ptr_1->data;
            discard_pile_ptr_1 = discard_pile_ptr_1->next;
        }
        shuffle(p1_discard_array, discard_pile_1);
        for(int i = 0; i < discard_pile_1; i++){
            singly_add_to_start_of_list(&player_one_cards, p1_discard_array[i]);
        }
        player_one_deck.head = player_one_cards;
        p1_discard_pile = NULL;

        int discard_pile_2 = 0;
        node *discard_pile_ptr_2 = NULL;
        discard_pile_ptr_2 = p2_discard_pile;

        while(discard_pile_ptr_2 != NULL){
            discard_pile_2++;
            discard_pile_ptr_2 = discard_pile_ptr_2->next;
        }
        int p2_discard_array[discard_pile_2];
        discard_pile_ptr_2 = p2_discard_pile;
        for(int i =0; i < discard_pile_2; i++){
            p2_discard_array[i] = discard_pile_ptr_2->data;
            discard_pile_ptr_2 = discard_pile_ptr_2->next;
        }
        shuffle(p2_discard_array, discard_pile_2);
        for(int i = 0; i < discard_pile_2; i++){
            singly_add_to_start_of_list(&player_two_cards, p2_discard_array[i]);
        }
        player_two_deck.head = player_two_cards;
        p2_discard_pile = NULL;
        }
        printf("ROUND ENDING...\n\n");
    }
}while((player_two_deck.head!= NULL)&&(player_one_deck.head != NULL));
if(p1_points > p2_points){
       printf("Player 1 Has %d Points \n", p1_points);
       printf("Player 2 Has %d Points \n", p2_points);
       printf("PLAYER 1 WINS!\n");
    }else if(p2_points){
       printf("Player 1 Has %d Points \n", p1_points);
       printf("PLayer 2 Has %d Points \n", p2_points);
       printf("PLAYER 2 WINS!\n");
    }else if( p1_points == p2_points){
       printf("Player 1 Has %d Points \n", p1_points);
       printf("Plaer 2 Has %d Points \n", p2_points);
       printf("Both PLAYERS TIED...Battle Again?\n");
    }else{
        printf("SOMETHING WENT WRONG\n");
    }
}