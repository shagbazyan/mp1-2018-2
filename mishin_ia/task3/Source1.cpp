#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include "Header.h"

void secondGame() {
	srand(time(NULL));
	int length;
	int flag = 0;
	printf("Choose number length between 2 and 5\n");
	scanf_s("%d", &length);

	while (length < 2 || length > 5) 
	{
		printf("Length not in range between 2 and 5\nEnter new length:\n");
		scanf_s("%d", &length);
	}

	int myNum;
	int myNumber[5];

	int addict[10];
	for (int i = 0; i < 10; i++)
	{
		addict[i] = 1;
	}

	int power = 10;
	power = pow(power, length - 1);
	printf("Enter your number:\n");

	scanf_s("%d", &myNum);

	for (int i = 0; i < length; i++)
	{
		myNumber[i] = (myNum % (power * 10)) / power;
		power /= 10;

	}

	int number[5];

	printf("Start!\n");

	int r = rand() % 9 + 1;
	number[0] = r;

	int attempts = 0;
	while (attempts < length * 50)
	{
		attempts++;
		int cows = 0;
		int bulls = 0;

		int r = rand() % 9 + 1;
		number[0] = r;

		for (int i = 1; i < length; i++)
		{
			r = rand() % 10;
			int j = 0;
			while (j <= i - 1) 
			{
				if ((r == number[j]) || (0 > addict[r])) 
				{
					r = rand() % 10;
					j = 0;
				}
				j++;
			}
			number[i] = r;
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
					if (myNumber[i] == number[j]) 
					{
						cows++;
					}
				}
			}
		}
		if (bulls == length) 
		{
			flag = 1;
			printf("\nYour number: ");
			for (int i = 0; i < length; i++)
			{
				printf("%d", number[i]);
			}
			printf("\nComputer win for %d attempts!", attempts);
			break;
		}
		
		if ((bulls == 0) && (cows == 0)) 
		{
			for (int i = 0; i < length; i++)
			{
				addict[number[i]] -= 100;
			}
		}
		else 
		{
			for (int i = 0; i < length; i++)
			{
				addict[number[i]] += bulls + cows;
			}
		}
	}

	if (flag == 0)
	{
		int num;
		int maximum[6];

		printf("Numbers from your number: ");

		for (int i = 0; i < length + 1; i++)
		{
			int max = 0;
			for (int j = 0; j < 10; j++)
			{
				if (addict[j] > max)
				{
					num = j;
					max = addict[j];
				}
			}
			maximum[i] = num;
			addict[num] = 0;
			if (i != length) printf("%d ", maximum[i]);
		}

		int testNumber[5];
		int finalNumber[5];

		for (int i = 0; i < length; i++)
		{
			testNumber[i] = maximum[length];
		}

		for (int i = 0; i < length; i++)
		{
			for (int h = 0; h < length; h++)
			{
				testNumber[h] = maximum[length];
			}

			for (int j = 0; j < length; j++)
			{
				attempts++;
				testNumber[j] = maximum[i];
				if (testNumber[j] == myNumber[j]) 
				{
					finalNumber[j] = maximum[i];
					break;
				}
			}
		}

		printf("\nYour number: ");

		for (int i = 0; i < length; i++)
		{
			printf("%d", finalNumber[i]);
		}
		printf("\nComputer win for %d attemts", attempts);
	}
	_getch();
}