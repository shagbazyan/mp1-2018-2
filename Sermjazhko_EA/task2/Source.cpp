#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

int main(void)
{
	setlocale(LC_ALL, "Rus");
	int rezh1, chis, chis1, n, random, r1, r2;

	srand(time(NULL));
	printf("Выберите режим 1 или 2\n");
	scanf_s("%i", &rezh1);
	n = 1;

	if (rezh1 == 1)
	{
		printf("Компьютер загадал число от 1 до 1000. Попробуйте отгадать его. Введите число от 1 до 1000\n");
		scanf_s("%i", &chis);
		while ((chis > 1000) || (chis < 1))
		{
			printf("Данные введены неверно. Попробуйте ещё раз (от 1 до 1000)\n");
			scanf_s("%i", &chis);
		}
		random = 1 + rand() % 1000;
		if (chis == random)
			printf("Вы отгадали число. Количество попыток: 1");
		else
		{
			while (chis > random || chis < random)
			{
				if (chis > random)
				{
					printf("Загаданное число меньше вашего\n"); 
				}
				else
				{
					printf("Загаданное число больше вашего\n");
				}
				scanf_s("%i", &chis);
				n++;
			}
			printf("Вы угадали число! Количество попыток: %i", n);
		}
	}
	else
	{
		printf("Загадайте число в диапазоне от 1 до 1000, а компьютер попытается его отгадать\n");
		scanf_s("%i", &chis);

		while ((chis > 1000) || (chis < 1))
		{
			printf("Данные введены неверно. Попробуйте ещё раз (от 1 до 1000)\n");
			scanf_s("%i", &chis);
		}

		printf("Ваше число %i (напоминалка)\n", chis);
		random = 1 + rand() % 1000;
		chis1 = 0;
		printf("Вы загадали: %i?\n Если да(=), напишите: 1\n Если ваше число больше(>), напишите: 2\n Если меньше(<), напишите: 3 \n", random);
		scanf_s("%i", &chis1);
		r1 = 1;
		r2 = 1000;

		if (chis1 == 1)
			printf("Компьютер угадал число с 1 попытки\n");
		else
		{
			while ((chis1 == 2) || (chis1 == 3))
			{
				if (chis1 == 2)
				{
					r1 = random;
					random = 1 + random + rand() % (r2-random);
					printf("Вы загадали: %i?\n Если да(=), напишите: 1\n если ваше число больше(>), напишите: 2\n  если меньше(<), напишите: 3 \n", random);
					scanf_s("%i", &chis1);
				}
				else 
				{
					r2 = random;
					random = 1 + random - rand() % (r1-random);
					printf("Вы загадали: %i?\n Если да(=), напишите: 1\n если ваше число больше(>), напишите: 2\n  если меньше(<), напишите: 3 \n", random);
					scanf_s("%i", &chis1);
				}
				n++;
			}
			printf("Компьютер угадал число. Количество попыток: %i\n", n);
		}
			 
	}

}
