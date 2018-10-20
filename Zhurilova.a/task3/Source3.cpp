#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void main()
{
	setlocale(LC_ALL, "Rus");

	int exit;
	int n, gran, kolK=0, kolB=0;
	int  i, j;
	int proverka;
	int chisO[5] = { 0 };
	int chisZ[5] = { 0 };
	int zag=0, otg, zapas;
	do
	{
		printf("Введите длину числа от 2 до 5\n");
		scanf("%d", &n);
	}
	while ((n < 2) || (n > 5));
	proverka = 1;
	while (proverka != 0)
	{
        proverka = 0;//Если число создасться верно выход из цикла генерации обеспечен
		for (i = 1; i <= n; i++)//Генерация числа
		{
			if (i == (n - 1))//Если i старший разряд, значит i не может быть равно 0
			{
				chisZ[i] = 1 + rand() % (9);//От 1 до 9
			}
			else
			{
				chisZ[i] = rand() % (10);//От 0 до 9
			}
		}
		for (i = 0; i < n; i++)//Проверка на совпадение цифр
		{
			for (j = (i + 1); j < n; j++)//Нельзя сравнивать элементы одний позиции
			{
				if (chisZ[i] == chisZ[j])
				{
					proverka = 1;//Снова зайдет в цикл генерации
					break;//Дальнейшая проверка бессмысленна
				}
			}
		}

	}
	gran = 1;
	for (i = 0; i < n; i++)//Вычисление границ предполагаемого числа согласно его границам
	{
		gran = gran * 10;
	}	
	while (kolB != n)
	{
		proverka = 1;
		do
		{
			printf("Введите число.\nВНИМАНИЕ!!!\nДлина числа должна совпадать с введеной вами ранее и цифры в числе должны быть РАЗЛИЧНЫМИ\n");
			scanf("%d", &otg);
			zapas = otg;
			if ((otg<(gran/10))||(otg>(gran-1)))
			{
				printf("Число не той длины!!!\n");
				proverka = 1;
			}
			else				
			{
				proverka = 0;//Число верной длины				
			}
			for (i = 0; i < n; i++)//Заполнение массива с цифрами отгадки
			{
				chisO[i] = zapas % 10;
				zapas = zapas / 10;
			}
			for (i = 0; i < n; i++)//Проверка на повторяемость цифр в отгадке
			{
				for (j = (i + 1); j < n; j++)
				{
					if (chisO[i] == chisO[j])
					{
						proverka = 1;
						printf("Вы ввели число с повторяющимися цифрами!!!\n");
						break;
					}
				}
				if (proverka == 1)//Если встретились повторяющиеся элементы закрыть цикл. Начать сначала
				{
					break;
				}
			}
			
		} while (proverka!=0);
		kolK = 0;
		kolB = 0;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if ((chisZ[i] == chisO[j])&&(i==j))//Если совпали цифры
				{
					kolK++;
				}
				if ((i == j)&&(chisZ[i] == chisO[j]))//Если совпали их позиции
				{
					kolB++;
				}
			}
		}
		printf("Количестов коров %d, Количество быков %d\n", kolK, kolB);
	}
	printf("Поздравляю!!! Вы угадали число!\n");
	scanf("%d", &exit);
}