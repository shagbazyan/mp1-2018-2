#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

void main()
{
	setlocale(LC_ALL, "Rus");

	int type = 0;
	int inp, ger, count;
	char Cinp, tmp;
	srand(time(NULL));

	printf("��� ����� ���������? �� (1) ��� ��������� (2) ?:\n");
	scanf_s("%d", &type);

	while (type != 1 && type != 2)
	{
		printf("������������ ����.\n");
		scanf_s("%d", &type);
	}

	if (type == 1)
	{
		ger = (rand() % 1001);
		inp = -1;
		count = 0;

		while (inp != ger)
		{
			printf("������� ��� ������� �����:\n");
			scanf_s("%d", &inp);
			count++;
			if (inp == ger)
				printf("�� ������� �� %d �������!\n", count);
			else if (inp > ger)
				printf("�� ����� ������� ������� �����!\n");
			else
				printf("�� ����� ������� ��������� �����!\n");
		}
	}
	else
	{
		printf("������� ����� �� 1 �� 1000:\n");
		scanf_s("%d", &inp);
		scanf_s("%c", &Cinp);
		count = 0;
		ger = 0;
		ger = (rand() % 1001);
		int min, max;
		min = 0; max = 1001;
		bool vic = false;

		while (!vic)
		{
			printf_s("������� ����������: %d\n", ger);
			printf_s("����� ���������� ������ ���� ������ '>' ������ '<' ��� �� ������ '=' ?:\n");

			count++;
			scanf_s("%c", &Cinp);
			scanf_s("%c", &tmp);

			switch (Cinp)
			{
			case '>':
				min = (ger < min ? min : ger) + 1;
				break;
			case '<':
				max = (ger > max ? max : ger);
				break;
			case '=':
				printf("��������� ������ �� %d �������!\n", count);
				vic = true;
				break;
			default:
				printf("������� > < ��� =\n");
				break;
			}

			ger = min + rand() % (max - min);
		}
	}
	_getch();
}
