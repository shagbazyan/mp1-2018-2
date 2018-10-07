#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "Header.h"


int main() {

	printf("Enter 1 for first mode or 2 for second mode\n");
	int mode;
	scanf_s("%d", &mode);
	if (mode == 2) {
		secondGame();
	}
	
	srand(time(NULL));
	int length;
	
	printf("Choose number length between 2 and 5\n");

	scanf_s("%d", &length);
	
	while (length < 2 || length > 5) {
		printf("Length not in range between 2 and 5\nEnter new length:\n");
		scanf_s("%d", &length);
	}
	
	

	int number[5];

	printf("Start!\n");

	int r = rand() % 9 + 1;
	number[0] = r;
	
	for (int i = 1; i < length; i++)
	{
		int r = rand() % 10;
		int j = 0; 
		while(j<=i-1){			
			if (r == number[j]) {
				r = rand() % 10;
				j = 0;
			}
			j++;
		}
		number[i] = r;
	}

	int hiddenNumber = 0;
	int pow = 1;

	for (int i = length-1; i >= 0; i--)
	{
		hiddenNumber += pow * number[i];
		pow *= 10;
	}
	 
	int myNum;
	int myNumber[5];
	
	while (true) {
		printf("Enter your number:\n");
		int cows = 0;
		int bulls = 0;
		int pow2 = pow;
		scanf_s("%d", &myNum);
		
		for (int i = 0; i < length; i++)
		{
			myNumber[i] = (myNum % pow2 * 10) / pow2;
			pow2 /= 10;
		}
		
		for (int i = 0; i < length; i++)
		{
			if (myNumber[i] == number[i])
			{
				bulls++;
			}
			else
			{
				for (int j = 0; j < length; j++)
				{
					if (myNumber[i] == number[j]) {
						cows++;
					}
				}
			}
		}
		if (bulls == length) {
			printf("\nYou win!");
			break;
		};
		printf("Cows: %d, Bulls: %d\n", cows, bulls);
	}
	_getch();
	return 0;
}
