#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h>
#include <iostream>
int main()
{
	setlocale(LC_ALL, "Rus");
	int numb1, numb2, mode, i, end;
	int min, max;
	int attempt = 0;
	char symbol;
	srand(time(NULL));
	numb1 = (rand() % 1000 + 1);
	symbol = '+';
	min = 0;
	max = 1000;
	attempt = 0;
	i = 0;
	printf("Введите номер желаемого режима\n 1) Вы отгадываете число\n 2) Программа отгадывает число\n");
	scanf_s("%i", &mode);
	while ((mode != 1) && (mode != 2))
	{
		printf("Нет такого режима. Попробуйте ещё раз.\n");
		scanf_s("%i", &mode);
	}
	if (mode == 1)
	{
		while (i != numb1)
		{
			printf("Введите число от 1 до 1000\n");
			scanf_s("%i", &i);
			attempt++;
			if ((i > 1000) || (i < 1))
				printf("Число не входит в интервал. Попробуйте ещё раз.\n");
			else
				if (i > numb1)
					printf("Загаданное число меньше\n");
				else
					if (i < numb1)
						printf("Загаданное число больше\n");
					else
						printf("Поздравляю! Вы угадали!\n");
		}
		printf("Количество попыток %i\n", attempt);
	}
	else
	{
		printf("Загадайте число от 1 до 1000.\n");
		while (symbol!='=')
		{
			numb2 = (max + min) / 2;
			printf("Ваше число %i? Если да, введите '=', если нет, введите '<' или '>'\n", numb2);
			scanf_s("%c", &symbol);
			scanf_s("%c", &symbol);
			attempt++;
			switch (symbol)
			{
			case '>':
				min = numb2;
				break;
			case '<': 
				max = numb2;
				break;
			case '=': 
				printf("Компьютер угадал число за %i попыток.\n", attempt);
				break;
			default:
				printf("Введите '=', '<' или '>'\n");
				break;
			}
		}
	}
	scanf_s("%i", &end);
	return 0;
}
