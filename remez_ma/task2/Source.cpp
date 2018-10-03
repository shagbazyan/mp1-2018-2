#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

void main()
{
	setlocale(LC_ALL, "Rus");

	int type = 0;
	int inp, ger, count;
	char Cinp, tmp;
	srand(time(NULL));

	printf("Кто будет угадывать? Вы (1) или компьютер (2) ?:\n");
	scanf_s("%d", &type);

	while (type != 1 && type != 2)
	{
		printf("Некорректный ввод.\n");
		scanf_s("%d", &type);
	}

	if(type == 1) 
	{
		ger = (rand() % 1001);
		inp = -1;
		count = 0;

		while (inp != ger)
		{
			printf("Введите Ваш вариант числа:\n");
			scanf_s("%d", &inp);
			count++;
			if (inp == ger)
				printf("Вы угадали за %d попыток!\n", count);
			else if (inp > ger)
				printf("Вы ввели слишком большое число!\n");
			else
				printf("Вы ввели слишком маленькое число!\n");
		}
	} else
	{
		printf("Введите число от 1 до 1000:\n");
		scanf_s("%d", &inp);
		scanf_s("%c", &Cinp);
		count = 0;
		ger = 0;
		ger = (rand() % 1001);
		int min, max;
		min = 0; max = 1001;
		bool vic = false;

		while (!vic)
		{			
			printf_s("Вариант компьютера: %d\n", ger);
			printf_s("Число компьютера должно быть больше '>' меньше '<' или он угадал '=' ?:\n");

			count++;
			scanf_s("%c", &Cinp);
			scanf_s("%c", &tmp);

			switch (Cinp)
			{
				case '>':
					min = (ger < min ? min : ger) + 1;
					break;
				case '<':
					max = (ger > max ? max : ger);
					break;
				case '=':
					printf("Компьютер угадал за %d попыток!\n", count);
					vic = true;
					break;
				default:
					printf("Введите > < или =\n");
					break;
			}

			ger = min + rand() % (max - min);
		}
	}
	_getch();
}
