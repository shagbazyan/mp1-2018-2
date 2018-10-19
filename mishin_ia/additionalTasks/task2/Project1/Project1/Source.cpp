#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>

float jump() {
	int r1 = rand() % 15 + 30;
	int r2 = rand() % 10;
	return r1 + (float)r2 / 10;
}

float run() {
	int r1 = rand() % 180 + 3000;
	int r2 = rand() % 10;
	return r1 + (float)r2 / 10;
}

int main() {
	srand(time(NULL));
	int *sportsmens;
	float *results;

	printf("Enter number of sportsmens: ");
	int quantity;
	scanf_s("%d", &quantity);

	sportsmens = (int*)malloc(quantity * sizeof(int));
	results = (float*)malloc(quantity * sizeof(float));

	printf("First part results: \n");

	for (int i = 0; i < quantity; i++)
	{
		sportsmens[i] = i+1;
		for (int j = 0; j < 2; j++)
		{
			results[i] = jump();
			float jump2 = jump();
			if (jump2 > results[i])
			{
				results[i] = jump2;
			}
		}
		printf("%d : %3.1f meters\n", sportsmens[i], results[i]);
	}

	int max = 0;

	for (int i = 0; i < quantity; i++)
	{
		if (results[i] > max)
		{
			max = results[i];
		}
	}

	printf("\n\nSecond part results:\n");

	for (int i = 0; i < quantity; i++)
	{
		results[i] = (max - results[i]) * 5 + run();
		printf("%d : %3.1f seconds\n", sportsmens[i], results[i]);
	}
	
	for (int i = quantity - 2; i >= 0; i--)
	{
		for (int j = i; j < quantity - 1; j++)
		{
			if (results[j + 1] < results[j])
			{
				float tm = results[j + 1];
				results[j + 1] = results[j];
				results[j] = tm;

				int km = sportsmens[j + 1];
				sportsmens[j + 1] = sportsmens[j];
				sportsmens[j] = km;
			}
		}
	}

	printf("\n\nWinners:\n");

	for (int i = 0; i < 3; i++)
	{
		printf("%d place: %d \n", i + 1, sportsmens[i]);
	}

	_getch();
	return 0;
}