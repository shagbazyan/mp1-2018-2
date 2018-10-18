#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void main()
{
	setlocale(LC_ALL, "Rus");

	int n, proverka1=0, zag=0, i, j=10,  proverka2=0, otg, dl=0, kolK=0, kolB=0, x, r=1,q;
	int cfr[] = { 0,1,2,3,4,5,6,7,8,9};//Создание масссива с цифрами
	int chisZ[5] = { 0 };//Создание массива для цифр загаданного числа
	int chisO[5] = { 0 };//Создание массива для цифр отгадки
	
	printf("Выберите длину числа от 2 до 5\n");
	scanf("%d", &n);
	while ((n < 2) || (n > 5))
	{
		printf("Вы ввели недопустимую длину числа. Введите ещё раз\n");
		scanf("%d", &n);
	}
	
	while (proverka1 == 0)
	{

		for (i = 0; i < n;)//Генерирование числа по цифрам
		{
			x = rand() % (10);
			if (j != x)
			{
				chisZ[i] = x;//Заполнение массива chisZ
				j = x;
				zag = zag + x * r;
				r = r * 10;//Увеличение порядка
				i++;
			}
		}
		proverka1 = 1;//Число сгенерировано правильно
	}

	printf("Число загадано\n");

		
	while(proverka2==0)
	{
		while (dl != n)
		{
			printf("Введите предположительную отгадку, т.е. число с НЕПОВТОРЯЮЩИМИСЯ цифрами\n ВНИМАНИЕ! Длина числа(вашей отгадки) должна совпадать с выбранной ранее длиной загаданного числа\n");
			scanf("%d", &otg);
			for (i = 0; otg > 0; i++)//Заполнение массива chisO
			{
				chisO[i] = otg % 10;
				otg = otg / 10;
				dl++;
			}
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (chisZ[i] == chisO[j])//Сравнение цифр чисел
				{
					kolK++;
					if (i == j)//Сравнение позиций одинаковых цифр
					{
						kolB++;
					}

			     }
		     }
		}
		printf("Количество коров %d\n Количество быков %d\n", kolK, kolB);
		if (kolB==n)
		{
			printf("Вы угадали число полностью!");
			proverka2 = 1;//Окончание игры
		}
		dl = 0; kolK = 0; kolB = 0;//Обнуление переменных для входа в  while и for
	}
	scanf("%d", &q);
}