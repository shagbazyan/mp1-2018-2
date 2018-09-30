#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h>
#include <iostream>
int main()
{
	setlocale(LC_ALL, "Rus");
	int numb, mode, i, end;
	int attempt = 0;
	char more, less;
	srand(time(NULL));
	numb = (rand() % 1000 + 1);
	attempt = 0;
	i = 0;
	printf("Введите номер желаемого режима\n 1) Вы отгадываете число\n 2) Программа отгадывает число\n");
	scanf_s("%i", &mode);
	if (mode = 1)
		while (i != numb);
	{
		printf("Введите число от 1 до 1000");
		scanf_s("%i", &i);
		attempt++;
		if (i > numb)
			printf("Загаданное число меньше\n");
		else
			if (i < numb)
				printf("Загаданное число больше\n");
			else
				printf("Вы угадали!\n");
		printf("Количество попыток %i\n", attempt);
	}
	scanf_s("%i", &end);
	return 0;
}