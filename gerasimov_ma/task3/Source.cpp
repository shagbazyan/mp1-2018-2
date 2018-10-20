#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int number_digits[10][2];
//number_digits[i][1] = 1 if number contains the digit i, and = 0 if not. number_digits[i][2] shows the position of digit i in the number

int generate_number(int length)
{
	int mas[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int divra, number = 0, tmp, lmas = 10, i;

	srand(time(NULL));
	for (i = 1; i <= length; i++)
	{
		if (i == 1)
			divra = rand() % (lmas - 1) + 1;
		else
			divra = rand() % lmas;
		number = number * 10 + mas[divra];
		number_digits[mas[divra]][1] = 1;
		number_digits[mas[divra]][2] = i;
		if (divra != lmas - 1)
		{
			tmp = mas[divra];
			mas[divra] = mas[lmas - 1];
			mas[lmas - 1] = tmp;
		}
		lmas--;
	}
	return number;
}

void biks_and_cows(int scanned, int length)
{
	int cows = 0, biks = 0;

	for (int i = length; i >= 1; i--)
	{
		if (number_digits[scanned % 10][1] == 1)
			if (number_digits[scanned % 10][2] == i)
				biks++;
			else
				cows++;
		scanned /= 10;
	}
	printf("Biks = %d; Cows = %d\n", biks, cows);
}

bool scanned_check(int scanned)
{
	int mas[10] = { 0 };

	while (scanned > 0)
	{
		mas[scanned % 10]++;
		scanned /= 10;
	}
	bool flag = true;
	int i = 0;
	while ((i <= 9) && (flag))
	{
		if (mas[i] > 1)
			flag = false;
		i++;
	}
	return flag;
}

int main()
{
	int length, number, scanned, attempts, tmp, i, another;
	int number_digits[10][2];
	bool flag;

	do
	{
		printf("Enter the length of number between 2 and 5\n");
		do
		{
			scanf_s("%d", &length);
			if ((length > 5) || (length < 2))
				printf("You have entered an incorrect length. It should be between 2 and 5!\n");
		} while ((length > 5) || (length < 2));

		for (i = 0; i <= 9; i++)
		{
			number_digits[i][1] = 0;
			number_digits[i][2] = 0;
		}

		number = generate_number(length);
		attempts = 0;
		do
		{
			printf("Enter the supposed number\n");
			do
			{
				scanf_s("%d", &scanned);
				flag = scanned_check(scanned);
				if (flag == false)
					printf("You have entered an incorrect number. You should enter the number without repeated digits!\n");
			} while (flag == false);

			biks_and_cows(scanned, length);
			attempts++;
		} while (scanned != number);
		printf("YOU WON!!! CONGRATULATIONS!!!\n");
		printf("Attempts: %d\n", attempts);
		printf("Wanna play again? 1 - Yes; 0 - No\n");
		scanf_s("%d", &another);
	} while (another == 1);
}