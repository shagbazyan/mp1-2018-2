#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include <stdio.h>

void main()
{
	setlocale(LC_ALL, "Rus");
	int dlina;
	int numb[5];
	int numb1, numb2;
	int mult;
	int i, j, k;
	srand(time(NULL));
	printf("¬ведите длину числа от 2 до 5\n");
	scanf_s("%i", &dlina);

	while ((dlina < 2) || (dlina > 5))
	{
		printf("ƒлина задана неверно, введите новую длину\n");
		scanf_s("%i", &dlina);
	}
	for (int c = 0; c < 100; c++)
	{
		numb[0] = rand() % 9 + 1;
		for (i = 1; i < dlina; i++)
		{
			numb1 = rand() % 10;
			for (j = 0; j <= i-1; j++)
			{
				
				while (numb1 == numb[j])
				{
					j = 0;
					numb1 = rand() % 10;
				}
				
				numb[i] = numb1;
			}
		}
		numb1 = 0;
		mult = 1;
		for (i = dlina-1; i >= 0; i = i - 1)
		{
			numb1 = numb1 + mult * numb[i];
			mult = mult * 10;
		}
		printf("%d\n", numb1);
	}
	_getch();
}