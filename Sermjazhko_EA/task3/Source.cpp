#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	setlocale(LC_ALL, "Rus");
	int n, ran, i, q, r; //количество цифр в числе, рандом

	srand(time(NULL));
	printf("Введите длину загадываемого числа (от 2 до 4)\n");
	scanf_s("%d", &n);
	//слишком долго
	if (n == 2)
	{ 
		ran = rand()%100;
		i = ran;
		q = i / 10;
		r = i % 10;
		while (q==r)//если при делении на 10 остаток и частное равны, то повтор
		{
			ran = rand() % 100;
			i = ran;
		}
		printf("Число загадано. Напоминаю, что число двузначное, ваши предположения?\n");
		scanf_s("%d%d", &i1, &j1);
	}
	else
	{
		if (n == 3)
		{
			ran1 = 1 + rand() % 9;
			i = ran1;
			ran2 = rand() % 10;
			j = ran2;
			ran3 = rand() % 10;
			d = ran3;
			while ((j == i) || (i == d) || (j == d))//если при делении на 100 частное, остаток при делении на 10 и остаток остатка равны, то повтор
			{
				ran2 = rand() % 10;
				j = ran2;
				ran3 = rand() % 10;
				d = ran3;
			}
			printf("Число загадано. Напоминаю, что число трехзначное, ваши предположения?\n");
			scanf_s("%d%d%d", &i1, &j1, &d1);
		}
		else
		{
			ran1 = 1 + rand() % 9;
			i = ran1;
			ran2 = rand() % 10;
			j = ran2;
			ran3 = rand() % 10;
			d = ran3;
			ran4 = rand() % 10;
			l = ran4;
			while ((j == i) || (i == d) || (j == d)||( i == l )||( j == l )||( d == l ))//если при делении на 1000 частное, остаток при делении на 100, остаток от остатка на 10 и последний ост. равны, то повтор
			{
				ran2 = rand() % 10;
				j = ran2;
				ran3 = rand() % 10;
				d = ran3;
				ran4 = rand() % 10;
				l = ran4;
			}
			printf("Число загадано. Напоминаю, что число четырехзначное, ваши предположения?\n");
			scanf_s("%d%d%d%d", &i1, &j1, &d1, &l1);
		}

	}

}