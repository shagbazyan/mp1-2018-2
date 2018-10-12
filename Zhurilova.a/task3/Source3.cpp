#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void main()
{
	setlocale(LC_ALL, "Rus");

	int n, ch;
	int cif[] = { 0,1,2,3,4,5,6,7,8,9};//Создание массива с цифрами
	int ch[5];
	printf("Выберите длину числа от 2 до 5\n");
	scanf("%d", &n);
	while ((n < 2) || (n > 5))
	{
		printf("Вы ввели недопустимую длину числа. Введите ещё раз\n");
		scanf("%d", &n);
	}
	
	
	
	scanf("%d", &n);
}