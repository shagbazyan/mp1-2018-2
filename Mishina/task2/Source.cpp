#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <locale.h>
void main()
{
	setlocale(LC_ALL, "Rus");
	int a, x, y, n, min, max;
	char r;
	


	min = 1;
	max = 1000;
	n = 1;

	printf("Выберите режим: 1 - компьютер загадывает число, 2 - вы загадываете число\n");
	scanf("%i", &a);


	while ((a != 1) || (a != 2))
	{
		printf("Режим только 1 или 2: 1 - компьютер загадывает число, 2 - вы загадываете число. Выберите еще раз\n");
		scanf("%i", &a);
	}



	if (a == 1) {

		srand(0);
		x = 1 + rand() % 100;

		printf("Угадайте целое число между 1 и 1000\n");
		scanf("%i", &y);


		while (x != y) {

			if (x < y) printf("Загаданное число меньше \n", &y); else
				printf("Загаданное число больше \n", &y);
			scanf("%i", &y);
			n = n + 1;
		}

		printf("Вы отгадали число - ", &x);
		printf("Попыток ", n);
	}

	else {
		printf("Введите целое число в пределах между 1 и 1000\n");
		scanf("%i", &y);
		 

		while ((y < 1) || (y > 1000)) {
			printf("Число должно быть целым и в пределах между 1 и 1000. Введите еще раз\n");
			scanf("%i", &y);
		}

		r = '>';

		while (r!='=') {
			x = min + rand() % max;
			printf("Это число %i", x);
			printf("?  Знаками сравнения укажите отношение этого числа к вашему\n");
			scanf("%ch", &r);
			   while ((r!='=') && (r!= '>') && (r!= '<')) 
			   {
				   printf("Знаки сравнение - это >, <, =. Введите еще раз \n");
				   scanf("%ch", &r);
			   }
			   switch (r)
			   {
			   case '>': { x = min + rand() % (x - 1); max = x - 1; break; }
			   case '<': {x = (x + 1) + rand() % max; min = x + 1; break; }
			   case '=': break;
			   }
			   n = n + 1;
		}
		printf("Компьютер отгадал число - ", &y);
		printf("Попыток ", n);
	}



}