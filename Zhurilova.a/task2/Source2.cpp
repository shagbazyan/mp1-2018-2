﻿#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void main()
{
	setlocale(LC_ALL, "Rus");

	int x1, x2, kol=0, reg, a = 1, b = 1000; //Объявление переменных
	char otvet;
	

	printf("Выберите режим игры: 1-Вы отгадываете число, 2- отгадывает компьютер\n");
	scanf("%d", &reg);

	if (reg == 1)//Если выбран 1 режим
	{
		x1 = 1 + rand() % (1000);
		x2 = 0;//Обнуление предполагаемой отгадки для входа в цикл while
		printf("Число загаданно. Введите предположительную отгадку.\n");
		while (x1 != x2)
		{
			kol++;//Счетчик попыток отгадать число
			printf("Введите предположительную отгадку.\n");
			scanf("%d", &x2);
			if (x1 > x2)
			{
				printf("Попробуйте ввести число побольше\n");
			}
			else
				if (x1 < x2)
				{
					printf("Попробуйте ввести число поменьше\n");
				}
				else
					if (x1 == x2)
					{
						printf("Ура! Вы угадали %d", kol);
						
					}
		}
	}
	else
		if (reg == 2)//Если выбран режим 2
		{
			printf("Вы выбрали режим 2. Загадайте число от 1 до 1000\n");
			scanf("%d", &x1);
			x2 = 0;//Обнуление предположительной отгадки для входа в цикл while
			while (x1 != x2)
			{
				kol++;
				x2 = a + rand() % (b - a + 1);
				printf("Вы загадали это число: %d\n", x2);
				printf("Введите знак больше, меньше или равно для дальнейшего отгадывания\n");
				scanf("%c", &otvet);
				if (otvet == '>')//Значит число пользователя больше, x2 является нижней границей, соответсвтенно a=x2
				{
					a = x2;
				}
				else 
					if (otvet == '<')//Значит число пользоваетля меньше, x2 является верхней границей, соответсвенно b=x2
				{
					b = x2;
				}
				else if (otvet == '=')
				{
					printf("Ура! Число угадано. Количество попыток %d", kol);
					
				}
			}
		}

}