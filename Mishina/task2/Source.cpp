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

	printf("�������� �����: 1 - ��������� ���������� �����, 2 - �� ����������� �����\n");
	scanf_s("%d", &a);


	while ((a <1) || (a > 2))
	{
		printf("����� ������ 1 ��� 2: 1 - ��������� ���������� �����, 2 - �� ����������� �����. �������� ��� ���\n");
		scanf_s("%d", &a);
	}



	if (a == 1) {

		srand(0);
		x = 1 + rand() % 1000;

		printf("�������� ����� ����� ����� 1 � 1000\n");
		scanf_s("%d", &y);


		while (x != y) {

			if (x < y) printf("���������� ����� ������ \n", y); else
				printf("���������� ����� ������ \n", y);
			scanf_s("%d", &y);
			n = n + 1;
		}

		printf("�� �������� ����� %i ", x);
		printf(". ������� %i", n);
	}

	else {
		printf("������� ����� ����� � �������� ����� 1 � 1000\n");
		scanf_s("%i", &y);
		 

		while ((y < 1) || (y > 1000)) {
			printf("����� ������ ���� ����� � � �������� ����� 1 � 1000. ������� ��� ���\n");
			scanf_s("%i", &y);
		}
		x = min + rand() % max;
		r = '!';
		
		while (r!='=') {
			
			printf("��� ����� %i", x);
			printf("?  ������� ��������� ������� ��������� ����� ����� � ������\n");
			scanf_s("%ch", &r);
			   while ((r!='=') && (r!= '>') && (r!= '<')) 
			  {
				   printf("����� ��������� - ��� >, <, =. ������� ��� ��� \n");
				   scanf_s("%ch", &r);
			   }
			   switch (r)
			   {
			   case '>': {  max = x - 1;  x = min + rand() % max; break; }
			   case '<': { min = x + 1; x = min + rand() % max; break; }
			   }
			   n = n + 1;
		}
		printf("��������� ������� ����� - %i", y);
		printf("������� %i", n);
	}



}