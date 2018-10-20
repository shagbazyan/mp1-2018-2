#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int n; //n - количество цифр в числе
	int r = 1; //используем для контроля выхода из цикла
	int K[5] = { 0 }; // массив для хранения загаданного числа
	int B[5] = { 0 }; // массив для хранения моего числа
	int cow = 0; //"коровы"
	int bull = 0; //"быки"
	int i;
	int m;
	int p = 1; //p - отвечает за контроль длины вводимого числа
	int z; // z - наши попытки угадать загаданное число

	printf_s("Условие игры: вы пытаетесь угадать число, загаданное компьютером, сow - сколько цифр угадано без совпадения с их позициями в загаданном числе, а bull - сколько цифр угадано вплоть до позиции в загаданном числе\n");

	do
	{
		printf_s("Введите количество цифр в числе\n");
		scanf_s("%d", &n);
	} while (n < 2 || n > 5);

	while (r > 0)
	{
		r = 0; // r=0 - тогда нет повторов
		for (i = 0; i < n; i++)
		{
			if (i == (n - 1))
				K[i] = 1 + rand() % 9; // для первой цифры числа 9 вариантов цифры от 1 до 9
			else
				K[i] = rand() % 10; // для следующих цифр числа 10 вариантов цифр от 0 до 9
		}
		for (i = 0; i < n; i++)
			for (m = i + 1; m < n; m++)
			{
				if (K[i] == K[m])
				{
					r = 1; // значит есть повторы
					break;
				}
			}
	}

	for (i = 0; i < n; i++)
		p = p * 10;

	printf_s("Начнем игру!\n");

	while (bull != n)
	{
		do
		{
			r = 1; //нет повторов
			printf_s("Введите число с неповторяющимися цифрами\n");
			scanf_s("%d", &z);
			if (z > p - 1)
			{
				printf_s("Ваше число длинее, чем нужно\n");
				r = 0; 
			}
			else if (z < p / 10)
			{
				printf_s("Ваше число короче, чем нужно\n");
				r = 0;
			}
			else
			{ 
				for (i = 0; i < n; i++)
			{
				B[i] = z % 10;
				z = z / 10;
			}
			for (i = 0; i < n; i++)
				for (m = i + 1; m < n; m++)
				if (B[i] == B[m])
				{
					r = 0; // есть повторы, цикл повторяется
					break;
				}
			}
		} while (r != 1);
			
			bull = 0;
			cow = 0;
			for (i = 0; i < n; i++)
			{
				for (m = 0; m < n; m++)
				{
					if (B[i] == K[m] && i == m)
						bull++;
					if (B[i] == K[m] && i != m)
						cow++;
				}
			}
				printf_s("cow-%d, bull-%d\n", cow, bull);
			}
	printf_s("Победа!:)");
	scanf_s("%d", &cow);
}
