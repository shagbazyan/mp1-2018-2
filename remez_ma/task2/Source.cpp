#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

void main()
{
	setlocale(LC_ALL, "Rus");

	bool type;
	int inp, ger, count;
	char Cinp, tmp;
	srand(time(NULL));

	// ������ ����� 
	/*
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
	*/

	// ������ �����
	{
		printf("������� ����� �� 1 �� 1000:\n");
		scanf_s("%d", &inp);
		scanf_s("%c", &Cinp);
		count = 0;
		ger = 0;
		ger = (rand() % 1001);

		while (ger != inp)
		{			
			printf_s("������� ����������: %d\n", ger);

			count++;
			scanf_s("%c", &Cinp);
			scanf_s("%c", &tmp);

			if (Cinp == '<')
				ger += (rand() % (1000 - ger));
			else if (Cinp == '>')
				ger -= (rand() % ger);
			else if (inp == '=')
				printf("��������� ������ �� %d �������!\n", count);
		}

	}

	_getch();

}