#include <stdio.h>
#include <math.h>
void main()
{
	float h, w, d, m1, m2, m3, m4, m5, m, g, dsp, dvp;
	printf("������� � ����������� ������ ��������� ������ ����� � �������� �� 180 �� 220�� � ������ �� 80 �� 120��\n");
	scanf_s("%f", &h);
	scanf_s("%f", &w);
	while ((h > 220) || (h < 180) || (w > 120) || (w < 80))
	{
		printf("������� �������� ������. ��������� ��� ���.\n");
		scanf_s("%f", &h);
		scanf_s("%f", &w);
	}

	printf("������� � ����������� ������� ������� � �������� �� 50 �� 90��.\n");
	scanf_s("%f", &d);
	while ((d > 90) || (d < 50))
	{
		printf("������� �������� ������. ��������� ��� ���.\n");
		scanf_s("%f", &d);
	}

	g = 0.52; 
	dsp = 0.001;
	dvp = 0.82;
	m1 = dvp * h * w * 0.5;
	m2 = 2 * dsp * h * d * 1.5;
	m3 = 2 * dsp * w * d * 1.5;
	m4 = 2 * h * g * 1 * (w / 2);
	m5 = int(h / 40) * dsp * w * 1;
	m = m1 + m2 + m3 + m5 + m4;
	printf("����� ����� � �� = %f", m / 1000);
	scanf_s("%d", &w);
}