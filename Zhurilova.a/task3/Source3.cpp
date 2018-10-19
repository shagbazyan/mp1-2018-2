#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void main()
{
	setlocale(LC_ALL, "Rus");

	int exit;
	int n, dl, kolK, kolB;
	int x, y, i, j;
	int vvod1=0, vvod2, covp, proverka, game;
	int gen[] = { 0,1,2,3,4,5,6,7,8,9 };
	int chisO[5] = { 0 };
	int chisZ[5] = { 0 };
	int zag=0, otg, zapasO;

	do
	{
		printf("Введите длину числа от 2 до 5\n");
		scanf("%d", &n);
	}
	while ((n < 2) || (n > 5));
	
	
	y = 10;
	
	for (i = 1; i <= n; i++)
	{
		x = rand() % (10);
		if (y != x)
		{
			zag = zag * 10 + x;
			y = x;
			chisZ[i] = gen[x];
		}

	}
	game = 0;
	while (game == 0)
	{
		while (vvod1 == 0)
		{

			printf("Введите число\nВНИМАНИЕ!!! Число должно быть той же длины, что вы ввели раньше\nЧисло должно быть с РАЗЛИЧНЫМИ ЦИФРАМИ!\n");
			scanf("%otg", &otg);
			zapasO = otg;
			dl = 1;
			
			while(zapasO > 0)
			{
				zapasO = zapasO / 10;
				dl++;
			}
			zapasO = otg;
			for (i = 1; i <= dl; i++)
			{
				chisO[i] = zapasO % 10;
				zapasO = zapasO / 10;
			}
			if (dl != n)
			{
				printf("Сказано было ввести чиcло ОДИНАКОВОЙ длины!\n");
				vvod2 = 0;
			}
			else
				if (dl == n)
				{
					vvod2 = 1;
				}

			while (vvod2 == 1)
			{
				covp = 0;
				for (i = 1; i <= dl; i++)
				{
					for (j = (i + 1); j <= dl; j++)
					{
						if (chisO[i] != chisO[j])
						{
							covp = 0;

						}
						else
							if (chisO[i] == chisO[j])
							{
								covp = 1;
								
							}

					}
					if (covp = 1)
					{
						printf("Было сказано с РАЗЛИЧНЫМИ цифрами!\n");
						vvod2 = 0;
						
					}
					else
						if (covp = 0)
						{
							printf("Молодец! Вы ввели число верно!!!");
							proverka = 0;
						}
				}
			}
		}

		if (proverka == 0)
		{
			kolK = 0;
			kolB = 0;
			for (i = 1; i <= n; i++)
			{
				for (j = 1; j <= n; j++)
				{
					if (chisZ[i] == chisO[j])
					{
						kolK++;
					}
					if ((chisZ[i] == chisO[j]) && (i == j))
					{
						kolB++;
					}
				}
			}
			printf("Количество коров %d, Количество быков %d\n", kolK, kolB);
			if (kolB == n)
			{
				printf("Молодец, вы угадали число!");
				proverka = 1;
				game = 1;
			}
		}
	}
	
	scanf("%d", &exit);
}