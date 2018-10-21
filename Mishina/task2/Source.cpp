#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <locale.h>
void main()
{
	
	int a, x, y, n, min, max;
	char r;
	


	min = 1;
	max = 1000;
	n = 1;

	printf("Выберите режим: 1 - компьютер загадывает число, 2 - вы загадываете число\n");
	scanf_s("%d", &a);


	while ((a <1) || (a > 2))
	{
		printf("Режим только 1 или 2: 1 - компьютер загадывает число, 2 - вы загадываете число. Выберите еще раз\n");
		scanf_s("%d", &a);
	}



	if (a == 1) {

		srand(0);
		x = 1 + rand() % 1000;

		printf("Угадайте целое число между 1 и 1000\n");
		scanf_s("%d", &y);


		while (x != y) {

			if (x < y) printf("Загаданное число меньше \n", y); else
				printf("Загаданное число больше \n", y);
			scanf_s("%d", &y);
			n = n + 1;
		}

		printf("Вы отгадали число %i ", x);
		printf(". Попыток %i", n);
	}

	else {
		printf("Введите целое число в пределах между 1 и 1000\n");
		scanf_s("%i", &y);
		 

		while ((y < 1) || (y > 1000)) {
			printf("Число должно быть целым и в пределах между 1 и 1000. Введите еще раз\n");
			scanf_s("%i", &y);
		}
		x = min + rand() % max;
		r = '!';
		
		while (r!='=') {
			
			printf("Это число %i", x);
			printf("?  Знаками сравнения укажите отношение этого числа к вашему\n");
			scanf_s("%ch", &r);
			   while ((r!='=') && (r!= '>') && (r!= '<')) 
			  {
				   printf("Знаки сравнение - это >, <, =. Введите еще раз \n");
				   scanf_s("%ch", &r);
			   }
			   switch (r)
			   {
			   case '>': {  max = x - 1;  x = min + rand() % max; break; }
			   case '<': { min = x + 1; x = min + rand() % max; break; }
			   }
			   n = n + 1;
		}
		printf("Компьютер отгадал число - %i", y);
		printf("Попыток %i", n);
	}



}