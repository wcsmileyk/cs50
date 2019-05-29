#include <stdio.h>
#include <cs50.h>

int main(void){

	int height = 0;

	while (height<1 || height >8) {
		height = get_int("Height: ");
	}

	int y;
	for (y=1; y <= height; y++) {
		int x;
		for (x=1; x <= y; x++){
			printf("#");
		}
		printf("\n");
	}

}
