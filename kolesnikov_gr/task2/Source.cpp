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
	int popitki;
	int rejim;
	int max;
	int min;
	int truth;
	char neravenstvo;

	printf("Выберите режим игры: нажмите 1, чтобы угадывать число; нажми 2, чтобы загадывать\n");
	scanf_s("%d", &rejim);
	if (rejim > 2)
		printf("Такого режима еще нет(пока что)\n");
	if (rejim == 1)
	{
		predpolozhenie = -1;
		popitki = 0;
		chislo = rand() % 1001;
		printf("%i\n", chislo); //  для проверки
		while (predpolozhenie != chislo)
		{
			popitki = popitki + 1;
			printf("Введите ваше предположение\n");
			scanf_s("%d", &predpolozhenie);
			if (predpolozhenie == chislo)
				printf("Вы нашли загаданное число. Количество попыток: %d \n", popitki);
			else if (predpolozhenie > chislo)
				printf("Загаданное число меньше\n");
			else printf("Загаданное число больше\n");
		}
	}

	if (rejim == 2)
	{
		max = 1000;
		min = 0;
		truth = 0;
		printf("Введите число\n");
		scanf_s("%d", &chislo);
		popitki = 0;
		predpolozhenie = -1;
		while (predpolozhenie != chislo)
		{
			popitki = popitki + 1;
			predpolozhenie = rand () % (max-min) + min;
			printf("Вы загадали число %d ?\n", predpolozhenie);
			scanf_s("%c", &neravenstvo);
			scanf_s("%c", &neravenstvo);
			switch (neravenstvo)
			{
			    case('='):
			    {
				    printf("Ну я так и знал, что вы загадали именно это число. Количество попыток: %d", popitki);
				    predpolozhenie = chislo;
				    break;
			    }
			    case('>'):
			    {
				     min = predpolozhenie + 1;
				     break;
			     }
			    case('<'):
			    {
				     max = predpolozhenie - 1;
				     break;
			    }
			default:
				break;
			}
		}
	}
		_getch();
}
