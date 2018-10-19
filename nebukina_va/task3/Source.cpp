#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int n, num, i, j; //n - длина числа
	int cow = 0;
	int bull = 0;
	int comp[5]; // число компьютера
	int number[5]; // число игрока
	int d, a; // d - делитель
	srand(time(NULL));
	printf("Игра 'Быки и коровы'!\n Выберите длину загадываемого числа.\n Введите 2, 3, 4 или 5.\n");
	scanf_s("%i", &n);
	while ((n < 2) && (n > 5))
	{
		printf("Количество разрядов может быть только 2, 3, 4 или 5.\n");
		scanf_s("%i", &n);
	}
	comp[0] = (rand() % 9 + 1);
	for (i = 1; i < n; i++)
	{
		comp[i] = (rand() % 9 + 1);
		while (comp[i] == comp[i - 1])
		{
			comp[i] = (rand() % 9 + 1);
		}
	}
	printf("Введите Ваш вариант числа с неповторяющимися цифрами.\n");
	scanf_s("%i", &num);
	while (bull != n)
	{
		for (i = 0; i < n; i++);
		{
			a = num;
			d = pow(10, n - 1);
			number[i] = a / d;
			a %= d;
		}
		for (i = 0; i < n; i++)
		{
			if (number[i] == comp[i])
				bull++;
		}
		for (i = 0; i < n; i++)
		{
			for (j = 1; j < n; j++)
			{
				if ((i != j)&&(number[i] == comp[j]))
					cow++;
			}
		}
		printf("Быков: %i\nКоров: %i\n", bull, cow);
		scanf_s("%i", &num);
	}
	printf("Вы угадали! Это число %i.\n", num);

}