#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int random(int d_1, int d_2)
{
	srand(time(NULL));
	return (d_1 + rand() % (d_2 - d_1));
}

bool prov(int a)
{
	bool fl = true;
	int ch[10];
	for (int i = 0; i <= 9; i++)
		ch[i] = 0;
	while ((a > 0) && (fl == true))
	{
		ch[a % 10]++;
		if (ch[a % 10] > 1)
			fl = false;
		a = a / 10;
	}
	return fl;
}
void main()
{
	int r[10], ch[10], pos[10];
	int i, n, obl, new_ch, otvet, fl, cow, byk, att, des;
	for (i = 0; i <= 9; i++)
	{
		r[i] = i;
		ch[i] = 0;
		pos[i] = 0;
	}
	setlocale(LC_ALL, "Rus");
	fl = 1;
	while (fl == 1)
	{

		printf("Введите скольки значное будет число \n");
		scanf_s("%d", &n);
		des = pow(10, n - 1);
		if ((n <= 10) && (n >= 1))
		{
			new_ch = random(1, 10);
			ch[r[new_ch]] = 1;
			pos[r[new_ch]] = 1;
			//printf("%d", r[new_ch]);
			r[new_ch] = r[9];
			for (i = 2; i <= n; i++)
			{
				new_ch = random(0, 11 - i);
				ch[r[new_ch]] = 1;
				pos[r[new_ch]] = i;
				//printf("%d", r[new_ch]);
				r[new_ch] = r[10 - i];
			}
			printf("\n");
			byk = 0;
			att = 0;
			while (byk != n)
			{
				cow = 0;
				byk = 0;
				printf("Введите ваше число \n");
				scanf_s("%d", &otvet);
				if ((otvet >= des) && (otvet < des * 10) && (prov(otvet) == true))
				{
					for (i = n; i >= 1; i--)
					{
						if (ch[otvet % 10] == 1)
						{
							if (pos[otvet % 10] == i)
							{
								byk++;
							}
							else
							{
								cow++;
							}
						}
						otvet = otvet / 10;
					}
					att++;
					printf("Количество коров: %d, Количество быков: %d \n", cow, byk);
				}
				else
				{
					printf("Вы ввели недопустимое число! Попробуйте еще раз. \n");
				}
			}
			printf("Ура, вы победили! Вы угадали число с %d попытки.\n", att);
		}
		else
		{
			printf("Вы ввели недопустимое число \n");
		}
		printf("Хотите еще? 1.да 2.нет\n");
		scanf_s("%d", &fl);
	}
	while (true);
}