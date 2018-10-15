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
		numbers[i] = rand() % 100;
		printf("%d ", numbers[i]);
	}
	
	int k = 0, length = 0;

	for (int i = 1; i < N; i++)
	{
		if (numbers[i]==numbers[i - 1])
		{
			continue;
		}
		if (numbers[i]>numbers[i-1])
		{
			if (length == 0)
			{
				length = 1;
			}
			else
			{
				if (length > 0)
				{
					length++;
				}
				else
				{
					k++;
					length = 0;
				}
			}
		}
		else
		{
			if (length == 0)
			{
				length = -1;
			}
			else
			{
				if (length < 0)
				{
					length--;
				}
				else
				{
					k++;
					length = 0;
				}
			}
		}
	}

	if (length != 0 )
	{
		k++;
	}

	if (k == 0)
		printf("\nThis array isn't contain any monotony sequences");
	else
		printf("\nThis array contain %d monotony sequences", k);

	_getch();
	return 0;
}