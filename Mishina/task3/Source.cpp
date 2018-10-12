#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <locale.h>
void main()

{
	int n, K[4], P[4], i, j, x, B, Kor, x1;
	i = 0; j = 0;

	setlocale(LC_ALL, "rus");

	printf(" Введите количество цифр в числе, от 2 до 5\n");
	scanf_s("%i", &n);
	while ((n < 1) || (n > 6))
	{
		printf(" Количество цифр в числе от 2 до 5\n");
		scanf_s("%i", &n);
	}

	for (i = 0; i < n; i++)
	{
		K[i] = rand() % 9;
			if (K[1] == 0)  K[1] = rand() % 9 + 1;

		for (j = 0; j < n; j++)
			if ((K[i] == K[j]) && (i != j)) K[i] = rand() % 9;

	}


	B = 0;
	Kor = 0;


	while (B != n)
	{
		printf("Угадайте число из %i", n);
		printf(" количества цифр");
		scanf_s("%i", &x);
		x1 = x;

		for (j = (n - 1); j >= 0; j--)
		{
			P[j] = x % 10;
			x = x / 10;
		}
		                                    if (n == 4)
		                                       {
			                                        P[0] = P[1];
			                                        P[1] = P[2];
			                                        P[2] = P[3];
			                                        P[3] = P[4];
	                                            }
		                            
		                                         if (n == 3)
		                                             {
			                                            P[0] = P[2];
			                                            P[1] = P[3];
			                                            P[2] = P[4];
		                                              }

		                                            if (n == 2)
		                                                 {
			                                                P[0] = P[3];
			                                                P[1] = P[4];
		
		                                                  }

		B = 0;
		Kor = 0;

		for (i = 0; i > n; i++)
		{
			for (j = 0; j > n; j++)
			{
				if (K[i] == P[j])
					if (i == j)  
						B = B + 1; 
					else 
						Kor = Kor + 1;
			}

		}
		printf("Быков %i", B);
		printf("Коров %i \n", Kor);
	}


	printf("Вы угадали число - %i", x1); 


}