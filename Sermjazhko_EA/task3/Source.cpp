#include <stdio.h> 
#include <locale.h> 
#include <time.h> 
#include <stdlib.h> 

void main()
{
	setlocale(LC_ALL, "Rus");
	int n, i, mass[5], r1; //длина, счетчик, массив рандома, сравнение 
	int kor, byk, mas[5], m, a, k, N=0; //коровы, быки, массив числа, остаток, само число, счетчик, кол-во попыток

	srand(time(NULL));
	printf("Игра: Коровы и Быки!\n Введите длину загадываемого числа (от 2 до 5)\n");
	scanf_s("%d", &n);

	while ((n < 2) || (n > 5))
	{
		printf("Неверно введена длина загадываемого числа. Попробуйте ещё раз\n");
		scanf_s("%d", &n);
	}

	r1 = 1;
	while (r1 == 1)
	{
		r1 = 0;
		i = 0;
		while (i < n)
		{
			if (i == 0)
				mass[i] = 1 + rand() % 9;
			else

				mass[i] = rand() % 10;
			i++;
		}
		for (i = 0; i < n; i++)
			for (k = i + 1; k < n; k++) 
			{
				if (mass[i] == mass[k])
				{
					r1 = 1;
					break;
				}
			}

	}
	byk = 0;
	while (byk != n)
	{
		printf("Ваши предположения?\n");
		scanf_s("%d", &a);
		byk = 0;
		kor = 0;
		N++;
		for (i = n - 1; i >= 0; i--)
		{
			m = a % 10;
			mas[i] = m;
			a = (a - m) / 10;
		}
		for (i = 0; i < n; i++)
		{
			if (mas[i] == mass[i])
				byk++;
			else
			{
				for (k = 0; k < n; k++)
				{
					if (mas[i] == mass[k])
						kor++;
				}
			}
		}
		printf("Быков: %d, коров: %d \n", byk, kor);
	}

	printf("Поздравляю, вы победили! Количество попыток: %d\n", N);
	scanf_s("%d", a);
}
