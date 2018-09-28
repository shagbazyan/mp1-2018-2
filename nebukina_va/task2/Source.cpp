#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h>
#include <iostream>
int main()
{
	setlocale(LC_ALL, "Rus");
	int numb, mode, i;
	int attempt = 0;
	srand(time(NULL));
	numb = rand();
		printf("Введите номер желаемого режима\n 1) Вы отгадываете число\n 2) Программа отгадывает число\n");
	scanf_s("%i", &mode);
	if (mode = 1)
		do
		{
			printf("Введите число от 1 до 1000");
	scanf_s("%i", &i);
	attempt + 1;
	if (i > numb)
		printf("Загаданное число меньше\n");
	else
		printf("Загаданное число больше\n");
		} while (i != numb);
	printf("Вы угадали число!");

}