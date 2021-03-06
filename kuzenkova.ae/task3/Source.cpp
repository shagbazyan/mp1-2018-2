#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int randomchik(int x, int y)
{
	return x + rand() % (y - x + 1);
}

void obnulim(int b[], int n)
{
	for (int i = 0; i < n; i++)
		b[i] = 0;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int n; // длина числа
	int a[5], flag[10], flagpol[10]; //массив для числа загаданного компьютером, флаг для контроля встречаемости цифр для компьютера и пользователя
	int i; //счетчик для цикла
	int chislo, x; //число для ввода и буферная переменная для этого числа
	int buk = 0, korova = 0; //Значения коровы и быков
	int radar, radarn; //чем больше радаров тем лучше, радар следит за повторяющиеся цифры, а радарн за короткостью числа
	int k; // число попыток
	int otvet; //ответ для хардкорного режима
	int z = 1; //число игр
	while (z < 3) 
	{
		k = 0;
		do 
		{
			printf("Введи длину числа от 2 до 5\n");
			scanf_s("%d", &n);
		} 
		while (n < 2 || n > 5);
		obnulim(flag, 10); //обнулим массивы
		obnulim(a, 5);
		for (i = 0; i < n; i++)
		{
			do 
			{
				if (i == 0)
					a[i] = randomchik(1, 9);
				else
					a[i] = randomchik(0, 9);
			} 
			while (flag[a[i]] != 0);
			flag[a[i]] = 1;
		}
		while (1 > 0)
		{
			buk = 0;
			korova = 0;
			x = 1;
			k++;
			do 
			{
				radar = 0;
				radarn = 0;
				obnulim(flagpol, 10);
				printf("Введи число с неповторяющимися цифрами заданной длины\n");
				scanf_s("%d", &chislo);
				x = chislo;
				for (i = 0; i < n; i++)
				{
					flagpol[x % 10]++;
					if (flagpol[x % 10] == 2)
						radar = 1;
					if (x == 0)
						radarn = 1;
					x = x / 10;
				}
				if (x > 0)
					printf("Слишком длинное\n");
				else
					if (radarn == 1)
						printf("Слишком короткое\n");
					else
						if (radar == 1)
							printf("Я сказал без повторов!! >:l\n");
			} 
			while (x != 0 || radar != 0 || radarn != 0);
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
			if (z == 1)
				printf("Коров - %d, Быков - %d\n", korova, buk);
			if (z == 2)
			{
				if (korova == 0 && buk == 0) 
					printf("Коров и Быков по нулю\n");
				if (korova == buk && korova != 0 && buk != 0)
					printf("Коров и Быков одного количеситва\n");
				if (korova > buk)
					printf("Коров больше чем быков на %d\n", (korova-buk) );
				if (korova < buk)
					printf("Быков больше чем коров на %d\n", (buk - korova));
			}
			if (buk == n) break;
		}
		printf("Ура! Вы нашли мою последовательность:) Мое число %d. Ты отгадал за %d попыток\n", x, k);
		if (z == 1) 
		{
			printf("Не хотите сыграть в хардкорный режим??? Введи 1, если да, и 0, если нет\n");
			do 
			{
				scanf_s("%d", &otvet);
			} 
			while (otvet != 0 && otvet != 1);
			if (otvet == 1)
			{
				printf("Начнем игру:)\n");
			}
			else
			{
				printf("Эх, пропали азартные игроки в наши времена. Я в вас разочарован :(\n");
				z = 2;
			}
		}
		z++;
	}
	scanf_s("%d", &n);
}