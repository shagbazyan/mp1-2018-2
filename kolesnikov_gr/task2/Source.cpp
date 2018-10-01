#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <time.h>

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(0));
	int chislo;
	int predpolozhenie;
	
	predpolozhenie = -1;
	chislo = rand() % 1001;
	printf("%i\n", chislo); //  для проверки
	while (predpolozhenie != chislo)
	{
		printf("Введите ваше предположение\n");
		scanf_s("%d", &predpolozhenie);
		if (predpolozhenie == chislo)
			printf("Вы нашли загаданное число\n");
		else if (predpolozhenie > chislo)
			printf("Загаданное число меньше\n");
		else printf("Загаданное число больше\n");
	}

	_getch();
}