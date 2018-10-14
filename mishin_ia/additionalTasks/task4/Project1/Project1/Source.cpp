#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define N 100

int main() {
	srand(time(NULL));

	int numbers[N];

	for (int i = 0; i < N; i++)
	{
		numbers[i] = rand() % 20;
		printf("%d ", numbers[i]);
	}

	int i = 1, flag = 0, max = -1, k = 0;

	while (i < N - 1) 
	{
		if ((numbers[i - 1] > numbers[i]) && (numbers[i + 1] > numbers[i])) 
		{
			if (flag == 0) max = numbers[i];
			else if (max < numbers[i]) max = numbers[i];
			flag = 1;
			i++;
			k++;
		}
		i++;
	}

	if (max != -1)
	{
		printf("\nk=%d max=%d", k, max);
	}
	else printf("\nThis array haven't any local minimums");
	
	_getch();
	return 0;
}