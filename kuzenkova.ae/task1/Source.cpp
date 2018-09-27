#include <stdio.h>
#include <math.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	float h = 0, w = 0, d = 0; //h - ������, w - ������, d - �������
	float pDsp = 0.8, pDvp = 0.82, pWood = 0.6; //��������� ���, ���, ������ � ��/��^2
	int n; //���������� �����
	float Vzadn, Vbok, Vkrush, Vdver, Vpolk; //������ : Vzadn - ������ ������, Vbok - ���������, Vkrush - ������� � ������ ������, Vpolk - �����, Vdver - ������
	float massa; // ����� �����
	float tpolok; //������� �����
	bool flag = 0;

	do {
		if (flag == 1)
			printf("�������!!!\n");
		printf("������� ������ � ��������� �� 180 �� 220 � ��\n");
		scanf_s("%f", &h);
		flag = 1;
	} while (h < 180 || h>220);

	flag = 0;

	do {
		if (flag == 1)
			printf("�������!!!\n");
		printf("������� ������ � ��������� �� 80 �� 120 � ��\n");
		scanf_s("%f", &w);
		flag = 1;
	} while (w < 80 || w > 120);

	flag = 0;

	do {
		if (flag == 1)
			printf("�������!!!\n");
		printf("������� ������� � ��������� �� 50 �� 90 � ��\n");
		scanf_s("%f", &d);
		flag = 1;
	} while (d < 50 || d > 90);

	printf("������� ������� ����� � ��\n");
	scanf_s("%f", &tpolok);

	Vbok = 2 * h * d * 1.5;
	Vzadn = h * w * 0.5;
	Vkrush = 2 * w * d * 1.5;
	Vdver = h * w;
	n = int((h - tpolok) / 40);
	Vpolk = n * w * d * tpolok;
	massa = (pDvp * Vzadn + pDsp * (Vbok + Vkrush + Vpolk) + pWood * Vdver) / 1000;
	printf("����� ����� � ����������� %f", massa);
	scanf_s("%d", &n);
}