#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int N; // N - режим
	int k; // k - число попыток
	int a = 1, b = 1000;
	int number;
	int c;
	char z[2];

	printf("Введите режим: режим 1 - компьютер загадывает число; режим 2 - вы загадываете число \n");
	scanf_s("%d", &N);

	if (N == 1)
	{
		c = a + rand() % (b - a + 1);
		printf("Введите число \n");
		scanf_s("%d", &number);
			k = 1;
		while (number != c)
		{
			if (number > c)
				printf("загаданное число меньше вашего \n");
			if (number < c)
				printf("загаданное число больше вашего \n");
			printf("Введите число \n");
			scanf_s("%d", &number);
			k++;
		}
		printf("Ура! \n");
		printf("%d", k);
	}

	if (N == 2)
	{
		printf("Введите число, которое вы хотите загадать \n");
		scanf_s("%d", &number);
		k = 1;
		c = a + rand() % (b - a + 1);
		printf("%d", c);
		printf("Угадал? \n");
		gets_s(z);
		while (1 > 0)
		{
			gets_s(z);

			if (z[0] == '<')
				b = c - 1;
			if (z[0] == '>')
				a = c + 1;
			if (z[0] == '=')
				break;
			c = a + rand() % (b - a + 1);
			printf("%d", c);
			k++;
		}
		printf("Угадал! \n");
		printf("%d", k);
	}

	printf("Игра окончена\n");
	scanf_s("%d", &k);
}