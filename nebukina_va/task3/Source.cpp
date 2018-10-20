#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	int n, num, i, j, end; //n - длина числа, num - число игрока, i, j - счетчики для циклов
	int cow = 0; // количество коров
	int bull = 0; // количество быков
	int comp[5] = { 0 }; // массив для числа компьютера
	int number[5] = { 0 }; // массив для числа игрока
	int d, a; // d - делитель, a - вспомогательная переменная
	int attempt = 0;
	srand(time(NULL));
	printf("Игра 'Быки и коровы'!\nВыберите длину загадываемого числа.\nВведите 2, 3, 4 или 5.\n");
	scanf_s("%i", &n);
	while ((n < 2) || (n > 5))
	{
		printf("Количество разрядов может быть только 2, 3, 4 или 5. Введите длину заново.\n");
		scanf_s("%i", &n);
	}
	for (i = 0; i < n; i++)
	{
		comp[i] = (rand() % 9 + 1);
		for (j = 0; j < i; j++)
		{
			while (comp[i] == comp[j])
			{
				comp[i] = (rand() % 9 + 1);
			}
		}
	}
	printf("Введите Ваш вариант числа с неповторяющимися цифрами.\n");
	scanf_s("%i", &num);
	while (bull != n)
	{
		while ((num < pow(10, (n-1))) || (num >= pow(10, (n + 1))))
		{
			printf("Число не входит в выбранный диапазон!\n");
			scanf_s("%i", &num);
		}
		attempt++;
		a = num;
		for (i = n - 1; i >= 0; i--)
		{
			d = pow(10, i);
			number[i] = a / d;
			a %= d;
		}
		bull = 0;
		cow = 0;
		for (i = 0; i < n; i++)
		{
			if (number[i] == comp[i])
				bull++;
			else
				for (j = 0; j < n; j++)
			    {
				if ((i != j)&&(number[i] == comp[j]))
					cow++;
			    }
		}
		if (bull == n)
			break;
		printf("Быков: %i\nКоров: %i\n", bull, cow);
		scanf_s("%i", &num);
	}
	printf("В самом деле! Это число %i. Количество попыток: %i\n", num, attempt);
	scanf_s("%i", &end);
	return 0;
}
