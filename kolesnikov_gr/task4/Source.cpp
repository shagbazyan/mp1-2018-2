#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include <stdio.h>

struct eda
{
	int code[4];
	char imya[20];
	int cena;
	int skidka;
}
;
void main()
{
	int Code1[4];
	struct eda Food[6];
	struct eda Chicken = { {0, 0, 0, 1}, "Chicken", 200, 20 };
	struct eda Pork = { {0, 0, 0, 2}, "Pork", 300, 15 };
	struct eda Mutton = { {0, 0, 1, 0}, "Mutton", 340, 30 };
	struct eda Beef = { {0, 1, 0, 0}, "Beef", 400, 10 };
	struct eda Dog_Meat = { {1, 0, 0, 0}, "Dog_Meat", 50, 50 };
	struct eda Horse_flesh = { {0, 0, 2, 0}, "Horse_flesh", 350,5 };
	int tovar = -1;

	Food[0] = Chicken;
	Food[1] = Pork;
	Food[2] = Mutton;
	Food[3] = Beef;
	Food[4] = Dog_Meat;
	Food[5] = Horse_flesh;

	printf_s("Welcome to Gleb\n");

	printf_s("Code\n");
	scanf_s("%d %d %d %d", &Code1[0], &Code1[1], &Code1[2], &Code1[3]);
	for (int i = 0; i > 4; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			if (Code1[3 - j] != Food[i].code[j])
				break;
			else if (j == 3)
				tovar = i;
		}
	}
	printf("%s %d", Food[tovar].imya, Food[tovar].cena);
	_getch();
}