#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int random(int d_1, int d_2)
{
	srand(time(NULL));
	return (d_1 + rand() % (d_2 - d_1));
}

void main()
{
	int r[10], ch[10], pos[10];
	int i, n, obl, new_ch, otvet, fl, cow, byk, att;
	for (i = 0; i <= 9; i++)
	{
		r[i] = i;
		ch[i] = 0;
		pos[i] = 0;
	}
	setlocale(LC_ALL, "Rus");
	printf("Введите скольки значное будет число \n");
	scanf_s("%d", &n);
	new_ch = random(1, 10);
	ch[r[new_ch]] = 1;
	pos[r[new_ch]] = 1;
	printf("%d", r[new_ch]);
	r[new_ch] = r[9];
	for (i = 2; i <= n; i++)
	{
		new_ch = random(0, 11 - i);
		ch[r[new_ch]] = 1;
		pos[r[new_ch]] = i;
		printf("%d", r[new_ch]);
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
		fl = 1;
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
		printf("Колличество коров: %d, Колличество быков: %d \n", cow, byk);
	}
	printf("Ура, вы победили! Вы угадали число с %d попытки.\n", att);
	while (true);
}