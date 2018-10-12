#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define N 100

int main() {
	srand(time(NULL));

	int numArray[N];
	int serialArray[N];

	for (int i = 0; i < N; i++)
	{
		numArray[i] = rand() % 2;
		printf("%d ", numArray[i]);
	}

	int k = 0;
	int p = 1;

	for (int i = 1; i < N; i++)
	{
		if (numArray[i] == numArray[i - 1])
		{
			p++;
		}
		else
		{
			serialArray[k] = p;
			p = 1;
			k++;
		}
	}

	printf("\n");

	serialArray[k] = p;
	k++;

	for (int i = 0; i < k; i++)
	{
		printf("%d ", serialArray[i]);
	}

	_getch();
	return 0;
}