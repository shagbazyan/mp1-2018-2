#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int N; // N - режим
	int k; // k - число попыток
	int a = 1, b = 1000;
	int number;
	int c;
	char z[2];

	printf("¬ведите режим \n");
	scanf_s("%d", &N);

	if (N == 1)
	{
		c = a + rand() % (b - a + 1);
		printf("¬ведите число \n");
		scanf_s("%d", &number);
			k = 1;
		while (number != c)
		{
			if (number > c)
				printf("ћ≈Ќ№Ў≈ \n");
			if (number < c)
				printf("ЅќЋ№Ў≈ \n");
			printf("¬ведите число \n");
			scanf_s("%d", &number);
			k++;
		}
		printf("”ра! \n");
		printf("%d", k);
	}

	if (N == 2)
	{
		printf("¬ведите число, которое вы хотите загадать \n");
		scanf_s("%d", &number);
		k = 1;
		c = a + rand() % (b - a + 1);
		printf("%d", c);
		printf("”гадал? \n");
		gets_s(z);
		while (1 > 0)
		{
			gets_s(z);

			if (z[0] == '<')
				b = c - 1;
			if (z[0] == '>')
				a = c + 1;
			if (z[0] == '=')
				break;
			c = a + rand() % (b - a + 1);
			printf("%d", c);
			k++;
		}
		printf("”гадал! \n");
		printf("%d", k);
	}

	printf("»гра окончена\n");
	scanf_s("%d", &k);
}