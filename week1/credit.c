#include <stdio.h>
#include <cs50.h>
#include <math.h>

int length(long number);
int card_sum(long card_number);

int main(void){
    int card_length = 0;
    long card_number;
    
    do {
        card_number = get_long("Card Number: ");
        card_length = length(card_number);
    } while ((card_length != 13) && (card_length != 15) && (card_length != 16));  
    
    int card_validation = card_sum(card_number);
    if (card_validation % 10 == 0){
        if (card_length == 13) {
            printf("VISA\n");
        }
        else if (card_length == 15){
            printf("AMEX\n");
        }
        else if (floor(card_number / 15) == 4) {
            printf("VISA\n");
        }
        else {
            printf("MASTERCARD\n");
        }
    }
    else {
        printf("INVALID\n");
    }
}

int card_sum(long card_number){
    int digit_sum = 0;
    int card_num_dup = card_number;
    while (card_num_dup > 0){
        card_num_dup /= 10;
        digit_sum += (card_num_dup % 10) * 2;
    }
    
    while (card_number > 0){
        digit_sum += card_number % 10;
        card_number /= 10;
    }
    
    return digit_sum;
}

int length(long number){ 
    int count = 0;  
    while (number != 0){
        number /= 10;
        count++;
    }
    
    return count;
}
