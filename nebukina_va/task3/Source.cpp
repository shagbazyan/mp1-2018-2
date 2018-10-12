#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h>
#include <iostream>

int main()
{
	setlocale(LC_ALL, "Rus");
	int n, number, i;
	int cow, bull;
	int comp, c1, c2, c3, c4, c5; // заменить неравенство переменной каждой другой на неравенство всем
	c1 = 0;
	c2 = 1;
	c3 = 2;
	c4 = 3;
	c5 = 4;
	srand(time(NULL));
	printf("Игра 'Быки и коровы'!\n Выберите длину загадываемого числа.\n Введите 2, 3, 4 или 5.\n");
	scanf_s("%i", &n);
	switch (n)
	{
	case 2 :
		while (c4 == c5)
		{
			c4 = (rand() % 9 + 1);
			c5 = (rand() % 9 + 1);
		}
		comp = 10 * c4 + c5;
		printf("Введите число выбранной длины.\n");
		scanf_s("%i", &i);
		if ((i > 1) && (i < 99))
			if (((i / 10) == c4) && ((i % 10) == c5))
				printf("Вы угадали! это число %i", comp);
			else if (((i / 10) == c4) || ((i % 10) == c5))
				printf("")

		break;
	case 3 :
		while ((c3 == c4) && (c3 == c5) && (c4 == c5))
		{
			c3 = (rand() % 9 + 1);
			c4 = (rand() % 9 + 1);
			c5 = (rand() % 9 + 1);
		}
		comp = 100 * c3 + 10 * c4 + c5;
		break;
	case 4 :
		while ((c2 == c3) && (c2 == c4) && (c2 == c5) && (c3 == c4) && (c3 == c5) && (c4 == c5))
		{
			c2 = (rand() % 9 + 1);
			c3 = (rand() % 9 + 1);
			c4 = (rand() % 9 + 1);
			c5 = (rand() % 9 + 1);
		}
		comp = 1000 * c2 + 100 * c3 + 10 * c4 + c5;
		break;
	case 5 :
		while ((c1 == c2) && (c1 == c3) && (c1 == c4) && (c1 == c5) && (c2 == c3) && (c2 == c4) && (c2 == c5) && (c3 == c4) && (c3 == c5) && (c4 == c5))
		{
			c1 = (rand() % 9 + 1);
			c2 = (rand() % 9 + 1);
			c3 = (rand() % 9 + 1);
			c4 = (rand() % 9 + 1);
			c5 = (rand() % 9 + 1);
		}
		comp = 10000 * c1 + 1000 * c2 + 100 * c3 + 10 * c4 + c5;
		break;
	default : 
		printf("Введите 2, 3, 4 или 5.\n");
		break;
	}
	printf("Введите число выбранной длины.\n");
	scanf_s("%i", &i);
}	