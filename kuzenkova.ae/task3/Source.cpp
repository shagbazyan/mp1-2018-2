#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int randomchik(int x, int y)
{
	return x + rand() % (y - x + 1);
}

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int n; // длина числа
	int a[5], flag[10]; //массив для числа загаданного компьютером, флаг для контроля встречаемости цифр
	int i; //счетчик для цикла
	int chislo,x;
	int buk = 0, korova = 0; //Значения коровы и быков

	do {
		printf("Введи длину числа от 2 до 5\n");
		scanf_s("%d", &n);
	} while (n < 2 || n > 5);

	for (i = 0; i < 10; i++)
		flag[i] = 0;

	for (i = 0; i < 5; i++)
		flag[i] = 0;

	for (i = 0; i < n; i++)
	{
		do {
			if (i==0) 
				a[i] = randomchik(1, 9);
			else
				a[i] = randomchik(0, 9);
		} while (flag[a[i]] != 0);
		flag[a[i]] = 1;
		//printf("%d", a[i]);
	}
	
	while (1 > 0) 
	{
		buk = 0; 
		korova = 0;
		printf("Введи число с неповторяющимися цифрами заданной длины\n");
		scanf_s("%d", &chislo);
		x = chislo;
		for (i = n - 1; i >= 0; i--)
		{
			if (chislo % 10 == a[i])
				buk++;
			else
				if (flag[chislo % 10] == 1)
					korova++;
			chislo = chislo / 10;
		}
		printf("Коров - %d, Быков - %d\n", korova, buk);
		if (buk == n) break;
	}
	printf("Ура! Вы нашли мою последовательность:) Мое число %d", x);
	
	scanf_s("%d", &n);
}