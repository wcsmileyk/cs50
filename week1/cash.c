#include <stdio.h>
#include <cs50.h>
#include <math.h>

float get_change(void);
int get_count(float change);


int main(void){
	float change = get_change();

	int coin_count = get_count(change);

	printf("%i\n", coin_count);
}

int get_count(float change){

	int cents = round(change * 100);
	int coin_count = 0;

	do {
		if (cents >= 25){
			coin_count++;
			cents -= 25;
		}
		else if (cents >= 10){
			coin_count++;
			cents -= 10;
		}
		else if (cents >= 5){
			coin_count++;
			cents -= 5;
		}
		else {
			coin_count++;
			cents -= 1;
		}
	}
	while (cents > 0);

	return coin_count;

}

float get_change(void){

	float change;

	do {
		change = get_float("Customers change: ");
	}

	while (change < 0.00);

	return change;
}
