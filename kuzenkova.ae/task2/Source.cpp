#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>

int randomchik(int x, int y)
{
	return x + rand() % (y - x + 1);
}

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	int rejim; //переменная, отвечающая за режим
	int number; //число
	int k, m = 0; // k - это число, которое вводит пользователь для режима 1 или число предлагаемое компьютером, m - число попыток
	int a = 1, b = 1000; // границы рандома
	char c[2]; //вводимый символ < > =

	do {
		printf("Введи режим: 1 - программа загадывает, 2 - пользователь загадывает\n");
		scanf_s("%d", &rejim);
	} while (rejim != 1 && rejim != 2);

	if (rejim == 1)
	{
		number = randomchik(a, b);
		while (1 > 0)
		{
			printf("Введи число:\n");
			scanf_s("%d", &k);
			m++;
			if (k > number)
				printf("Загаданое число меньше\n");
			if (k < number)
				printf("Загаданое число больше\n");
			if (k == number)
				break;
		}
		printf("Вы угадали, поздравляю! Мое число %d. Вы угадали за %d попыток", number, m);

	}
	else
		if (rejim == 2)
		{
			printf("Введите загаданное число\n");
			scanf_s("%d", &number);
			gets_s(c);
			k = randomchik(a, b);
			while (1 > 0)
			{
				printf("Ваше число %d ?\n", k);
				gets_s(c);
				m++;
				if (c[0] == '>')
				{
					a = k - 1;
					k = randomchik(a, b);
				}
				if (c[0] == '<')
				{
					b = k - 1;
					k = randomchik(a, b);
				}
				if (c[0] == '=')
					break;
			}
			printf("Ваше число %d. Я угадал за %d попыток. Компьютеры рулят:) ", k, m);
		}
	scanf_s("%d", &k);

}